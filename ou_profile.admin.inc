<?php
/**
 * @file
 * Functions for OU Profiles Admin form at /admin/config/system/ou_profile
 *
 */


/**
* Implementation of hook_menu().
*
*/
function ou_profile_menu()
{
	$items = array();

	//People profile administration form link in /admin/config/system/ou_profile
	$items['admin/config/system/ou_profile'] = array(
		'title' => t('People Profile Server Settings'),
		'description' => t('Manage People Profiles server settings and data imports'),
		'page callback' => 'drupal_get_form',
		'page arguments'   => array('_config_form'),
		'access arguments' => array('administer data load'),
		'type' => MENU_NORMAL_ITEM,
	);
	return $items;
}


/**
 * Builds the administration form to allow users to configure the PIMs import
 * 
 */
function _config_form( $form_state )
{
	//PIMS IMPORT FIELDS
	$form['ou_profile_pims_import_settings'] = array(
		'#type'  => 'fieldset',
		'#title' => t('PIMs import settings'),
	);
	
	$form['ou_profile_pims_import_settings']['ou_profile_pims_preproc_path'] = array(
		'#type'          => 'textfield',
		'#title'         => t('PIMs import filepath'),
		'#default_value' => variable_get('ou_profile_pims_preproc_path', '/drupalshared/interface_files'),
		'#description'   => t('File path for the all_staff_ids.txt, new_staff_updates.txt, pims_previous.txt & pims_pp_imported.txt.'),
		'#size'         => '100',
	); 
	$form['ou_profile_pims_import_settings']['ou_profile_pims_import'] = array(
		'#type'          => 'checkbox',
		'#title'         => t('Force import on submit'),
		'#default_value' =>  0,
		'#description'   => t('If you submit this form with this checked, the import process will be started. The "Import file date" is ignored.'),
	);
	$form['ou_profile_pims_import_settings']['ou_profile_oneoff_pims_import'] = array(
		'#type'          => 'checkbox',
		'#title'         => t('ONE-OFF : Force import on submit'),
		'#default_value' =>  0,
		'#description'   => t('THIS IS A ONE-OFF PROCESS THAT WILL FORCE A **IMPORT OF PIMS.TXT VIA THE BATCH PROCESS. If you submit this form with this checked, the import process will be started. The "Import file date" is ignored. NOTE : The OU Units data should be imported first via drush.'),
	);
	$form['ou_profile_pims_import_settings']['ou_profile_pims_default_public'] = array(
		'#type'          => 'textfield',
		'#title'         => t('Public staff profiles'),
		'#default_value' => variable_get('ou_profile_pims_default_public', 'PACC,PARG,PARS,PVRS'),
		'#description'   => t('Enter a comma separated list of staff role codes that should have a public profile by default.<br /> (E.g. PACC,PARG,PARS,PREL,PSEC,PVIS,PLTC,PRTC)'),
		'#size'         => '100',
	);
	$form['ou_profile_pims_import_settings']['ou_profile_public_tids'] = array(
		'#type'          => 'textfield',
		'#title'         => t('Public staff profiles taxonomy IDs'),
		'#default_value' => variable_get('ou_profile_public_tids', ''),
		'#description'   => t('Enter a comma separated list of taxonomy TIDs from "Profile Taxonomy" (E.g. 1,4,6). Public profiles will be assigned these TIDs by default. The list should map the role codes above. i.e. first TID should be for the first value in the list.'),
		'#size'         => '100',
	);
	$form['ou_profile_pims_import_settings']['ou_profile_profiles_public'] = array(
		'#type'          => 'checkbox',
		'#title'         => t('Force profiles to public on submit.'),
		'#default_value' => 0,
		'#description'   => t('If you submit this form with this checked, it will set profiles with above role codes to public.'),
	);
	$form['ou_profile_pims_import_settings']['ou_profile_reporting'] = array(
		'#type'          => 'textfield',
		'#title'         => t('Module logging level'),
		'#default_value' => variable_get('ou_profile_reporting', '-1'),
		'#description'   => t('Sets the level of module logging for debugging. -1 for none, 3 to log all msgs, 4 to output to screen'),
		'#size'         => '10',
	);
	
		//PIMS IMPORT LOG
		$form['ou_profile_pims_import_settings']['ou_profile_pims_import_log'] = array(
			'#type'  => 'fieldset',
			'#title' => t('PIMs import log for last import'),
			'#collapsible'  => TRUE,
			'#collapsed'    => TRUE,
		);
		$form['ou_profile_pims_import_settings']['ou_profile_pims_import_log']['ou_profile_pims_import_file_mod'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Import file date: '),
			'#default_value' => variable_get('ou_profile_pims_import_file_mod', ''),
			'#description'   => t('Modified date of last import file. Modified date of import file must be greater than this to initiate cron import. Blank this value to force cron to import the file on the next run.'),
		);
		$form['ou_profile_pims_import_settings']['ou_profile_pims_import_log']['ou_profile_pims_import_start'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Last import started : '),
			'#default_value' => variable_get('ou_profile_pims_import_start', ''),
			'#description'   => t('When the last import started.'),
			'#attributes' => array(
				'readonly'=>'readonly',
				'style'=>'background: none repeat scroll 0 0 #EAEAEA;'
			),
		);
		$form['ou_profile_pims_import_settings']['ou_profile_pims_import_log']['ou_profile_pims_import_queue_size'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Queue size : '),
			'#default_value' => variable_get('ou_profile_pims_import_queue_size', 0),
			'#description'   => t('How many entries remain in the queue.'),
			'#attributes' => array(
				'readonly'=>'readonly',
				'style'=>'background: none repeat scroll 0 0 #EAEAEA;'
			),
		);
		$form['ou_profile_pims_import_settings']['ou_profile_pims_import_log']['ou_profile_pims_import_progress'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Processed : '),
			'#default_value' => variable_get('ou_profile_pims_import_processed', 0),
			'#description'   => t('How many entries have been processed.'),
			'#attributes' => array(
				'readonly'=>'readonly',
				'style'=>'background: none repeat scroll 0 0 #EAEAEA;'
			),
		);
		$form['ou_profile_pims_import_settings']['ou_profile_pims_import_log']['ou_profile_pims_import_finish'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Last import finished : '),
			'#default_value' => variable_get('ou_profile_pims_import_finish', ''),
			'#description'   => t('When the last import finished.'),
			'#attributes' => array(
				'readonly'=>'readonly',
				'style'=>'background: none repeat scroll 0 0 #EAEAEA;'
			),
		);
		$form['ou_profile_pims_import_settings']['ou_profile_pims_import_log']['ou_profile_pims_import_deletions'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Deletions : '),
			'#default_value' => variable_get('ou_profile_pims_import_deletions', ''),
			'#attributes' => array(
				'readonly'=>'readonly',
				'style'=>'background: none repeat scroll 0 0 #EAEAEA;'
			),
		);
		$form['ou_profile_pims_import_settings']['ou_profile_pims_import_log']['ou_profile_pims_import_creations'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Creations : '),
			'#default_value' => variable_get('ou_profile_pims_import_creations', ''),
			'#attributes' => array(
				'readonly'=>'readonly',
				'style'=>'background: none repeat scroll 0 0 #EAEAEA;'
			),
		);
		$form['ou_profile_pims_import_settings']['ou_profile_pims_import_log']['ou_profile_pims_import_updates'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Updates : '),
			'#default_value' => variable_get('ou_profile_pims_import_updates', ''),
			'#attributes' => array(
				'readonly'=>'readonly',
				'style'=>'background: none repeat scroll 0 0 #EAEAEA;'
			),
		);

	//Form submit processing
	$form['submit'] = array('#type' => 'submit', '#value' => t('Save'));
	return $form;

}


/**
 * Processes the administration form "_config_form" when submitted
 *
 * @param unknown_type $form
 * @param unknown_type $form_state
 */
function _config_form_submit($form, &$form_state)
{

	//Get the administration form fields
	$form_fields = $form_state['values'];

	//Save the form values
	//variable_set( 'ou_profile_pims_filename', $form_fields['ou_profile_pims_filename'] );
	variable_set( 'ou_profile_pims_preproc_path', $form_fields['ou_profile_pims_preproc_path'] );
	variable_set( 'ou_profile_pims_import_file_mod', $form_fields['ou_profile_pims_import_file_mod'] );
	variable_set( 'ou_profile_pims_default_public', strtoupper( $form_fields['ou_profile_pims_default_public'] ) );
	variable_set( 'ou_profile_public_tids', $form_fields['ou_profile_public_tids'] );
	variable_set( 'ou_profile_reporting', $form_fields['ou_profile_reporting'] );
	
	//Check if one-off import of pims.txt was requested
	if( $form_fields['ou_profile_oneoff_pims_import'] == 1 )
	{
		$module_path = drupal_get_path('module', 'ou_profile');
		
		//PIMs import functions
		require_once $module_path.'/cron/ou_profile.import.pims_oneoff.inc';
		oneoff_pims_import_initialise( 'batch' );
	}

	//Check if force public was requested, 1 = yes
	//(This is intended as a one-off process to be run after FELs import.)
	if( $form_fields['ou_profile_profiles_public'] == 1 )
	{
		_ou_profile_profiles_public( strtoupper( $form_fields['ou_profile_pims_default_public'] ) );
	}

	//Check if import was requested, 1 = yes
	if( $form_fields['ou_profile_pims_import'] == 1 )
	{
		//Set the import dates
		_pims_import_initialise( 'batch' );

		// Tell the user
		drupal_set_message(t('PIMs data reloaded.'));
	}

	drupal_set_message(t('Configuration settings saved.'));

}

?>