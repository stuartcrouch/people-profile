<?php
/**
 * @file - Functions related to retrieving lists of (or individual) people
 * Functions local to the module
/*

/**
 * Get unit code that this site is responsible for.
 * Return unit code if it exists, else return FALSE
**/
function ou_profile_lget_unit_code() {
  $INCLUDES = drupal_get_path('module', 'ou_profile') . "/includes";
  $site_name = variable_get('site_name', 0);

  if (!$site_name)
    return FALSE;

  // Set database to profiles
  db_set_active('profiles');
  $query = 'SELECT field_ou_unit_ref_nid FROM {content_type_allowed_sites} WHERE field_site_name_value="' . $site_name . '"';
  $allowed = db_result(db_query($query)); // $allowed = the nid reference for content_type_ou_unit

  $unit_code = FALSE;
  if ($allowed) {
    // Get unit code that this site is responsible for
    $query = 'SELECT field_unit_code_value FROM {content_type_ou_unit} WHERE nid="' . $allowed . '"';
    $unit_code = db_result(db_query($query));
  }
  // Set database back to original
  db_set_active();
  return $unit_code;
}

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

define ('SITE_NOT_ALLOWED', 0);
define ('SITE_UNKNOWN', 1);
define ('SITE_INTRANET', 2);
define ('SITE_PUBLIC', 3);


/* Get information about the site querying the profiles system */
function ou_profile_lget_site_info($http_referer = NULL) {

  $site_path = NULL;
  if (!isset($http_referer)) {
    $site_path = ou_profile_lget_site_path();
  }
  else {
    $site_path = $http_referer;
  }
  
  ou_profile_log("site path = ($site_path)");

  $a_site_info = array();
  db_set_active('profiles');

  $query = db_select('field_data_field_site_visibility', 'sv');

  $query->join('field_data_field_site_path', 'sp', 'sp.entity_id = sv.entity_id');
  $query->join('field_data_field_ou_unit_ref', 'ur', 'ur.entity_id = sv.entity_id');
  $query->join('field_data_field_unit_code', 'uc', 'uc.entity_id = ur.field_ou_unit_ref_nid');

  $query->addField('sv', 'field_site_visibility_value', 'field_site_visibility_value');
  $query->addField('uc', 'field_unit_code_value', 'field_unit_code_value');

  $query->condition('sp.field_site_path_value', $site_path, '=');

  $data = $query->execute()->fetchObject();

  //$query = "SELECT s.field_site_visibility_value,u.field_unit_code_value FROM {content_type_allowed_sites} AS s, {content_type_ou_unit} AS u WHERE s.field_ou_unit_ref_nid=u.nid AND field_site_path_value= :site_path";

  //$data = db_fetch_object(db_query($query));
  //$data = db_query($query, array(':site_path' => $site_path))->fetchObject();

  db_set_active();

  if (!empty($data)) {
    $a_site_info['unit_code'] = $data->field_unit_code_value;
    $a_site_info['visibility'] = $data->field_site_visibility_value;
  }
  else {
    $a_site_info['unit_code'] = '';
    $a_site_info['visibility'] = '';
    ou_profile_log("no site data returned");
  }

  return $a_site_info;
}


/* Is the site allowed to access the profiles system? */
function ou_profile_lsite_allowed($http_referer = NULL) {
  $a_site_info = ou_profile_lget_site_info($http_referer);

  if ($a_site_info['unit_code'])
    return TRUE;
  else
    return FALSE;

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
function ou_profile_lset_profile_owner($oucu, $uid) {

  $query = "SELECT nid FROM {content_type_profile} WHERE field_oup_oucu_value=:oucu";
  db_set_active('profiles');
  $result = db_query($query, array(':oucu' => $oucu));

  while ($data = db_fetch_object($result)) {
    if ($data->nid) {
      $pnode = node_load($data->nid, NULL, TRUE); // keep the cache clear
      if ($pnode->uid != $uid) {
        $pnode->uid = $uid;
        node_save($pnode);
      }
      unset($pnode);
    }
  }
}

/* Build and return a list of privacy values */
function ou_profile_lget_privacy_values() {

  $site_path = ou_profile_lget_site_path();
  global $_ou_profile_server_site_path;

  if ($site_path != $_ou_profile_server_site_path) {
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

  if ($site_path != $_ou_profile_server_site_path) {
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

function ou_propfile_edit_profile_link() {
  $request_url = ou_profile_get_request_url();
  
  if ($GLOBALS['base_url'] == $request_url) {
    if ((node_access('update', $node, $user) == TRUE) || ($account->uid == 1)) {
      return '<a class="profile-button" href="node/' . $node->nid . '/edit">Edit profile</a>';
    }
  }
  
  return '';
}

function ou_profile_request_image($style_name, $image_name) {

  $request_url = ou_profile_get_request_url();
  $request_path = 'www.open.ac.uk.people';
  
  if ($GLOBALS['base_url'] == $request_url) {
    return theme_image_style(array('style_name' => $style_name, 'path' => $image_name));
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