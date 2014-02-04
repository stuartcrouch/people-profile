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

	//Get the values of any filter fields
	if (isset( $_GET[ 'keyword' ] ) )
	{
		$filter_keyword = trim( strtolower( urldecode( $_GET[ 'keyword' ] ) ) );
	}
	if (isset( $_GET[ 'job' ] ) )
	{
		$filter_job = trim( strtolower( urldecode( $_GET[ 'job' ] ) ) );
	}
	if (isset( $_GET[ 'dept' ] ) )
	{
		$filter_dept = trim( strtolower( urldecode( $_GET[ 'dept' ] ) ) );
		switch( substr( $filter_dept, -1 ) )
			{
			case '1':
				$deptfield = 'field_pims_l1_estab_unit_desc';
				break;
			case '2':
				$deptfield = 'field_pims_l2_estab_unit_name';
				break;
			case '3':
				$deptfield = 'field_pims_l3_estab_unit_name';
				break;
			case '4':
				$deptfield = 'field_pims_l4_estab_unit_name';
				break;
			}
		$filter_dept = substr( $filter_dept, 0, strlen( $filter_dept )-2 );
	}

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
	
		//Check for the keyword value
		if( isset( $filter_keyword ) )
		{
			$user_field_values = field_get_items( 'node', $snode, 'field_profile_taxonomy' );
			if( $user_field_values )
			{
				$user_field = array();
				foreach( $user_field_values as $data )
				{
					$user_field[] = trim( strtolower( $data[ 'value' ] ) );
				}
				if( !array_search( $filter_keyword, $user_field ) )
				{
					$display_person = FALSE;
				}
				
			} else {
				$display_person = FALSE;
			}
		}

		//Check for the job title value
		if( isset( $filter_job ) )
		{
			$user_field_values = field_get_items( 'node', $snode, 'field_pims_appt_job_title' );
			if( $user_field_values )
			{
				if( $filter_job != trim( strtolower( $user_field_values[0]['value'] )))
				{
					$display_person = FALSE;
				}
				
			} else {
				$display_person = FALSE;
			}
		}

		//Check for the dept
		if( isset( $filter_dept ) )
		{
			$user_field_values = field_get_items( 'node', $snode, $deptfield );
			if( $user_field_values )
			{
				if( $filter_dept != trim( strtolower( $user_field_values[0]['value'] )))
				{
					$display_person = FALSE;
				}
				
			} else {
				$display_person = FALSE;
			}
		}


        // If we matched the search (or there was no search) add it to the list of valid IDs
        if ($display_person) {

          // Build the persons name and role
          $list_item = l($snode->title, "node/" . $snid, array('attributes' => array('class' => array('ou_profile_profile_link'))) );

          if ( isset( $snode->field_oup_job_title['und'] ) ) {
            $list_item .= '<div class="ou_profile_job_title">'.$snode->field_oup_job_title['und'][0]['safe_value'].'</div>';
          } 
          elseif ( isset( $snode->field_pims_appt_job_title['und'] ) ) {
            $list_item .= '<div class="ou_profile_job_title">'.$snode->field_pims_appt_job_title['und'][0]['safe_value'].'</div>';
          }

          // Figure out where they belong in the list
          if ($staff_data['pref_surname']) {
            $initial = strtoupper( substr($staff_data['pref_surname'], 0, 1) );
          } 
          else {
            $initial = strtoupper( substr($staff_data['surname'], 0, 1) );
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
  {
    ksort( $abc_staff_list );
	return $abc_staff_list;
  } else {
    return "<p>No staff biographies match your keyword search. Please try a different keyword.</p>";
  }
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
  $search_form .= '<div><input type="text" maxlength="128" name="match" id="edit-match" size="26" value="' . $search_query . '" class="form-text" placeholder="Search for a name" />';
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
function ou_profile_get_profile_nodes( $type = NULL )
{

  
  $INCLUDES = drupal_get_path('module', 'ou_profile') . "/includes";
  require_once "$INCLUDES/local_functions.inc";

  $a_site_info = ou_profile_lget_site_info();
  $site_path = ou_profile_lget_site_path();
  $unit_code = $a_site_info['unit_code'];

  ou_profile_log("Unit code = " . $unit_code);

  // Set database to profiles
  db_set_active('profiles');
  
  // This needs to stay as an old-school select for parameters to be passed to it
  $server_query = 
  "SELECT " .
  "pims_unique_id.field_pims_unique_id_value, " .
  "pims_pref_surname.field_pims_pref_surname_value, " .
  "pims_staff_surname.field_pims_staff_surname_value, " .
  "CONCAT(pims_pref_surname.field_pims_pref_surname_value, pims_staff_surname.field_pims_staff_surname_value) AS ordername " .
  "FROM field_data_field_pims_unique_id pims_unique_id " .
  "INNER JOIN field_data_field_pims_pref_surname pims_pref_surname ON pims_unique_id.entity_id = pims_pref_surname.entity_id " .
  "INNER JOIN field_data_field_pims_staff_surname pims_staff_surname ON pims_unique_id.entity_id = pims_staff_surname.entity_id " .
  "INNER JOIN field_data_".$a_site_info['unit_code_field']." pims_unit_code ON pims_unique_id.entity_id = pims_unit_code.entity_id " .
  "INNER JOIN field_data_field_pims_staff_id pims_staff_id ON pims_unique_id.entity_id = pims_staff_id.entity_id " .
  "INNER JOIN field_data_field_oup_staff_id oup_staff_id ON pims_staff_id.field_pims_staff_id_value = oup_staff_id.field_oup_staff_id_value " .
  "INNER JOIN field_data_field_oup_visibility oup_visibility ON oup_staff_id.entity_id = oup_visibility.entity_id " .
  "WHERE oup_visibility.field_oup_visibility_value >= " . ( ( (int)$a_site_info['visibility'] ) -1 ) . " "; // only return visible profiles

  //Filter the ou_unit
  if ($unit_code)
  {
    $server_query .= "AND pims_unit_code.".$a_site_info['unit_code_field']."_value ='" . $unit_code . "' "; // only return results for unit
  }
  $server_query .= "ORDER BY ordername ASC"; // order by preferred surname or surname if preferred surname is not set
  ou_profile_log("server_query = " . $server_query);
  
  $server_result = db_query($server_query);
  
  //Create an array of results by surname using the pims_unique_id as the key
  $staff_ids = array();
  $INLIST = "";
  foreach ($server_result as $pims_data)
  {
    //$staff_ids[$pims_data->field_pims_unique_id_value]['surname'] = $pims_data->field_pims_staff_surname_value;
	if( $pims_data->field_pims_pref_surname_value == '' )
	{
      $staff_ids[$pims_data->field_pims_unique_id_value]['pref_surname'] = $pims_data->field_pims_staff_surname_value;
	} else {
      $staff_ids[$pims_data->field_pims_unique_id_value]['pref_surname'] = $pims_data->field_pims_pref_surname_value;
	}
	
    $INLIST .= "'" .$pims_data->field_pims_unique_id_value. "',";
  } 

  // Set database back to original and query client website to get local, matching profiles
  db_set_active();
  

  $client_profiles = array();
  
  $unordered_client_profiles = array();
  if ($INLIST)
  {
     $INLIST = rtrim($INLIST, ",");
	
     if ($site_path != ou_profile_server_site_path())
	 {
	   // On client site, get the list of matching profiles using the pims_unique_id
       $client_query = 
	      "SELECT node.nid, node.title, field_data_field_pims_unique_id.field_pims_unique_id_value as staff_id " .
          "FROM {node}, {field_data_field_pims_unique_id} " .
          "WHERE " .
          "node.type in ('ou_profile') " .
          "AND node.status = 1 " .
          "AND node.nid = field_data_field_pims_unique_id.entity_id " .
          "AND field_data_field_pims_unique_id.field_pims_unique_id_value IN (" . $INLIST . ")";
          // N.B. 'ORDER BY find_in_set(staff_id, $INLIST)' cannot be used here as all profiles may not be on client server
     } else {
       $client_query = 
          "SELECT n.nid, n.title, pims_unique_id.field_pims_unique_id_value as staff_id " .
          "FROM node n " .
          "INNER JOIN field_data_field_pims_unique_id pims_unique_id ON pims_unique_id.entity_id = n.nid " .
          "WHERE n.type in ('pims') ".
          "AND n.status = '1' " .
          "AND pims_unique_id.field_pims_unique_id_value IN (" . $INLIST .") ";
    }

    ou_profile_log("client query = " . $client_query);
    $client_result = db_query($client_query);

    foreach ($client_result as $profile) {
      if ($type == "list")
	  {
          $unordered_client_profiles[$profile['staff_id']] = l($profile['title'], "node/" . $profile['nid']); // Drupal function to return well-formed link to node
      } else {
          $unordered_client_profiles[$profile->staff_id] = $profile->nid;
      }
    }
  } else {
     return;
  }
  
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

/**
*
* Author: Mark Williams
*
* Return an array of expertise keywords for the client website's unit
*
*/
function theme_get_expertise_tags() {
  
  $a_site_info = ou_profile_lget_site_info();
  $unit_code = $a_site_info['unit_code'];
  $site_visibility = (int) $a_site_info['visibility'];

  // Set database to profiles
  db_set_active('profiles');

  // TODO: Rewrite me as db_query array
  //$sql_query = db_select('node', 'n')->distinct();
  $sql_query = db_select('field_data_field_oup_expertise', 'expertise')->distinct();
  $sql_query->addField('expertise', 'field_oup_expertise_value');

  $sql_query->join('field_data_field_prv_expertise', 'expertise_privacy', 'expertise.entity_id = expertise_privacy.entity_id');
  $sql_query->join('field_data_field_privacy_value', 'privacy', 'privacy.entity_id = expertise_privacy.field_prv_expertise_nid');
  $sql_query->join('field_data_field_pims_l1_estab_unit_code', 'l1_estab_unit', 'expertise.entity_id = l1_estab_unit.entity_id');
  
  $sql_query
    ->condition( 'privacy.field_oup_visibility_value', $site_visibility,'>=')
    ->condition( 'l1_estab_unit.field_pims_l1_estab_unit_code_value', $unit_code, '=' );
  
  $sql_query->isNotNull('expertise.field_oup_expertise_value');


  /*$sql_query = "SELECT DISTINCT field_oup_expertise_value ";
  $sql_query .= "FROM {content_type_profile}, {content_type_pims}, {content_field_oup_expertise}, {content_type_privacy_value} ";
  $sql_query .= "WHERE content_field_oup_expertise.nid = content_type_profile.nid ";
  $sql_query .= "AND content_type_profile.field_oup_staff_id_value=content_type_pims.field_pims_staff_id_value ";
  $sql_query .= "AND content_type_profile.field_prv_expertise_nid=content_type_privacy_value.nid ";
  $sql_query .= "AND content_type_privacy_value.field_privacy_value_value >=" . $site_visibility . " ";
  $sql_query .= "AND content_type_pims.field_pims_l1_estab_unit_code_value =" . $unit_code . " ";
  $sql_query .= "AND content_field_oup_expertise.field_oup_expertise_value IS NOT NULL ";
*/


  $sql_result = db_query($sql_query);

  $tags = array();
  while ($row = db_fetch_object($sql_result)) {
    $tags[] = $row->field_oup_expertise_value;
  }

  db_set_active();

  return $tags;
}