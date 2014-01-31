<?php

function ou_profile_client_config()
{
	$form = drupal_get_form('ou_profile_client_config_form');
	return t('OU Profile Import') . drupal_render($form);
}

/**
 * Builds the form to allow admin to force import of profiles into client site
 * @param unknown_type $form_state
 */
function ou_profile_client_config_form($form_state)
{

	$form['ou_profile_client_import_finish'] = array(
		'#type'          => 'textfield',
		'#title'         => t('Last import finished : '),
		'#default_value' => variable_get('ou_profile_client_import_finish', ''),
		'#description'   => t('Next automatic import will be at least 24 hours after this time. Use checkbox below to perform an immediate import.'),
		'#attributes'    => array(
			'readonly'   =>'readonly',
			'style'      =>'background: none repeat scroll 0 0 #EAEAEA;'
		),
	);
	$form['ou_profile_client_profile_import'] = array(
		'#type'          => 'checkbox',
		'#title'         => t('Force import on submit'),
		'#default_value' =>  0,
		'#description'   => t('If you submit this form with this checked, the import process will be started.'),
	);
	$form['ou_profile_reporting'] = array(
		'#type'          => 'textfield',
		'#title'         => t('Module logging level'),
		'#default_value' => variable_get('ou_profile_reporting', '-1'),
		'#description'   => t('Sets the level of module logging for debugging. -1 for none, 3 to log all msgs, 4 to output to screen'),
		'#size'         => '10',
	);
	$form['ou_profile_client_profile_categories'] = array(
		'#type'  => 'fieldset',
		'#title' => t('Profile categories'),
	);

	$form['ou_profile_client_profile_categories']['ou_profile_client_profile_taxonomy'] = array(
		'#type'          => 'textarea',
		'#title'         => t('Profile taxonomy'),
		'#default_value' => variable_get('ou_profile_client_profile_taxonomy', ''),
		'#cols'          => 60,
		'#rows'          => 5,
		'#description'   => t('Profile taxonomy entries compiled from imported profiles. It is recreated on each import cycle. Separate each value with newline.'),
	); 

	$form['ou_profile_client_profile_categories']['ou_profile_client_pims_units'] = array(
		'#type'          => 'textarea',
		'#title'         => t('PIMs units'),
		'#default_value' => variable_get('ou_profile_client_pims_units', ''),
		'#cols'          => 60,
		'#rows'          => 5,
		'#description'   => t('PIMs unit entries compiled from imported profiles. It is recreated on each import cycle. Separate each value with newline.'),
	); 

	$form['ou_profile_client_profile_categories']['ou_profile_client_pims_job_title'] = array(
		'#type'          => 'textarea',
		'#title'         => t('PIMs job titles'),
		'#default_value' => variable_get('ou_profile_client_pims_job_title', ''),
		'#cols'          => 60,
		'#rows'          => 5,
		'#description'   => t('PIMs job title entries compiled from imported profiles. It is recreated on each import cycle. Separate each value with newline.'),
	); 

	//Form submit processing
	$form['submit'] = array('#type' => 'submit', '#value' => t('Save'));
	return $form;

}

/**
 * Implements hook_form_submit().
 *
 * @param unknown_type $form
 * @param unknown_type $form_state
 */
function ou_profile_client_config_form_submit($form, &$form_state)
{
	//Get the administration form fields
	$form_fields = $form_state['values'];
	variable_set( 'ou_profile_reporting', $form_fields['ou_profile_reporting'] );
	variable_set( 'ou_profile_client_profile_taxonomy', trim( $form_fields['ou_profile_client_profile_taxonomy'] ) );
	variable_set( 'ou_profile_client_pims_units', trim( $form_fields['ou_profile_client_pims_units'] ) );
	variable_set( 'ou_profile_client_pims_job_title', trim( $form_fields['ou_profile_client_pims_job_title'] ) );
	
	//Check if import was requested, 1 = yes
	if( $form_fields['ou_profile_client_profile_import'] == 1 )
	{
		//Start batch import
		ou_profile_client_batch_import();

		// Set the finish time & tell the user
		drupal_set_message(t('Profile data reloaded.'));
	}

	drupal_set_message(t('Configuration settings saved.'));
	
}
