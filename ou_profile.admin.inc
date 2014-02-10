<?php
/**
 * @file
 * Functions for OU Profiles Admin form at /admin/config/system/ou_profile
 *
 */



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
		'#description'   => t('THIS IS A ONE-OFF PROCESS THAT WILL FORCE A **FULL IMPORT OF PIMS.TXT VIA THE BATCH PROCESS. If you submit this form with this checked, the import process will be started. The "Import file date" is ignored.'),
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

/*

SK - Started work on admin form, but found that RPS data would not be avaliable. On back burner until RPS
Data is available. Fields below were just a guess at what I'd need. These will need to be revised once
RPS data is made available.


	//RPS Research Groups IMPORT FIELDS
	$form['ou_profile_rps_groups_import_settings'] = array(
		'#type'  => 'fieldset',
		'#title' => t('RPS Research Groups import settings'),
	);
	$form['ou_profile_rps_groups_import_settings']['ou_profile_rps_groups_filename'] = array(
		'#type'          => 'textfield',
		'#title'         => t('RPS Research Groups filename'),
		'#default_value' => variable_get('ou_profile_rps_groups_filename', 'rps_research_groups_and_centres.csv'),
		'#description'   => t('The RPS Research Groups import file name.'),
	);  
	
		//RPS Research Groups IMPORT LOG
		$form['ou_profile_rps_groups_import_settings']['ou_profile_rps_groups_import_log'] = array(
			'#type'  => 'fieldset',
			'#title' => t('RPS Research Groups import log for last import'),
			'#collapsible'  => TRUE,
			'#collapsed'    => TRUE,
		);
		$form['ou_profile_rps_groups_import_settings']['ou_profile_rps_groups_import_log']['ou_profile_rps_groups_import_file_mod'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Import file date: '),
			'#default_value' => variable_get('ou_profile_rps_groups_import_file_mod', ''),
			'#description'   => t('Modified date of last import file. Modified date of import file must be greater than this to initiate cron import. Blank this value to force cron to import the file on the next run.'),
		);
		$form['ou_profile_rps_groups_import_settings']['ou_profile_rps_groups_import_log']['ou_profile_rps_groups_import_start'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Last import started : '),
			'#default_value' => variable_get('ou_profile_rps_groups_import_start', ''),
			'#description'   => t('When the last import started.'),
			'#attributes' => array(
				'readonly'=>'readonly',
				'style'=>'background: none repeat scroll 0 0 #EAEAEA;'
			),
		);
		$form['ou_profile_rps_groups_import_settings']['ou_profile_rps_groups_import_log']['ou_profile_rps_groups_import_finish'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Last import finished : '),
			'#default_value' => variable_get('ou_profile_rps_groups_import_finish', ''),
			'#description'   => t('When the last import finished.'),
			'#attributes' => array(
				'readonly'=>'readonly',
				'style'=>'background: none repeat scroll 0 0 #EAEAEA;'
			),
		);
		$form['ou_profile_rps_groups_import_settings']['ou_profile_rps_groups_import_log']['ou_profile_rps_groups_import_deletions'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Deletions : '),
			'#default_value' => variable_get('ou_profile_rps_groups_import_deletions', ''),
			'#attributes' => array(
				'readonly'=>'readonly',
				'style'=>'background: none repeat scroll 0 0 #EAEAEA;'
			),
		);
		$form['ou_profile_rps_groups_import_settings']['ou_profile_rps_groups_import_log']['ou_profile_rps_groups_import_creations'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Creations : '),
			'#default_value' => variable_get('ou_profile_rps_groups_import_creations', ''),
			'#attributes' => array(
				'readonly'=>'readonly',
				'style'=>'background: none repeat scroll 0 0 #EAEAEA;'
			),
		);
		$form['ou_profile_rps_groups_import_settings']['ou_profile_rps_groups_import_log']['ou_profile_rps_groups_import_updates'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Updates : '),
			'#default_value' => variable_get('ou_profile_rps_groups_import_updates', ''),
			'#attributes' => array(
				'readonly'=>'readonly',
				'style'=>'background: none repeat scroll 0 0 #EAEAEA;'
			),
		);



	//RPS Research Projects IMPORT FIELDS
	$form['ou_profile_rps_projects_import_settings'] = array(
		'#type'  => 'fieldset',
		'#title' => t('RPS Research Projects import settings'),
	);
	$form['ou_profile_rps_projects_import_settings']['ou_profile_rps_projects_filename'] = array(
		'#type'          => 'textfield',
		'#title'         => t('RPS Research Projects filename'),
		'#default_value' => variable_get('ou_profile_rps_projects_filename', 'rps_projects.csv'),
		'#description'   => t('The RPS Research Projects import file name.'),
	);
	
		//RPS Research Projects IMPORT LOG
		$form['ou_profile_rps_projects_import_settings']['ou_profile_rps_projects_import_log'] = array(
			'#type'  => 'fieldset',
			'#title' => t('RPS Research Projects import log for last import'),
			'#collapsible'  => TRUE,
			'#collapsed'    => TRUE,
		);
		$form['ou_profile_rps_projects_import_settings']['ou_profile_rps_projects_import_log']['ou_profile_rps_projects_import_file_mod'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Import file date: '),
			'#default_value' => variable_get('ou_profile_rps_projects_import_file_mod', ''),
			'#description'   => t('Modified date of last import file. Modified date of import file must be greater than this to initiate cron import. Blank this value to force cron to import the file on the next run.'),
		);
		$form['ou_profile_rps_projects_import_settings']['ou_profile_rps_projects_import_log']['ou_profile_rps_projects_import_start'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Last import started : '),
			'#default_value' => variable_get('ou_profile_rps_projects_import_start', ''),
			'#description'   => t('When the last import started.'),
			'#attributes' => array(
				'readonly'=>'readonly',
				'style'=>'background: none repeat scroll 0 0 #EAEAEA;'
			),
		);
		$form['ou_profile_rps_projects_import_settings']['ou_profile_rps_projects_import_log']['ou_profile_rps_projects_import_finish'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Last import finished : '),
			'#default_value' => variable_get('ou_profile_rps_projects_import_finish', ''),
			'#description'   => t('When the last import finished.'),
			'#attributes' => array(
				'readonly'=>'readonly',
				'style'=>'background: none repeat scroll 0 0 #EAEAEA;'
			),
		);
		$form['ou_profile_rps_projects_import_settings']['ou_profile_rps_projects_import_log']['ou_profile_rps_projects_import_deletions'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Deletions : '),
			'#default_value' => variable_get('ou_profile_rps_projects_import_deletions', ''),
			'#attributes' => array(
				'readonly'=>'readonly',
				'style'=>'background: none repeat scroll 0 0 #EAEAEA;'
			),
		);
		$form['ou_profile_rps_projects_import_settings']['ou_profile_rps_projects_import_log']['ou_profile_rps_projects_import_creations'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Creations : '),
			'#default_value' => variable_get('ou_profile_rps_projects_import_creations', ''),
			'#attributes' => array(
				'readonly'=>'readonly',
				'style'=>'background: none repeat scroll 0 0 #EAEAEA;'
			),
		);
		$form['ou_profile_rps_projects_import_settings']['ou_profile_rps_projects_import_log']['ou_profile_rps_projects_import_updates'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Updates : '),
			'#default_value' => variable_get('ou_profile_rps_projects_import_updates', ''),
			'#attributes' => array(
				'readonly'=>'readonly',
				'style'=>'background: none repeat scroll 0 0 #EAEAEA;'
			),
		);

*/

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
	
	/*

	//*** SEE RPS COMMENTS ABOVE IN THE FORM

	//RPS GROUPS
	variable_set( 'ou_profile_rps_groups_filename', $form_fields['ou_profile_rps_groups_filename'] );
	variable_set('ou_profile_rps_groups_import_file_mod', $form_fields['ou_profile_rps_groups_import_file_mod'] );

	//RPS PROJECTS
	variable_set( 'ou_profile_rps_projects_filename', $form_fields['ou_profile_rps_projects_filename'] );
	variable_set('ou_profile_rps_projects_import_file_mod', $form_fields['ou_profile_rps_projects_import_file_mod'] );
	*/

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

