<?php
/**
 * @file
 * Cron functions for drupal installations running as a server
 *
 */

$DEBUG=0;

if ($DEBUG) {
  // Create a log file for debugging / informational purposes
  $debug_log = fopen("/tmp/people_server_cron.log", "w");
  fwrite($debug_log, "Cron called\n");
  $debug_count = 1;
}

$INCLUDES = drupal_get_path('module', 'ou_profile') . "/includes";
require_once "$INCLUDES/local_functions.inc";


/* Read in the PIMS schema - this creates:
 * $a_pims_fields['field_name']['start']
* $a_pims_fields['field_name']['end']
* for each field that needs to be imported from the PIMS data file.
*/


// PIMS data file
if ($_GET["data"] == "subset") { // i.e. url contains ?data=subset
  $pims_file = drupal_get_path('module', 'ou_profile') . "/cron/pims_test_data.txt";
}
else {
  // Look in the database for the location of the data file. If it doesn't exist, check the module directory.
  $pims_file = variable_get('pims_data_file', drupal_get_path('module', 'ou_profile') . "/cron/pims_test_data_full.txt");
}

//watchdog("ou_profile", "PIMS data file = %pims_file", array('%pims_file' => $pims_file));
ou_profile_log("PIMS data file = %pims_file", array('%pims_file' => $pims_file));

// Are we running on OUBS-Reporting server?
//
$oubs_reporting = variable_get('oubs_reporting', 0);

// open the PIMS data file for reading
if ($fh_pims_file = fopen($pims_file, 'r')) {
  node_load(FALSE, NULL, TRUE); // keep the cache empty - any deleted nodes will be cleared from memory

  // Keep track of unique IDs (computed) PIMS data file.
  $a_pims_file_unique_ids = array();

  // Build a list of unique IDs from the drupal database.
  $a_pims_db_unique_ids = array();

  // Create an array of all the data. This could break the PHP limit?
  $a_pims_file_data = array();

  // Create array to store OU unit codes / descriptions.
  $a_ou_units = array();

  // If this is run on OUBS Reporting, build a list of unique OUBS IDs from the drupal database
  if ($oubs_reporting) {
    $a_pims_oubs_db_unique_ids = array();
  }


  // First load all the IDs that we need to compare against
  ou_profile_retrieve_existing_pims_data($a_pims_db_unique_ids, $a_pims_oubs_db_unique_ids);
  ou_profile_retrieve_all_pims_file_data($fh_pims_file, $a_pims_file_unique_ids, $a_ou_units, $a_pims_file_data);

  // Delete anything that is expired so we dont waste time updating it
  ou_profile_delete_expired_pims_records($a_pims_db_unique_ids, $a_pims_file_unique_ids);

  // Add and update the records in the file
  ou_profile_process_pims_file_records($a_pims_db_unique_ids, $a_pims_file_unique_ids, $a_pims_file_data);

  // Make sure the list of units is up to date
  ou_profile_update_ou_units($a_ou_units);

  // Build a list of default privacy fields - we can use these later to pre-set these in a profile.
  $a_profile = content_fields(NULL, 'profile');
  $a_privacy_fields = array();
  foreach ($a_profile as $key => $value) {
    if (preg_match("/^field_prv_/", $key) || preg_match("/^field_pprv_/", $key)) {
      $a_privacy_fields[$key] = $value['widget']['default_value'][0]['nid'];
    }
  }
} 
else {
  if ($DEBUG) {
    print "<p>ou_profiles::Error: couldn't open $pims_file</p>\n";
  }
  watchdog("ou_profile", "Could not open PIMS data file %pims_file", array('%pims_file' => $pims_file), "WATCHDOG_ERROR");
}
// close the PIMS data file
fclose($fh_pims_file);

if ($DEBUG) {
  fclose($debug_log);
}

function ou_profile_update_ou_units($a_ou_units) {
  if (!$oubs_reporting) { // Update OU unit codes
    foreach ($a_ou_units as $ucode => $udesc) {
      $query = 'SELECT nid FROM {content_type_ou_unit} WHERE field_unit_code_value=' . $ucode;
      $unit_nid = db_result(db_query($query));
      if ($unit_nid) {
        // Update unit code
        $unit_node = node_load($unit_nid, NULL, TRUE);
      } 
      else {
        // Insert unit code
        $unit_node = new stdClass();
        $unit_node->type = 'ou_unit';
        $node->created = time();
      }
      
      $unit_node->title = $udesc;
      $unit_node->field_unit_code[0]['value'] = $ucode;
      $unit_node->changed = time();
      node_save($unit_node);
      unset($unit_node);
      
    }
  }
}

function ou_profile_retrieve_existing_pims_data(&$a_pims_db_unique_ids, &$a_pims_oubs_db_unique_ids) {
  if ($oubs_reporting) { // field_pims_unique_id_value is used in two Drupal content types so has its own table
    $query = 'SELECT content_type_pims.nid, field_pims_unique_id_value, field_pims_l1_estab_unit_code_value ';
    $query .= 'FROM content_field_pims_unique_id, content_type_pims ';
    $query .= 'WHERE content_field_pims_unique_id.nid=content_type_pims.nid';
  } 
  else {
    $query = 'SELECT nid,field_pims_unique_id_value, field_pims_l1_estab_unit_code_value FROM {content_type_pims}';
  }
  
  $result = db_query($query);
  while ($data = db_fetch_object($result)) {
    $a_pims_db_unique_ids[$data->nid] =  trim($data->field_pims_unique_id_value);

    if ($oubs_reporting && $data->field_pims_l1_estab_unit_code_value == "0153") {
      $a_pims_oubs_db_unique_ids[$data->nid] =  trim($data->field_pims_unique_id_value);
    }
  }
}

function ou_profile_retrieve_all_pims_file_data($fh_pims_file, &$a_pims_file_unique_ids, &$a_ou_units, &$a_pims_file_data) {

  require_once "pims_schema.inc"; // $a_pims_fields

  // loop over each row in the PIMS data file
  while ($row = fgets($fh_pims_file)) {

    $a_pims_row = array();

    // Extract the required fields (see pims_schema.inc) from the PIMS row.
    foreach ($a_pims_fields as $field_name => $a_col) {
      $a_pims_row[$field_name] = trim(substr($row, $a_col['start'], $a_col['length']));
    }

    // If there's a populated staff_id field, then insert/update the drupal database
    if ($a_pims_row['staff_id']) {
      $unique_id = $a_pims_row['staff_id'] . "-" . $a_pims_row['l1_estab_unit_code'];

      $a_pims_row['unique_id'] = $unique_id;
      array_push($a_pims_file_unique_ids, $unique_id);
      $a_pims_file_data[$unique_id] = $a_pims_row;
    }

    if ($a_pims_row['l1_estab_unit_code']) {
      $a_ou_units[$a_pims_row['l1_estab_unit_code']] = $a_pims_row['l1_estab_unit_desc'];
    }
  }
}

function ou_profile_delete_expired_pims_records($a_pims_db_unique_ids, $a_pims_file_unique_ids) {

  // find all the IDs that are in the database, but arent in the file.
  $expired = array_diff($a_pims_db_unique_ids, $a_pims_file_unique_ids);

  $processed = 0;

  if (count($expired) == 0) {
    ou_profile_log("no records to delete");
    return;
  }

  // If there are entries left in $a_pims_db_unique_ids, they need to be removed from
  // the drupal database as they are no longer in the PIMS file.
  foreach (array_keys($expired) as $nid) {
     
    $staff_id = substr($a_pims_db_unique_ids[$nid], 0, 8);
     
    watchdog("ou_profile", "checking whether to remove %id", array('%id' => $staff_id));

    // For OUBS Reporting, unpublish the PIMS entry
    // For People Profiles, delete the PIMS entry
    if ($oubs_reporting && $a_pims_oubs_db_unique_ids[$nid]) {
      watchdog("ou_profile", "unsetting %id", array('%id' => $staff_id));
      $pnode = node_load($nid, NULL, TRUE);
      $pnode->status = 0;
      node_save($pnode);
      unset($pnode);
    } 
    else {
      watchdog("ou_profile", "deleting %id", array('%id' => $staff_id));
      // Delete the PIMS entry for this staff_id
      node_delete($nid);
      node_load(FALSE, NULL, TRUE); // keep the cache empty as node_delete performs a node_load first
      $query = 'SELECT nid FROM {content_type_profile} WHERE field_oup_staff_id_value=' . $staff_id;
      $profile_nid = db_result(db_query($query));
      // and unpublish the profile node so that it can be reactivated later; and keep its node title
      if ($profile_nid) {
        
        $query = 'SELECT title FROM {node} WHERE nid=' . $profile_nid;
        $node_title = db_result(db_query($query));
        
        // Get the NID for the profile and set the status to inactive
        $profile_node = node_load($profile_nid, NULL, TRUE);
        $profile_node->title = $node_title; // restore title
        $profile_node->status=0; // unpublish profile node
        $profile_node->field_oup_active[0]['value'] = 0;
        
        node_save($profile_node);
        unset($profile_node);
      }
    }
     
    $processed++;
  }

  watchdog("ou_profile", "deleted %count records", array('%count' => $processed));
}


function ou_profile_process_pims_file_records($a_pims_db_unique_ids, $a_pims_file_unique_ids, $a_pims_file_data) {

  // find all the IDs that are in the database, but arent in the file.
  $new_records = array_diff($a_pims_file_unique_ids, $a_pims_db_unique_ids);
  // Find all the IDs that are in both the database and the file
  $existing_records = array_intersect($a_pims_file_unique_ids, $a_pims_db_unique_ids);

  // Memory is an issue in drupal (memory leak in node_load)
  // Always create as many profiles as we can with the memory available
  ou_profile_create_pims_records($new_records, $a_pims_file_data);
  // Then do a round robin updating with whatever memory is left
  ou_profile_update_pims_records($existing_records, $a_pims_file_data, $a_pims_db_unique_ids);

}

function ou_profile_create_pims_records($records, $a_pims_file_data) {

  $max_mem = str_replace('M', '000000', ini_get('memory_limit'));
  $processed = 0;

  if (count($records) == 0) {
    ou_profile_log("no records to create");
    return;
  }

  // Go through all the records to be upgraded
  foreach ($records as $record) {
    if (memory_get_usage() > $max_mem)
      break;
     
    if (array_key_exists($record, $a_pims_file_data)) {
      // Grab the row of data from the pims file
      $a_pims_row = $a_pims_file_data[$record];

      $node = new stdClass();
      $node->type = 'pims';
      $node->created = time();
      ou_profile_process_pims_record($node, $a_pims_row);
      unset($node);
      node_load(FALSE, NULL, TRUE); // keep the cache empty - any deleted nodes will be cleared from memory

      ou_profile_log("creating %s", array("%s" => $record));
      ou_profile_process_profile_record($a_pims_row);
      $processed++;
    }
  }

  watchdog("ou_profile", "created %count records, %remaining remain", array('%count' => $processed, '%remaining' => count($records) - $processed ));
}

function ou_profile_update_pims_records($records, $a_pims_file_data, $a_pims_db_unique_ids) {

  $max_mem = str_replace('M', '000000', ini_get('memory_limit'));
  $last_pims_record = variable_get("ou_profile_last_pims_record", 0);

  $processing = FALSE;
  $processed = 0;
  $skipped = 0;

  ou_profile_log("updating records");

  // Go through all the records to be upgraded
  foreach ($records as $record) {

    // This bit of code makes us run through the records list until
    // we find the last one we worked on. It then moves to the next record
    if (($record == $last_pims_record  || $last_pims_record == 0) && $processing == FALSE)
      $processing = TRUE;
     
    // If we haven't been told to start processing then continue
    if ($processing == FALSE) {
      $skipped++;
      continue;
    }

    // If we are close to running out of memory then stop and exit gracefully
    if (memory_get_usage() > $max_mem)
      break;

    // If we get up this high the script is in danger of timing ouit.
    if ($processed > 500)
      break;

    ou_profile_log("updating %d %s", array("%d" => $processed, "%s" => $record));

    if (array_key_exists($record, $a_pims_file_data)) {

      // Grab the row of data from the pims file
      $a_pims_row = $a_pims_file_data[$record];

      // Find the Node ID of the record in the database
      $nid = -1;
      $nid = array_search($record, $a_pims_db_unique_ids);
      // If we found the node ID
      if ($nid != -1) {
        // Load the node
        $node = node_load($nid, NULL, TRUE); // keep the cache clear
        // Update the pims record
        ou_profile_process_pims_record($node, $a_pims_row);
        // Update the profile record
        ou_profile_process_profile_record($a_pims_row);
        $processed++;
        // Blank the record incase we hit the end of the array (this will make it loop back to the start on the next run)
        $record = 0;

        // Clear the node to save memory
        unset($node);
        unset($a_pims_row);
        unset($nid);
        node_load(FALSE, NULL, TRUE); // keep the cache empty - any deleted nodes will be cleared from memory


      }
    }
  }

  // If we got to here and didnt start processing
  // we need to reset the last_pims_id and start over
  if ($processing == FALSE)
    $record = 0;

  // Store the last record we worked on
  variable_set("ou_profile_last_pims_record", $record);

  watchdog("ou_profile", "updated %skipped - %count of %remaining", array('%skipped' => $skipped, '%count' => $skipped + $processed,  '%remaining' => count($records) ));
}

function ou_profile_generate_pims_title($a_pims_row) {

  $pims_title = "";

  // Start with title, e.g. Dr, but omit Mr, Mrs, Miss and Ms and extend Prof
  $staff_title = $a_pims_row['staff_title'];
  if ($staff_title && $staff_title != "Mr" && $staff_title != "Miss" && $staff_title != "Ms" && $staff_title != "Mrs") {
    $staff_title = preg_replace("/Prof/", "Professor", $staff_title);
    $pims_title .= $staff_title . " ";
  }

  // Add forenames
  if ($a_pims_row['pref_forenames'])
    $pims_title .= $a_pims_row['pref_forenames'] . " ";
  else
    $pims_title .= $a_pims_row['staff_forenames'] . " ";

  // Add surname
  if ($a_pims_row['pref_surname'])
    $pims_title .= $a_pims_row['pref_surname'];
  else
    $pims_title .= $a_pims_row['staff_surname'];

  return $pims_title;
}

function ou_profile_process_pims_record(&$node, $a_pims_row) {
  $node->title = ou_profile_generate_pims_title($a_pims_row);
   
  $node->field_pims_staff_title[0]['value'] = $a_pims_row['staff_title'];
  $node->field_pims_staff_initials[0]['value'] = $a_pims_row['staff_initials'];

  $node->field_pims_staff_forenames[0]['value'] = $a_pims_row['staff_forenames'];
  $node->field_pims_pref_forenames[0]['value'] = $a_pims_row['pref_forenames'];
  $node->field_pims_staff_surname[0]['value'] = $a_pims_row['staff_surname'];
  $node->field_pims_pref_surname[0]['value'] = $a_pims_row['pref_surname'];

  $node->field_pims_oucu[0]['value'] = $a_pims_row['oucu'];
  $node->field_pims_unique_id[0]['value'] = $a_pims_row['unique_id'];
  $node->field_pims_staff_id[0]['value'] = $a_pims_row['staff_id'];
  $node->field_pims_ou_email_address[0]['value'] = $a_pims_row['ou_email_address'];

  $node->field_pims_l1_estab_unit_code[0]['value'] = $a_pims_row['l1_estab_unit_code'];
  $node->field_pims_l1_estab_unit_desc[0]['value'] = $a_pims_row['l1_estab_unit_desc'];
  $node->field_pims_l2_estab_unit_name[0]['value'] = $a_pims_row['l2_estab_unit_name'];
  $node->field_pims_l3_estab_unit_name[0]['value'] = $a_pims_row['l3_estab_unit_name'];
  $node->field_pims_l4_estab_unit_name[0]['value'] = $a_pims_row['l4_estab_unit_name'];

  $node->field_pims_personal_website[0]['value'] = $a_pims_row['personal_website'];
  $node->field_pims_appt_job_title[0]['value'] = $a_pims_row['appt_job_title'];
  $node->field_pims_appt_role_desc[0]['value'] = $a_pims_row['appt_role_desc'];

  // For OUBS Reporting
  if ($a_pims_row['l1_estab_unit_code'] == "0153" && $oubs_reporting) {
    // Add additional PIMS data for OUBS
    $node->field_pims_sal_con_emp_strt_date[0]['value'] = $a_pims_row['sal_con_emp_strt_date'];
    $node->field_pims_appt_start_date[0]['value'] = $a_pims_row['appt_start_date'];
    $node->field_pims_unit_job_code_desc[0]['value'] = $a_pims_row['unit_job_code_desc'];
    $node->field_pims_appt_term_date[0]['value'] = $a_pims_row['appt_term_date'];
    $node->field_pims_full_or_part_time[0]['value'] = $a_pims_row['full_or_part_time'];
    $node->field_pims_fte[0]['value'] = $a_pims_row['fte'];
    $node->field_pims_hrs_worked_per_week[0]['value'] = $a_pims_row['hrs_worked_per_week'];
    $node->field_pims_gender[0]['value'] = $a_pims_row['gender'];
    $node->field_pims_perm_staff_flag[0]['value'] = $a_pims_row['perm_staff_flag'];
    $node->field_pims_appt_role_code[0]['value'] = $a_pims_row['appt_role_code'];
    $node->field_pims_unit_job_code_desc[0]['value'] = $a_pims_row['unit_job_code_desc'];
  }

  $node->changed = time();
  $node->language = 'en';
  $node->uid = 1;
  $node->status = 1;


  if ($a_pims_row['l1_estab_unit_code'] ) {
    ou_profile_log("[pims] unit code = " . $a_pims_row['l1_estab_unit_code']);
    ou_profile_lset_content_access($node, $a_pims_row['l1_estab_unit_code']);
  }

  node_load(FALSE, NULL, TRUE); // keep the cache empty - any deleted nodes will be cleared from memory
  node_save($node);
  node_load(FALSE, NULL, TRUE); // keep the cache empty - any deleted nodes will be cleared from memory
}

function ou_profile_process_profile_record($a_pims_row) {

  if (empty($a_pims_row['staff_id']) || $a_pims_row['staff_id'] == '') {
    print_r($a_pims_row);
    bt();
  }

  // Get a list of Profiles with the same Staff ID as the current PIMS record
  $query = 'SELECT nid FROM {content_type_profile} WHERE field_oup_staff_id_value = ' . $a_pims_row['staff_id'];
  $profile_nid = db_result(db_query($query));
  if ($profile_nid) { // Load the existing profile
    // Get the NID for the profile and set the status to Active
    $profile_node = node_load($profile_nid, NULL, TRUE);
  } 
  else {
    // Create a new record.
    $profile_node = new stdClass();
    $profile_node->type = 'profile';
    $profile_node->created = time();
    $profile_node->language = 'en';
    // Default visibility setting = invisible
    $profile_node->field_oup_visibility[0]['value'] = 0;
    // Set profile owner to admin
    $profile_node->uid = 1; // Owner is now set when user logs in to keep in sync with SAMS. See hook ou_profile_user()
  }

  ou_profile_log("profile oucu = %poucu | pims oucu = %pimsoucu", array("%poucu" => $profile_node->field_oup_oucu[0]['value'], "%pimsoucu" => $a_pims_row['oucu']));

  // Set the default values
  $profile_node->field_oup_staff_id[0]['value'] = $a_pims_row['staff_id'];
  $profile_node->title = ou_profile_generate_pims_title($a_pims_row);
  $profile_node->field_oup_active[0]['value'] = 1;
  $profile_node->changed = time();
  $profile_node->field_oup_oucu[0]['value'] = $a_pims_row['oucu'];
  $profile_node->status=1; // make sure profile node is published


  if ($a_pims_row['l1_estab_unit_code']) {
    ou_profile_log("[profile] unit code = " . $a_pims_row['l1_estab_unit_code']);
    ou_profile_lset_content_access($profile_node, $a_pims_row['l1_estab_unit_code']);
  }

  node_save($profile_node);

  unset($query);
  unset($profile_nid);
  unset($profile_node);
}

function bt() {
  array_walk( debug_backtrace(), create_function( '$a,$b', 'print "<br /><b>". basename( $a[\'file\'] ). "</b> &nbsp; <font color=\"red\">{$a[\'line\']}</font> &nbsp; <font color=\"green\">{$a[\'function\']} ()</font> &nbsp; -- ". dirname( $a[\'file\'] ). "/";' ) );
}