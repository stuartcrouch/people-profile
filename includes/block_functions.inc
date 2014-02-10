<?php
/**
 * @file 
 * Functions used to generate the blocks that are rendered on the client sites
 */

$INCLUDES = drupal_get_path('module', 'ou_profile') . "/includes";
require_once "$INCLUDES/people_functions.inc";
  

//Displays a block containing all the level 1 pims units
function ou_profile_get_unit_list_block()
{
	global $user;
	
	// Is the user more than just "authenticated"
	if( count( $user->roles ) > 1 )
	{
		// Check to see if a unit has been requested via querystring so that it can be highlighted in the list
		$unit_id = "";
		if( isset( $_GET['unit'] ) )
		{
			if (is_numeric($_GET['unit']))
			{
				$unit_id = $_GET['unit'];
			}
		}

		// our block content
		$unit_list = "";
		
		# Get a list of units
		$query = db_select('node', 'n');
		$query->join('field_data_field_unit_code', 'uc', 'n.nid = uc.entity_id');
		$query->join('field_data_field_unit_level', 'ul', 'n.nid = ul.entity_id');
		$query->condition( 'ul.field_unit_level_value', '1', '=' ); //Only get level 1 units
		$query->addField('n', 'title');
		$query->addField('uc', 'field_unit_code_value', 'unit_code');
		$query->orderBy( 'n.title' ); 
		
		//This checks for those admin roles (e.g. PP0110 & PP0153)
		if (!in_array('DRADMIN', array_values($user->roles)))
		{
			$qor = array();
			foreach ($user->roles as $role)
			{
				if (strpos($role, "PP") !== FALSE)
				{
					$qor[] = str_replace( "PP", "", $role );
				}
			}
			$query->condition( 'uc.field_unit_code_value', $qor, 'IN' );
		}
		
		$all_pims_units = $query->execute()->fetchAll();

		//Loop through the results and produce a list of pims units
		foreach( $all_pims_units as $pims_unit )
		{
			if ($pims_unit->unit_code == $unit_id)
			{
				$title = "<strong>[".$pims_unit->title."]</strong>";
			} else {
				$title = $pims_unit->title;
			}
			$unit_list .= "<li><a href='?unit=".$pims_unit->unit_code."'>".$title."</a></li>\n";
		}

		$block['subject'] = t("PIMS Units List");
		$block['content']['#markup'] = $unit_list;
		
		return $block;
	}

	return '';
}

function ou_profile_get_people_search_block() {
  
    $block['subject'] = t("Search by name");
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
          $staff_list .= '<h3 name="' . $key . '" id="' . $key . '">' . $key . '</h3>';
          $staff_list .= '<a class="to-top" href="#list-top">Back to top</a>';
          $staff_list .= '<ul class="ou_profile_names">' . $value . '</ul>';
          
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
    $wrapper = '<div class="item-list" id="list-top"><ul class="AtoZ">' . $abc . '</ul></div>';
    $wrapper .= '<div class="list-items">' . $staff_list . '</div>';
      
    $block['subject'] = t("Find Staff Members by name");
    $block['content']['#markup'] = $wrapper;//ou_profile_get_people_and_job_titles(staff_node_ids, $search_query, TRUE);
    
    return $block;

}
