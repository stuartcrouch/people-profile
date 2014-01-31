<?php
/**
 * @file
 * Functions for PIMs import. Can be initiated either through the admin page or Cron
 *
 */

//====================== CRON PROCESSING START ================= 
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
		$filepath = variable_get('ou_profile_pims_preproc_path', '/drupalshared/interface_files');
		$pims_file = $filepath.'/new_staff_updates.txt';
		$error = FALSE;
		
		//Check that the files exist
		if( !file_exists( $pims_file ) )
		{
			ou_profile_log( 'PIMs import file not found : '.$pims_file, null, WATCHDOG_ERROR );
			$error = TRUE;
		}
		if( !file_exists( $filepath.'/pimsprevious.txt' ) )
		{
			ou_profile_log( 'PIMs import file not found : '.$filepath.'/pimsprevious.txt', null, WATCHDOG_ERROR );
			$error = TRUE;
		}
		if( !file_exists( $filepath.'/all_staff_ids.txt' ) )
		{
			ou_profile_log( 'PIMs import file not found : '.$filepath.'/all_staff_ids.txt', null, WATCHDOG_ERROR );
			$error = TRUE;
		}

		//If all the files exists...
		if( !$error )
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
				ou_profile_log( 'PIMs import file detected. Initiating import.' );
				_pims_import_initialise( "cron" );
			}
			
		}
	}
}
//====================== CRON PROCESSING FINISH ================= 


//MAIN ROUTINE TO MANAGE THE PIMS IMPORT
//$import_type = cron, batch, drush
function _pims_import_initialise( $import_type = "cron", &$batch = array() )
{

	//Array to hold the pims file data, unprocessed.
	$pims_rawdata = array();

	//Array to hold the pims data, after it is processed and split into the fields.
	$pims_importdata = array();
	
	//Array to hold the business units imported from PIMs
	$ou_units = array();

	//Array to hold all the imported unique_ids
	$pims_imported_unique_ids = array();

	//Array to hold published pims records currently in system
	$system_pims_unique_ids_published = array();
	
	//Array to hold pims records currently in system
	$system_pims_unique_ids = array();

	//Array to hold pims records to unpublish
	$pims2unpublish = array();

	//Array to hold pims records to update
	$pims2update = array();

	//Array to hold pims records to create
	$pims2create = array();

	//Get pims filename from the config page /admin/config/system/ou_profile
	$filepath = variable_get('ou_profile_pims_preproc_path', '/drupalshared/interface_files');
	$pims_file = $filepath.'/new_staff_updates.txt';
	$error = FALSE;
	
	//Check that the files exist
	if( !file_exists( $pims_file ) )
	{
		ou_profile_log( 'PIMs import file not found : '.$pims_file, null, WATCHDOG_ERROR );
		$error = TRUE;
	}
	if( !file_exists( $filepath.'/pimsprevious.txt' ) )
	{
		ou_profile_log( 'PIMs import file not found : '.$filepath.'/pimsprevious.txt', null, WATCHDOG_ERROR );
		$error = TRUE;
	}
	if( !file_exists( $filepath.'/all_staff_ids.txt' ) )
	{
		ou_profile_log( 'PIMs import file not found : '.$filepath.'/all_staff_ids.txt', null, WATCHDOG_ERROR );
		$error = TRUE;
	}

	//If all the files exists...
	if( !$error )
	{
		$file_time = filemtime( $pims_file );
		variable_set('ou_profile_pims_import_file_mod', date("d F Y H:i:s", $file_time ) );
		
		//Import pims file into an array in one go.
		$pims_rawdata = file( $pims_file, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES );
		
		//Split out the data into columns.
		//Takes $pims_rawdata as input, returns the remaining arrays populated. pims arrays are
		//one per row. $ou_units is one per unit.
		_pims_process_file( $pims_rawdata, $pims_importdata, $pims_imported_unique_ids, $ou_units );
		
		//Import all the unique ids
		$pims_all_unique_ids = file( $filepath.'/all_staff_ids.txt', FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES );

		//Delete the raw data, don't need it.
		unset( $pims_rawdata );
		
		//Update the OU Business unit list with the one just imported
		_pims_update_ou_units( $ou_units );

		//Get the existing PUBLISHED PIMs IDs
		_pims_get_existing_data( $system_pims_unique_ids_published, TRUE );

		//Get ALL the existing PIMs IDs
		_pims_get_existing_data( $system_pims_unique_ids, FALSE );
		
		// find all the IDs that are in the database, but are not in the list of all IDs.
		$pims2unpublish = array_diff( $system_pims_unique_ids_published, $pims_all_unique_ids );
		variable_set('ou_profile_pims_import_deletions', count( $pims2unpublish ) );
		
		// find all the IDs that are in the file, but arent in the databse.
		$pims2create = array_diff( $pims_imported_unique_ids, $system_pims_unique_ids );
		variable_set('ou_profile_pims_import_creations', count( $pims2create ) );

		// Find all the IDs that are in both the database and the file
		$pims2update = array_intersect( $system_pims_unique_ids, $pims_imported_unique_ids );
		variable_set('ou_profile_pims_import_updates', count( $pims2update ) );
		
		//Create the batch or update the queue
		//NOTE : Be aware that the processing could run more than once for each entry
		
		if( $import_type == "cron" )
		{
			// Create the Drupal QUEUE process
			ou_profile_log( 'Cron import of PIMs : '.$pims_file );
			
			//Get the queue
			$queue = DrupalQueue::get( 'pims_import' );
			
			$queue->createItem( array( "start" ) );

			// Create the Drupal QUEUE items
			foreach( $pims2unpublish as $nid => $unique_id )
			{
				$queue->createItem( array( "unpublish", $nid, $unique_id ) );
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
			ou_profile_log( 'User initiated import of PIMs : '.$pims_file );
			// Create the Drupal BATCH operations
			// NOTE : 2nd value for operations, if you need to pass a single value, it can just be array( value ). Multiple
			// values must be stored in array( array( value1, value2 ) ). When batch calls the processing functions, it 
			// sends the VALUE of the array NOT an array containing the value
			// e.g. array( value ) will send just value.
			// 		array( array( value1, value2 ) ) will send array( value1, value2 )
			
			//Array for the batch operations
			$operations[] = array();
			$operations[] = array( "_pims_batch_process", array( array( "start" ) ) );

			
			foreach( $pims2unpublish as $nid => $unique_id )
			{
				$operations[] = array(
						"_pims_batch_process",
						array( array( "unpublish", $nid, $unique_id ) )
					);
			}

			foreach( $pims2create as $unique_id )
			{
				$operations[] = array(
						"_pims_batch_process",
						array( array( "create", $unique_id, $pims_importdata[ $unique_id ] ) )
					);
			}

			foreach( $pims2update as $nid => $unique_id )
			{
				$operations[] = array(
						"_pims_batch_process",
						array( array( "update", $nid, $unique_id, $pims_importdata[ $unique_id ] ) )
					);
			}

			$operations[] = array( "_pims_batch_process", array( array( "finished" ) ) );
			
			//Define the batch
			$batch = array(
				'operations' => $operations,
				'title' => 'PIMs import :'.$pims_file,
				'finished' => '_pims_batch_import_complete'
			);
			
			//If this is a user initiated batch job, run it now. Otherwise, its a drush batch job. That's
			//run by drush
			if( $import_type == "batch" )
			{
				//Run the batch
				batch_set( $batch );
			}
		}
	}
}

//================= BATCH PROCESSING START ================= 

//Process each batch operation
function _pims_batch_process( $pims_data, &$context )
{
	//Shift off the first value and return
	$process_type = array_shift( $pims_data );
	
	//Process an operation
	$processed = variable_get('ou_profile_pims_import_processed', 0);
	switch( $process_type )
	{
		case 'start':
			variable_set('ou_profile_pims_import_start', date('d-m-Y H:i:s') );
			variable_set('ou_profile_pims_import_finish', 'In progress...' );
			variable_set('ou_profile_pims_import_processed', 0 );
			ou_profile_log( 'PIMS queue import : Start' );
			break;
		case 'unpublish':
			_pims_unpublish( $pims_data, $context );
			variable_set('ou_profile_pims_import_processed', ++$processed );
			break;
		case 'update':
			_pims_update( $pims_data, $context );
			variable_set('ou_profile_pims_import_processed', ++$processed );
			break;
		case 'create':
			_pims_create( $pims_data, $context );
			variable_set('ou_profile_pims_import_processed', ++$processed );
			break;
		case 'finished':
			//Get pims filename from the config page /admin/config/system/ou_profile
			$filepath = variable_get('ou_profile_pims_preproc_path', '/drupalshared/interface_files');
			$pims_file = $filepath.'/pimsprevious.txt';
			
			//Delete PIMS_PP_Imported.txt if it already exists
			if( unlink( $filepath.'/PIMS_PP_Imported.txt' ) )
			{
				ou_profile_log( 'Deleted PIMS_PP_Imported.txt file' );
			}
			
			//Then rename
			if( rename( $pims_file, $filepath.'/PIMS_PP_Imported.txt' ) )
			{
				ou_profile_log( 'PIMS batch import, PIMS_PP_Imported.txt file updated.' );
			} else {
				ou_profile_log( 'PIMS batch import. Unable to rename '.$pims_file.' to '.$filepath.'/PIMS_PP_Imported.txt', null, WATCHDOG_ERROR );
				drupal_set_message( 'Unable to rename '.$pims_file.' to '.$filepath.'/PIMS_PP_Imported.txt', 'error' );
			}

			ou_profile_log( 'PIMS batch import : Finished' );
			variable_set('ou_profile_pims_import_finish', date("d-m-Y H:i:s") );
			break;
			
	}
}

//Function called when the batch process is complete
function _pims_batch_import_complete( $success, $results, $operations )
{
	if( $success )
	{
		// Here we could do something meaningful with the results.
		// We just display the number of nodes we processed...
		variable_set('ou_profile_pims_import_finish', date("d-m-Y H:i:s") );
		drupal_set_message(t('@count records  processed.', array('@count' => count( $results ) ) ) );
		ou_profile_log( 'User initiated import of PIMs - COMPLETE. Processed : '.count( $operations ) );
	} else {
		// An error occurred.
		// $operations contains the operations that remained unprocessed.
		$error_operation = reset( $operations );
		drupal_set_message(t('An error occurred while processing @operation with arguments : @args', array('@operation' => $error_operation[0], '@args' => print_r($error_operation[0], TRUE))));
	}

}
//================= BATCH PROCESSING FINISH ================= 



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
		'time' => 225,
	);
	
	return $queues;
}

//Process each queue operation
function _pims_queue_process( $pims_data )
{

	//Empty array. Since the processing functions are used by BATCH too, we re-use them by
	//passing this array. Not used in this QUEUE process.
	$context = array();
	
	//Shift off the first value and return
	$process_type = array_shift( $pims_data );
	
	//Get a count of unprocessed entries
	$queue = DrupalQueue::get( 'pims_import' );
	$queue_size = $queue->numberOfItems();

	variable_set( 'ou_profile_pims_import_queue_size', $queue_size - 1 );

	//Process an operation
	$processed = variable_get( 'ou_profile_pims_import_processed', 0 );
	switch( $process_type )
	{
		case 'start':
			variable_set('ou_profile_pims_import_start', date('d-m-Y H:i:s') );
			variable_set('ou_profile_pims_import_finish', 'In progress...' );
			variable_set('ou_profile_pims_import_processed', 0);
			variable_set('ou_profile_pims_import_cron_runs', 0);
			ou_profile_log( 'PIMS queue import : Start' );
			break;
		case 'unpublish':
			_pims_unpublish( $pims_data, $context );
			variable_set('ou_profile_pims_import_processed', ++$processed );
			break;
		case 'update':
			_pims_update( $pims_data, $context );
			variable_set('ou_profile_pims_import_processed', ++$processed );
			break;
		case 'create':
			_pims_create( $pims_data, $context );
			variable_set('ou_profile_pims_import_processed', ++$processed );
			break;
		case 'finished':
			//Get pims filename from the config page /admin/config/system/ou_profile
			$filepath = variable_get('ou_profile_pims_preproc_path', '/drupalshared/interface_files');
			$pims_file = $filepath.'/pimsprevious.txt';
			
			//Delete PIMS_PP_Imported.txt if it already exists
			if( unlink( $filepath.'/PIMS_PP_Imported.txt' ) )
			{
				ou_profile_log( 'Deleted PIMS_PP_Imported.txt file' );
			}
			//Then rename
			if( rename( $pims_file, $filepath.'/PIMS_PP_Imported.txt' ) )
			{
				ou_profile_log( 'PIMS queue import, PIMS_PP_Imported.txt file updated.' );
			} else {
				ou_profile_log( 'PIMS queue import. Unable to rename '.$pims_file.' to '.$filepath.'/PIMS_PP_Imported.txt', null, WATCHDOG_ERROR );
			}
			
			ou_profile_log( 'PIMS queue import : Finished' );
			variable_set('ou_profile_pims_import_finish', date("d-m-Y H:i:s") );
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
						$ou_units[$l1]["#"]["#"]["#"] = $pims_row['l1_estab_unit_code'];
						$ou_units[$l1][$l2]["#"]["#"] = $pims_row['l2_estab_unit_code'];
					}
				} else {
					$ou_units[$l1]["#"]["#"]["#"] = $pims_row['l1_estab_unit_code'];
					$ou_units[$l1][$l2]["#"]["#"] = $pims_row['l2_estab_unit_code'];
					$ou_units[$l1][$l2][$l3]["#"] = $pims_row['l3_estab_unit_code'];
				}
			} else {
				$ou_units[$l1]["#"]["#"]["#"] = $pims_row['l1_estab_unit_code'];
				$ou_units[$l1][$l2]["#"]["#"] = $pims_row['l2_estab_unit_code'];
				$ou_units[$l1][$l2][$l3]["#"] = $pims_row['l3_estab_unit_code'];
				$ou_units[$l1][$l2][$l3][$l4] = $pims_row['l4_estab_unit_code'];
			}
			
		}
		
	}
}


//Get the list of current published PIMs records. $published sets whether to return published records only
function _pims_get_existing_data( &$system_pims_unique_ids, $published )
{
	//Create the query
	$query = db_select('node', 'n' );
	$query->join( 'field_data_field_pims_unique_id', 'puid', 'n.nid = puid.entity_id' );
	$query->addfield('n', 'nid', 'nid' );
	$query->addfield('puid', 'field_pims_unique_id_value', 'pims_unique_id' );
	if( $published )
	{
		$query->condition( 'n.status', 0, '>' );
	}
	$system_pims_unique_ids = $query->execute()->fetchAllKeyed();
}

//Updates the list of business units. One off process per import file.
function _pims_update_ou_units( $ou_units )
{

	//Sort the business units, multi-dimensional array. Have to go through each level.
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


	//Walk array and create the ou_units nodes
	foreach( $ou_units as $key1 => $lv1 )
	{
		foreach( $lv1 as $key2 => $lv2 )
		{
			foreach( $lv2 as $key3 => $lv3 )
			{

				foreach( $lv3 as $key4 => $lv4 )
				{
					//Get the Business Unit nid using the unit_code
					$query = db_select('field_data_field_unit_code', 'df_ucode')
								->fields('df_ucode', array('entity_id') )
								->condition('df_ucode.field_unit_code_value', $lv4, "=" );
					$unit_nid = $query->execute()->fetchField();

					// Reset the entity structure incase it loaded from the server instead of us
					field_info_cache_clear(); //NOTE : You need this otherwise node fields aren't updated

					if( $unit_nid )
					{
						// Load the Unit node
						$node = node_load( $unit_nid );
						
					} else {
						// Insert unit code
						$node = new stdClass();
						$node->type = 'ou_unit';
						$node->created = time();
						$node->language = LANGUAGE_NONE;
						node_object_prepare($node);
						$node->field_unit_code[$node->language][0]['value'] = $lv4;
					}
					
					$tmp_title = "";
					$tmp_level = 1;

					if( $key4 != "#" )
					{
						$tmp_title = '\\'.$key4;
						$tmp_level++;
						$node->field_unit_name_lv4[$node->language][0]['value'] = $key4;
					}
					
					if( $key3 != "#" )
					{
						$tmp_title = '\\'.$key3.$tmp_title;
						$tmp_level++;
						$node->field_unit_name_lv3[$node->language][0]['value'] = $key3;
					}
					
					if( $key2 != "#" )
					{
						$tmp_title = '\\'.$key2.$tmp_title;
						$tmp_level++;
						$node->field_unit_name_lv2[$node->language][0]['value'] = $key2;
					}
					

					$node->field_unit_name_lv1[$node->language][0]['value'] = $key1;
					$node->field_unit_level[$node->language][0]['value'] = $tmp_level;
					$node->title = $key1.$tmp_title;
					
					$node->changed = time();
					node_save($node);
					
				}
			}
		}
	}
}



//Unpublishs a pims record
function _pims_unpublish( $pims_details, &$context )
{
	$nid = $pims_details[ 0 ];
	$staff_id = substr( $pims_details[ 1 ], 0, 8 );

	$node = node_load( $nid );

	//Since batch & queue processes could run more than once on an import entry, check that node exists
	if( $node )
	{
		$staff_name = check_plain( $node->title );
		ou_profile_log( 'PIMs import : Unpublishing : PIMs : '.$staff_name.' ('.$nid.')' );

		//Store results in batch array
		$context['results'][] = 'Unpublishing : PIMs : '.$staff_name.' ('.$nid.')';
		
		// Optional message displayed under the progressbar.
		$context['message'] = 'Unpublishing : PIMs : '.$staff_name.' ('.$nid.')';

		// Reset the entity structure incase it loaded from the server instead of us
		field_info_cache_clear(); //NOTE : You need this otherwise node fields aren't updated

		//unpublish pims node
		$node->status = 0;
		node_save( $node );

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
		$profile_node = node_load( $profile_nid );
		
		if( $profile_node )
		{
			// Reset the entity structure incase it loaded from the server instead of us
			field_info_cache_clear(); //NOTE : You need this otherwise node fields aren't updated

			$staff_name = check_plain( $profile_node->title );
			ou_profile_log( 'PIMs import : Unpublishing : Profile : '.$staff_name.' ('.$profile_nid.')' );

			//Store results in batch array
			$context['results'][] = 'Unpublishing : Profile : '.$staff_name.' ('.$profile_nid.')';
			
			// Optional message displayed under the progressbar.
			$context['message'] = 'Unpublishing : Profile : '.$staff_name.' ('.$profile_nid.')';

			//???$profile_node->title = $node_title; // restore title

			//unpublish profile node
			$profile_node->field_oup_active[0]['value'] = 0;
			$profile_node->status = 0;
			node_save( $profile_node );
		}
	}
	
}



//Creates a pims record
function _pims_create( $pims_details, &$context )
{

	//Splitting out array values to make code more readable
	$staff_uid = $pims_details[ 0 ];
	$staff_data = $pims_details[ 1 ];

	//Check if PIMs record already created (This is because Queue and Batch operations could be run more that once for an entry)
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

		ou_profile_log( 'PIMs import : Creating : PIMs : '.$staff_name.' ('.$node->nid.')' );

		//Store results in batch array
		$context['results'][] = 'Creating : PIMs : '.$staff_name.' ('.$node->nid.')';
		
		// Optional message displayed under the progressbar.
		$context['message'] = 'Creating : PIMs : '.$staff_name.' ('.$node->nid.')';
		
		//create the profile record
		_pims_import_data_into_profile_record($staff_data, $context);

	}

}



//Updates a pims record
function _pims_update( $pims_details, &$context )
{

	//Splitting out array values to make code more readable
	$nid = $pims_details[ 0 ];
	$staff_data = $pims_details[ 2 ];

	$node = node_load( $nid );

	if( $node )
	{
		_pims_import_data_into_node( $node, $staff_data );
		$staff_name = check_plain( $node->title );

		ou_profile_log( 'PIMs import : Updating : PIMs : '.$staff_name.' ('.$node->nid.')' );

		//Store results in batch array
		$context['results'][] = 'Updating : PIMs : '.$staff_name.' ('.$node->nid.')';
		
		// Optional message displayed under the progressbar.
		$context['message'] = 'Updating : PIMs : '.$staff_name.' ('.$node->nid.')';
		
		//Update the profile record
		_pims_import_data_into_profile_record($staff_data, $context);

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



//Update the PIMS PROFILE node with data from the imported PIMs file
function _pims_import_data_into_node(&$node, $a_pims_row)
{

	// Reset the entity structure incase it loaded from the server instead of us
	field_info_cache_clear(); //NOTE : You need this otherwise node fields aren't updated

	//NOTE: Technically, should use "[$node->language]" instead of "['und']", however, template is expecting "['und']"

	$node->title = _generate_node_title($a_pims_row);

	$node->field_pims_staff_title['und'][0]['value'] = $a_pims_row['staff_title'];
	$node->field_pims_staff_initials['und'][0]['value'] = $a_pims_row['staff_initials'];

	$node->field_pims_staff_forenames['und'][0]['value'] = $a_pims_row['staff_forenames'];
	$node->field_pims_pref_forenames['und'][0]['value'] = $a_pims_row['pref_forenames'];
	$node->field_pims_staff_surname['und'][0]['value'] = $a_pims_row['staff_surname'];
	$node->field_pims_pref_surname['und'][0]['value'] = $a_pims_row['pref_surname'];

	$node->field_pims_oucu['und'][0]['value'] = $a_pims_row['oucu'];
	$node->field_pims_unique_id['und'][0]['value'] = $a_pims_row['unique_id'];
	$node->field_pims_staff_id['und'][0]['value'] = $a_pims_row['staff_id'];
	$node->field_pims_ou_email_address['und'][0]['value'] = $a_pims_row['ou_email_address'];

	$node->field_pims_l1_estab_unit_code['und'][0]['value'] = $a_pims_row['l1_estab_unit_code'];
	$node->field_pims_l1_estab_unit_desc['und'][0]['value'] = $a_pims_row['l1_estab_unit_desc'];

	if( $a_pims_row['l2_estab_unit_name'] == '' )
	{
		//Remove the node fields
		unset( $node->field_pims_l2_estab_unit_name );
		unset( $node->field_pims_l2_estab_unit_code );
	} else {
		$node->field_pims_l2_estab_unit_name['und'][0]['value'] = $a_pims_row['l2_estab_unit_name'];
		$node->field_pims_l2_estab_unit_code['und'][0]['value'] = $a_pims_row['l2_estab_unit_code'];
	}

	if( $a_pims_row['l3_estab_unit_name'] == '' )
	{
		//Remove the node fields
		unset( $node->field_pims_l3_estab_unit_name );
		unset( $node->field_pims_l3_estab_unit_code );
	} else {
		$node->field_pims_l3_estab_unit_name['und'][0]['value'] = $a_pims_row['l3_estab_unit_name'];
		$node->field_pims_l3_estab_unit_code['und'][0]['value'] = $a_pims_row['l3_estab_unit_code'];
	}

	if( $a_pims_row['l4_estab_unit_name'] == '' )
	{
		//Remove the node fields
		unset( $node->field_pims_l4_estab_unit_name );
		unset( $node->field_pims_l4_estab_unit_code );
	} else {
		$node->field_pims_l4_estab_unit_name['und'][0]['value'] = $a_pims_row['l4_estab_unit_name'];
		$node->field_pims_l4_estab_unit_code['und'][0]['value'] = $a_pims_row['l4_estab_unit_code'];
	}

	if( $a_pims_row['personal_website'] == '' )
	{
		//Remove the node field
		unset( $node->field_pims_personal_website );
	} else {
		$node->field_pims_personal_website['und'][0]['value'] = $a_pims_row['personal_website'];
	}

	$node->field_pims_appt_job_title['und'][0]['value'] = $a_pims_row['appt_job_title'];
	$node->field_pims_appt_role_desc['und'][0]['value'] = $a_pims_row['appt_role_desc'];
	$node->field_pims_appt_role_code['und'][0]['value'] = $a_pims_row['appt_role_code'];

	$node->changed = time();
	$node->uid = 1; // Owner is now set when user logs in to keep in sync with SAMS. See hook ouprofile_user()
	$node->status = 1;
	node_save($node);
}



//Create or update the PROFILE node
function _pims_import_data_into_profile_record( $a_pims_row, &$context )
{

	//Get the list of public appointment types and check if this profile is one of them
	$public_roles = variable_get( 'ou_profile_pims_default_public' );
	$public = FALSE;

	if( isset( $public_roles ) )
	{
		$public_role_codes = explode( ',', $public_roles );
		$public = in_array( strtoupper( $a_pims_row['appt_role_code'] ), $public_role_codes );
	}

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
		$node = node_load( $profile_nid );
		
		// Reset the entity structure incase it loaded from the server instead of us
		field_info_cache_clear(); //NOTE : You need this otherwise node fields aren't updated

	} else {

		// Create a new record.
		$node = new stdClass();
		
		// Reset the entity structure incase it loaded from the server instead of us
		field_info_cache_clear(); //NOTE : You need this otherwise node fields aren't updated

		$node->type = 'profile';
		$node->created = time();
		$node->language = LANGUAGE_NONE;
		
		// Default visibility setting = invisible
		$node->field_oup_visibility['und'][0]['value'] = 0;
		
		// Set profile owner to admin
		$node->uid = 1; // Owner is now set when user logs in to keep in sync with SAMS. See hook ou_profile_user()

		//Set default privacy values if this is a public profile
		if( $public )
		{
			_ou_profile_public_profile( $node, '3' );
		}

	}
	
	if( $node )
	{
		// Set the default values
		$node->title = _generate_node_title( $a_pims_row );
		$node->field_oup_staff_id['und'][0]['value'] = $a_pims_row['staff_id'];
		$node->field_oup_oucu['und'][0]['value'] = $a_pims_row['oucu'];
		$node->field_oup_active['und'][0]['value'] = 1;
		$node->changed = time();
		$node->status=1; // make sure profile node is published
		node_save($node);

		ou_profile_log( 'PIMs import : '.$type.' : Profile : '.$node->title.' ('.$node->nid.')' );

		//Store results in batch array
		$context['results'][] = $type.' : Profile : '.$node->title.' ('.$node->nid.')';
		
		// Optional message displayed under the progressbar.
		$context['message'] = $type.' : Profile : '.$node->title.' ('.$node->nid.')';

		//Give access to business unit editors
		if ($a_pims_row['l1_estab_unit_code'])
		{
			ou_profile_lset_content_access($node, $a_pims_row['l1_estab_unit_code']); // in local_functions.inc
		}
	}
}

//Sets all privacy field values on a profile
//Sending privacy as a parameter, incase we need to change function
function _ou_profile_public_profile( &$node, $privacy = '3' )
{

	//Privacy fields.
	static $public_fields = array(
		'field_pprv_appt_job_title',
		'field_pprv_appt_role_desc',
		'field_pprv_l1_estab_unit_desc',
		'field_pprv_l2_estab_unit_name',
		'field_pprv_l3_estab_unit_name',
		'field_pprv_l4_estab_unit_name',
		'field_pprv_ou_email_address',
		'field_pprv_personal_website',
		'field_pprv_pref_forenames',
		'field_pprv_pref_surname',
		'field_pprv_staff_forenames',
		'field_pprv_staff_initials',
		'field_pprv_staff_surname',
		'field_pprv_staff_title',
		'field_prv_alternative_email',
		'field_prv_blog',
		'field_prv_expertise',
		'field_prv_flickr',
		'field_prv_job_title',
		'field_prv_letters',
		'field_prv_linkedin',
		'field_prv_openlearn_bio',
		'field_prv_oubs_internatl_collabs',
		'field_prv_oubs_public_esteem',
		'field_prv_oubs_research_impact',
		'field_prv_personal_bio',
		'field_prv_photo',
		'field_prv_research_interests',
		'field_prv_slideshare',
		'field_prv_teaching_interests',
		'field_prv_twitter',
		'field_prv_web_links'
		);
	
	
	//Privacy values are held in a content type "Privacy value". The privacy fields are "Node Reference" fields
	//Theefore value must be set to the NID of the privacy value we want.
	$privacy_values = ou_profile_lget_privacy_values();
	//Currently, "Public" = 3, so we're searching for that value.
	$public_value = array_search( $privacy, $privacy_values );
	if( $public_value )
	{
		//array_search returns an integer. Need to change to string
		$public_value = strval( $public_value );

		//Loop through all the fields defined earlier.
		foreach( $public_fields as $public_field )
		{
			$node->{$public_field}['und'][0]['nid'] = $public_value;
		}
		
		//Set visibility
		$node->field_oup_visibility['und'][0]['value'] = (int)$privacy - 1;
	}
}


/* Process to set profiles to public
 * This is invoked though the PP server admin page, called through _config_form_submit
*/
function _ou_profile_profiles_public( $codes )
{

	//Check we have codes to match against
	if( $codes == "" )
	{
		drupal_set_message( "No role codes set. No data updated" );
		return( FALSE );
	}

	//Create role code array for query
	$role_codes = explode( ',', $codes );

	//Find all profiles with role code
	$query = db_select( 'field_data_field_pims_appt_role_code', 'role_code' );
	$query->join( 'field_data_field_pims_staff_id', 'staff_id', 'role_code.entity_id = staff_id.entity_id' );
	$query->join( 'field_data_field_oup_staff_id', 'oup_staff_id', 'staff_id.field_pims_staff_id_value = oup_staff_id.field_oup_staff_id_value' );
	$query->condition( 'role_code.field_pims_appt_role_code_value', $role_codes, 'IN' );
	$query->addField( 'oup_staff_id', 'entity_id' );
	$result = $query->execute()->fetchCol();
	
	//Loop through results and set public
	foreach( $result as $profile_nid )
	{
		$node = node_load( $profile_nid );
		if( $node )
		{
			_ou_profile_public_profile( $node, '3' );
			node_save( $node );
		}
	}
	drupal_set_message(t( count( $result ).' profile(s) set to public'));
	return( TRUE );
}
