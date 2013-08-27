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

  // Set database to profiles
  db_set_active('profiles');

  // Create blank profile nodes (client) that link to profiles on the OU profiles server
  // Build a list of Staff IDs for people in this unit. These are generated from
  // published profiles (content_type_profile) on the profiles server.

  // Grab the ids for the pims and profile nodes that we are allowed to view
  $query = db_select('node', 'n');

  $query->join('field_data_field_pims_staff_id', 'ps', 'n.nid = ps.entity_id');
  $query->join('field_data_field_pims_l1_estab_unit_code', 'u', 'n.nid = u.entity_id');
  $query->join('field_data_field_oup_staff_id', 'oup', 'ps.field_pims_staff_id_value = oup.field_oup_staff_id_value');
  $query->join('field_data_field_oup_visibility', 'v', 'oup.entity_id = v.entity_id');

  $query->addField('n', 'nid', 'pims_entity_id');
  $query->addField('oup', 'entity_id', 'profile_entity_id');

  $query->condition('n.status', 0, '>')
    ->condition('v.field_oup_visibility_value', (((int)$a_site_info['visibility'])-1) ,'>=')
    ->condition('u.field_pims_l1_estab_unit_code_value', $unit_code, '=');

  $a_profiles = $query->execute()->fetchAll();

  //$a_local_profile = array();

  if ($result == FALSE)
    watchdog("ou_profile", "Error retrieving data", NULL, WATCHDOG_WARNING);
  else
    watchdog("ou_profile", "Fetched %count rows", array('%count' => count($a_profiles))); // do this even if count is zero

  // Set database back to original
  db_set_active();


  foreach ($a_profiles as $item) {

    // Set database to people and fully load this node
    db_set_active('profiles');
    $pims_data = node_load($item->pims_entity_id, NULL, TRUE);
    $profile_data = node_load($item->profile_entity_id, NULL, TRUE);
    db_set_active();

    // Reset the entity structure incase it loaded from the server instead of us
    _field_info_collate_fields(TRUE);

    // Don't create local profiles when the profile is marked hidden.
    if (!(int) $profile_data->field_oup_visibility[$profile_data->language][0]['value']) {
      ou_profile_log("$data->field_pims_unique_id_value is not visible");
      continue;
    }

    $unique_id = $pims_data->field_pims_unique_id[$profile_data->language][0]['value'];

    $profile_title = ou_profile_lcreate_name($pims_data->field_pims_staff_title[$pims_data->language][0]['value'],
                        $pims_data->field_pims_staff_forenames[$pims_data->language][0]['value'],
                        $pims_data->field_pims_staff_surname[$pims_data->language][0]['value'],
                        $pims_data->field_pims_pref_forenames[$pims_data->language][0]['value'],
                        $pims_data->field_pims_pref_surname[$pims_data->language][0]['value']);

    ou_profile_log("name = $profile_title");


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
      $oup_node->language = LANGUAGE_NONE;
      node_object_prepare($oup_node);
      $oup_node->uid = 1;
    }

    if (!isset($oup_node->title) ||
        ($oup_node->title != $profile_title)) {
      $oup_node->title = $profile_title;
      $oup_node->field_pims_unique_id[$oup_node->language][0]['value'] = $unique_id;
      $oup_node->changed = time();
    }

    $oup_node->status = 1;
    $node_change = TRUE;

    db_set_active();
    node_save($oup_node);
    unset($oup_node);
    unset($pims_data);
    unset($profile_data);
    node_load_multiple(NULL, NULL, TRUE); // keep the cache empty as node_delete performs a node_load first
  }


  // Set database back to original
  db_set_active();

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