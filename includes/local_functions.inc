<?php
/**
 * @file - Functions related to retrieving lists of (or individual) people
 * Functions local to the module
/*

/**
 * Get unit code that this site is responsible for.
 * Return unit code if it exists, else return FALSE
 *
 * Updated : Sirnjeet Kalwan : 28 Nov 2013
 * 		ou_profile_lget_site_info() : Added more selection criteria
**/

define ('SITE_NOT_ALLOWED', 0);
define ('SITE_UNKNOWN', 1);
define ('SITE_INTRANET', 2);
define ('SITE_PUBLIC', 3);


/* Get information about the site querying the profiles system */
function ou_profile_lget_site_info( $http_referer = NULL )
{
	//Get URL of client site. Used to find "allowed sites" node on server
	$site_path = NULL;
	if ( !isset( $http_referer ) )
	{
		$site_path = ou_profile_lget_site_path();
	} else {
		$site_path = $http_referer;
	}
	ou_profile_log("site path = ($site_path)");

	//Setup array to return information
	$site_info = array();
	$site_info['client_allowed'] = FALSE;
    $site_info['visibility'] = '';
	

	// Clear the caches. Must be done before switching dbs
	_ou_profile_cc();

	//==============Switch to profile server
	db_set_active('profiles');

	//Get NID for the allowed_sites node for this site from server
	$query = db_select('field_data_field_site_path', 'sp');
	$query->join( 'field_data_field_ou_unit_ref', 'ou_unit', 'sp.entity_id = ou_unit.entity_id' );
	$query->addfield('sp', 'entity_id', 'allowed_site_nid' );
	$query->addfield('ou_unit', 'field_ou_unit_ref_nid', 'ou_nid' );
	$query->condition('sp.field_site_path_value', $site_path, '=');
	$nids = $query->execute()->fetchAll();

	//If NID found...
	if ( isset( $nids ) )
	{
		//Load the allowed_sites node for the client site
		$allowed_sites = node_load( $nids[0]->allowed_site_nid, NULL, TRUE );
		if( $allowed_sites )
		{
			//Set flag for other processes
			$site_info['client_allowed'] = TRUE;
			
			//Get the site visibility, none, intranet, internet
			$site_info['visibility'] = $allowed_sites->field_site_visibility['und'][0]['value'];
			
			//Get list of profile taxonomy tids
			if( isset( $allowed_sites->field_profile_taxonomy['und'] ) )
			{
				$site_info['taxonomy'] = $allowed_sites->field_profile_taxonomy['und'];
			}
			//Get list of field_media expertise taxonomy tids
			if( isset( $allowed_sites->field_media_expertise['und'] ) )
			{
				$site_info['media'] = $allowed_sites->field_media_expertise['und'];
			}
			//If ou unit selected, get the ou_unit node
			if( isset( $nids[0]->ou_nid ) )
			{
				//Get the ou_unit node
				$ou_unit = node_load( $nids[0]->ou_nid );
				if( $ou_unit )
				{
					//Get the ou_unit field to use in our select statement.
					//Since we can select all 4 levels, need to get correct field.
					$ou_unit_field = "field_pims_l1_estab_unit_code";
					if( isset( $ou_unit->field_unit_name_lv2['und'] ) )
					{
						$ou_unit_field = "field_pims_l2_estab_unit_code";
					}
					if( isset( $ou_unit->field_unit_name_lv3['und'] ) )
					{
						$ou_unit_field = "field_pims_l3_estab_unit_code";
					}
					if( isset( $ou_unit->field_unit_name_lv4['und'] ) )
					{
						$ou_unit_field = "field_pims_l4_estab_unit_code";
					}
					
					$site_info['unit_code'] = $ou_unit->field_unit_code['und'][0]['value'];
					$site_info['unit_code_field'] = $ou_unit_field;
				}
				
			}
		} else {
			ou_profile_log("Site setup not found on server.");
		}
		
	} else {
		ou_profile_log("Site setup not found on server.");
	}
	
	// Clear the caches. Must be done before switching dbs
	_ou_profile_cc();

	//==============Switch back to client site
	db_set_active();
	return $site_info;
}



// TODO: SAC - Obsolete function? Cant find any calls to it.
/*
function ou_profile_lget_unit_code() {
  $INCLUDES = drupal_get_path('module', 'ou_profile') . "/includes";
  $site_name = variable_get('site_name', 0);

  if (!$site_name)
    return FALSE;

  // Set database to profiles
  db_set_active('profiles');
/*
  //$query = 'SELECT field_ou_unit_ref_nid FROM {content_type_allowed_sites} WHERE field_site_name_value="' . $site_name . '"';
  //$allowed = db_result(db_query($query)); // $allowed = the nid reference for content_type_ou_unit

  $unit_code = FALSE;
  if ($allowed) {
    // Get unit code that this site is responsible for
    //$query = 'SELECT field_unit_code_value FROM {content_type_ou_unit} WHERE nid="' . $allowed . '"';
    //$unit_code = db_result(db_query($query));
  }*/
/*
  $query = db_select('field_data_field_unit_code', 'unit_code')
    ->fields('unit_code', array('field_unit_code_value'))
    ->join('node', 'n', 'n.nid = unit_code.entity_id')
    ->condition('n.title', $site_name, '=');

   $unit_code = $query->fetchField();

  // Set database back to original
  db_set_active();
  return $unit_code;
}
*/

/*============================================================================================*/

/**
 * Get pims data for the person in the unit
**/
function ou_profile_lget_pims_data($unit_code, $staff_id) {
  //if (!$unit_code || !$staff_id) { return FALSE; }
  if (!$staff_id)
    return FALSE;

  $INCLUDES = drupal_get_path('module', 'ou_profile') . "/includes";

  // Set database to profiles
  db_set_active('profiles');

  $query = db_select('field_data_field_pims_staff_id', 'staff_id');
  $query->addField('staff_id', 'entity_id', 'field_site_visibility_value');
  $query->condition('staff_id.field_pims_staff_id_value', $staff_id, '=');

  $nid = $query->execute()->fetchField();

  // TODO: Update the entire codebase not to use arrays anymore.
  $data = node_load($nid, NULL, TRUE);

  // Set database back to original
  db_set_active();
  return $data;
}

/*============================================================================================*/

/**
 * Get profile data for the person in the unit
**/
function ou_profile_lget_profile_data($staff_id) {
  if (!$staff_id)
    return FALSE;

  $INCLUDES = drupal_get_path('module', 'ou_profile') . "/includes";
  $site_name = variable_get('site_name', 0);

  // Set database to profiles
  db_set_active('profiles');


  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'profile')
  ->propertyCondition('status', 1)
  ->fieldCondition('field_oup_staff_id', 'value', $staff_id, '=');

  $result = $query->execute();

  if (isset($result['node'])) {
    $news_items_nids = array_keys($result['node']);
    $news_items = entity_load('node', $news_items_nids);
  }

  // Set database back to original
  db_set_active();
  //oupdb($data);
  return $data;
}

/*============================================================================================*/

/**
 * Get list of "pims" fields, along with field type, single/multiple instance and label
 *
 * 22-8-11 l.austin: Added group-name and weight. Null group-names are given the name of 'Generic' and both are used to organise and weight fields
**/
function ou_profile_lget_field_info($content_type) {
  $INCLUDES = drupal_get_path('module', 'ou_profile') . "/includes";

  $a_fields_info = array();

  // Set database to profiles
  db_set_active('profiles');

  // Get the list of fields in the node
  $fields = field_info_instances('node', $content_type);
  foreach ($fields as $field_info) {
    // Get the display info for each field
	
    $field_group = ou_profile_lfield_get_field_group($field_info);
    // Store the display info
    $a_fields_info[$field_info['field_name']] = (array)$field_group;
  }

  db_set_active();
  return $a_fields_info;
}

function ou_profile_lfield_get_field_group($field) {
  $group_info = field_group_read_groups(array('entity_type' => $field['entity_type'], 'bundle' => $field['bundle']));
  if (isset($group_info[$field['entity_type']])) {
    foreach ($group_info[$field['entity_type']][$field['bundle']]['form'] as $group) {
      if (in_array($field['field_name'], $group->children)) {
        return $group;
      }
    }
  }
  
  return FALSE;
}

/*============================================================================================*/

/**
 * Get data from a multi instance field, given a table name on the profiles server and a NID.
**/
function ou_profile_lget_multi_field_data($table_name, $NID) {
  $INCLUDES = drupal_get_path('module', 'ou_profile') . "/includes";
  $a_field_data = array();
  $field_name_prefix = preg_replace("/^content_/", "", $table_name) . "_";

  // Set database to profiles
  db_set_active('profiles');

  //$query = 'SELECT * FROM {' . $table_name . '} WHERE nid="' . $NID . '"';
  //$result = db_query($query);

  $result = db_select($table_name, "u")
    ->fields("u")
    ->condition('u.nid', $NID, "=")
    ->execute();

  //while ($data = db_fetch_array($result)) {
  while ($data = $result->fetchAssoc()) {
    $delta = $data['delta'];
    // Loop over all fields - some fields can be compound values consisting of more than one
    // field item
    foreach ($data as $key => $value) {
      if (preg_match("/^field_/", $key)) {       // Only interested in keys starting with "field_"
        $clean_key = str_replace($field_name_prefix, "", $key); // remove the field name from the key - leaving 'url' instead of 'field_name_url' for example
        $a_field_data[$delta][$clean_key] = $value;
      }
    }
  }

  db_set_active();
  return $a_field_data;
}


/*============================================================================================*/

/* print debug vars */
function oupdb($var) {
  if (gettype($var) == "array"||gettype($var)=="object") {
    print "<pre>A/O:" . print_r($var, 1) . "\n</pre>";
  }
  else {
    print "<pre>V:$var\n</pre>";
  }
}

/* Check if user has view permissions for a node owned by $node_uid */
function ou_profile_lview_permission($unit_code, $node_uid) {
  global $user;
  if ($user->uid == 1) {
    return TRUE;
  } // Allow access to admin

  if ($user->uid == $node_uid) {
    return TRUE;
  } // Allow user to view nodes owned by them

  foreach ($user->roles as $role) {
    if (preg_match("/^PP\d\d\d\d$/", $role)) {
      $role_id = substr($role, -4);
      if ($role_id == $unit_code) {
        return TRUE;
      } // User is in the group admin role for the unit
    }
  }
  return FALSE;
}

/* Given a username (OUCU), return a drupal UID
  If the UID doesn't exist, return a UID of 1 (admin) */
function ou_profile_lget_uid($oucu) {
  $query = 'SELECT uid FROM {users} WHERE name="' . $oucu . '"';
  $uid = db_result(db_query($query));

  if (!$uid)
     $uid = 1;

  return $uid;
}

/* Grant update access to a node for unit admins */
function ou_profile_lset_content_access($node, $unit_code) {
  $rid = ou_profile_lget_admin_role_id($unit_code);

  if (!$rid)
    return FALSE ;

  ou_profile_log("setting content access on %n to %r (%u)",
      array("%n" => $node->nid,
            "%r" => $rid,
            "%u" => $unit_code)
      );

  // load content access functions
  require_once(drupal_get_path('module', 'content_access') . '/content_access_rules/content_access_rules.rules.inc');
  $settings = array();
  //$settings['view'][0] = 1;  // public view access
  //$settings['update'][0] = $rid; // group "unit admin" update access
  //$settings['view_own'][0] = 2; // group authenticated_user update access
  $settings[] = "view:1";
  $settings[] = "update:$rid";
  $settings[] = "view_own:2";
  content_access_action_grant_node_permissions($node, $settings);
  //content_access_save_per_node_settings($node, $settings);
}


/* Given a unit code, return a role_id (rid) for the admin role of that unit */
function ou_profile_lget_admin_role_id($unit_code) {
  require_once(drupal_get_path('module', 'user') . "/user.admin.inc");

  foreach (user_roles() as $rid => $role) {
    // Profiles server roles are of the form PPXXXX where XXXX = the unit code of the department (Level 1 unit code)
    // These roles have to be created in SAMS.
    if (preg_match("/^PP\d\d\d\d$/", $role)) {
      $role_unit_code = substr($role, -4);
      if ($unit_code == substr($role, -4)) {
        return $rid;
      }
    }
  }
  return FALSE;
}

/* Get the prefix path for the drupal site. e.g. mbaopen, oubs etc... */
// OR! we could just ask drupal what the path is...
// The orginal function will only work for top level sites like OUBS, eg faculties/science/main just wont work.
function ou_profile_lget_site_path() {
//  global $base_path;
//  return $base_path;
  // TODO: Fix this for new URL format
  return $GLOBALS['base_url'];
}

/* Is the site allowed to access the profiles system? */
function ou_profile_lsite_allowed($http_referer = NULL)
{
	$a_site_info = ou_profile_lget_site_info($http_referer);

	if ( $a_site_info['client_allowed'] )
	{
		return TRUE;
	} else {
		return FALSE;
	}
}

/* Create URL/path alias for a profile [content type Profile] */
// OR! We could let drupal do this, seeing as its designed to do that and stuff...
// Im sacking this function off.
function ou_profile_lset_profile_alias($nid, $oucu) {

  /*  select * from url_alias;
    +-----+----------------+-------------+----------+
    | pid | src            | dst         | language |
    +-----+----------------+-------------+----------+
    | 335 | node/3090      | hb4483      | en       |
    | 336 | node/3090/feed | hb4483/feed | en       |
    +-----+----------------+-------------+----------+
  */
/*
  $query = "SELECT pid FROM {url_alias} WHERE dst='$oucu'";
  $pid = db_result(db_query($query));
  if (!$pid) {
    $query = "INSERT INTO {url_alias} (src,dst,language) VALUES ('node/$nid', '$oucu', 'en')";
    $result = db_query($query);
  }

  $query = "SELECT pid FROM {url_alias} WHERE dst='$oucu/feed'";
  $pid = db_result(db_query($query));
  if (!$pid) {
    $query = "INSERT INTO {url_alias} (src,dst,language) VALUES ('node/$nid/feed', '$oucu/feed', 'en')";
    $result = db_query($query);
  }
*/
}

/* Given a FID (file id), return the file info */
function ou_profile_lget_file_info($fid) {

  if ($fid) {
    $query = "SELECT filepath FROM {files} WHERE fid = :fid";
    db_set_active('profiles');
    $file_info = db_query($query, array(':fid' => $fid))->fetchObject();
    db_set_active();
    return $file_info;
  }
}

/* Given a user oucu + uid, find any profiles containing their oucu and set the uid
  of the node to their uid */
function ou_profile_lset_profile_owner($oucu, $uid)
{

	//Switch to Profiles DB
	_ou_profile_cc();
	db_set_active('profiles');
	
	//Find profile
	$query = db_select('field_data_field_oup_oucu', 'oucu');
	$query->condition( 'oucu.field_oup_oucu_value', $oucu, '=' );
	$query->condition( 'oucu.bundle', 'profile', '=' );
	$query->addField( 'oucu', 'entity_id');
	
	$result = $query->execute()->fetchAll();

	//For each node found, set the AUTHOR field to the user
	foreach( $result as $data )
	{
		$pnode = node_load($data->entity_id, NULL, TRUE); // keep the cache clear
		if( $pnode->uid != $uid )
		{
			$pnode->uid = $uid;
			node_save($pnode);
		}
	}

	_ou_profile_cc();
	db_set_active();

}

/* Build and return a list of privacy values */
function ou_profile_lget_privacy_values() {

  $site_path = ou_profile_lget_site_path();

  if ($site_path != ou_profile_server_site_path()) {
    // Not called from the profiles server, so need to change the database to connect to the
    // profiles server database.
    db_set_active('profiles');
  }

//  $query = 'SELECT nid, field_privacy_value_value FROM {content_type_privacy_value}';
//  $results = db_query($query);

  $results = db_select('field_data_field_privacy_value', 'p')
  ->fields('p', array('entity_id', 'field_privacy_value_value'))
  ->execute();

  foreach ($results as $data) {
    $a_privacy_values[$data->entity_id] = $data->field_privacy_value_value;
  }

  if ($site_path != ou_profile_server_site_path()) {
    db_set_active();
  }

  return $a_privacy_values;
}

/* Given a profile NID, return it's visibility for Public and Intranet sites
 * Return value = "public", "intranet" or "invisible";
 */
function ou_profile_lget_profile_visibility($nid) {
  if (!$nid)
    return FALSE;

  // Build a list of nid / privacy values
  $a_privacy_values = ou_profile_lget_privacy_values();

  // An array to link the number to the type of visility
  $a_site_visibility = array(
        2 => 'public',
        1 => 'intranet',
        0 => 'invisible',
    );

  //$query = "SELECT * FROM {content_type_profile} AS pr WHERE pr.nid=:nid";
  $query = "SELECT field_oup_visibility_value FROM {field_data_field_oup_visibility} AS pr WHERE pr.entity_id = :nid";

  $data = db_query($query, array(':nid' => $nid))->fetchObject();
  
  $visibility = 0;
  if (isset($data->field_oup_visibility_value))
    $visibility = $data->field_oup_visibility_value;

  switch ($visibility) {
     case 1:
         return "intranet";
         break;
     case 2:
         return "public";
         break;
     case 0:
     default:
         return "invisible" ;
         break;
  }

}

// This code is written all over this module, trying to turn it into a function
function ou_profile_lcreate_name($in_title, $in_forenames, $in_surname, $in_pref_forname, $in_pref_surname) {

  $staff_title = "";
  if ($in_title) {
    $staff_title = $in_title;
    if ($staff_title && $staff_title != "Mr" && $staff_title != "Miss" && $staff_title != "Ms" && $staff_title != "Mrs") {
      $staff_title = preg_replace("/Prof/", "Professor", $staff_title);
    }
    $staff_title .= " ";
  }
    //oupdb("staff title: $staff_title");

    // Add forenames
    $forenames = "";
    if ($in_pref_forname) {
      $forenames = $in_pref_forname . " ";
    }
    else {
      if ($in_forenames) {
        $forenames = $in_forenames . " ";
      }
    }
    //oupdb("forenames: $forenames");

    // Add surname
    $surname = "";
    if ($in_pref_surname) {
      $surname = $in_pref_surname;
    }
    else {
      if ($in_surname) {
        $surname = $in_surname;
      }
    }

    return $staff_title . $forenames . $surname;
}

function ou_profile_node_get_field_value($node, $value) {
  $items = field_get_items('node', $node, $value);
  if (is_array($items)) {
    $data = field_view_value('node', $node, $value, reset($items));
    return $data['#markup'];
  }

  return '';
}

function ou_profile_server_site_path() {
  return ou_profile_get_request_url();
}

function ou_profile_get_request_url() {
  $env = strtolower(getenv('OUENV'));
  $request_url = "";
  switch ($env) {
    case 'live':
      $request_url = 'http://www.open.ac.uk/people';
      break;
  
    default:
      $request_url = 'http://www-' . $env . '.open.ac.uk/people';
  }
  
  return $request_url;
  
}

function ou_profile_edit_profile_link($node, $user ) {
  $request_url = ou_profile_get_request_url();
  
  if ($GLOBALS['base_url'] == $request_url) {
    if ((node_access('update', $node, $user) == TRUE) || ($user->uid == 1)) {
      return '<a class="profile-button" href="node/' . $node->nid . '/edit">Edit profile</a>';
    }
  }
  
  return '';
}

function ou_profile_request_image($style_name, $image_name) {

  $request_url = ou_profile_get_request_url();
  $request_path = 'www.open.ac.uk.people';
  
  if ($GLOBALS['base_url'] == $request_url) {
	//Have to pass NULL width & height as function is expecting them even though theay are optional
    return theme_image_style(array('style_name' => $style_name, 'path' => $image_name, 'width' => null, 'height' => null));
  }
  else {
    $image_name = str_replace("public://", "", $image_name);
    return '<img src="' . $request_url . '/sites/' . $request_path . '/files/styles/' . $style_name . '/public/' . $image_name . '" />';
  }
}

/////////////////////
// Logging
/////////////////////

define ('OU_PROFILE_REPORT_ERROR', 0);
define ('OU_PROFILE_REPORT_WARNING', 1);
define ('OU_PROFILE_REPORT_INFO', 2);
define ('OU_PROFILE_REPORT_DEBUG', 3);

function ou_profile_log($message, $params = array(), $level = OU_PROFILE_REPORT_DEBUG) {

    $watchdog_type = NULL;
    switch ($level) {
      case OU_PROFILE_REPORT_ERROR:
        $watchdog_type = WATCHDOG_ERROR;
      break;

      case OU_PROFILE_REPORT_WARNING:
        $watchdog_type = WATCHDDOG_WARNING;
      break;

      case OU_PROFILE_REPORT_INFO:
        $watchdog_type = WATCHDOG_INFO;
      break;

      case OU_PROFILE_REPORT_DEBUG:
      default:
        $watchdog_type = WATCHDOG_DEBUG;
      break;
    }

    $ou_profile_reporting = variable_get('ou_profile_reporting', -1);
    if ($level <= $ou_profile_reporting) {
      if ($ou_profile_reporting == 4) {
        print("log - " . strtr($message, $params));
        print("<br />\n");
      }

      watchdog('ou_profile', $message, $params, $watchdog_type, NULL);
    }
}


//Clears the caches. Needed when switching between dbs using db_set_active.
//Must be done BEFORE calling db_set_active, otherwise fields you are expecting won't be retrieved.
function _ou_profile_cc()
{
	$core = array('cache', 'cache_path', 'cache_filter', 'cache_bootstrap', 'cache_page');
    $cache_tables = array_merge(module_invoke_all('flush_caches'), $core);
    foreach ($cache_tables as $table)
	{
		cache_clear_all('*', $table, TRUE);
    }

	field_info_cache_clear();
}


/**
 * ===== ORO Functions ======
 * Gets data from http://oro.open.ac.uk and presents it in the profile.
 * Tried AJAX, but that won't work as the data is in a different sub-domain.
**/

//Main function to get the ORO data and generate the HTML from the JSON data
function _ou_profile_generate_oro_html( $node )
{

	//Get the OUCU
	if( isset( $node->field_oup_oucu['und'][0]['value'] ) )
	{
		$oucu = $node->field_oup_oucu['und'][0]['value'];
	}

	//If we have OUCU, we can retrieve the ORO data
	if( isset( $oucu ) )
	{
		// e.g. http://oro.open.ac.uk/cgi/exportview/person/ma3776/HTML/ma3776.html
		$oro_url = "http://oro.open.ac.uk/cgi/exportview/person/".$oucu."/JSON/".$oucu.".js";
		$oro_data_json = _ou_profile_get_web_page( $oro_url );
		
		//If the page request was successful, process the JSON data
		if( $oro_data_json['errno' ] == 0 )
		{
			$oro_data = json_decode($oro_data_json['content'], true);
			//An invalid URL does not always raise an error from the ORO site(?!). It returns a blank array.
			//If no data, just return a blank string
			if( empty( $oro_data ) )
			{
				return( "" );
			}

			$oro_html = array();
			
			//Loop through the data and generate the HTML
			foreach( $oro_data as $oro_entry )
			{
				$tmp = "<strong><a href='".$oro_entry['uri']."'>".$oro_entry['title']."</a> (".$oro_entry['date'].") </strong><br />";
				if( isset($oro_entry['creators']) )
				{
					$tmp .= _ou_profile_get_creators( $oro_entry['creators'] )."<br />";
				}
				switch( $oro_entry[ 'type' ] )
				{
					case "article":
						$tmp .= $oro_entry['publication'];
						if( isset($oro_entry['pagerange']) )
						{
							if( preg_match( '#[0-9]#', $oro_entry['pagerange'] ) )
							{
								$tmp .= " (pp. ".$oro_entry['pagerange'].")";
							} else {
								$tmp .= " ".$oro_entry['pagerange']; 
							}
						}
						$tmp .= "<hr />";
						$oro_html["article"][] = $tmp;
					break;
					case "book":
					case "book_section":
					case "bookedit":
						$tmp .= _ou_profile_book_details( $oro_entry );
						$tmp .= "<hr />";
						$oro_html[$oro_entry[ 'type' ]][] = $tmp;
					break;					
					case "conference_item":
						if( isset( $oro_entry['event_title'] ) )
						{
							$tmp .= "In : ".$oro_entry['event_title'];
							if( isset( $oro_entry['event_dates'] ) )
							{
								$tmp .= " (".$oro_entry['event_dates'];
								if( isset( $oro_entry['event_location'] ) )
								{
									$tmp .= ", ".$oro_entry['event_location'];
								}
								$tmp .= ")";
							}
							$tmp .= "<hr />";
						}
						$oro_html["conference_item"][] = $tmp;
					break;
					default:
						$tmp .= "<hr />";
						$oro_html["other"][] = $tmp;
					break;
				}
			}
			
			//Generate the titles if needed for that particular ORO data type (Don't use foreach, output will be in the order that the different types were found)
			$node_oro_html = null;
			if( isset( $oro_html["article"] ) )
			{
				$tmp = implode( "", $oro_html["article"] );
				$node_oro_html .= "<h3>Journal articles</h3><ul>".$tmp."</ul>";
			}
			if( isset( $oro_html["book"] ) )
			{
				$tmp = implode( "", $oro_html["book"] );
				$node_oro_html .= "<h3>Authored books</h3><ul>".$tmp."</ul>";
			}
			if( isset( $oro_html["book_section"] ) )
			{
				$tmp = implode( "", $oro_html["book_section"] );
				$node_oro_html .= "<h3>Book chapters</h3><ul>".$tmp."</ul>";
			}
			if( isset( $oro_html["bookedit"] ) )
			{
				$tmp = implode( "", $oro_html["bookedit"] );
				$node_oro_html .= "<h3>Edited book</h3><ul>".$tmp."</ul>";
			}
			if( isset( $oro_html["conference_item"] ) )
			{
				$tmp = implode( "", $oro_html["conference_item"] );
				$node_oro_html .= "<h3>Conference items</h3><ul>".$tmp."</ul>";
			}
			if( isset( $oro_html["other"] ) )
			{
				$tmp = implode( "", $oro_html["other"] );
				$node_oro_html .= "<h3>Other</h3><ul>".$tmp."</ul>";
			}
			
			//Create the oro tab title
			if( isset( $node_oro_html ) )
			{
				$node_oro_html = "<h2>Publications</h2>".$node_oro_html;
				//Pass final HTML back. tpl file will just print this.
				return( $node_oro_html );
			}
		}
	}
	
	return( "" );
}


/**
 * Get a web file (HTML, XHTML, XML, image, etc.) from a URL.  Return an
 * array containing the HTTP server response header fields and content.
 * We can't get the ORO data via AJAX, so we grab it here
 */
function _ou_profile_get_web_page( $url )
{
	$options = array(
		CURLOPT_RETURNTRANSFER => true,     // return web page
		CURLOPT_HEADER         => false,    // don't return headers
		CURLOPT_FOLLOWLOCATION => true,     // follow redirects
		CURLOPT_ENCODING       => "",       // handle all encodings
		CURLOPT_USERAGENT      => "spider", // who am i
		CURLOPT_AUTOREFERER    => true,     // set referer on redirect
		CURLOPT_CONNECTTIMEOUT => 120,      // timeout on connect
		CURLOPT_TIMEOUT        => 120,      // timeout on response
		CURLOPT_MAXREDIRS      => 10,       // stop after 10 redirects
	);

	$ch      = curl_init( $url );
	curl_setopt_array( $ch, $options );
	$content = curl_exec( $ch );
	$err     = curl_errno( $ch );
	$errmsg  = curl_error( $ch );
	$header  = curl_getinfo( $ch );
	curl_close( $ch );

	$header['errno']   = $err;
	$header['errmsg']  = $errmsg;
	$header['content'] = $content;
	return $header;
}

// Helper agent for _ou_profile_generate_oro_html
// Returns a formatted list of authors for a ORO entry
function _ou_profile_get_creators( $creators )
{
	$creatorlist = array();
	foreach( $creators as $creator)
	{
		$creatorlist[] = $creator[ 'name' ]['given'].' '.$creator['name']['family'];
	}

	return( implode( ", ", $creatorlist ) );
}

// Helper agent for _ou_profile_generate_oro_html
// Returns the isbn, pub & place of pub
function _ou_profile_book_details( $oro_entry )
{
	$tmp = array();
	
	if( isset( $oro_entry['isbn'] ) )
	{
		$tmp[] = "ISBN : ".$oro_entry['isbn'];
	}
	
	if( isset( $oro_entry['publisher'] ) )
	{
		$tmp[] = "Publisher : ".$oro_entry['publisher'];
	}

	if( isset( $oro_entry['place_of_pub'] ) )
	{
		$tmp[] = "Published : ".$oro_entry['place_of_pub'];
	}
	
	$line = implode( " | ", $tmp );
	
	return( $line );
}
