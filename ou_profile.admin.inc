<?php

/**
* Implementation of hook_menu().
*
* People profile administration form link in /admin/config/system/ou_profile
*/
function ou_profile_menu()
{
	$items = array();
	$items['admin/config/system/ou_profile'] = array(
		'title' => t('OU Profile Settings'),
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
 * @param unknown_type $form_state
 */
function _config_form( $form_state )
{
	//PIMS IMPORT FIELDS
	$form['ou_profile_pims_import_settings'] = array(
		'#type'  => 'fieldset',
		'#title' => t('PIMs import settings'),
	);
	$form['ou_profile_pims_import_settings']['ou_profile_pims_filename'] = array(
		'#type'          => 'textfield',
		'#title'         => t('PIMs filename'),
		'#default_value' => variable_get('ou_profile_pims_filename', 'sites/all/modules/custom/people-profile/cron/data/pims.txt'),
		'#description'   => t('The PIMs import file name.'),
	);  
	$form['ou_profile_pims_import_settings']['ou_profile_pims_import'] = array(
		'#type'          => 'checkbox',
		'#title'         => t('Force import on submit'),
		'#default_value' => variable_get('ou_profile_pims_import', 0),
		'#description'   => t('If you submit this form with this checked, the import process will be started. The "Import file date" is ignored.'),
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
		$form['ou_profile_pims_import_settings']['ou_profile_pims_import_log']['ou_profile_pims_import_cron_runs'] = array(
			'#type'          => 'textfield',
			'#title'         => t('Cron runs : '),
			'#default_value' => variable_get('ou_profile_pims_import_cron_runs', 0),
			'#description'   => t('How many times cron had run on this queue.'),
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
function _config_form_submit($form, &$form_state) {

  //Get the administration form fields
  $form_fields = $form_state['values'];
  
  //Save the form values
  //PIMS
  variable_set( 'ou_profile_pims_filename', $form_fields['ou_profile_pims_filename'] );
  variable_set('ou_profile_pims_import_file_mod', $form_fields['ou_profile_pims_import_file_mod'] );

  //RPS GROUPS
  variable_set( 'ou_profile_rps_groups_filename', $form_fields['ou_profile_rps_groups_filename'] );
  variable_set('ou_profile_rps_groups_import_file_mod', $form_fields['ou_profile_rps_groups_import_file_mod'] );

  //RPS PROJECTS
  variable_set( 'ou_profile_rps_projects_filename', $form_fields['ou_profile_rps_projects_filename'] );
  variable_set('ou_profile_rps_projects_import_file_mod', $form_fields['ou_profile_rps_projects_import_file_mod'] );
  
  //Check if import was requested, 1 = yes
  if( $form_fields['ou_profile_pims_import'] == 1 )
  {
    //Set the import dates
    _pims_import_initialise( 'user_import' );

    // Set the finish time & tell the user
    drupal_set_message(t('Configuration settings saved. PIMs data reloaded.'));

  } else {
    drupal_set_message(t('Configuration settings saved.'));
  }
}

