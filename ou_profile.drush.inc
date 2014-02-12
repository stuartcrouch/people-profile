<?php

/**
* Implements of hook_drush_command().
*
* "pimsimport" Command to allow batch processing of PIMs import file.
*
*/ 
function ou_profile_drush_command()
{
	$items = array();
	$items['pimsimport'] = array(
		'description' => 'Runs the People Profiles PIMs import batch process.',
		'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
	);
	$items['oneoffpimsimport'] = array(
		'description' => 'Runs the one off People Profiles PIMs import batch process. Complete import of PIMs.txt',
		'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
	);
	$items['oneoffpimsimportunits'] = array(
		'description' => 'Runs the one off People Profiles PIMs import batch process. Complete import of PIMs.txt',
		'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
	);
	return $items;
}
 
/**
* Set and process a PIMS batch job with drush.
*
*/
function drush_ou_profile_pimsimport()
{
	//Get pims filename from the config page /admin/config/system/ou_profile
	$filepath = variable_get('ou_profile_pims_preproc_path', '/drupalshared/interface_files');
	$pims_file = $filepath.'/new_staff_updates.txt';
	$error = FALSE;
	
	//Check that the files exist
	if( !file_exists( $pims_file ) )
	{
		drush_print( 'PIMs import file not found : '.$pims_file );
		$error = TRUE;
	}
	if( !file_exists( $filepath.'/pimsprevious.txt' ) )
	{
		drush_print( 'PIMs import file not found : '.$filepath.'/pimsprevious.txt' );
		$error = TRUE;
	}
	if( !file_exists( $filepath.'/all_staff_ids.txt' ) )
	{
		drush_print( 'PIMs import file not found : '.$filepath.'/all_staff_ids.txt' );
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
			drush_print( 'Valid PIMs import file detected. Initiating import.' );
			$batch = array();
			_pims_import_initialise( 'drush', $batch );
			if( !empty( $batch ) )
			{
				$batch['progressive'] = FALSE;
				batch_set($batch);
				// Process the batch.
				drush_backend_batch_process();
			} else {
				return drush_set_error( 'File processing did not generate any items to process.' );
			}
		} else {
			return drush_set_error( 'Import file last modified is older or same as last import file : '.$config_last_imported );
		}
	} 
}


/**
* Set and process a ONEOFF PIMS batch job with drush.
*
*/
function drush_ou_profile_oneoffpimsimport()
{
	//Get pims filename from the config page /admin/config/system/ou_profile
	$filepath = variable_get('ou_profile_pims_preproc_path', '/drupalshared/interface_files');
	$pims_file = $filepath.'/PIMS.txt';
	$error = FALSE;
	
	//Check that the files exist
	if( !file_exists( $pims_file ) )
	{
		drush_print( 'PIMs import file not found : '.$pims_file );
		$error = TRUE;
	}

	//If the files exists...
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
			drush_print( 'Valid PIMs import file detected. Initiating import.' );
			$batch = array();
			
			$module_path = drupal_get_path('module', 'ou_profile');
			require_once $module_path.'/cron/ou_profile.import.pims_oneoff.inc';
			oneoff_pims_import_initialise( 'drush', $batch );
			if( !empty( $batch ) )
			{
				$batch['progressive'] = FALSE;
				batch_set($batch);
				// Process the batch.
				drush_backend_batch_process();
			} else {
				return drush_set_error( 'File processing did not generate any items to process.' );
			}
		} else {
			return drush_set_error( 'Import file last modified is older or same as last import file : '.$config_last_imported );
		}
	} 
}


/**
* Set and process a ONEOFF PIMS batch job with drush.
*
*/
function drush_ou_profile_oneoffpimsimportunits()
{
	//Get pims filename from the config page /admin/config/system/ou_profile
	$filepath = variable_get('ou_profile_pims_preproc_path', '/drupalshared/interface_files');
	$pims_file = $filepath.'/PIMS.txt';
	$error = FALSE;
	
	//Check that the files exist
	if( !file_exists( $pims_file ) )
	{
		drush_print( 'PIMs import file not found : '.$pims_file );
		$error = TRUE;
	}

	//If the files exists...
	if( !$error )
	{

		drush_print( 'Valid PIMs import file detected. Initiating OU Units import.' );

		$module_path = drupal_get_path('module', 'ou_profile');
		
		//PIMs import functions
		require_once $module_path.'/cron/ou_profile.import.pims_oneoff.inc';
		oneoff_pims_import_initialise_units( 'batch' );
	} 
}
