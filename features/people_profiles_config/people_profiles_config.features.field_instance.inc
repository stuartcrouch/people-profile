<?php
/**
 * @file
 * people_profiles_config.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function people_profiles_config_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-allowed_sites-field_media_expertise'
  $field_instances['node-allowed_sites-field_media_expertise'] = array(
    'bundle' => 'allowed_sites',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use the "Ctrl" key to make multiple selections.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_media_expertise',
    'label' => 'Media Expertise',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-allowed_sites-field_ou_unit_ref'
  $field_instances['node-allowed_sites-field_ou_unit_ref'] = array(
    'bundle' => 'allowed_sites',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The OU unit / department that this site is hosting. This is ignored if the allowed site is the profiles server (path = /people/)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 0,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ou_unit_ref',
    'label' => 'Unit ref',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 0,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
    'widget_type' => 'nodereference_select',
  );

  // Exported field_instance: 'node-allowed_sites-field_profile_taxonomy'
  $field_instances['node-allowed_sites-field_profile_taxonomy'] = array(
    'bundle' => 'allowed_sites',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use the "Ctrl" key to make multiple selections.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_profile_taxonomy',
    'label' => 'Profile Taxonomy',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-allowed_sites-field_site_path'
  $field_instances['node-allowed_sites-field_site_path'] = array(
    'bundle' => 'allowed_sites',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_site_path][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter the path name of the drupal site including all preceding and trailing slashes. e.g. /mbaopen/',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_site_path',
    'label' => 'Site path',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 3,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-allowed_sites-field_site_visibility'
  $field_instances['node-allowed_sites-field_site_visibility'] = array(
    'bundle' => 'allowed_sites',
    'default_value' => array(
      0 => array(
        'value' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'Is this a public website, or an intranet?',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_site_visibility',
    'label' => 'Site visibility',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 4,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_buttons',
      'weight' => 5,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );

  // Exported field_instance: 'node-ou_unit-field_unit_code'
  $field_instances['node-ou_unit-field_unit_code'] = array(
    'bundle' => 'ou_unit',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_unit_code][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_unit_code',
    'label' => 'Unit code',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-ou_unit-field_unit_level'
  $field_instances['node-ou_unit-field_unit_level'] = array(
    'bundle' => 'ou_unit',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => 0,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_unit_level',
    'label' => 'Unit level',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-ou_unit-field_unit_name_lv1'
  $field_instances['node-ou_unit-field_unit_name_lv1'] = array(
    'bundle' => 'ou_unit',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_unit_name_lv1',
    'label' => 'Unit name lv1',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-ou_unit-field_unit_name_lv2'
  $field_instances['node-ou_unit-field_unit_name_lv2'] = array(
    'bundle' => 'ou_unit',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_unit_name_lv2',
    'label' => 'Unit name lv2',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-ou_unit-field_unit_name_lv3'
  $field_instances['node-ou_unit-field_unit_name_lv3'] = array(
    'bundle' => 'ou_unit',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_unit_name_lv3',
    'label' => 'Unit name lv3',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-ou_unit-field_unit_name_lv4'
  $field_instances['node-ou_unit-field_unit_name_lv4'] = array(
    'bundle' => 'ou_unit',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_unit_name_lv4',
    'label' => 'Unit name lv4',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-pims-field_pims_appt_job_title'
  $field_instances['node-pims-field_pims_appt_job_title'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_appt_job_title][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_appt_job_title',
    'label' => 'Appt job title',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 28,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-pims-field_pims_appt_role_code'
  $field_instances['node-pims-field_pims_appt_role_code'] = array(
    'bundle' => 'pims',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_appt_role_code',
    'label' => 'Appt Role Code',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'node-pims-field_pims_appt_role_desc'
  $field_instances['node-pims-field_pims_appt_role_desc'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_appt_role_desc][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_appt_role_desc',
    'label' => 'Appt Role Desc',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 38,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-pims-field_pims_l1_estab_unit_code'
  $field_instances['node-pims-field_pims_l1_estab_unit_code'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_l1_estab_unit_code][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_l1_estab_unit_code',
    'label' => 'Level 1 Establishment Unit code',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 36,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-pims-field_pims_l1_estab_unit_desc'
  $field_instances['node-pims-field_pims_l1_estab_unit_desc'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_l1_estab_unit_desc][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_l1_estab_unit_desc',
    'label' => 'Level 1 Establishment Unit Desc',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 35,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-pims-field_pims_l2_estab_unit_code'
  $field_instances['node-pims-field_pims_l2_estab_unit_code'] = array(
    'bundle' => 'pims',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_l2_estab_unit_code',
    'label' => 'Level 2 Establishment Unit code',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 41,
    ),
  );

  // Exported field_instance: 'node-pims-field_pims_l2_estab_unit_name'
  $field_instances['node-pims-field_pims_l2_estab_unit_name'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_l2_estab_unit_name][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_l2_estab_unit_name',
    'label' => 'Level 2 Establishment Unit name',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 40,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-pims-field_pims_l3_estab_unit_code'
  $field_instances['node-pims-field_pims_l3_estab_unit_code'] = array(
    'bundle' => 'pims',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_l3_estab_unit_code',
    'label' => 'Level 3 Establishment Unit code',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 44,
    ),
  );

  // Exported field_instance: 'node-pims-field_pims_l3_estab_unit_name'
  $field_instances['node-pims-field_pims_l3_estab_unit_name'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_l3_estab_unit_name][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 17,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_l3_estab_unit_name',
    'label' => 'Level 3 Establishment Unit name',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 43,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-pims-field_pims_l4_estab_unit_code'
  $field_instances['node-pims-field_pims_l4_estab_unit_code'] = array(
    'bundle' => 'pims',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_l4_estab_unit_code',
    'label' => 'Level 4 Establishment Unit code',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 46,
    ),
  );

  // Exported field_instance: 'node-pims-field_pims_l4_estab_unit_name'
  $field_instances['node-pims-field_pims_l4_estab_unit_name'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_l4_estab_unit_name][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 19,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_l4_estab_unit_name',
    'label' => 'Level 4 Establishment Unit name',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 45,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-pims-field_pims_ou_email_address'
  $field_instances['node-pims-field_pims_ou_email_address'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_ou_email_address][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_ou_email_address',
    'label' => 'OU email address',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 39,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-pims-field_pims_oucu'
  $field_instances['node-pims-field_pims_oucu'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_oucu][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_oucu',
    'label' => 'OUCU',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 42,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-pims-field_pims_personal_website'
  $field_instances['node-pims-field_pims_personal_website'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_personal_website][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 21,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_personal_website',
    'label' => 'Personal Website',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 34,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-pims-field_pims_pref_forenames'
  $field_instances['node-pims-field_pims_pref_forenames'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_pref_forenames][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 34,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 34,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 34,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 34,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_pref_forenames',
    'label' => 'Preferred Staff Forenames',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 34,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 48,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-pims-field_pims_pref_surname'
  $field_instances['node-pims-field_pims_pref_surname'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_pref_surname][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_pref_surname',
    'label' => 'Preferred Staff Surname',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 27,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-pims-field_pims_staff_forenames'
  $field_instances['node-pims-field_pims_staff_forenames'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_staff_forenames][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_staff_forenames',
    'label' => 'Staff Forenames',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 29,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-pims-field_pims_staff_id'
  $field_instances['node-pims-field_pims_staff_id'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_staff_id][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_staff_id',
    'label' => 'Staff ID',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 33,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-pims-field_pims_staff_initials'
  $field_instances['node-pims-field_pims_staff_initials'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_staff_initials][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_staff_initials',
    'label' => 'Staff initials',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 30,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-pims-field_pims_staff_surname'
  $field_instances['node-pims-field_pims_staff_surname'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_staff_surname][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_staff_surname',
    'label' => 'Staff Surname',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 32,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-pims-field_pims_staff_title'
  $field_instances['node-pims-field_pims_staff_title'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_staff_title][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_staff_title',
    'label' => 'Staff title',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 7,
      ),
      'type' => 'text_textfield',
      'weight' => 31,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-pims-field_pims_unique_id'
  $field_instances['node-pims-field_pims_unique_id'] = array(
    'bundle' => 'pims',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_unique_id][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'This is a concatenation of staffid + L1 + L2 + L3 + L4 unit codes',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 33,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 33,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 33,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 33,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pims_unique_id',
    'label' => 'PIMS unique ID (computed)',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 33,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 47,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_media_expertise'
  $field_instances['node-profile-field_media_expertise'] = array(
    'bundle' => 'profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use the "Ctrl" key to make multiple selections.<br>
This is one of the criteria that can be used to determine sites your profile will appear upon. It is not displayed on your profile.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 132,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_media_expertise',
    'label' => 'Media Expertise',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 152,
    ),
  );

  // Exported field_instance: 'node-profile-field_oup_alternative_email'
  $field_instances['node-profile-field_oup_alternative_email'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'email' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter an alternative Open University Email address if you have one.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 110,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 110,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 110,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 110,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 110,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_alternative_email',
    'label' => 'Alternative Email address',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 110,
    'widget' => array(
      'active' => 0,
      'module' => 'email',
      'settings' => array(
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 202,
    ),
    'widget_type' => 'email_textfield',
  );

  // Exported field_instance: 'node-profile-field_oup_blog'
  $field_instances['node-profile-field_oup_blog'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'title' => '',
        'url' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'Add a link to your main blog here and if you have any more blogs to your name add them as other web links',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 81,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 81,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 81,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 81,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 81,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_blog',
    'label' => 'Blog',
    'required' => FALSE,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'title' => '',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'weight' => 81,
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'link_field',
      'weight' => 84,
    ),
    'widget_type' => 'link',
  );

  // Exported field_instance: 'node-profile-field_oup_expertise'
  $field_instances['node-profile-field_oup_expertise'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_oup_expertise][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Pick keywords/phrases that best describe your areas of expertise. If a keyword/phrase is not there please contact your information officer to get it added
',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_expertise',
    'label' => 'Areas of expertise',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 83,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 211,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_oup_flickr'
  $field_instances['node-profile-field_oup_flickr'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'title' => '',
        'url' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'Include a relevant flickr page here',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 87,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 87,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 87,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 87,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 87,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_flickr',
    'label' => 'Flickr page',
    'required' => FALSE,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'title' => '',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'weight' => 87,
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'link_field',
      'weight' => 91,
    ),
    'widget_type' => 'link',
  );

  // Exported field_instance: 'node-profile-field_oup_job_title'
  $field_instances['node-profile-field_oup_job_title'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_oup_job_title][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 106,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 106,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 106,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 106,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 106,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_job_title',
    'label' => 'Unabbreviated job title',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 106,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 201,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_oup_letters'
  $field_instances['node-profile-field_oup_letters'] = array(
    'bundle' => 'profile',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 102,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 102,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 102,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 102,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 102,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_letters',
    'label' => 'Letters after name',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 102,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'rows' => NULL,
        'size' => NULL,
      ),
      'type' => 'text_textfield',
      'weight' => 200,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_oup_linkedin'
  $field_instances['node-profile-field_oup_linkedin'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'title' => '',
        'url' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 89,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 89,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 89,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 89,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 89,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_linkedin',
    'label' => 'LinkedIn profile',
    'required' => FALSE,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'title' => 'value',
      'title_maxlength' => 128,
      'title_value' => 'LinkedIn profile page',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'weight' => 89,
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'link_field',
      'weight' => 88,
    ),
    'widget_type' => 'link',
  );

  // Exported field_instance: 'node-profile-field_oup_media_relations_bio'
  $field_instances['node-profile-field_oup_media_relations_bio'] = array(
    'bundle' => 'profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 133,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_media_relations_bio',
    'label' => 'Media relations biography',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 153,
    ),
  );

  // Exported field_instance: 'node-profile-field_oup_openlearn_bio'
  $field_instances['node-profile-field_oup_openlearn_bio'] = array(
    'bundle' => 'profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 134,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_openlearn_bio',
    'label' => 'OpenLearn biography',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 210,
    ),
  );

  // Exported field_instance: 'node-profile-field_oup_oubs_internatl_collabs'
  $field_instances['node-profile-field_oup_oubs_internatl_collabs'] = array(
    'bundle' => 'profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Write about any type of international collaboration',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 89,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 89,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 89,
      ),
      'search_index' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 89,
      ),
      'search_result' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 89,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 89,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 89,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_oubs_internatl_collabs',
    'label' => 'International links',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 89,
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 210,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-profile-field_oup_oubs_public_esteem'
  $field_instances['node-profile-field_oup_oubs_public_esteem'] = array(
    'bundle' => 'profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Include items such as journal editorships, important consulting work, membership of important committees, honours, awards and prestigious posts',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 87,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 87,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 87,
      ),
      'search_index' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 87,
      ),
      'search_result' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 87,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 87,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 87,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_oubs_public_esteem',
    'label' => 'External contributions',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 87,
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 209,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-profile-field_oup_oubs_research_impact'
  $field_instances['node-profile-field_oup_oubs_research_impact'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_oup_oubs_research_impact][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Include here the impact of your research such as consultancy, policy advice, media coverage etc',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 85,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 85,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 85,
      ),
      'search_index' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 85,
      ),
      'search_result' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 85,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 85,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 85,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_oubs_research_impact',
    'label' => 'Impact and engagement',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 85,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 208,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-profile-field_oup_oucu'
  $field_instances['node-profile-field_oup_oucu'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_oup_oucu][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 71,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 71,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 71,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 71,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 71,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_oucu',
    'label' => 'OUCU',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 71,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_oup_personal_bio'
  $field_instances['node-profile-field_oup_personal_bio'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_oup_personal_bio][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 79,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 79,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 79,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 79,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 79,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_personal_bio',
    'label' => 'Personal Biography',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 79,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 176,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-profile-field_oup_photo'
  $field_instances['node-profile-field_oup_photo'] = array(
    'bundle' => 'profile',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 88,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 88,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 88,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 88,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 88,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_photo',
    'label' => 'Photograph',
    'required' => FALSE,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'photos',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '320x240',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 88,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 175,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-profile-field_oup_profile_layout'
  $field_instances['node-profile-field_oup_profile_layout'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => 'p2cl',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 125,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 125,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 125,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 125,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 125,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_profile_layout',
    'label' => 'Layout',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 125,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 219,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );

  // Exported field_instance: 'node-profile-field_oup_profile_layout_colour'
  $field_instances['node-profile-field_oup_profile_layout_colour'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => 'light',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 129,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 129,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 129,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 129,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 129,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_profile_layout_colour',
    'label' => 'Light / Dark',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 129,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 214,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );

  // Exported field_instance: 'node-profile-field_oup_profile_layout_image'
  $field_instances['node-profile-field_oup_profile_layout_image'] = array(
    'bundle' => 'profile',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 127,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 127,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 127,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 127,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 127,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_profile_layout_image',
    'label' => 'Image',
    'required' => FALSE,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 127,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 215,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-profile-field_oup_research_interests'
  $field_instances['node-profile-field_oup_research_interests'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_oup_research_interests][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_research_interests',
    'label' => 'Research interests',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 83,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 178,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-profile-field_oup_slideshare'
  $field_instances['node-profile-field_oup_slideshare'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'title' => '',
        'url' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'Link to your slideshare account where your presentations may be stored',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 85,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 85,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 85,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 85,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 85,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_slideshare',
    'label' => 'Slideshare',
    'required' => FALSE,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'title' => '',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'weight' => 85,
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'link_field',
      'weight' => 217,
    ),
    'widget_type' => 'link',
  );

  // Exported field_instance: 'node-profile-field_oup_staff_id'
  $field_instances['node-profile-field_oup_staff_id'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_oup_staff_id][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 69,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 69,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 69,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 69,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 69,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_staff_id',
    'label' => 'Staff ID',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 69,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_oup_teaching_interests'
  $field_instances['node-profile-field_oup_teaching_interests'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_oup_teaching_interests][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 81,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 81,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 81,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 81,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 81,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_teaching_interests',
    'label' => 'Teaching interests',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 81,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 177,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-profile-field_oup_twitter'
  $field_instances['node-profile-field_oup_twitter'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_oup_twitter][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_twitter',
    'label' => 'Twitter user name',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 83,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 85,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_oup_visibility'
  $field_instances['node-profile-field_oup_visibility'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '<p>This field is only visible to user 1, but is always over-ridden by the module.  It\'s basically read only. To set this field, use the CCK privacy values below (highest privacy value is applied to this field)</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 70,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 70,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 70,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 70,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 70,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_visibility',
    'label' => 'Profile visibility',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 70,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 5,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );

  // Exported field_instance: 'node-profile-field_oup_web_links'
  $field_instances['node-profile-field_oup_web_links'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'title' => '',
        'url' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter links to relevant websites - e.g. your inaugural lecture',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 91,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 91,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 91,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 91,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 91,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oup_web_links',
    'label' => 'Web links',
    'required' => FALSE,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'title' => '',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'weight' => 91,
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'link_field',
      'weight' => 89,
    ),
    'widget_type' => 'link',
  );

  // Exported field_instance: 'node-profile-field_pdat_appt_job_title'
  $field_instances['node-profile-field_pdat_appt_job_title'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pdat_appt_job_title][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 104,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 104,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 104,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 104,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 104,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pdat_appt_job_title',
    'label' => 'Appt job title ',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 104,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 187,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_pdat_appt_role_desc'
  $field_instances['node-profile-field_pdat_appt_role_desc'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pdat_appt_role_desc][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 120,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 120,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 120,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 120,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 120,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pdat_appt_role_desc',
    'label' => 'Appt Role Desc',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 120,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 193,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_pdat_l1_estab_unit_desc'
  $field_instances['node-profile-field_pdat_l1_estab_unit_desc'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pdat_l1_estab_unit_desc][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 112,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 112,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 112,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 112,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 112,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pdat_l1_estab_unit_desc',
    'label' => 'Level 1 Establishment Unit Desc',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 112,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 184,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_pdat_l2_estab_unit_name'
  $field_instances['node-profile-field_pdat_l2_estab_unit_name'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pdat_l2_estab_unit_name][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 114,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 114,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 114,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 114,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 114,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pdat_l2_estab_unit_name',
    'label' => 'Level 2 Establishment Unit name',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 114,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 185,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_pdat_l3_estab_unit_name'
  $field_instances['node-profile-field_pdat_l3_estab_unit_name'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pdat_l3_estab_unit_name][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 116,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 116,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 116,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 116,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 116,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pdat_l3_estab_unit_name',
    'label' => 'Level 3 Establishment Unit name',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 116,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 186,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_pdat_l4_estab_unit_name'
  $field_instances['node-profile-field_pdat_l4_estab_unit_name'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pdat_l4_estab_unit_name][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 118,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 118,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 118,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 118,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 118,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pdat_l4_estab_unit_name',
    'label' => 'Level 4 Establishment Unit name',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 118,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 186,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_pdat_ou_email_address'
  $field_instances['node-profile-field_pdat_ou_email_address'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pdat_ou_email_address][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 108,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 108,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 108,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 108,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 108,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pdat_ou_email_address',
    'label' => 'OU Email address',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 108,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 188,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_pdat_personal_website'
  $field_instances['node-profile-field_pdat_personal_website'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pdat_personal_website][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 79,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 79,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 79,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 79,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 79,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pdat_personal_website',
    'label' => 'Personal website ',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 79,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 216,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_pdat_pref_forenames'
  $field_instances['node-profile-field_pdat_pref_forenames'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pdat_pref_forenames][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 98,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 98,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 98,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 98,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 98,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pdat_pref_forenames',
    'label' => 'Preferred Staff Forenames',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 98,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 189,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_pdat_pref_surname'
  $field_instances['node-profile-field_pdat_pref_surname'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pdat_pref_surname][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 95,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 95,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 95,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 95,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 95,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pdat_pref_surname',
    'label' => 'Preferred Staff Surname',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 95,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 190,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_pdat_staff_forenames'
  $field_instances['node-profile-field_pdat_staff_forenames'] = array(
    'bundle' => 'profile',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 93,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 93,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 93,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 93,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 93,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pdat_staff_forenames',
    'label' => 'Staff Forenames',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 93,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'rows' => NULL,
        'size' => NULL,
      ),
      'type' => 'text_textfield',
      'weight' => 182,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_pdat_staff_initials'
  $field_instances['node-profile-field_pdat_staff_initials'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pdat_staff_initials][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 100,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 100,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 100,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 100,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 100,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pdat_staff_initials',
    'label' => 'Staff initials',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 100,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 192,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_pdat_staff_surname'
  $field_instances['node-profile-field_pdat_staff_surname'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pdat_staff_surname][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 97,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 97,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 97,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 97,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 97,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pdat_staff_surname',
    'label' => 'Staff Surname',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 97,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 191,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_pdat_staff_title'
  $field_instances['node-profile-field_pdat_staff_title'] = array(
    'bundle' => 'profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 90,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 90,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 90,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 90,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 90,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pdat_staff_title',
    'label' => 'Staff title',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 90,
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 176,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-profile-field_pprv_appt_job_title'
  $field_instances['node-profile-field_pprv_appt_job_title'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 105,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 105,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 105,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 105,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 105,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pprv_appt_job_title',
    'label' => 'Appt job title (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 105,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 188,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_pprv_appt_role_desc'
  $field_instances['node-profile-field_pprv_appt_role_desc'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 121,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 121,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 121,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 121,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 121,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pprv_appt_role_desc',
    'label' => 'Appt Role Desc (privacy setting) ',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 121,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 194,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_pprv_l1_estab_unit_desc'
  $field_instances['node-profile-field_pprv_l1_estab_unit_desc'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 113,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 113,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 113,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 113,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 113,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pprv_l1_estab_unit_desc',
    'label' => 'Level 1 Establishment Unit Desc (privacy setting) ',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 113,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 183,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_pprv_l2_estab_unit_name'
  $field_instances['node-profile-field_pprv_l2_estab_unit_name'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 115,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 115,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 115,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 115,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 115,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pprv_l2_estab_unit_name',
    'label' => 'Level 2 Establishment Unit name (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 115,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 184,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_pprv_l3_estab_unit_name'
  $field_instances['node-profile-field_pprv_l3_estab_unit_name'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 117,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 117,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 117,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 117,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 117,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pprv_l3_estab_unit_name',
    'label' => 'Level 3 Establishment Unit name (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 117,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 185,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_pprv_l4_estab_unit_name'
  $field_instances['node-profile-field_pprv_l4_estab_unit_name'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 119,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 119,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 119,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 119,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 119,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pprv_l4_estab_unit_name',
    'label' => 'Level 4 Establishment Unit name (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 119,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 187,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_pprv_ou_email_address'
  $field_instances['node-profile-field_pprv_ou_email_address'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 109,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 109,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 109,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 109,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 109,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pprv_ou_email_address',
    'label' => 'OU email address (privacy setting) ',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 109,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 189,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_pprv_personal_website'
  $field_instances['node-profile-field_pprv_personal_website'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 80,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 80,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 80,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 80,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 80,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pprv_personal_website',
    'label' => 'Personal website (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 80,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 217,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_pprv_pref_forenames'
  $field_instances['node-profile-field_pprv_pref_forenames'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 94,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 94,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 94,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 94,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 94,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pprv_pref_forenames',
    'label' => 'Preferred Staff Forenames (privacy setting) ',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 94,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 190,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_pprv_pref_surname'
  $field_instances['node-profile-field_pprv_pref_surname'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 96,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 96,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 96,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 96,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 96,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pprv_pref_surname',
    'label' => 'Preferred Staff Surname (privacy setting) ',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 96,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 191,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_pprv_staff_forenames'
  $field_instances['node-profile-field_pprv_staff_forenames'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 92,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 92,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 92,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 92,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 92,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pprv_staff_forenames',
    'label' => 'Staff Forenames (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 92,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 183,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_pprv_staff_initials'
  $field_instances['node-profile-field_pprv_staff_initials'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 101,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 101,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 101,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 101,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 101,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pprv_staff_initials',
    'label' => 'Staff initials (privacy setting) ',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 101,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 193,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_pprv_staff_surname'
  $field_instances['node-profile-field_pprv_staff_surname'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 99,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 99,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 99,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 99,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 99,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pprv_staff_surname',
    'label' => 'Staff Surname (privacy setting) ',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 99,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 192,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_pprv_staff_title'
  $field_instances['node-profile-field_pprv_staff_title'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 91,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 91,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 91,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 91,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 91,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pprv_staff_title',
    'label' => 'Staff title (privacy setting) ',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 91,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 177,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_profile_taxonomy'
  $field_instances['node-profile-field_profile_taxonomy'] = array(
    'bundle' => 'profile',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use the "Ctrl" key to make multiple selections.<br>
This is one of the criteria that can be used to determine sites your profile will appear upon. It is not displayed on your profile.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 131,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_profile_taxonomy',
    'label' => 'Profile Taxonomy',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 152,
    ),
  );

  // Exported field_instance: 'node-profile-field_prv_alternative_email'
  $field_instances['node-profile-field_prv_alternative_email'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 111,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 111,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 111,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 111,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 111,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_alternative_email',
    'label' => 'Alternative Email address (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 111,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 201,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_prv_blog'
  $field_instances['node-profile-field_prv_blog'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 82,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 82,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 82,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 82,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 82,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_blog',
    'label' => 'Blog (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 82,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 83,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_prv_expertise'
  $field_instances['node-profile-field_prv_expertise'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 84,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 84,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 84,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 84,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 84,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_expertise',
    'label' => 'Areas of expertise (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 84,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 210,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_prv_flickr'
  $field_instances['node-profile-field_prv_flickr'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 88,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 88,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 88,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 88,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 88,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_flickr',
    'label' => 'Flickr page (privacy settings)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 88,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 90,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_prv_job_title'
  $field_instances['node-profile-field_prv_job_title'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 107,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 107,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 107,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 107,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 107,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_job_title',
    'label' => 'Unabbreviated job title (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 107,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 200,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_prv_letters'
  $field_instances['node-profile-field_prv_letters'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 1587,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 103,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 103,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 103,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 103,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 103,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_letters',
    'label' => 'Letters after name (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 103,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 199,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_prv_linkedin'
  $field_instances['node-profile-field_prv_linkedin'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 90,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 90,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 90,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 90,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 90,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_linkedin',
    'label' => 'LinkedIn profile (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 90,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 87,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_prv_openlearn_bio'
  $field_instances['node-profile-field_prv_openlearn_bio'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 135,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_openlearn_bio',
    'label' => 'OpenLearn biography (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 209,
    ),
  );

  // Exported field_instance: 'node-profile-field_prv_oubs_internatl_collabs'
  $field_instances['node-profile-field_prv_oubs_internatl_collabs'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 90,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 90,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 90,
      ),
      'search_index' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 90,
      ),
      'search_result' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 90,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 90,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 90,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_oubs_internatl_collabs',
    'label' => 'International links (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 90,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 208,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_prv_oubs_public_esteem'
  $field_instances['node-profile-field_prv_oubs_public_esteem'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 88,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 88,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 88,
      ),
      'search_index' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 88,
      ),
      'search_result' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 88,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 88,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 88,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_oubs_public_esteem',
    'label' => 'External contributions (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 88,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 208,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_prv_oubs_research_impact'
  $field_instances['node-profile-field_prv_oubs_research_impact'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 86,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 86,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 86,
      ),
      'search_index' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 86,
      ),
      'search_result' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 86,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 86,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 86,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_oubs_research_impact',
    'label' => 'Impact and engagement (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 86,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 207,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_prv_personal_bio'
  $field_instances['node-profile-field_prv_personal_bio'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 80,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 80,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 80,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 80,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 80,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_personal_bio',
    'label' => 'Personal Biography (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 80,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 175,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_prv_photo'
  $field_instances['node-profile-field_prv_photo'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 89,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 89,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 89,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 89,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 89,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_photo',
    'label' => 'Photograph (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 89,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 174,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_prv_research_interests'
  $field_instances['node-profile-field_prv_research_interests'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 84,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 84,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 84,
      ),
      'search_index' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 84,
      ),
      'search_result' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 84,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 84,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 84,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_research_interests',
    'label' => 'Research interests (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 84,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 177,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_prv_slideshare'
  $field_instances['node-profile-field_prv_slideshare'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 86,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 86,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 86,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 86,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 86,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_slideshare',
    'label' => 'Slideshare (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 86,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 216,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_prv_teaching_interests'
  $field_instances['node-profile-field_prv_teaching_interests'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 82,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 82,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 82,
      ),
      'search_index' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 82,
      ),
      'search_result' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 82,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 82,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 82,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_teaching_interests',
    'label' => 'Teaching interests (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 82,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 176,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_prv_twitter'
  $field_instances['node-profile-field_prv_twitter'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 84,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 84,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 84,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 84,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 84,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_twitter',
    'label' => 'Twitter user name (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 84,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 84,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-profile-field_prv_web_links'
  $field_instances['node-profile-field_prv_web_links'] = array(
    'bundle' => 'profile',
    'default_value' => array(
      0 => array(
        'nid' => 19916,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 92,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 92,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 92,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 92,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 92,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prv_web_links',
    'label' => 'Web links (privacy setting)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 92,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 88,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<p>This field is only visible to user 1, but is always over-ridden by the module.  It\'s basically read only. To set this field, use the CCK privacy values below (highest privacy value is applied to this field)</p>');
  t('Add a link to your main blog here and if you have any more blogs to your name add them as other web links');
  t('Alternative Email address');
  t('Alternative Email address (privacy setting)');
  t('Appt Role Code');
  t('Appt Role Desc');
  t('Appt Role Desc (privacy setting) ');
  t('Appt job title');
  t('Appt job title ');
  t('Appt job title (privacy setting)');
  t('Areas of expertise');
  t('Areas of expertise (privacy setting)');
  t('Blog');
  t('Blog (privacy setting)');
  t('Enter an alternative Open University Email address if you have one.');
  t('Enter links to relevant websites - e.g. your inaugural lecture');
  t('Enter the path name of the drupal site including all preceding and trailing slashes. e.g. /mbaopen/');
  t('External contributions');
  t('External contributions (privacy setting)');
  t('Flickr page');
  t('Flickr page (privacy settings)');
  t('Image');
  t('Impact and engagement');
  t('Impact and engagement (privacy setting)');
  t('Include a relevant flickr page here');
  t('Include here the impact of your research such as consultancy, policy advice, media coverage etc');
  t('Include items such as journal editorships, important consulting work, membership of important committees, honours, awards and prestigious posts');
  t('International links');
  t('International links (privacy setting)');
  t('Is this a public website, or an intranet?');
  t('Layout');
  t('Letters after name');
  t('Letters after name (privacy setting)');
  t('Level 1 Establishment Unit Desc');
  t('Level 1 Establishment Unit Desc (privacy setting) ');
  t('Level 1 Establishment Unit code');
  t('Level 2 Establishment Unit code');
  t('Level 2 Establishment Unit name');
  t('Level 2 Establishment Unit name (privacy setting)');
  t('Level 3 Establishment Unit code');
  t('Level 3 Establishment Unit name');
  t('Level 3 Establishment Unit name (privacy setting)');
  t('Level 4 Establishment Unit code');
  t('Level 4 Establishment Unit name');
  t('Level 4 Establishment Unit name (privacy setting)');
  t('Light / Dark');
  t('Link to your slideshare account where your presentations may be stored');
  t('LinkedIn profile');
  t('LinkedIn profile (privacy setting)');
  t('Media Expertise');
  t('Media relations biography');
  t('OU Email address');
  t('OU email address');
  t('OU email address (privacy setting) ');
  t('OUCU');
  t('OpenLearn biography');
  t('OpenLearn biography (privacy setting)');
  t('PIMS unique ID (computed)');
  t('Personal Biography');
  t('Personal Biography (privacy setting)');
  t('Personal Website');
  t('Personal website ');
  t('Personal website (privacy setting)');
  t('Photograph');
  t('Photograph (privacy setting)');
  t('Pick keywords/phrases that best describe your areas of expertise. If a keyword/phrase is not there please contact your information officer to get it added
');
  t('Preferred Staff Forenames');
  t('Preferred Staff Forenames (privacy setting) ');
  t('Preferred Staff Surname');
  t('Preferred Staff Surname (privacy setting) ');
  t('Profile Taxonomy');
  t('Profile visibility');
  t('Research interests');
  t('Research interests (privacy setting)');
  t('Site path');
  t('Site visibility');
  t('Slideshare');
  t('Slideshare (privacy setting)');
  t('Staff Forenames');
  t('Staff Forenames (privacy setting)');
  t('Staff ID');
  t('Staff Surname');
  t('Staff Surname (privacy setting) ');
  t('Staff initials');
  t('Staff initials (privacy setting) ');
  t('Staff title');
  t('Staff title (privacy setting) ');
  t('Teaching interests');
  t('Teaching interests (privacy setting)');
  t('The OU unit / department that this site is hosting. This is ignored if the allowed site is the profiles server (path = /people/)');
  t('This is a concatenation of staffid + L1 + L2 + L3 + L4 unit codes');
  t('Twitter user name');
  t('Twitter user name (privacy setting)');
  t('Unabbreviated job title');
  t('Unabbreviated job title (privacy setting)');
  t('Unit code');
  t('Unit level');
  t('Unit name lv1');
  t('Unit name lv2');
  t('Unit name lv3');
  t('Unit name lv4');
  t('Unit ref');
  t('Use the "Ctrl" key to make multiple selections.');
  t('Use the "Ctrl" key to make multiple selections.<br>
This is one of the criteria that can be used to determine sites your profile will appear upon. It is not displayed on your profile.');
  t('Web links');
  t('Web links (privacy setting)');
  t('Write about any type of international collaboration');

  return $field_instances;
}
