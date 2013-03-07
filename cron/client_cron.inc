<?php
/**
 * @file
 * Cron functions for drupal installations running as a client
 *
 */

  $INCLUDES = drupal_get_path('module', 'ou_profile') . "/includes";

  require_once "$INCLUDES/local_functions.inc";

  // Get a list of local profiles
  $a_local_profile = array();

  // $query = 'SELECT nid, field_pims_unique_id_value FROM {content_type_ou_profile}';
  $query = 'SELECT entity_id, field_pims_unique_id_value FROM {field_data_field_pims_unique_id}';
 
  $result = db_query($query);
  foreach ($result as $data) {
    $a_local_profile[$data->entity_id] = $data->field_pims_unique_id_value;
  }

  $site_visibility = null;
  
  $a_site_info = ou_profile_lget_site_info();
  if (!empty($a_site_info)) {
    $unit_code = $a_site_info['unit_code'];
    $site_visibility = $a_site_info['visibility'];
  
    ou_profile_log("unit_code = %unit | visibility = %vis", 
      array(  "%unit" => $a_site_info['unit_code'], 
          "%vis" => $a_site_info['visibility']));
  }

  if (!$site_visibility) {
        ou_profile_log ("This website (%site_path) is not an 'allowed site'", array('%site_path' => ou_profile_lget_site_path()), OU_PROFILE_REPORT_ERROR);
    
    return;
  }

  // Get a list of privacy values
  $a_privacy_values = ou_profile_lget_privacy_values();
  
  // Set database to profiles (even if we are doing OUBS reporting because we need to check visibility values)
  db_set_active('profiles');
  
  // Create blank profile nodes (client) that link to profiles on the OU profiles server
  // Build a list of Staff IDs for people in this unit. These are generated from
  // published profiles (content_type_profile) on the profiles server.
  // TODO: rewrite me as a db_query array
  $a_staff_ids = array();
  $query = "SELECT DISTINCT ";
  $query .=  "pi.field_pims_staff_title_value, ";
  $query .=  "pi.field_pims_staff_surname_value, ";
  $query .=  "pi.field_pims_staff_forenames_value, ";
  $query .=  "pi.field_pims_pref_surname_value, ";
  $query .=  "pi.field_pims_pref_forenames_value, ";
  $query .=  "pi.field_pims_unique_id_value, ";    
  $query .=  "pr.field_oup_visibility_value, ";
  $query .=  "pr.field_pprv_staff_title_nid, ";
  $query .=  "pr.field_pprv_staff_forenames_nid, ";
  $query .=  "pr.field_pprv_pref_forenames_nid, ";
  $query .=  "pr.field_pprv_staff_surname_nid, ";
  $query .=  "pr.field_pprv_pref_surname_nid ";
  $query .="FROM ";
  $query .=  "node AS n, ";
  $query .=  "content_type_profile AS pr, ";
  $query .=  "content_type_pims AS pi ";
  $query .="WHERE ";
  $query .=  "n.status>0 AND ";
  $query .=  "pr.field_oup_visibility_value >= " . (((int)$a_site_info['visibility'])-1) . " AND ";
  $query .=  "n.nid=pr.nid AND ";
  $query .=  "pi.field_pims_staff_id_value=pr.field_oup_staff_id_value ";
  $query .=  "AND pi.field_pims_l1_estab_unit_code_value='$unit_code'";
  
  ou_profile_log ("$query");
  
  $a_profiles = array();
  $result = db_query($query);
  
  if ($result == FALSE)
    watchdog("ou_profile", "Error retrieving data", NULL, WATCHDOG_WARNING);
  
  $count=0;
  //while ($data = db_fetch_object($result)) {
  foreach ($result as $data) {
    array_push($a_profiles, $data);
    $count++;
  }
  watchdog("ou_profile", "Fetched %count rows", array('%count' => $count)); // do this even if count is zero
  
  // Set database back to original
  db_set_active('default');
  
  foreach ($a_profiles as $data) {
  
    // Don't create local profiles when the profile is marked hidden.
    if (!(int) $data->field_oup_visibility_value) {
      ou_profile_log("$data->field_pims_unique_id_value is not visible");
      continue;
    }
    
    $unique_id = $data->field_pims_unique_id_value;
  
    $profile_title = ou_profile_lcreate_name($data->field_pims_staff_title_value,
                        $data->field_pims_staff_forenames_value,
                        $data->field_pims_staff_surname_value,
                        $data->field_pims_pref_forenames_value,
                        $data->field_pims_pref_surname_value);
                        
    ou_profile_log("name = $profile_title ($data->field_pims_staff_surname_value)($data->field_pims_pref_surname_value)");
    
    
    // If a local profile does not exist for this unique_id, create one and remove the unique_id from the list.
    $query = 'SELECT entity_id FROM {field_data_field_pims_unique_id} WHERE field_pims_unique_id_value=\'' . $unique_id . '\'';
    // field_data_field_pims_unique_id?
    
    $oup_nid = db_query($query)->fetchField();
  
    if ($oup_nid) {
      // Profile exists but things like surnames can change so they need to be kept in synch
      // and we may as well keep the title in synch too to save manual effort on client sites
      $oup_node = node_load($oup_nid, NULL, TRUE);
      $node_change = FALSE;
      
      unset($a_local_profile[$oup_nid]);
    } 
    else {
      // Create local profile    
      $oup_node = new stdClass();
      $oup_node->type = 'ou_profile';
      $oup_node->created = time();
      $oup_node->changed = time();
      $oup_node->language = 'en';
      $oup_node->uid = 1;
    }
    
    if (!isset($oup_node->title) ||
        ($oup_node->title != $profile_title)) {
      $oup_node->title = $profile_title;
      $oup_node->field_pims_unique_id['und'][0]['value'] = $unique_id;
      $oup_node->changed = time();    
    }
  
    $oup_node->status = 1;
    $node_change = TRUE;
  
    node_save($oup_node);
    unset($oup_node);
    node_load_multiple(FALSE, NULL, TRUE); // keep the cache empty as node_delete performs a node_load first
  }


  // Set database back to original
  db_set_active('default');
  
  // Unpublish any profiles which no longer exist on the profiles server
  foreach ($a_local_profile as $oup_nid => $unique_id) {
    //node_delete($oup_nid);
    //node_load(FALSE, NULL, TRUE); // keep the cache empty as node_delete performs a node_load first
    $oup_node = node_load($oup_nid);
    if ($oup_node->status) { // Unpublish published profiles (no need to do it more than once!)
       $oup_node->status = 0;
       node_save($oup_node);
    }
    unset($oup_node);
    node_load_multiple(FALSE, NULL, TRUE); // keep the cache empty as node_delete performs a node_load first
}
