<?php
/**
 * @file
 * Functions for PIMs import. Can be initiated either through the admin page or Cron
 *
 */


//MAIN ROUTINE TO MANAGE THE PIMS IMPORT
function _pims_import_initialise()
{
	
	//Array to hold the pims file data, unprocessed.
	$pims_rawdata = array();

	//Array to hold the pims data, after it is processed and split into the fields.
	$pims_importdata = array();
	
	//Array to hold the business units imported from PIMs
	$ou_units = array();

	//Array to hold all the imported unique_ids
	$pims_imported_unique_ids = array();

	//Array to hold pims records currently in system
	$system_pims_unique_ids = array();

	//Array to hold pims records to delete
	$pims2delete = array();

	//Array to hold pims records to update
	$pims2update = array();

	//Array to hold pims records to create
	$pims2create = array();

	//Get pims filename from the config page /admin/config/system/ou_profile
	$pims_filename = variable_get( 'ou_profile_pims_filename', 'pims.txt' );
	$pims_file = drupal_get_path( 'module', 'ou_profile' ).'/cron/data/'. $pims_filename;

	if( file_exists( $pims_file ) )
	{
		$file_time = filemtime( $pims_file );
		variable_set('ou_profile_pims_import_file_mod', date("d F Y H:i:s", $file_time ) );
		
		//Import pims file into an array in one go.
		$pims_rawdata = file( $pims_file, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES );
		
		//Split out the data into columns.
		//Takes $pims_rawdata as input, returns the remaining arrays populated. pims arrays are
		//one per row. $ou_units is one per unit.
		_pims_process_file( $pims_rawdata, $pims_importdata, $pims_imported_unique_ids, $ou_units );
		
		//Delete the raw data, don't need it.
		unset( $pims_rawdata );
		
		//Update the OU Business unit list with the one just imported
		_pims_update_ou_units( $ou_units );
		
		//Get the existing PIMs IDs
		_pims_get_existing_data( $system_pims_unique_ids );
		
		// find all the IDs that are in the database, but are not in the file.
		$pims2delete = array_diff( $system_pims_unique_ids, $pims_imported_unique_ids );
		variable_set('ou_profile_pims_import_deletions', count( $pims2delete ) );
		
		// find all the IDs that are in the file, but arent in the databse.
		$pims2create = array_diff( $pims_imported_unique_ids, $system_pims_unique_ids );
		variable_set('ou_profile_pims_import_creations', count( $pims2create ) );

		// Find all the IDs that are in both the database and the file
		$pims2update = array_intersect( $system_pims_unique_ids, $pims_imported_unique_ids );
		variable_set('ou_profile_pims_import_updates', count( $pims2update ) );
		
		
		// Create the Drupal QUEUE process
		//NOTE : Be aware that the processing could run more than once for each entry

		watchdog( 'ou_profile', 'Cron import of PIMs : '.$pims_file );
		
		//Get the queue
		$queue = DrupalQueue::get( 'pims_import' );
		
		$queue->createItem( array( "start" ) );

		// Create the Drupal QUEUE items
		foreach( $pims2delete as $nid => $unique_id )
		{
			$queue->createItem( array( "delete", $nid, $unique_id ) );
		}

		foreach( $pims2create as $unique_id )
		{
			$queue->createItem( array( "create", $unique_id, $pims_importdata[ $unique_id ] ) );
		}

		foreach( $pims2update as $nid => $unique_id )
		{
			$queue->createItem( array( "update", $nid, $unique_id, $pims_importdata[ $unique_id ] ) );
		}
		
		$queue->createItem( array( "finished" ) );
			
	} else {
		drupal_set_message( 'Import file not found :'.$pims_file, 'error' );
		watchdog( 'ou_profile', 'Import file not found : '.$pims_file, WATCHDOG_ERROR );
	}
}

//================= CRON START=================
/*
 * Implements hook_cron().
 */
function ou_profile_cron()
{
	//Get a count of unprocessed entries
	$queue = DrupalQueue::get( 'pims_import' );
	$queue_size = $queue->numberOfItems();

	//Only run if queue is 10 or less (arbitary value). Cron job is processing them so by the
	//time we run, it will (I'm guessing) have processed those 10.
	//This is to allow previous imports to complete before reading in a new file.
	if( $queue_size <= 10 )
	{
		//Get pims filename from the config page /admin/config/system/ou_profile
		$pims_filename = variable_get( 'ou_profile_pims_filename', 'pims.txt' );
		$pims_file = drupal_get_path( 'module', 'ou_profile' ).'/cron/data/'. $pims_filename;
		if( file_exists( $pims_file ) )
		{
			//Get files modified date
			$file_time = filemtime( $pims_file );
			
			//Get mod date of last import (NOTE: Blank value will force import)
			//Only import files where the modified date is greater than the previous one.
			$config_last_imported = variable_get('ou_profile_pims_import_file_mod', '');
			if( $config_last_imported == '' )
			{
				$config_last_imported == 'January 1 1970 00:00:00';
			}
			
			$last_imported = strtotime( $config_last_imported );
			if( $file_time > $last_imported )
			{
				watchdog( 'ou_profile', 'PIMs import file detected. Initiating import.' );
				_pims_import_initialise();
			}
			
		} else {
			drupal_set_message( 'Import file not found :'.$pims_file, 'error' );
			watchdog( 'ou_profile', 'Import file not found : '.$pims_file, WATCHDOG_ERROR );
		}
	}
}
//================= CRON FINISH================= 

//================= QUEUE PROCESSING START ================= 

/*
 * Implements hook_cron_queue_info().
 */
function ou_profile_cron_queue_info()
{
	//Here we tell Drupal that we want a queue. Nothing added to it at this stage, just defines its 
	//parameters. Alter TIME to adjust how long this is allowed to run.
	$queues['pims_import'] = array(
		'worker callback' => '_pims_queue_process',
		'time' => 120,
	);
	
	return $queues;
}

//Process each queue operation
function _pims_queue_process( $pims_data )
{

	//Shift off the first value and return
	$process_type = array_shift( $pims_data );
	
	//Process an operation
	switch( $process_type )
	{
		case 'start':
			variable_set('ou_profile_pims_import_start', date('d-m-Y H:i:s') );
			variable_set('ou_profile_pims_import_finish', 'In progress...' );
			watchdog( 'ou_profile', 'PIMS queue import : Start' );
			break;
		case 'delete':
			watchdog( 'ou_profile', 'PIMs delete' );
			//_pims_delete( $pims_data );
			break;
		case 'update':
			watchdog( 'ou_profile', 'PIMs update' );
			//_pims_update( $pims_data );
			break;
		case 'create':
			watchdog( 'ou_profile', 'PIMs create' );
			//_pims_create( $pims_data );
			break;
		case 'finished':
			watchdog( 'ou_profile', 'PIMS queue import : Finished' );
			variable_set('ou_profile_pims_import_finish', date("d-m-Y H:i:s") );
			break;
		default:
			break;
	}
}

//================= QUEUE PROCESSING FINISH =================



//Process each file row and split out the fields
function _pims_process_file( $rawdata, &$pims_importdata, &$pims_imported_unique_ids, &$ou_units )
{
	$schema = drupal_get_path( 'module', 'ou_profile' ).'/cron/pims_schema.inc';
	require_once $schema; // Defines $a_pims_fields

	foreach( $rawdata as $rawdataline )
	{	
		$pims_row = array();
		
		// Extract the required fields (see pims_schema.inc) from the PIMS row.
		foreach ( $a_pims_fields as $field_name => $a_col )
		{
			$field_data = trim( substr( $rawdataline, $a_col['start'], $a_col['length'] ) );
			$pims_row[ $field_name ] = $field_data;
		}

		if( !empty( $pims_row['staff_id'] ) )
		{

			//Get the "unique id"
			$unique_id = $pims_row['staff_id'] . '-' . $pims_row['l1_estab_unit_code'];
			$pims_row['unique_id'] = $unique_id;		

			$pims_importdata[ $unique_id ] = $pims_row;
			
			//Update our array
			$pims_imported_unique_ids[] = $unique_id;
			
		}
		
		//Import the OU business units
		if ( !empty( $pims_row['l1_estab_unit_code'] ) )
		{
			$l1 = $pims_row[ 'l1_estab_unit_desc' ];
			$l2 = $pims_row[ 'l2_estab_unit_name' ];
			$l3 = $pims_row[ 'l3_estab_unit_name' ];
			$l4 = $pims_row[ 'l4_estab_unit_name' ];
			
			if( empty( $l4 ) )
			{
				if( empty( $l3 ) )
				{
					if( empty( $l2 ) )
					{
						$ou_units[$l1]["#"]["#"]["#"] = $pims_row['l1_estab_unit_code'];
					} else {
						$ou_units[$l1][$l2]["#"]["#"] = $pims_row['l1_estab_unit_code'];
					}
				} else {
					$ou_units[$l1][$l2][$l3]["#"] = $pims_row['l1_estab_unit_code'];
				}
			} else {
				$ou_units[$l1][$l2][$l3][$l4] = $pims_row['l1_estab_unit_code'];
			}
			
		}

	}
}



//Get the list of current PIMs records
function _pims_get_existing_data( &$system_pims_unique_ids )
{
	//Create the query
	$query = db_select('field_data_field_pims_unique_id', 'puid');
	$query->fields('puid', array('entity_id', 'field_pims_unique_id_value') );
	$result = $query->execute();
	
	//$result = db_query('SELECT entity_id, field_pims_unique_id_value FROM {field_data_field_pims_unique_id}');
	foreach ($result as $data)
	{
		$system_pims_unique_ids[ $data->entity_id ] =  trim($data->field_pims_unique_id_value);
	}

}



//Updates & creates the list of business units & sub-units. One off process per import file.
function _pims_update_ou_units( $ou_units )
{

	//Sort the business units. Multi-dimensional array, so we have to go through each level.
	ksort( $ou_units );
	foreach( $ou_units as $key1 => $lv1 )
	{
		ksort( $ou_units[ $key1 ] );
		foreach( $lv1 as $key2 => $lv2 )
		{
			ksort( $ou_units[ $key1 ][ $key2 ] );
			foreach( $lv2 as $key3 => $lv3 )
			{
				ksort( $ou_units[ $key1 ][ $key2 ][$key3] );
			}
		}
	}
	
	//Implode the array (sort of). Remove "#"s and create an array of sub-units by level1 units
	$ou_lv1_units = array();
	$ou_sub_units = array();
	foreach( $ou_units as $key1 => $lv1 )
	{
		$ou_sub_units_tmp = array();
		$ou_lv1_code = "";
		
		foreach( $lv1 as $key2 => $lv2 )
		{
			if( $key2 == "#" ){$key2 = "";}
			foreach( $lv2 as $key3 => $lv3 )
			{
				if( $key3 == "#" ){$key3 = "";} else {$key3 = "\\".$key3;}
				
				foreach( $lv3 as $key4 => $lv4 )
				{
					$ou_lv1_code = $lv4;

					if( $key4 == "#" ){$key4 = "";} else {$key4 = "\\".$key4;}
					if( $key2.$key3.$key4 != "" )
					{
						$ou_sub_units_tmp[]["value"] = $key2.$key3.$key4;
					}
				}
			}
		}
		$ou_sub_units[ $ou_lv1_code ] = $ou_sub_units_tmp;
		$ou_lv1_units[ $ou_lv1_code ] = $key1;
	}

	foreach ( $ou_lv1_units as $unit_code => $unit_desc )
	{

		//Get the Business Unit nid using the unit_code
		$query = db_select('field_data_field_unit_code', 'df_ucode')
					->fields('df_ucode', array('entity_id') )
					->condition('df_ucode.field_unit_code_value', $unit_code, "=" );
		$unit_nid = $query->execute()->fetchField();

		if( $unit_nid )
		{
			// Load the Unit node
			$node = node_load( $unit_nid, NULL, TRUE );
			
		} else {
			// Insert unit code
			$node = new stdClass();
			$node->type = 'ou_unit';
			$node->created = time();
			$node->language = LANGUAGE_NONE;
			node_object_prepare($node);
		}

		$node->title = $unit_desc;
		$node->field_unit_code[$node->language][0]['value'] = $unit_code;
		$node->field_sub_units[$node->language] = $ou_sub_units[ $unit_code ];
		$node->changed = time();
		node_save($node);
	}
}



//Deletes a pims record
function _pims_delete( $pims_details )
{
	$nid = $pims_details[ 0 ];
	$staff_id = substr( $pims_details[ 1 ], 0, 8 );

	node_load( NULL, NULL, TRUE ); // keep the cache empty as node_delete performs a node_load first
	
	$node = node_load( $nid );

	//Since batch & queue processes could run more than once on an import entry, check that node exists
	if( $node )
	{
		$staff_name = check_plain( $node->title );
		watchdog( 'ou_profile', 'PIMs import : Deleting : PIMs : '.$staff_name.' ('.$nid.')' );

		// Delete the PIMS entry for this staff_id
		node_delete( $nid );
	}

	//Get the profile nid using the staff id
	$query = db_select('field_data_field_oup_staff_id', 'sid')
				->fields('sid', array('entity_id'))
				->condition('sid.field_oup_staff_id_value', $staff_id, '=');
	$profile_nid = $query->execute()->fetchField();
	
	// Unpublish the profile node so that it can be reactivated later; and keep its node title
	if( $profile_nid )
	{
		//Not sure why the title is being set
		//???$query = 'SELECT title FROM {node} WHERE nid=' . $profile_nid;
		//???$node_title = db_query($query)->fetchField();

		// Get the NID for the profile and set the status to inactive
		$profile_node = node_load( $profile_nid, NULL, TRUE );
		
		if( $profile_node )
		{

			$staff_name = check_plain( $profile_node->title );
			watchdog( 'ou_profile', 'PIMs import : Deleting : Profile : '.$staff_name.' ('.$profile_nid.')' );

			//???$profile_node->title = $node_title; // restore title

			//unpublish profile node
			$profile_node->field_oup_active[0]['value'] = 0;
			$profile_node->status = 0;
			node_save( $profile_node );
		}
	}
	
}



//Creates a pims record
function _pims_create( $pims_details )
{

	//Splitting out array values to make code more readable
	$nid = $pims_details[ 0 ];
	$staff_uid = $pims_details[ 1 ];
	$staff_data = $pims_details[ 2 ];

	node_load(NULL, NULL, TRUE); // keep the cache empty - any deleted nodes will be cleared from memory

	//Check if PIMs record already created
	$query = db_select('field_data_field_pims_unique_id', 'puid');
	$query->fields('puid', array('entity_id', 'field_pims_unique_id_value') );
	$query->condition( 'field_pims_unique_id_value', $staff_uid, '=' );
	$result = $query->execute()->rowCount();

	//Record not found, so safe to create
	if( $result == 0 )
	{
		$node = new stdClass();
		$node->type = 'pims';
		$node->created = time();
		$node->language = LANGUAGE_NONE;
		node_object_prepare($node);
	
		_pims_import_data_into_node( $node, $staff_data );
		$staff_name = check_plain( $node->title );

		watchdog( 'ou_profile', 'PIMs import : Creating : PIMs : '.$staff_name.' ('.$node->nid.')' );

		//create the profile record
		_pims_import_data_into_profile_record( $staff_data );

	}

}



//Updates a pims record
function _pims_update( $pims_details )
{

	//Splitting out array values to make code more readable
	$nid = $pims_details[ 0 ];
	$staff_data = $pims_details[ 2 ];

	$node = node_load( $nid );

	if( $node )
	{
		_pims_import_data_into_node( $node, $staff_data );
		$staff_name = check_plain( $node->title );

		watchdog( 'ou_profile', 'PIMs import : Updating : PIMs : '.$staff_name.' ('.$node->nid.')' );
		
		unset( $node );

		//Update the profile record
		_pims_import_data_into_profile_record( $staff_data );

	}

}



//Generates the page title based on the staff members name
function _generate_node_title( $a_pims_row )
{
	$pims_title = "";

	// Start with title, e.g. Dr, but omit Mr, Mrs, Miss and Ms and extend Prof
	$staff_title = $a_pims_row['staff_title'];
	if ($staff_title && $staff_title != "Mr" && $staff_title != "Miss" && $staff_title != "Ms" && $staff_title != "Mrs")
	{
		$staff_title = preg_replace("/Prof/", "Professor", $staff_title);
		$pims_title .= $staff_title . " ";
	}

	// Add forenames
	if ($a_pims_row['pref_forenames'])
	{
		$pims_title .= $a_pims_row['pref_forenames'] . " ";
	} else {
		$pims_title .= $a_pims_row['staff_forenames'] . " ";
	}

	// Add surname
	if ($a_pims_row['pref_surname'])
	{
		$pims_title .= $a_pims_row['pref_surname'];
	} else {
		$pims_title .= $a_pims_row['staff_surname'];
	}

	return $pims_title;
}



//Update the node with data from the imported PIMs file
function _pims_import_data_into_node(&$node, $a_pims_row)
{

	$node->title = _generate_node_title($a_pims_row);

	$node->field_pims_staff_title[$node->language][0]['value'] = $a_pims_row['staff_title'];
	$node->field_pims_staff_initials[$node->language][0]['value'] = $a_pims_row['staff_initials'];

	$node->field_pims_staff_forenames[$node->language][0]['value'] = $a_pims_row['staff_forenames'];
	$node->field_pims_pref_forenames[$node->language][0]['value'] = $a_pims_row['pref_forenames'];
	$node->field_pims_staff_surname[$node->language][0]['value'] = $a_pims_row['staff_surname'];
	$node->field_pims_pref_surname[$node->language][0]['value'] = $a_pims_row['pref_surname'];

	$node->field_pims_oucu[$node->language][0]['value'] = $a_pims_row['oucu'];
	$node->field_pims_unique_id[$node->language][0]['value'] = $a_pims_row['unique_id'];
	$node->field_pims_staff_id[$node->language][0]['value'] = $a_pims_row['staff_id'];
	$node->field_pims_ou_email_address[$node->language][0]['value'] = $a_pims_row['ou_email_address'];

	$node->field_pims_l1_estab_unit_code[$node->language][0]['value'] = $a_pims_row['l1_estab_unit_code'];
	$node->field_pims_l1_estab_unit_desc[$node->language][0]['value'] = $a_pims_row['l1_estab_unit_desc'];
	$node->field_pims_l2_estab_unit_name[$node->language][0]['value'] = $a_pims_row['l2_estab_unit_name'];
	$node->field_pims_l3_estab_unit_name[$node->language][0]['value'] = $a_pims_row['l3_estab_unit_name'];
	$node->field_pims_l4_estab_unit_name[$node->language][0]['value'] = $a_pims_row['l4_estab_unit_name'];

	$node->field_pims_personal_website[$node->language][0]['value'] = $a_pims_row['personal_website'];
	$node->field_pims_appt_job_title[$node->language][0]['value'] = $a_pims_row['appt_job_title'];
	$node->field_pims_appt_role_desc[$node->language][0]['value'] = $a_pims_row['appt_role_desc'];

	$node->changed = time();
	$node->uid = 1;
	$node->status = 1;
	node_save($node);

}



//Create or update the profile record
function _pims_import_data_into_profile_record( $a_pims_row )
{
	$type = 'Creating';
	
	//Check if Profile record already created
	$query = db_select('field_data_field_oup_staff_id', 'sid');
	$query->fields('sid', array('entity_id') );
	$query->condition( 'field_oup_staff_id_value', $a_pims_row['staff_id'], '=' );
	$profile_nid = $query->execute()->fetchField();

	if ( !empty( $profile_nid ) )
	{ 
		// Load the existing profile
		$type = 'Updating';
		$node = node_load($profile_nid, NULL, TRUE);

	} else {

		// Create a new record.
		$node = new stdClass();
		$node->type = 'profile';
		$node->created = time();
		$node->language = LANGUAGE_NONE;
		// Default visibility setting = invisible
		$node->field_oup_visibility[$node->language][0]['value'] = 0;
		// Set profile owner to admin
		$node->uid = 1; // Owner is now set when user logs in to keep in sync with SAMS. See hook ou_profile_user()
	}
	
	if( $node )
	{
		// Set the default values
		$node->title = _generate_node_title( $a_pims_row );
		$node->field_oup_staff_id[$node->language][0]['value'] = $a_pims_row['staff_id'];
		$node->field_oup_oucu[$node->language][0]['value'] = $a_pims_row['oucu'];
		$node->field_oup_active[$node->language][0]['value'] = 1;
		$node->changed = time();
		$node->status=1; // make sure profile node is published

		node_save($node);

		watchdog( 'ou_profile', 'PIMs import : '.$type.' : Profile : '.$node->title.' ('.$node->nid.')' );

		//Give access to business unit editors
		if ($a_pims_row['l1_estab_unit_code'])
		{
			ou_profile_lset_content_access($node, $a_pims_row['l1_estab_unit_code']); // in local_functions.inc
		}
	}	
}
