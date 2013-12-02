<?php
/**
 * @file
 * Cron functions for drupal installations running as a client
 
Create blank profile nodes (client) that link to profiles on the OU profiles server
Build a list of Staff IDs for people in this unit. These are generated from
published profiles (content_type_profile) on the profiles server.

 *
 * Updated : Sirnjeet Kalwan 27/11/2013
 * 	Added new selction criteria for creation of stub records
 * 	i.e. Multi-level PIMS, Profile taxonomy & Media Expertise
 * 
 */

	require_once drupal_get_path('module', 'ou_profile') .'/includes/local_functions.inc';
	
	watchdog("ou_profile_client", "Running client cron");

	//local_functions.inc : ou_profile_lget_site_info() : 
	//Get details from the "allowed sites" document from the server about what profiles this site is allowed to view
	$site_info = ou_profile_lget_site_info();

	//Check if we are an allowed site
	if ( !$site_info['visibility'] )
	{
		ou_profile_log( "This website (%site_path) is not an 'allowed site'",
			array( '%site_path' => ou_profile_lget_site_path() ),
			OU_PROFILE_REPORT_ERROR);
		return;
	} else {
		ou_profile_log("unit_code = %unit | visibility = %vis", array(
				"%unit" => $site_info['unit_code'],
				"%vis" => $site_info['visibility']
			)
		);

	}

	// Set database to profiles
	db_set_active('profiles');

	dsm( $site_info );
	
	// Grab the ids for the pims and profile nodes matching the PIMs unit code
	$profiles_by_ou_unit = array();
	if( isset( $site_info['unit_code'] ) )
	{
	/*
		$query = db_select('node', 'n');
		$query->join('field_data_field_pims_staff_id', 'ps', 'n.nid = ps.entity_id');
		$query->join('field_data_'.$site_info['unit_code_field'], 'u', 'n.nid = u.entity_id');
		
		$query->join('field_data_field_oup_staff_id', 'oup', 'ps.field_pims_staff_id_value = oup.field_oup_staff_id_value');
		$query->join('field_data_field_oup_visibility', 'v', 'oup.entity_id = v.entity_id');
		$query->addField('n', 'nid', 'pims_entity_id');
		$query->addField('oup', 'entity_id', 'profile_entity_id');
		$query->condition('n.status', 0, '>')
		->condition('v.field_oup_visibility_value', (((int)$a_site_info['visibility'])-1) ,'>=')
		->condition('u.'.$site_info['unit_code_field'].'_value', $site_info['unit_code'], '=');
		$profiles_by_ou_unit = $query->execute()->fetchAll();
*/




		$query = db_select('node', 'n');
		$query->join('field_data_field_oup_visibility', 'v', 'n.nid = v.entity_id');
		$query->join('field_data_field_oup_staff_id', 'oup', 'n.nid = oup.entity_id');
		$query->join('field_data_field_pims_staff_id', 'ps', 'oup.field_oup_staff_id_value = ps.field_pims_staff_id_value');
		$query->join('field_data_'.$site_info['unit_code_field'], 'u', 'ps.nid = u.entity_id');
		$query->addField('ps', 'entity_id', 'pims_entity_id');
		$query->addField('n', 'nid', 'profile_entity_id');
		$query->condition( 'n.status', 0, '>' )
		->condition('v.field_oup_visibility_value', (int)$a_site_info['visibility'] ,'>=')
		->condition('u.'.$site_info['unit_code_field'].'_value', $site_info['unit_code'], '=');
		$profiles_by_taxonomy = $query->execute()->fetchAll();






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
		->condition('v.field_oup_visibility_value', (((int)$a_site_info['visibility'])-1) ,'>=')
		->condition('tx.field_profile_taxonomy_tid', $tids, 'IN')
		->condition('tx.bundle', 'profile', '=');
		$profiles_by_taxonomy = $query->execute()->fetchAll();
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
		->condition('v.field_oup_visibility_value', (((int)$a_site_info['visibility'])-1) ,'>=')
		->condition('tx.field_media_expertise_tid', $tids, 'IN')
		->condition('tx.bundle', 'profile', '=');
		$profiles_by_media = $query->execute()->fetchAll();
	}

	//Results could be duplicated. This will de-dupe the results
	$profiles = array();
	$unsorted_results = array_merge( $profiles_by_ou_unit, $profiles_by_taxonomy, $profiles_by_media );
	
	dsm( $profiles_by_ou_unit );
	dsm( $profiles_by_taxonomy );
	dsm( $profiles_by_media );
	
	foreach( $unsorted_results as $item )
	{
		$profiles[ $item->pims_entity_id ] = $item->profile_entity_id;
	}

	dsm( $profiles );

	if( empty( $profiles ) )
	{
		watchdog("ou_profile", "Warning, no data was retrieved.", NULL, WATCHDOG_WARNING);
	} else {
		watchdog("ou_profile", "Fetched %count rows", array('%count' => count($profiles)));
	}


	// Set database back
	db_set_active('default');

	//Get local profile stubs : $local_profiles[ nid ]=unique_id
	$local_profiles = _ou_profile_client_cron_get_local_stubs();

	foreach ( $profiles as $pims_entity_id => $profile_entity_id )
	{

		watchdog("ou_profile", "loading pims : $pims_entity_id and profile : $profile_entity_id");

		// Set database to server and load PIMs profile & Person profile
		db_set_active( 'profiles' );
		$pims_data = node_load( $pims_entity_id, NULL, TRUE );
		$profile_data = node_load( $profile_entity_id, NULL, TRUE );
		db_set_active( 'default' );
		
		if( $pims_data && $profile_data )
		{
			watchdog("ou_profile", "loaded");
			dsm( "Loaded" );

			// Reset the entity structure incase it loaded from the server instead of us
			//field_info_cache_clear();

	//Don't need this. Query only returns profiles that are valid for this site
			// Don't create local profiles when the profile is marked hidden.
			if ( !isset( $profile_data->field_oup_visibility['und'][0]['value']) || !(int) $profile_data->field_oup_visibility['und'][0]['value'])
			{
				ou_profile_log($pims_data->title . " is not visible");
				dsm( $pims_data->title . " is not visible" );
				continue;
			}
		

		dsm( $pims_data );
		dsm( $profile_data );


			$unique_id = $pims_data->field_pims_unique_id['und'][0]['value'];
			dsm( $unique_id );
			
			watchdog("ou_profile", '$unique_id : '.$unique_id);
			
			$profile_title = ou_profile_lcreate_name(
				isset($pims_data->field_pims_staff_title['und'][0]['value']) ? $pims_data->field_pims_staff_title['und'][0]['value'] : '',
				isset($pims_data->field_pims_staff_forenames['und'][0]['value']) ? $pims_data->field_pims_staff_forenames['und'][0]['value'] : '',
				isset($pims_data->field_pims_staff_surname['und'][0]['value']) ? $pims_data->field_pims_staff_surname['und'][0]['value'] : '',
				isset($pims_data->field_pims_pref_forenames['und'][0]['value']) ? $pims_data->field_pims_pref_forenames['und'][0]['value'] : '',
				isset($pims_data->field_data_field_pims_pref_surname['und'][0]['value']) ? $pims_data->field_data_field_pims_pref_surname['und'][0]['value'] : ''
			);
dsm( $profile_title );
			ou_profile_log('Name = '.$profile_title);

			// If a local profile does not exist for this unique_id, create one and remove the unique_id from the list.
			$query = 'SELECT entity_id FROM {field_data_field_pims_unique_id} WHERE field_pims_unique_id_value=\'' . $unique_id . '\'';
			// field_data_field_pims_unique_id?

			$oup_nid = db_query($query)->fetchField();

			if ($oup_nid)
			{
				// Profile exists but things like surnames can change so they need to be kept in synch
				// and we may as well keep the title in synch too to save manual effort on client sites
				$oup_node = node_load($oup_nid, NULL, TRUE);
				$node_change = FALSE;

				unset($local_profiles[$oup_nid]);
			} else {
				// Create local profile
				$oup_node = new stdClass();
				$oup_node->type = 'ou_profile';
				$oup_node->created = time();
				$oup_node->changed = time();
				$oup_node->language = LANGUAGE_NONE;
				node_object_prepare($oup_node);
				$oup_node->uid = 1;
			}

			if (!isset($oup_node->title) || ($oup_node->title != $profile_title))
			{
				$oup_node->title = $profile_title;
				$oup_node->field_pims_unique_id['und'][0]['value'] = $unique_id;
				$oup_node->changed = time();
			}

			$oup_node->status = 1;
			$node_change = TRUE;

			node_save($oup_node);
			unset($oup_node);
			unset($pims_data);
			unset($profile_data);
			node_load_multiple(NULL, NULL, TRUE); // keep the cache empty as node_delete performs a node_load first
		}
		break;
	}
	
	// Unpublish any profiles which no longer exist on the profiles server
	foreach ($local_profiles as $oup_nid => $unique_id)
	{
		//node_delete($oup_nid);
		//node_load(FALSE, NULL, TRUE); // keep the cache empty as node_delete performs a node_load first
		$oup_node = node_load($oup_nid);
		if ($oup_node->status) 
		{ 
			// Unpublish published profiles (no need to do it more than once!)
			$oup_node->status = 0;
			node_save($oup_node);
		}
		unset($oup_node);
		node_load_multiple(FALSE, NULL, TRUE); // keep the cache empty as node_delete performs a node_load first
	}


// Get the local profile stubs
function _ou_profile_client_cron_get_local_stubs( )
{
	$local_profiles = array();
	$query = db_select('field_data_field_pims_unique_id', 'pims_id_table');
	$query->fields('pims_id_table', array('entity_id', 'field_pims_unique_id_value' ) );
	$result = $query->execute();
	foreach ( $result as $data )
	{
		$local_profiles[$data->entity_id] = $data->field_pims_unique_id_value;
	}
	
	return $local_profiles;
}