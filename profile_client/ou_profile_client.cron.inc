<?php
/*
error_reporting(E_ALL);
ini_set('display_errors', TRUE);
ini_set('display_startup_errors', TRUE);
*/

/**
 * @file
 * Cron functions for drupal installations running as a client
 
Create blank profile nodes (client) that link to profiles on the OU profiles server
Build a list of Staff IDs for people in this unit. These are generated from
published profiles (content_type called profile) on the profiles server.

 *
 * Updated : Sirnjeet Kalwan 27/11/2013
 * 	Added new selction criteria for creation of stub records
 * 	i.e. Multi-level PIMS, Profile taxonomy & Media Expertise
 * 
 */

require_once drupal_get_path('module', 'ou_profile') .'/includes/local_functions.inc';

/**
 * Implementation of hook_cron().
 *
 * Run the appropriate cron job for each OU website that uses this module
 * Notes:
 * 1, Client cron checks the database of allowed sites so no need to check here
 * 2, OUBS reporting keeps its own copies of PIMS data so needs to run client and server crons
 * 3, Run the server cron before the client cron on OUBS reporting
 *
 */
function ou_profile_client_cron()
{
	$queue = DrupalQueue::get( 'ou_profile_client_profile_import' );
	$queue_size = $queue->numberOfItems();

	if( $queue_size < 5 )
	{

		//We only import after 24 hours have elapsed since last import
		$config_last_imported = variable_get('ou_profile_client_import_finish', '');
		if( $config_last_imported == '' )
		{
			$config_last_imported == 'January 1 1970 00:00:00';
		}
		$next_import = strtotime( $config_last_imported.' + 24 hours' );
		$nowtime = date("Y-m-d H:i:s", time() );
		
		if( $next_import > time() )
		{
			ou_profile_log( 'Next import due after : '.date('d-m-Y H:i:s', $next_import) );			
		} else {
		
			$profiles = _ou_profile_client_get_profile_nids();
			if( !$profiles )
			{
				ou_profile_log( 'No profiles found to import.' );
			}

			$profiles2delete = _ou_profile_client_cron_get_profiles2delete( $profiles );
			if( !$profiles2delete )
			{
				ou_profile_log( 'No profiles found to unpublish.' );
			}


			if( !empty( $profiles ) || !empty( $profiles2delete ) )
			{

				// Create the Drupal QUEUE items
				$queue->createItem( array( 'start' ) );
				foreach( $profiles2delete as $nid => $content )
				{
					$queue->createItem( array( 'delete', $nid ) );
				}

				// Create the Drupal QUEUE items
				foreach( $profiles as $pims_entity_id => $profile_entity_id )
				{
					$queue->createItem( array( 'import', $pims_entity_id, $profile_entity_id ) );
				}

				$queue->createItem( array( 'finished' ) );
			}
		}

	} else {
		ou_profile_log( 'Queue not updated. Queue size : '.$queue_size );
	}

}

//================= QUEUE PROCESSING START ================= 

/*
 * Implements hook_cron_queue_info().
 */
function ou_profile_client_cron_queue_info()
{
	//Here we tell Drupal that we want a queue. Nothing added to it at this stage, just defines its 
	//parameters. Alter TIME to adjust how long this is allowed to run.
	$queues['ou_profile_client_profile_import'] = array(
		'worker callback' => 'ou_profile_client_profile_import_process',
		'time' => 150,
	);
	return $queues;
}

//Process each queue operation
function ou_profile_client_profile_import_process( $data )
{
	//Empty array. Since the processing functions are used by BATCH too, we re-use them by
	//passing this array. Not used in this QUEUE process.
	$context = array();
	
	//Shift off the first value and return
	$process_type = array_shift( $data );
	
	//Get a count of unprocessed entries
	$queue = DrupalQueue::get( 'ou_profile_client_profile_import' );
	$queue_size = $queue->numberOfItems();

	switch( $process_type )
	{
		case 'start':
			ou_profile_log( 'Profile queue import : Start ('.$queue_size.')' );
			_ou_profile_client_tmpvar_init();
			break;
		case 'import':
			_ou_profile_client_profile_import( $data, $context );
			break;
		case 'delete':
			_ou_profile_client_profile_delete( $data, $context );
			break;
		case 'finished':
			variable_set('ou_profile_client_import_finish', date("d-m-Y H:i:s") );
			ou_profile_log( 'Profile queue import : Finished' );
			
			//Set the client site categories up, we use these as values for our drop-down lists for filtering
			_ou_profile_client_sort_and_set_category( 'ou_profile_client_profile_taxonomy_tmp', 'ou_profile_client_profile_taxonomy' );
			_ou_profile_client_sort_and_set_category( 'ou_profile_client_pims_units_tmp', 'ou_profile_client_pims_units' );
			_ou_profile_client_sort_and_set_category( 'ou_profile_client_pims_job_title_tmp', 'ou_profile_client_pims_job_title' );
			break;
	}
}
//================= QUEUE PROCESSING FINISH =================


//================= BATCH PROCESSING START ================= 

//Create the batch. Initiated from the admin page
function ou_profile_client_batch_import()
{
	//Delete the queue items as we are about to initiate a batch import
	$queue = DrupalQueue::get( 'ou_profile_client_profile_import' );
	$queue_size = $queue->numberOfItems();
	if( $queue_size > 0 )
	{
		drupal_set_message( 'Import queue still had : '.$queue_size.' items to process. Queue has been deleted.' );
		//Pull items out one at a time.
		while($item = $queue->claimItem())
		{
			$queue->deleteItem($item);
		}
	}

	//Get details of profiles to import
	$profiles = _ou_profile_client_get_profile_nids();
	if( !$profiles )
	{
		drupal_set_message( 'No profiles found to import.' );
	}

	//Get details of profiles to delete
	$profiles2delete = _ou_profile_client_cron_get_profiles2delete( $profiles );
	if( !$profiles2delete )
	{
		drupal_set_message( 'No profiles found to unpublish.' );
	}

	//If we have something to process...
	if( !empty( $profiles ) || !empty( $profiles2delete ) )
	{
		// Create the Drupal BATCH items
		$operations[] = array();
		$operations[] = array( 'ou_profile_client_batch_process', array( array( 'start' ) ) );

		foreach( $profiles2delete as $nid => $content )
		{
			$operations[] = array(
				'ou_profile_client_batch_process',
				array( array( 'delete', $nid ) )
				);
		}

		// Create the Drupal BATCH items
		foreach( $profiles as $pims_entity_id => $profile_entity_id )
		{
			$operations[] = array(
				'ou_profile_client_batch_process',
				array( array( 'import', $pims_entity_id, $profile_entity_id ) )
				);
		}
		
		//Define the batch
		$batch = array(
			'operations' => $operations,
			'title' => 'People profile client import',
			'finished' => 'ou_profile_client_batch_complete'
		);

		//Run the batch
		batch_set( $batch );
	}
}

//Batch processor
function ou_profile_client_batch_process( $data, &$context )
{
	//Shift off the first value and return
	$process_type = array_shift( $data );
	
	switch( $process_type )
	{
		case 'start':
			ou_profile_log( 'Profile batch import : Start' );
			_ou_profile_client_tmpvar_init();
			break;
		case 'import':
			_ou_profile_client_profile_import( $data, $context );
			break;
		case 'delete':
			_ou_profile_client_profile_delete( $data, $context );
			break;
	}

}

//Function called when the batch process is complete
function ou_profile_client_batch_complete( $success, $results, $operations )
{
	if( $success )
	{
		// Here we could do something meaningful with the results.
		variable_set('ou_profile_client_import_finish', date("d-m-Y H:i:s") );
		drupal_set_message(t('@count records  processed.', array('@count' => count( $results ) ) ) );
		ou_profile_log( 'Profile batch import : Complete : '.count( $operations ) );

		//Set the client site categories up, we use these as values for our drop-down lists for filtering
		_ou_profile_client_sort_and_set_category( 'ou_profile_client_profile_taxonomy_tmp', 'ou_profile_client_profile_taxonomy' );
		_ou_profile_client_sort_and_set_category( 'ou_profile_client_pims_units_tmp', 'ou_profile_client_pims_units' );
		_ou_profile_client_sort_and_set_category( 'ou_profile_client_pims_job_title_tmp', 'ou_profile_client_pims_job_title' );
	
	} else {
		// An error occurred.
		// $operations contains the operations that remained unprocessed.
		$error_operation = reset( $operations );
		drupal_set_message(t('An error occurred while processing @operation with arguments : @args', array('@operation' => $error_operation[0], '@args' => print_r($error_operation[0], TRUE))));
	}

}
//================= BATCH PROCESSING FINISH ================= 


//================= START Tmp var functions =================
//We store category values in tmp vars so we can set the admin page values upon completion

//Blank out the temporary taxonomy categories in order to rebuild
function _ou_profile_client_tmpvar_init()
{
	variable_del( 'ou_profile_client_profile_taxonomy_tmp' );
	variable_del( 'ou_profile_client_pims_units_tmp' );
	variable_del( 'ou_profile_client_pims_job_title_tmp' );
}

//Helper function to take temp stored var and set admin var
function _ou_profile_client_sort_and_set_category( $tmpvar, $var )
{
	$tmp_get = explode( "\r\n", variable_get( $tmpvar, '' ) );
	natcasesort( $tmp_get );
	$tmp_implode = implode( "\r\n", $tmp_get );
	variable_set( $var, $tmp_implode );
	variable_del( $tmpvar );
}

//Adds value to the tmp var
function _ou_profile_client_tmpvar_add( $tmpvar, $value )
{
	$tmp = explode( "\r\n", variable_get( $tmpvar, '' ) );
	$tmp[] = $value;
	$tmp_unique = array_unique( $tmp );
	$tmp_implode = implode( "\r\n", $tmp_unique );
	variable_set( $tmpvar, $tmp_implode );
}
//================= END Tmp var functions =================

//Get details of the profiles to import
function _ou_profile_client_get_profile_nids()
{
	//local_functions.inc : ou_profile_lget_site_info() :
	//Get details from the "allowed sites" document from the server about what profiles this site is allowed to view
	$site_info = ou_profile_lget_site_info();

	//Check if we are an allowed site
	if ( !$site_info['visibility'] )
	{
		ou_profile_log( "This website (%site_path) is not an 'allowed site'",
			array( '%site_path' => ou_profile_lget_site_path() ),
			OU_PROFILE_REPORT_ERROR);
		return( FALSE );
	} else {
		ou_profile_log("unit_code = %unit | visibility = %vis", array(
				"%unit" => $site_info['unit_code'],
				"%vis" => $site_info['visibility']
			)
		);
	}

	// Clear the caches. Must be done before switching dbs
	//_ou_profile_cc();

	// Set database to profiles
	db_set_active('profiles');

	// Grab the ids for the pims and profile nodes matching the PIMs unit code
	$profiles_by_ou_unit = array();
	if( isset( $site_info['unit_code'] ) )
	{
		//$profiles_by_ou_unit = array();
		$query = db_select('node', 'n');
		$query->join('field_data_field_oup_visibility', 'v', 'n.nid = v.entity_id');
		$query->join('field_data_field_oup_staff_id', 'oup', 'n.nid = oup.entity_id');
		$query->join('field_data_field_pims_staff_id', 'ps', 'oup.field_oup_staff_id_value = ps.field_pims_staff_id_value');
		$query->join('field_data_'.$site_info['unit_code_field'], 'u', 'ps.entity_id = u.entity_id');
		$query->addField('ps', 'entity_id', 'pims_entity_id');
		$query->addField('n', 'nid', 'profile_entity_id');
		$query->condition( 'n.status', 0, '>' )
		->condition('v.field_oup_visibility_value', (((int)$site_info['visibility']) - 1),'>=')
		->condition('u.'.$site_info['unit_code_field'].'_value', $site_info['unit_code'], '=');
		$profiles_by_ou_unit = $query->execute()->fetchAllKeyed();
	}

	// Grab the ids for the pims and profile nodes matching the profile taxonomy
	$profiles_by_taxonomy = array();
	if( isset( $site_info['taxonomy'] ) )
	{
		$tmp_array = array();
		$tids_children = array();

		//Loop through each term and get child terms
		foreach( $site_info['taxonomy'] as $list_item )
		{
			$result = taxonomy_get_children( $list_item[ 'tid' ] );
			$tids_children = array_merge( $tids_children, $result );
			
			//Strip out the TID
			$tmp_array[] = $list_item[ 'tid' ];
		}
		
		//Process above returns objects, we just want the TID
		foreach( $tids_children as $list_item )
		{
			$tmp_array[] = $list_item->tid;
		}
		
		//Remove the dupes
		$tids = array_unique( $tmp_array );
		
		$query = db_select('node', 'n');
		$query->join('field_data_field_profile_taxonomy', 'tx', 'n.nid = tx.entity_id');
		$query->join('field_data_field_oup_visibility', 'v', 'n.nid = v.entity_id');
		$query->join('field_data_field_oup_staff_id', 'oup', 'n.nid = oup.entity_id');
		$query->join('field_data_field_pims_staff_id', 'ps', 'oup.field_oup_staff_id_value = ps.field_pims_staff_id_value');
		$query->addField('ps', 'entity_id', 'pims_entity_id');
		$query->addField('n', 'nid', 'profile_entity_id');
		$query->condition( 'n.status', 0, '>' )
		->condition('v.field_oup_visibility_value', (((int)$site_info['visibility'])-1) ,'>=')
		->condition('tx.field_profile_taxonomy_tid', $tids, 'IN')
		->condition('tx.bundle', 'profile', '=');
		$profiles_by_taxonomy = $query->execute()->fetchAllKeyed();

		//Filter the list to just those found in OU_Unit
		if( isset( $site_info['unit_code'] ) )
		{
			$profiles_by_taxonomy = array_intersect_assoc( $profiles_by_ou_unit, $profiles_by_taxonomy );
			$profiles_by_ou_unit = $profiles_by_taxonomy; //Do this as we merge all output later
		}
		
	}

	// Grab the ids for the pims and profile nodes matching the media expertise
	$profiles_by_media = array();
	if( isset( $site_info['media'] ) )
	{

		$tmp_array = array();
		$tids_children = array();

		//Loop through each term and get child terms
		foreach( $site_info['media'] as $list_item )
		{
			$result = taxonomy_get_children( $list_item[ 'tid' ] );
			$tids_children = array_merge( $tids_children, $result );
			
			//Strip out the TID
			$tmp_array[] = $list_item[ 'tid' ];
		}
		
		//Process above returns objects, we just want the TID
		foreach( $tids_children as $list_item )
		{
			$tmp_array[] = $list_item->tid;
		}
		
		//Remove the dupes
		$tids = array_unique( $tmp_array );
		
		$query = db_select('node', 'n');
		$query->join('field_data_field_media_expertise', 'tx', 'n.nid = tx.entity_id');
		$query->join('field_data_field_oup_visibility', 'v', 'n.nid = v.entity_id');
		$query->join('field_data_field_oup_staff_id', 'oup', 'n.nid = oup.entity_id');
		$query->join('field_data_field_pims_staff_id', 'ps', 'oup.field_oup_staff_id_value = ps.field_pims_staff_id_value');
		$query->addField('ps', 'entity_id', 'pims_entity_id');
		$query->addField('n', 'nid', 'profile_entity_id');
		$query->condition( 'n.status', 0, '>' )
		->condition('v.field_oup_visibility_value', (((int)$site_info['visibility'])-1) ,'>=')
		->condition('tx.field_media_expertise_tid', $tids, 'IN')
		->condition('tx.bundle', 'profile', '=');
		$profiles_by_media = $query->execute()->fetchAllKeyed();

		//Filter the list to just those found in OU_Unit
		if( isset( $site_info['unit_code'] ) )
		{
			$profiles_by_media = array_intersect_assoc( $profiles_by_ou_unit, $profiles_by_media );
			$profiles_by_ou_unit = $profiles_by_media; //Do this as we merge all output later
		}
		
		//Finally filter the list to just those found in taxonomy
		if( isset( $site_info['taxonomy'] ) )
		{
			$profiles_by_media = array_intersect_assoc( $profiles_by_taxonomy, $profiles_by_media );
			$profiles_by_taxonomy = $profiles_by_media; //Do this as we merge all output later
			$profiles_by_ou_unit = $profiles_by_media; //Do this as we merge all output later
		}
	}

	// Clear the caches. Must be done before switching dbs
	_ou_profile_cc();

	// Set database back
	db_set_active('default');

	//Results could be duplicated (e.g. same profile returned for a match to ou unit & taxonomy). This will de-dupe the results
	$profiles = array();

	//This merges the arrays (we can't be sure which query ran, so just check for all of them)
	//Don't use array_merge or array_merge_recursive, loses the key value
	foreach( $profiles_by_ou_unit as $key => $content )
	{
		$profiles[ $key ] = $content;
	}
	foreach( $profiles_by_taxonomy as $key => $content )
	{
		$profiles[ $key ] = $content;
	}
	foreach( $profiles_by_media as $key => $content )
	{
		$profiles[ $key ] = $content;
	}

	//Check if results have been returned
	if( empty( $profiles ) )
	{
		ou_profile_log(  "Warning, no data was retrieved.", NULL, WATCHDOG_WARNING);
		return( FALSE );
	} else {
		ou_profile_log(  "Fetched %count rows", array('%count' => count($profiles)));
		return( $profiles );
	}
}


//Create or update the profile stub
function _ou_profile_client_profile_import( $data, $context = NULL )
{
	//Store results in batch array
	$context['results'][] = 'Loading pims : '.$data[ 0 ].' and profile : '.$data[1];
	
	// Optional message displayed under the progressbar.
	$context['message'] = 'Loading pims : '.$data[ 0 ].' and profile : '.$data[1];

	// Clear the caches. Must be done before switching dbs
	_ou_profile_cc();

	// Set database to server and load PIMs profile & Person profile
	db_set_active( 'profiles' );
	
	$pims_data = node_load( $data[ 0 ], NULL, TRUE );
	$profile_data = node_load( $data[ 1 ], NULL, TRUE );
	
	// Clear the caches. Must be done before switching dbs
	_ou_profile_cc();

	db_set_active( 'default' );
	
	if( $pims_data && $profile_data )
	{
		
		//Function to generate the profiles name
		$profile_title = ou_profile_lcreate_name(
			isset($pims_data->field_pims_staff_title['und'][0]['value']) ? $pims_data->field_pims_staff_title['und'][0]['value'] : '',
			isset($pims_data->field_pims_staff_forenames['und'][0]['value']) ? $pims_data->field_pims_staff_forenames['und'][0]['value'] : '',
			isset($pims_data->field_pims_staff_surname['und'][0]['value']) ? $pims_data->field_pims_staff_surname['und'][0]['value'] : '',
			isset($pims_data->field_pims_pref_forenames['und'][0]['value']) ? $pims_data->field_pims_pref_forenames['und'][0]['value'] : '',
			isset($pims_data->field_data_field_pims_pref_surname['und'][0]['value']) ? $pims_data->field_data_field_pims_pref_surname['und'][0]['value'] : ''
		);
	
		$unique_id = $pims_data->field_pims_unique_id['und'][0]['value'];
		
		ou_profile_log( 'Name = '.$profile_title.' Unique id = '.$unique_id );
		
		// Check if local profile exists for this unique_id
		$query = db_select( 'field_data_field_pims_unique_id', 'pims_id_table' );
		$query->fields( 'pims_id_table', array('entity_id') );
		$query->condition('field_pims_unique_id_value', $unique_id ,'=' );
		$oup_nid = $query->execute()->fetchField();
		
		if( $oup_nid )
		{
			// Profile exists but things like surnames can change so need to check name
			$oup_node = node_load($oup_nid, NULL, TRUE);
		} else {
			// Create local profile as one was not found
			$oup_node = new stdClass();
			$oup_node->type = 'ou_profile';
			$oup_node->created = time();
			$oup_node->language = LANGUAGE_NONE;
			node_object_prepare($oup_node);
			$oup_node->uid = 1;
			$oup_node->field_pims_unique_id['und'][0]['value'] = $unique_id;
		}

		if (!isset($oup_node->title) || ($oup_node->title != $profile_title))
		{
			$oup_node->title = $profile_title;
		}

		$oup_node->field_oup_oucu = $profile_data->field_oup_oucu; //could do this in the create, but here it will catch existing sites
		
		//Set the client node fields. Unset the field if it doesn't exist on the server profile
		//Overidden job title 
		if( isset( $profile_data->field_oup_job_title['und'] ) )
		{
			$oup_node->field_oup_job_title = $profile_data->field_oup_job_title;
		} else {
			unset( $oup_node->field_oup_job_title['und'] );
		}
		
		//pims job title
		if( isset( $pims_data->field_pims_appt_job_title['und'][0]['value'] ) )
		{
			$oup_node->field_pims_appt_job_title = $pims_data->field_pims_appt_job_title;
			//Add to category list
			_ou_profile_client_tmpvar_add( 'ou_profile_client_pims_job_title_tmp', $pims_data->field_pims_appt_job_title['und'][0]['value'] );
			
		} else {
			unset( $oup_node->field_pims_appt_job_title );
		}
		
		//Tmp vars to store PIMS units
		$pims_units[] = array();
		$pims_units[ 0 ] = '';
		$pims_units[ 1 ] = '';
		
		//PIMs unit lv1
		if( isset( $pims_data->field_pims_l1_estab_unit_desc['und'][0]['value'] ) )
		{
			if( $pims_data->field_pims_l1_estab_unit_desc['und'][0]['value'] != '' )
			{
				$oup_node->field_pims_l1_estab_unit_desc = $pims_data->field_pims_l1_estab_unit_desc;
				$pims_units[ 0 ] = $pims_data->field_pims_l1_estab_unit_desc['und'][0]['value'];
				$pims_units[ 1 ] = $pims_data->field_pims_l1_estab_unit_desc['und'][0]['value'].'~1';
			}
		} else {
			unset( $oup_node->field_pims_l1_estab_unit_desc );
		}
		
		//PIMs unit lv2
		if( isset( $pims_data->field_pims_l2_estab_unit_name['und'][0]['value'] ) )
		{
			if( $pims_data->field_pims_l2_estab_unit_name['und'][0]['value'] != '' )
			{
				$oup_node->field_pims_l2_estab_unit_name = $pims_data->field_pims_l2_estab_unit_name;
				$pims_units[ 0 ] = $pims_units[ 0 ].' - '.$pims_data->field_pims_l2_estab_unit_name['und'][0]['value'];
				$pims_units[ 1 ] = $pims_data->field_pims_l2_estab_unit_name['und'][0]['value'].'~2';
			}
		} else {
			unset( $oup_node->field_pims_l2_estab_unit_name );
		}
		
		//PIMs unit lv3
		if( isset( $pims_data->field_pims_l3_estab_unit_name['und'][0]['value'] ) )
		{
			if( $pims_data->field_pims_l3_estab_unit_name['und'][0]['value'] != '' )
			{
				$oup_node->field_pims_l3_estab_unit_name = $pims_data->field_pims_l3_estab_unit_name;
				$pims_units[ 0 ] = $pims_units[ 0 ].' - '.$pims_data->field_pims_l3_estab_unit_name['und'][0]['value'];
				$pims_units[ 1 ] = $pims_data->field_pims_l3_estab_unit_name['und'][0]['value'].'~3';
			}
		} else {
			unset( $oup_node->field_pims_l3_estab_unit_name );
		}

		//PIMs unit lv4
		if( isset( $pims_data->field_pims_l4_estab_unit_name['und'][0]['value'] ) )
		{
			if( $pims_data->field_pims_l4_estab_unit_name['und'][0]['value'] != '' )
			{
				$oup_node->field_pims_l4_estab_unit_name = $pims_data->field_pims_l4_estab_unit_name;
				$pims_units[ 0 ] = $pims_units[ 0 ].' - '.$pims_data->field_pims_l4_estab_unit_name['und'][0]['value'];
				$pims_units[ 1 ] = $pims_data->field_pims_l4_estab_unit_name['und'][0]['value'].'~4';
			}
		} else {
			unset( $oup_node->field_pims_l4_estab_unit_name );
		}
		
		if( $pims_units[ 0 ] != '' )
		{
			_ou_profile_client_tmpvar_add( 'ou_profile_client_pims_units_tmp', $pims_units[ 0 ].'|'.$pims_units[ 1 ] );
		}
		
		//profile_taxonomy
		if( isset( $profile_data->field_profile_taxonomy['und'][0]['tid'] ) )
		{
			//We can't sent the TID, we need to sent the full taxonomy text name
			$oup_node->field_profile_taxonomy['und'] = array();
			$profile_taxonomy = _ou_profile_client_build_tid_name( $profile_data->field_profile_taxonomy['und'] );
			$oup_node->field_profile_taxonomy['und'] = $profile_taxonomy[ 0 ];

			//Build the client site taxomony list
			$client_taxonomy = explode( "\r\n", variable_get( 'ou_profile_client_profile_taxonomy_tmp', '' ) );
			$new_client_taxonomy = array_merge( $client_taxonomy, $profile_taxonomy[ 1 ] );
			$sorted_client_taxonomy = array_unique( $new_client_taxonomy );
			$implode_client_taxonomy = implode( "\r\n", $sorted_client_taxonomy );
			variable_set( 'ou_profile_client_profile_taxonomy_tmp', $implode_client_taxonomy );
		} else {
			unset( $oup_node->field_profile_taxonomy );
		}
		
		//media_expertise
		if( isset( $profile_data->field_media_expertise['und'][0]['tid'] ) )
		{
			//We can't sent the TID, we need to sent the full taxonomy text name
			$oup_node->field_media_expertise['und'] = array();
			$media_expertise = _ou_profile_client_build_tid_name( $profile_data->field_media_expertise['und'] );
			$oup_node->field_media_expertise['und'] = $media_expertise[ 0 ];
		} else {
			unset( $oup_node->field_media_expertise );
		}
		$oup_node->status = 1;
		node_save($oup_node);
	}
}

//Helper function to build the full taxonomy name e.g. parent_taxonomy_name\taxonomy_name
function _ou_profile_client_build_tid_name( $get_tid_details )
{
	// Clear the caches. Must be done before switching dbs
	_ou_profile_cc();

	// Set database to server and load PIMs profile & Person profile
	db_set_active( 'profiles' );

	$field_tid = array();
	$tid_name = array();
	
	//Loop through all the terms
	foreach( $get_tid_details as $selected_tid )
	{
		$this_tid_name = array();
		
		//Get the parents. Array is in reverse order. Term is first, then parent.
		$parent_tids = taxonomy_get_parents_all( $selected_tid[ 'tid' ] );
		
		foreach( $parent_tids as $term )
		{
			//$this_tid_name = $term->name.'\\'.$this_tid_name;
			$this_tid_name[] = $term->name;
		}
		$this_tid_name = array_reverse( $this_tid_name );
		$this_tid_name_implode = implode( '\\', $this_tid_name );
		$field_tid[]['value'] = $this_tid_name_implode;
		$tid_name[] = $this_tid_name_implode.'|'.$selected_tid[ 'tid' ];
	}
	
	// Clear the caches. Must be done before switching dbs
	_ou_profile_cc();

	// Set database to server and load PIMs profile & Person profile
	db_set_active( 'default' );

	return( array( $field_tid, $tid_name ) );
}

//Unpublish profiles that no longer exist in the import
function _ou_profile_client_profile_delete( $data, $context = NULL )
{
	//Store results in batch array
	$context['results'][] = 'Unpublishing node : '.$data[ 0 ];
	
	// Optional message displayed under the progressbar.
	$context['message'] = 'Unpublishing node : '.$data[ 0 ];

	$oup_node = node_load( $data[ 0 ] );
	if( $oup_node->status )
	{ 
		// Unpublish published profiles (no need to do it more than once!)
		$oup_node->status = 0;
		node_save($oup_node);
	}
}

// Get a list of the local profile stubs to delete
// $profiles['pims id'] = profiles id : parameter are the profiles to be imported
function _ou_profile_client_cron_get_profiles2delete( $profiles )
{
	$local_profiles = array();
	$query = db_select( 'field_data_field_pims_unique_id', 'pims_id_table');
	$query->fields( 'pims_id_table', array('entity_id', 'field_pims_unique_id_value' ) );
	$result = $query->execute();
	
	foreach ( $result as $data )
	{
		$local_profiles[$data->entity_id] = $data->field_pims_unique_id_value;
	}

	// Clear the caches. Must be done before switching dbs
	_ou_profile_cc();

	// Set database to server and load PIMs profile & Person profile
	db_set_active( 'profiles' );
		
	foreach( $profiles as $pims_entity_id => $profile_entity_id )
	{
		$pims_data = node_load( $pims_entity_id, NULL, TRUE );
		$profile_data = node_load( $profile_entity_id, NULL, TRUE );
		
		if( $pims_data && $profile_data )
		{
			$unique_id = $pims_data->field_pims_unique_id['und'][0]['value'];
			
			$profile_exists = array_search( $unique_id, $local_profiles );
			if( $profile_exists )
			{

				//Remove the unique ID from the list of local profiles. 
				unset( $local_profiles[$profile_exists] );
			}
		}
	}

	// Clear the caches. Must be done before switching dbs
	_ou_profile_cc();

	db_set_active( 'default' );
		
	return $local_profiles;
}
