<?php
/**
 * @file - Functions related to retrieving lists of (or individual) people
 */

/**
 * Given an array of node ids from the people profile system
 * and/or a search query this function returns a nice HTML list
 * of links to people profiles with job titles
 * -- by Mark Williams December 2010
 * -- added ability to alphabetise in May 2011
 * -- renamed functions to avoid conflict with those on the business school site in October 2011
 * -- and removed business school specific functions in October 2011, too
 */

$INCLUDES = drupal_get_path('module', 'ou_profile') . "/includes";
require_once "$INCLUDES/local_functions.inc";

function ou_profile_get_people_and_job_titles($staff_node_ids, $search_query = NULL, $alphabetise = NULL) {

  $abc_staff_list = array();
  $staff_list="";
  $tag_search="";
  $search_query="";

  if (!$search_query && isset($_GET["match"]))
    $search_query = $_GET["match"];

  if (isset($_GET["tags"]))
    $tag_search = $_GET["tags"];

  ou_profile_log("ou_profile_get_people_and_job_titles q = %q t = %t", array("%q" => $search_query, "%t" => $tag_search));

  // Loop through all the staff we have
  if (is_array($staff_node_ids)) {
    $count = count($staff_node_ids);
    ou_profile_log("found %s nodes", array("%s" => $count));
    foreach ($staff_node_ids as $snid => $staff_data) {
      // Load the node
      $snode = node_load($snid, NULL, TRUE);
      $display_person = FALSE;

      // If we have nothing to filter for, we will always want to display this person
      if (!$search_query && !$tag_search)
        $display_person = TRUE;

      if (is_object($snode)) {

        if ($search_query) {
          // Check if it matches any of our search criteria

          // See if the search was found in the default name
          if (preg_match("/" . $search_query . "/i", $snode->title))
            $display_person = TRUE;

          //print_r($snode);die();
                    
          // See if the search was found in the surname
          if (isset ($snode->ou_profile['pdata']['field_pims_pref_surname']['value']) && 
              preg_match("/" . $search_query . "/i", $snode->ou_profile['pdata']['field_pims_pref_surname']['value']))
            $display_person = TRUE;
          
          if (isset ($snode->ou_profile['pdata']['field_pims_staff_surname']['value']) && 
              preg_match("/" . $search_query . "/i", $snode->ou_profile['pdata']['field_pims_staff_surname']['value']))
            $display_person = TRUE;

          // See if the search was found in the bio
          if (isset ($snode->ou_profile['pdata']['field_oup_personal_bio']['value']) && 
              preg_match("/" . $search_query . "/i", $snode->ou_profile['pdata']['field_oup_personal_bio']['value']))
            $display_person = TRUE;
        }

        if ($tag_search && $snode->ou_profile['pdata']['field_oup_expertise']['value']) {

          foreach ($snode->ou_profile['pdata']['field_oup_expertise']['value'] as $expertise) {
            if (preg_replace("/\+/", " ", $tag_search) == $expertise['value'])
              $display_person = TRUE;
          }
        }

        // If we matched the search (or there was no search) add it to the list of valid IDs
        if ($display_person) {

          //print_r($snode);
          // Build the persons name and role
          $list_item = l($snode->title, "node/" . $snid);

          if (isset($snode->ou_profile['pdata']['field_oup_job_title'])) {
            $list_item .= $snode->ou_profile['data']['field_oup_job_title']['value'];
          } 
          elseif (isset($snode->ou_profile['pdata']['field_pims_appt_job_title'])) {
            $list_item .= $snode->ou_profile['pdata']['field_pims_appt_job_title']['value'];
          }

          // Figure out where they belong in the list
          if ($staff_data['pref_surname']) {
            $initial = substr($staff_data['pref_surname'], 0, 1);
          } 
          else {
            $initial = substr($staff_data['surname'], 0, 1);
          }

          // Add it to the list
          if (!isset($abc_staff_list[$initial]))
            $abc_staff_list[$initial] = "";
          $abc_staff_list[$initial] .= "<li>$list_item</li>";
        }

      }


      // clear some memory
      unset($snode);
    }
  }


  if (count($abc_staff_list)) 
    return $abc_staff_list;
  else 
    return "<p>No staff biographies match your keyword search. Please try a different keyword.</p>";
  
}

function ou_profile_field_search($in_array) {
  
  $source_string = "";
  
  if (isset($in_array))
    $source_string = $in_array['value'];
  
  return preg_match("/" . $search_query . "/i", $source_string);
}

/**
 * Given an array of node ids from a local search (e.g. senior management team)
 * returns a nice HTML list of links to people profiles with job titles
 * sorted in order of surname (not possible with a view as data doesn't exist locally)
 * -- by Mark Williams March 2011
 */
function ou_profile_get_people_and_job_titles_for_local_search($staff_node_ids) {
  
  $staff_list_items=array();
  
  foreach ($staff_node_ids as $snid) {

    $snode = node_load($snid, NULL, TRUE);
    if (is_object($snode)) {
      
      if ($surname = $snode->ou_profile['data']['field_pims_pref_surname']['value']) {
        $surname = $snode->ou_profile['data']['field_pims_pref_surname']['value'];
      } 
      elseif ($snode->ou_profile['data']['field_pims_staff_surname']['value']) {
        $surname = $snode->ou_profile['data']['field_pims_staff_surname']['value'];
      } 
      else { // skip this node as it may now be invisible or unpublished
        unset($snode);
        continue;
      }
      
      $staff_list_items[$surname] = "<li>" . l($snode->title, "node/" . $snid);
      if ($snode->ou_profile['data']['field_oup_job_title']['value']) {
        $staff_list_items[$surname] .= "<br/>" . $snode->ou_profile['data']['field_oup_job_title']['value'];
      } 
      elseif ($snode->ou_profile['data']['field_pims_appt_job_title']['value']) {
        $staff_list_items[$surname] .= "<br/>" . $snode->ou_profile['data']['field_pims_appt_job_title']['value'];
      }
      
      $staff_list_items[$surname] .= "</li>";
    }
    unset($snode);
  }
  
  ksort($staff_list_items); // sort array by key - i.e surname in this case
  
  if (!empty($staff_list_items)) {
    
    $staff_list = "<ul>";
    foreach ($staff_list_items as $item) {
      $staff_list .= $item;
    }
    
    $staff_list .= "</ul>";
    return $staff_list;
  } 
  else {
    return "<p>No staff.</p>";
  }
}


/**
 * Returns a search form for use with profiles from the people profile system
 * -- by Mark Williams, December 2010
 */
function ou_profile_get_people_search_form($search_query = NULL) {
  
  if (!$search_query && !empty($_GET["match"])) 
    $search_query = $_GET["match"];
  elseif ($search_query == "All") // ignore current selection
    $search_query = "";
  
  $split_uri = preg_split("/\?/", request_uri());
  // TODO: Convert this to use the FORMS API to avoid XSS
  $search_form = '<form action="' . $split_uri[0] . '" method="get" accept-charset="UTF-8" id="people-profiles-search-form">';
  $search_form .= '<div><input type="text" maxlength="128" name="match" id="edit-match" size="15" value="' . $search_query . '" class="form-text" />';
  $search_form .= '<input type="submit" value="Search" class="form-submit"></div>';
  $search_form .= '</form>';
  
  if ($search_query ||  isset($_GET["tags"])) {
    // TODO: Convert this to use the FORMS API to avoid XSS
    $search_form .= '<form action="' . $split_uri[0] . '" method="get" accept-charset="UTF-8" id="people-profiles-search-reset-form">';
    $search_form .= '<input type="submit" value="Reset" class="form-submit" title="See all staff profiles">';
    $search_form .= '</form>';
  }
  return $search_form;
}

function ou_profile_search_form(&$form_state) {
  $form['match'] = array(
      '#type' => 'textfield',
      '#title' => 'Search',
      '#description' => t('Enter the value you wish to find'),
      );
  $form['submit'] = array(
      '#type' => 'submit', 
      '#value' => t('Search')
      );
  
  return $form;
}

/**
 * Returns a select list form for finding experts as tagged on profiles in the people profile system
 * -- by Mark Williams, December 2010
 */
function ou_profile_get_expertise_selection() {
  
  $tag_search = $_GET["tags"];
  $tag_array = theme_get_expertise_tags();
  
  $split_uri = preg_split("/\?/", request_uri());
  // TODO: Convert this to use the FORMS API to avoid XSS
  $select_form = '<form action="' . $split_uri[0] . '" method="get" accept-charset="UTF-8" id="people-profiles-expertise-form">';
  $select_form .= '<div><label for="edit-tags" style="font-weight:bold;">Find an expert:</label></div>';
  $select_form .= '<div><select name="tags"><option value="">select...</option>';
  
  foreach ($tag_array as $tag) {
    $selected = ($tag == preg_replace("/\+/", " ", $tag_search)) ? " selected " : "";
    $select_form .= '<option ' . $selected . 'value="' . $tag . '">' . $tag . '</option>';
  }
  
  $select_form .= "</select>";
  $select_form .= '<input type="submit" value="Search" class="form-submit"></div>';
  $select_form .= '</form>';
  
  return $select_form;
}

/**
 * Generic function which returns a select menu for a Drupal CCK field to a form
 * to be used when Drupal views are not flexible enough
 * - $field = CCK field name
 * - $label = Label to give select menu if the one in the database isn't appropriate
 * - $par_name = Parameter passed in the URL when a selection is made and form is submitted
 * - $default_value = Selected value for parameter (e.g. a default value passed to this function)
 * - $allowed_values = Array of key value pairs - e.g. node reference ids and node titles
 * - $any = If TRUE allow the "Any" option in the select menu
 * -- by Mark Williams, May 2011
 *
 */
function ou_profile_get_select_menu_for_field($field, $label = NULL, $par_name = NULL, $default_value = NULL, $allowed_values = NULL, $any = TRUE) {
  
  if (substr($field, 0, 5) == "field") { // This is a CCK field
    $field_info = content_fields($field);
    if (!is_array($allowed_values)) $allowed_values = content_allowed_values($field_info);
    if (!$label) $label = $field_info['widget']['label'];
    
  } 
  elseif (!is_array($allowed_values)) {
    return "<p>Error: Allowed values not specified for the select menu</p>";
  } 
  elseif (!$label) {
    return "<p>Error: Label not specified for the select menu</p>";
  }
  
  if (!$par_name) 
    $par_name = $field;
  
  if ($default_value) {
    $selected_value = $default_value;
  } 
  elseif ($par_name) {
    $selected_value = $_GET[$par_name];
  } 
  else {
    $selected_value = "";
  }
  
  
  $select_form = '<div class="' . $field . '-select miw-form"><label for="edit-' . $field . '">' . $label . ': </label>';
  $select_form .= '<select name="' . $par_name . '" class="form-select" id="edit-' . $par_name . '">';
  
  if ($any) {
    if (!$allowed_values[$selected_value]) {
      $select_form .= '<option value="All" selected="selected">&lt;Any&gt;</option>';
    } 
    else {
      $select_form .= '<option value="All">&lt;Any&gt;</option>';
    }
  }
  
  
  foreach ($allowed_values as $key => $value) {
    if ($key == $selected_value) {
      $select_form .= '<option value="' . $key . '" selected="selected">' . $value . '</option>';
    } 
    else {
      $select_form .= '<option value="' . $key . '">' . $value . '</option>';
    }
  }
  
  $select_form .= "</select></div>";
  return $select_form;
}

/**
 * Replace title for old staff member if hidden by profile modules or if profile made invisible and ou_profile client cron job has not yet run
 * This use of a db_query was agreed with Sheila Coupe in June 2011
 * By Mark Williams
 */
function ou_profile_get_title($node_title, $nid) {
  if (preg_match("/This profile /", $node_title)) {
    $title=db_result(db_query("SELECT title from {node} WHERE nid=" . $nid));
  } 
  else {
    $title = $node_title;
  }
  return $title;
}


/**
*
* Author: Mark Williams
*
* Return local nodes on client website based on query of full profile and PIMS nodes on profile server
* Do this by getting all unique ids for selected PIMS nodes on the profile server and then
* using these unique ids to get local nodes
*
*/
function ou_profile_get_profile_nodes($query = NULL, $type = NULL) {
  
  if (preg_match("/;/", $query)) {
    return;
  }
  $INCLUDES = drupal_get_path('module', 'ou_profile') . "/includes";
  require_once "$INCLUDES/local_functions.inc";

  $a_site_info = ou_profile_lget_site_info();
  $site_path = ou_profile_lget_site_path();
  $unit_code = $a_site_info['unit_code'];

  ou_profile_log("Unit code = " . $unit_code);
  ou_profile_log("query = " . $query);
  ou_profile_log("type = " . $type);

  // Set database to profiles
  db_set_active('profiles');

  // This needs to stay as an old-school select for parameters to be passed to it
  $server_query = "SELECT field_pims_unique_id_value, field_pims_pref_surname_value, field_pims_staff_surname_value ";
  $server_query .= ", CONCAT_WS(',',field_pims_pref_surname_value, field_pims_staff_surname_value) AS ordername ";
  $server_query .= "FROM content_type_pims ";
  $server_query .= "WHERE ";
  if ($query) {
    $server_query .= $query . " ";
  }
  else { // no query specified so all results will be returned
    $server_query .= " 1 ";
  }

  if ($unit_code)
    $server_query .= "AND field_pims_l1_estab_unit_code_value=" . $unit_code . " "; // only return results for unit
 
  $server_query .= "AND field_pims_staff_id_value IN " .
    "(SELECT field_oup_staff_id_value FROM content_type_profile " . 
    "WHERE field_oup_visibility_value= " .
    (((int)$a_site_info['visibility'])-1) . ")" . // only return visible profiles!
    " ORDER BY ordername ASC"; // order by preferred surname or surname if preferred surname is not set
  ou_profile_log("server_query = " . $server_query);
  
  $server_result = db_query($server_query);
  $staff_ids = array();
  //while ($pims_data = db_fetch_object($server_result)) {
  foreach ($server_result as $pims_data) {
    $staff_ids[$pims_data->field_pims_unique_id_value]['surname'] = $pims_data->field_pims_staff_surname_value;
    $staff_ids[$pims_data->field_pims_unique_id_value]['pref_surname'] = $pims_data->field_pims_pref_surname_value;
  }

  // Set database back to original and query client website to get local, matching profiles
  db_set_active();
  
  $client_profiles = array();
  $INLIST = "";
  // loop over staff ids and get local nodes on client website
  foreach ($staff_ids as $staff_id => $staff_data) { 
     $INLIST .= "'" . $staff_id . "',";
  }

  $unordered_client_profiles = array();
  if ($INLIST) {
     $INLIST = rtrim($INLIST, ",");
     if ($site_path != ou_profile_server_site_path()) {
      $client_query = "SELECT node.nid, node.title, field_data_field_pims_unique_id.field_pims_unique_id_value as staff_id " .
          "FROM {node}, {field_data_field_pims_unique_id} " .
          "WHERE " .
          "node.type in ('ou_profile') " .
          "AND node.status = 1 " .
          "AND node.nid = field_data_field_pims_unique_id.entity_id " .
          "AND field_data_field_pims_unique_id.field_pims_unique_id_value IN (" . $INLIST . ")";
          // N.B. 'ORDER BY find_in_set(staff_id, $INLIST)' cannot be used here as all profiles may not be on client server
    }
    else {
      $client_query = "SELECT node.nid, node.title, content_type_pims.field_pims_unique_id_value as staff_id FROM {node}, {content_type_pims} ";
      $client_query .= "WHERE ";
      $client_query .= "node.type in ('pims') AND node.status='1' ";
      $client_query .= "AND node.nid=content_type_pims.nid ";
      $client_query .= "AND content_type_pims.field_pims_unique_id_value IN (" . $INLIST . ") "; 
      // N.B. 'ORDER BY find_in_set(staff_id, $INLIST)' cannot be used here as all profiles may not be on client server
    }

    ou_profile_log("client query = " . $client_query);
    $client_result = db_query($client_query);
    //while ($profile = db_fetch_array($client_result)) {
    foreach ($client_result as $profile) {
      if ($type == "list") {
      ou_profile_log("creating list item for - " . $profile['title']);
              $unordered_client_profiles[$profile['staff_id']] = l($profile['title'], "node/" . $profile['nid']); // Drupal function to return well-formed link to node
      }
      else {
       $unordered_client_profiles[$profile->staff_id] = $profile->nid;
      }
    }
  }
  else
     return;

  ou_profile_log("re-ordering data");
  foreach ($staff_ids as $staff_id => $staff_data) { // reorder the unordered client profiles to restore surname order
    if (isset($unordered_client_profiles[$staff_id])) {
      // If we were asked for an array, we pass back the staff_data array
      if ($type == "array")
        $client_profiles[$unordered_client_profiles[$staff_id]] = $staff_data;
      else // Otherwise we just pass back the nid so they can do thier own processing
        $client_profiles[] = $unordered_client_profiles[$staff_id];
    }
  }

  ou_profile_log("returning profiles");
  return $client_profiles;
}