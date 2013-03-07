<?php
/**
 * @file 
 * Functions used to generate the blocks that are rendered on the client sites
 */

$INCLUDES = drupal_get_path('module', 'ou_profile') . "/includes";
require_once "$INCLUDES/people_functions.inc";
  

function ou_profile_get_unit_list_block() {
  
  global $user;
  
  if (count($user->roles) > 1) { 
    // our block content
    $unit_list = "";
    # Get a list of units
    $query = "SELECT n.title, u.field_unit_code_value FROM {node} AS n, content_type_ou_unit AS u WHERE n.nid=u.nid ";
    if (!in_array('DRADMIN', array_values($user->roles))) {
      $query .= "AND (";
      $qor = "";
      foreach ($user->roles as $role) {
        if (strpos($role, "PP") !== FALSE) {
          if ($qor != "")
            $qor .= "OR ";
          $qor .= "u.field_unit_code_value = '" . str_replace("PP", "", $role) . "' ";
        }
      }
      
      $query .= $qor . ") ";
    }
    $query .= "ORDER by n.title";
    
    $result = db_query($query);
    $unit_title = "";
    
    while ($data = db_fetch_object($result)) {
      
      if ($data->field_unit_code_value == $unit_id) {
        $title = "<strong>[$data->title]</strong>";
        $unit_title = $data->title;
      } 
      else 
        $title = $data->title;
      
      $unit_list .= "<li><a href='?unit=$data->field_unit_code_value'>$title</a></li>\n";
    }
    
    $block['subject'] = t("PIMS Units List");
    $block['content']['#markup'] = $unit_list;
  }
  
  return $block;
}

function ou_profile_get_people_search_block() {
  
    $block['subject'] = t("Search for people");
    $block['content']['#markup'] = ou_profile_get_people_search_form();
    
    return $block;
}

function ou_profile_get_people_list_block() {
  
    if (!isset($search_query))
      $search_query = "";
    
    $staff_node_ids = theme_get_profile_node_list();
    $people_results = ou_profile_get_people_and_job_titles($staff_node_ids, $search_query, TRUE);
    
    $staff_initials = array();
    $staff_list = "";
    if (is_array($people_results)) {
      
      foreach ($people_results as $key => $value) {
          $staff_list .= '<h3 name="' . $key . '" id="' . $key . '">' . $key . '</h3><ul class="ou_profile_names">' . $value . '</ul>';
          $staff_list .= '<a class="to-top" href="#org">Back to top</a>';
          $staff_initials[$key] = TRUE;
      }
    }
    else 
      $staff_list .= $people_results;
  
    $abc = "";
    foreach (range('A', 'Z') as $i) {
      if (isset($staff_initials[$i])) {
        $abc .= '<li><a href="#' . $i . '">' . $i . '</a></li>';
      } 
      else 
        $abc .= "<li>$i</li>";
    }
    
    if (isset($_GET["tags"]) || isset($_GET["match"])) 
      $reset_text = '<span class="reset-text">(reset form to see all staff profiles)</span>';
  
    //$wrapper = '<p class="AtoZ">Find staff members by name: '.$reset_text.'</p>';
    $wrapper = '<ul class="AtoZ">' . $abc . '</ul>';
    $wrapper .= $staff_list;
      
    $block['subject'] = t("Find Staff Members by name");
    $block['content']['#markup'] = $wrapper;//ou_profile_get_people_and_job_titles(staff_node_ids, $search_query, TRUE);
    
    return $block;

}
