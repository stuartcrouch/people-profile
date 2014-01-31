<?php
/**
 * @file
 * people_profiles_config.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function people_profiles_config_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_alt_email_add|node|profile|form';
  $field_group->group_name = 'group_alt_email_add';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sss_overrides';
  $field_group->data = array(
    'label' => 'Alternative Email address',
    'weight' => '199',
    'children' => array(
      0 => 'field_oup_alternative_email',
      1 => 'field_prv_alternative_email',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Alternative Email address',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_alt_email_add|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_appt_job_title|node|profile|form';
  $field_group->group_name = 'group_appt_job_title';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sss_info';
  $field_group->data = array(
    'label' => 'Appt job title',
    'weight' => '225',
    'children' => array(
      0 => 'field_pdat_appt_job_title',
      1 => 'field_pprv_appt_job_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Appt job title',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-nofield',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_appt_job_title|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_appt_role_desc|node|profile|form';
  $field_group->group_name = 'group_appt_role_desc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sss_info';
  $field_group->data = array(
    'label' => 'Appt Role Desc',
    'weight' => '231',
    'children' => array(
      0 => 'field_pdat_appt_role_desc',
      1 => 'field_pprv_appt_role_desc',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Appt Role Desc',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-nofield',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_appt_role_desc|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_areas_of_expertise|node|profile|form';
  $field_group->group_name = 'group_areas_of_expertise';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_oup_oubs_0153';
  $field_group->data = array(
    'label' => 'Areas of expertise',
    'weight' => '204',
    'children' => array(
      0 => 'field_oup_expertise',
      1 => 'field_prv_expertise',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Areas of expertise',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_areas_of_expertise|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blog|node|profile|form';
  $field_group->group_name = 'group_blog';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_external_profiles_accounts';
  $field_group->data = array(
    'label' => 'Blog',
    'weight' => '218',
    'children' => array(
      0 => 'field_oup_blog',
      1 => 'field_prv_blog',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Blog',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_blog|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories|node|profile|form';
  $field_group->group_name = 'group_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_groups';
  $field_group->data = array(
    'label' => 'Non-PIMs Categories',
    'weight' => '150',
    'children' => array(
      0 => 'field_profile_taxonomy',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_categories|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_groups|node|pims|form';
  $field_group->group_name = 'group_content_groups';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pims';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content Group',
    'weight' => '0',
    'children' => array(
      0 => 'group_header',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_content_groups|node|pims|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_groups|node|profile|form';
  $field_group->group_name = 'group_content_groups';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content Group',
    'weight' => '0',
    'children' => array(
      0 => 'group_external_profiles_accounts',
      1 => 'group_header',
      2 => 'group_layout_design',
      3 => 'group_oup_oubs_0153',
      4 => 'group_teaching_research_interest',
      5 => 'group_categories',
      6 => 'group_media_expert',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_content_groups|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ext_contrib|node|profile|form';
  $field_group->group_name = 'group_ext_contrib';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_oup_oubs_0153';
  $field_group->data = array(
    'label' => 'External contributions',
    'weight' => '206',
    'children' => array(
      0 => 'field_oup_oubs_public_esteem',
      1 => 'field_prv_oubs_public_esteem',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'External contributions',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ext_contrib|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_external_profiles_accounts|node|profile|default';
  $field_group->group_name = 'group_external_profiles_accounts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'External Profiles / Accounts',
    'weight' => '74',
    'children' => array(
      0 => 'field_oup_blog',
      1 => 'field_oup_flickr',
      2 => 'field_oup_linkedin',
      3 => 'field_oup_slideshare',
      4 => 'field_oup_twitter',
      5 => 'field_oup_web_links',
      6 => 'field_pdat_personal_website',
      7 => 'field_pprv_personal_website',
      8 => 'field_prv_blog',
      9 => 'field_prv_flickr',
      10 => 'field_prv_linkedin',
      11 => 'field_prv_slideshare',
      12 => 'field_prv_twitter',
      13 => 'field_prv_web_links',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_external_profiles_accounts|node|profile|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_external_profiles_accounts|node|profile|form';
  $field_group->group_name = 'group_external_profiles_accounts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_groups';
  $field_group->data = array(
    'label' => 'External Profiles',
    'weight' => '147',
    'children' => array(
      0 => 'field_pdat_personal_website',
      1 => 'field_pprv_personal_website',
      2 => 'group_blog',
      3 => 'group_twitter',
      4 => 'group_slideshare',
      5 => 'group_flickr',
      6 => 'group_linkedin',
      7 => 'group_web_links',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'External Profiles',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'privacy_options',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_external_profiles_accounts|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_external_profiles_accounts|node|profile|teaser';
  $field_group->group_name = 'group_external_profiles_accounts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'External Profiles / Accounts',
    'weight' => '74',
    'children' => array(
      0 => 'field_oup_blog',
      1 => 'field_oup_flickr',
      2 => 'field_oup_linkedin',
      3 => 'field_oup_slideshare',
      4 => 'field_oup_twitter',
      5 => 'field_oup_web_links',
      6 => 'field_pdat_personal_website',
      7 => 'field_pprv_personal_website',
      8 => 'field_prv_blog',
      9 => 'field_prv_flickr',
      10 => 'field_prv_linkedin',
      11 => 'field_prv_slideshare',
      12 => 'field_prv_twitter',
      13 => 'field_prv_web_links',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_external_profiles_accounts|node|profile|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_flickr|node|profile|form';
  $field_group->group_name = 'group_flickr';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_external_profiles_accounts';
  $field_group->data = array(
    'label' => 'Flickr',
    'weight' => '221',
    'children' => array(
      0 => 'field_oup_flickr',
      1 => 'field_prv_flickr',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Flickr',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_flickr|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header|node|pims|form';
  $field_group->group_name = 'group_header';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pims';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_groups';
  $field_group->data = array(
    'label' => 'Open University Information',
    'weight' => '24',
    'children' => array(
      0 => 'group_sss_info',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_header|node|pims|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header|node|profile|default';
  $field_group->group_name = 'group_header';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Profile Header',
    'weight' => '72',
    'children' => array(
      0 => 'field_oup_alternative_email',
      1 => 'field_oup_job_title',
      2 => 'field_oup_letters',
      3 => 'field_oup_photo',
      4 => 'field_pdat_appt_job_title',
      5 => 'field_pdat_appt_role_desc',
      6 => 'field_pdat_l1_estab_unit_desc',
      7 => 'field_pdat_l2_estab_unit_name',
      8 => 'field_pdat_l3_estab_unit_name',
      9 => 'field_pdat_l4_estab_unit_name',
      10 => 'field_pdat_ou_email_address',
      11 => 'field_pdat_pref_forenames',
      12 => 'field_pdat_pref_surname',
      13 => 'field_pdat_staff_forenames',
      14 => 'field_pdat_staff_initials',
      15 => 'field_pdat_staff_surname',
      16 => 'field_pdat_staff_title',
      17 => 'field_pprv_appt_job_title',
      18 => 'field_pprv_appt_role_desc',
      19 => 'field_pprv_l1_estab_unit_desc',
      20 => 'field_pprv_l2_estab_unit_name',
      21 => 'field_pprv_l3_estab_unit_name',
      22 => 'field_pprv_l4_estab_unit_name',
      23 => 'field_pprv_ou_email_address',
      24 => 'field_pprv_pref_forenames',
      25 => 'field_pprv_pref_surname',
      26 => 'field_pprv_staff_forenames',
      27 => 'field_pprv_staff_initials',
      28 => 'field_pprv_staff_surname',
      29 => 'field_pprv_staff_title',
      30 => 'field_prv_alternative_email',
      31 => 'field_prv_job_title',
      32 => 'field_prv_letters',
      33 => 'field_prv_photo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_header|node|profile|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header|node|profile|form';
  $field_group->group_name = 'group_header';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_groups';
  $field_group->data = array(
    'label' => 'Open University Information',
    'weight' => '144',
    'children' => array(
      0 => 'group_sss_info',
      1 => 'group_sss_overrides',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Open University Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'privacy_options',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_header|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header|node|profile|teaser';
  $field_group->group_name = 'group_header';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Profile Header',
    'weight' => '72',
    'children' => array(
      0 => 'field_oup_alternative_email',
      1 => 'field_oup_job_title',
      2 => 'field_oup_letters',
      3 => 'field_oup_photo',
      4 => 'field_pdat_appt_job_title',
      5 => 'field_pdat_appt_role_desc',
      6 => 'field_pdat_l1_estab_unit_desc',
      7 => 'field_pdat_l2_estab_unit_name',
      8 => 'field_pdat_l3_estab_unit_name',
      9 => 'field_pdat_l4_estab_unit_name',
      10 => 'field_pdat_ou_email_address',
      11 => 'field_pdat_pref_forenames',
      12 => 'field_pdat_pref_surname',
      13 => 'field_pdat_staff_forenames',
      14 => 'field_pdat_staff_initials',
      15 => 'field_pdat_staff_surname',
      16 => 'field_pdat_staff_title',
      17 => 'field_pprv_appt_job_title',
      18 => 'field_pprv_appt_role_desc',
      19 => 'field_pprv_l1_estab_unit_desc',
      20 => 'field_pprv_l2_estab_unit_name',
      21 => 'field_pprv_l3_estab_unit_name',
      22 => 'field_pprv_l4_estab_unit_name',
      23 => 'field_pprv_ou_email_address',
      24 => 'field_pprv_pref_forenames',
      25 => 'field_pprv_pref_surname',
      26 => 'field_pprv_staff_forenames',
      27 => 'field_pprv_staff_initials',
      28 => 'field_pprv_staff_surname',
      29 => 'field_pprv_staff_title',
      30 => 'field_prv_alternative_email',
      31 => 'field_prv_job_title',
      32 => 'field_prv_letters',
      33 => 'field_prv_photo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_header|node|profile|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_image|node|profile|form';
  $field_group->group_name = 'group_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_layout_design';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '216',
    'children' => array(
      0 => 'field_oup_profile_layout_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-nofield',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_image|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_impact_engagement|node|profile|form';
  $field_group->group_name = 'group_impact_engagement';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_oup_oubs_0153';
  $field_group->data = array(
    'label' => 'Impact and engagement',
    'weight' => '205',
    'children' => array(
      0 => 'field_oup_oubs_research_impact',
      1 => 'field_prv_oubs_research_impact',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Impact and engagement',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_impact_engagement|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_international_links|node|profile|form';
  $field_group->group_name = 'group_international_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_oup_oubs_0153';
  $field_group->data = array(
    'label' => 'International links',
    'weight' => '208',
    'children' => array(
      0 => 'field_oup_oubs_internatl_collabs',
      1 => 'field_prv_oubs_internatl_collabs',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'International links',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_international_links|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_design|node|profile|default';
  $field_group->group_name = 'group_layout_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'LAYOUT/DESIGN Settings',
    'weight' => '76',
    'children' => array(
      0 => 'field_oup_profile_layout',
      1 => 'field_oup_profile_layout_colour',
      2 => 'field_oup_profile_layout_image',
      3 => 'field_prv_profile_layout',
      4 => 'field_prv_profile_layout_colour',
      5 => 'field_prv_profile_layout_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_layout_design|node|profile|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_design|node|profile|form';
  $field_group->group_name = 'group_layout_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_groups';
  $field_group->data = array(
    'label' => 'Layout settings',
    'weight' => '148',
    'children' => array(
      0 => 'group_layout',
      1 => 'group_image',
      2 => 'group_light_dark',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Layout settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_layout_design|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_design|node|profile|teaser';
  $field_group->group_name = 'group_layout_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'LAYOUT/DESIGN Settings',
    'weight' => '76',
    'children' => array(
      0 => 'field_oup_profile_layout',
      1 => 'field_oup_profile_layout_colour',
      2 => 'field_oup_profile_layout_image',
      3 => 'field_prv_profile_layout',
      4 => 'field_prv_profile_layout_colour',
      5 => 'field_prv_profile_layout_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_layout_design|node|profile|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout|node|profile|form';
  $field_group->group_name = 'group_layout';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_layout_design';
  $field_group->data = array(
    'label' => 'Layout',
    'weight' => '217',
    'children' => array(
      0 => 'field_oup_profile_layout',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Layout',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-nofield',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_layout|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_letters_after_name|node|profile|form';
  $field_group->group_name = 'group_letters_after_name';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sss_overrides';
  $field_group->data = array(
    'label' => 'Letters after name',
    'weight' => '197',
    'children' => array(
      0 => 'field_oup_letters',
      1 => 'field_prv_letters',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Letters after name',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_letters_after_name|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_level_1_est|node|profile|form';
  $field_group->group_name = 'group_level_1_est';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sss_info';
  $field_group->data = array(
    'label' => 'Level 1 Est',
    'weight' => '221',
    'children' => array(
      0 => 'field_pdat_l1_estab_unit_desc',
      1 => 'field_pprv_l1_estab_unit_desc',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Level 1 Est',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-nofield',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_level_1_est|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_level_2_est|node|profile|form';
  $field_group->group_name = 'group_level_2_est';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sss_info';
  $field_group->data = array(
    'label' => 'Level 2 Est',
    'weight' => '222',
    'children' => array(
      0 => 'field_pdat_l2_estab_unit_name',
      1 => 'field_pprv_l2_estab_unit_name',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Level 2 Est',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-nofield',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_level_2_est|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_level_3_est|node|profile|form';
  $field_group->group_name = 'group_level_3_est';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sss_info';
  $field_group->data = array(
    'label' => 'Level 3 Est',
    'weight' => '223',
    'children' => array(
      0 => 'field_pdat_l3_estab_unit_name',
      1 => 'field_pprv_l3_estab_unit_name',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Level 3 Est',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-nofield',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_level_3_est|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_level_4_est|node|profile|form';
  $field_group->group_name = 'group_level_4_est';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sss_info';
  $field_group->data = array(
    'label' => 'Level 4 Est',
    'weight' => '224',
    'children' => array(
      0 => 'field_pdat_l4_estab_unit_name',
      1 => 'field_pprv_l4_estab_unit_name',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Level 4 Est',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-nofield',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_level_4_est|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_light_dark|node|profile|form';
  $field_group->group_name = 'group_light_dark';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_layout_design';
  $field_group->data = array(
    'label' => 'Light Dark',
    'weight' => '218',
    'children' => array(
      0 => 'field_oup_profile_layout_colour',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Light Dark',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-nofield',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_light_dark|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_linkedin|node|profile|form';
  $field_group->group_name = 'group_linkedin';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_external_profiles_accounts';
  $field_group->data = array(
    'label' => 'LinkedIn',
    'weight' => '222',
    'children' => array(
      0 => 'field_oup_linkedin',
      1 => 'field_prv_linkedin',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'LinkedIn',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_linkedin|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_expert|node|profile|form';
  $field_group->group_name = 'group_media_expert';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_groups';
  $field_group->data = array(
    'label' => 'Media Expert',
    'weight' => '149',
    'children' => array(
      0 => 'field_media_expertise',
      1 => 'field_oup_media_relations_bio',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Media Expert',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_media_expert|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_openlearn_bio|node|profile|form';
  $field_group->group_name = 'group_openlearn_bio';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_teaching_research_interest';
  $field_group->data = array(
    'label' => 'OpenLearn biography',
    'weight' => '156',
    'children' => array(
      0 => 'field_oup_openlearn_bio',
      1 => 'field_prv_openlearn_bio',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'OpenLearn biography',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_openlearn_bio|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ou_email_address|node|profile|form';
  $field_group->group_name = 'group_ou_email_address';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sss_info';
  $field_group->data = array(
    'label' => 'OU Email address',
    'weight' => '226',
    'children' => array(
      0 => 'field_pdat_ou_email_address',
      1 => 'field_pprv_ou_email_address',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'OU Email address',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-nofield',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ou_email_address|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_oup_oubs_0153|node|profile|default';
  $field_group->group_name = 'group_oup_oubs_0153';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'OUBS',
    'weight' => '75',
    'children' => array(
      0 => 'field_oup_expertise',
      1 => 'field_oup_oubs_internatl_collabs',
      2 => 'field_oup_oubs_public_esteem',
      3 => 'field_oup_oubs_research_impact',
      4 => 'field_prv_expertise',
      5 => 'field_prv_oubs_internatl_collabs',
      6 => 'field_prv_oubs_public_esteem',
      7 => 'field_prv_oubs_research_impact',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_oup_oubs_0153|node|profile|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_oup_oubs_0153|node|profile|form';
  $field_group->group_name = 'group_oup_oubs_0153';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_groups';
  $field_group->data = array(
    'label' => 'OUBS',
    'weight' => '146',
    'children' => array(
      0 => 'group_areas_of_expertise',
      1 => 'group_impact_engagement',
      2 => 'group_ext_contrib',
      3 => 'group_international_links',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'OUBS',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'privacy_options',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_oup_oubs_0153|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_oup_oubs_0153|node|profile|teaser';
  $field_group->group_name = 'group_oup_oubs_0153';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'OUBS',
    'weight' => '75',
    'children' => array(
      0 => 'field_oup_expertise',
      1 => 'field_oup_oubs_internatl_collabs',
      2 => 'field_oup_oubs_public_esteem',
      3 => 'field_oup_oubs_research_impact',
      4 => 'field_prv_expertise',
      5 => 'field_prv_oubs_internatl_collabs',
      6 => 'field_prv_oubs_public_esteem',
      7 => 'field_prv_oubs_research_impact',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_oup_oubs_0153|node|profile|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal_biography|node|profile|form';
  $field_group->group_name = 'group_personal_biography';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_teaching_research_interest';
  $field_group->data = array(
    'label' => 'Personal Biography',
    'weight' => '153',
    'children' => array(
      0 => 'field_oup_personal_bio',
      1 => 'field_prv_personal_bio',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Personal Biography',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_personal_biography|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photograph|node|profile|form';
  $field_group->group_name = 'group_photograph';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sss_info';
  $field_group->data = array(
    'label' => 'Photograph',
    'weight' => '218',
    'children' => array(
      0 => 'field_oup_photo',
      1 => 'field_prv_photo',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Photograph',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_photograph|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pref_staff_fore|node|profile|form';
  $field_group->group_name = 'group_pref_staff_fore';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sss_info';
  $field_group->data = array(
    'label' => 'Preferred Staff Forenames',
    'weight' => '227',
    'children' => array(
      0 => 'field_pdat_pref_forenames',
      1 => 'field_pprv_pref_forenames',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Preferred Staff Forenames',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-nofield',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_pref_staff_fore|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pref_staff_sur|node|profile|form';
  $field_group->group_name = 'group_pref_staff_sur';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sss_info';
  $field_group->data = array(
    'label' => 'Preferred Staff Surname',
    'weight' => '228',
    'children' => array(
      0 => 'field_pdat_pref_surname',
      1 => 'field_pprv_pref_surname',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Preferred Staff Surname',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-nofield',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_pref_staff_sur|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_research_interests|node|profile|form';
  $field_group->group_name = 'group_research_interests';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_teaching_research_interest';
  $field_group->data = array(
    'label' => 'Research interests',
    'weight' => '155',
    'children' => array(
      0 => 'field_oup_research_interests',
      1 => 'field_prv_research_interests',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Research interests',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_research_interests|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_slideshare|node|profile|form';
  $field_group->group_name = 'group_slideshare';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_external_profiles_accounts';
  $field_group->data = array(
    'label' => 'Slideshare',
    'weight' => '220',
    'children' => array(
      0 => 'field_oup_slideshare',
      1 => 'field_prv_slideshare',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Slideshare',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_slideshare|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sss_info|node|pims|form';
  $field_group->group_name = 'group_sss_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pims';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_header';
  $field_group->data = array(
    'label' => 'Staff Self Service Information',
    'weight' => '24',
    'children' => array(
      0 => 'field_pims_appt_job_title',
      1 => 'field_pims_appt_role_desc',
      2 => 'field_pims_l1_estab_unit_code',
      3 => 'field_pims_l1_estab_unit_desc',
      4 => 'field_pims_l2_estab_unit_name',
      5 => 'field_pims_l3_estab_unit_name',
      6 => 'field_pims_l4_estab_unit_name',
      7 => 'field_pims_oucu',
      8 => 'field_pims_ou_email_address',
      9 => 'field_pims_personal_website',
      10 => 'field_pims_pref_forenames',
      11 => 'field_pims_pref_surname',
      12 => 'field_pims_staff_forenames',
      13 => 'field_pims_staff_id',
      14 => 'field_pims_staff_initials',
      15 => 'field_pims_staff_surname',
      16 => 'field_pims_staff_title',
      17 => 'field_pims_unique_id',
      18 => 'field_pims_l2_estab_unit_code',
      19 => 'field_pims_l3_estab_unit_code',
      20 => 'field_pims_l4_estab_unit_code',
      21 => 'metatags',
      22 => 'title',
      23 => 'path',
      24 => 'field_pims_appt_role_code',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_sss_info|node|pims|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sss_info|node|profile|form';
  $field_group->group_name = 'group_sss_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_header';
  $field_group->data = array(
    'label' => 'Staff Self Service Info',
    'weight' => '152',
    'children' => array(
      0 => 'group_staff_title',
      1 => 'group_staff_forenames',
      2 => 'group_level_1_est',
      3 => 'group_level_2_est',
      4 => 'group_level_3_est',
      5 => 'group_level_4_est',
      6 => 'group_appt_job_title',
      7 => 'group_ou_email_address',
      8 => 'group_pref_staff_fore',
      9 => 'group_pref_staff_sur',
      10 => 'group_staff_surname',
      11 => 'group_staff_initials',
      12 => 'group_appt_role_desc',
      13 => 'group_photograph',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_sss_info|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sss_overrides|node|profile|form';
  $field_group->group_name = 'group_sss_overrides';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_header';
  $field_group->data = array(
    'label' => 'Staff Self Service Overrides',
    'weight' => '154',
    'children' => array(
      0 => 'group_letters_after_name',
      1 => 'group_unab_job_title',
      2 => 'group_alt_email_add',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Staff Self Service Overrides',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_sss_overrides|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_staff_forenames|node|profile|form';
  $field_group->group_name = 'group_staff_forenames';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sss_info';
  $field_group->data = array(
    'label' => 'Staff Forenames',
    'weight' => '220',
    'children' => array(
      0 => 'field_pdat_staff_forenames',
      1 => 'field_pprv_staff_forenames',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Staff Forenames',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-nofield',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_staff_forenames|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_staff_initials|node|profile|form';
  $field_group->group_name = 'group_staff_initials';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sss_info';
  $field_group->data = array(
    'label' => 'Staff initials',
    'weight' => '230',
    'children' => array(
      0 => 'field_pdat_staff_initials',
      1 => 'field_pprv_staff_initials',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Staff initials',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-nofield',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_staff_initials|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_staff_surname|node|profile|form';
  $field_group->group_name = 'group_staff_surname';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sss_info';
  $field_group->data = array(
    'label' => 'Staff Surname',
    'weight' => '229',
    'children' => array(
      0 => 'field_pdat_staff_surname',
      1 => 'field_pprv_staff_surname',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Staff Surname',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-nofield',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_staff_surname|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_staff_title|node|profile|form';
  $field_group->group_name = 'group_staff_title';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sss_info';
  $field_group->data = array(
    'label' => 'Staff title',
    'weight' => '219',
    'children' => array(
      0 => 'field_pdat_staff_title',
      1 => 'field_pprv_staff_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Staff title',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-nofield',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_staff_title|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaching_interests|node|profile|form';
  $field_group->group_name = 'group_teaching_interests';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_teaching_research_interest';
  $field_group->data = array(
    'label' => 'Teaching interests',
    'weight' => '154',
    'children' => array(
      0 => 'field_oup_teaching_interests',
      1 => 'field_prv_teaching_interests',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Teaching interests',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_teaching_interests|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaching_research_interest|node|profile|default';
  $field_group->group_name = 'group_teaching_research_interest';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teaching / Research / Interests',
    'weight' => '73',
    'children' => array(
      0 => 'field_oup_personal_bio',
      1 => 'field_oup_research_interests',
      2 => 'field_oup_teaching_interests',
      3 => 'field_prv_personal_bio',
      4 => 'field_prv_research_interests',
      5 => 'field_prv_teaching_interests',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_teaching_research_interest|node|profile|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaching_research_interest|node|profile|form';
  $field_group->group_name = 'group_teaching_research_interest';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_groups';
  $field_group->data = array(
    'label' => 'Biographical Information',
    'weight' => '145',
    'children' => array(
      0 => 'group_personal_biography',
      1 => 'group_teaching_interests',
      2 => 'group_research_interests',
      3 => 'group_openlearn_bio',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Biographical Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'privacy_options',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_teaching_research_interest|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaching_research_interest|node|profile|teaser';
  $field_group->group_name = 'group_teaching_research_interest';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teaching / Research / Interests',
    'weight' => '73',
    'children' => array(
      0 => 'field_oup_personal_bio',
      1 => 'field_oup_research_interests',
      2 => 'field_oup_teaching_interests',
      3 => 'field_prv_personal_bio',
      4 => 'field_prv_research_interests',
      5 => 'field_prv_teaching_interests',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_teaching_research_interest|node|profile|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_twitter|node|profile|form';
  $field_group->group_name = 'group_twitter';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_external_profiles_accounts';
  $field_group->data = array(
    'label' => 'Twitter',
    'weight' => '219',
    'children' => array(
      0 => 'field_oup_twitter',
      1 => 'field_prv_twitter',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Twitter',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_twitter|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_unab_job_title|node|profile|form';
  $field_group->group_name = 'group_unab_job_title';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sss_overrides';
  $field_group->data = array(
    'label' => 'Unabbreviated job title',
    'weight' => '198',
    'children' => array(
      0 => 'field_oup_job_title',
      1 => 'field_prv_job_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Unabbreviated job title',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_unab_job_title|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_web_links|node|profile|form';
  $field_group->group_name = 'group_web_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_external_profiles_accounts';
  $field_group->data = array(
    'label' => 'Web Links',
    'weight' => '223',
    'children' => array(
      0 => 'field_oup_web_links',
      1 => 'field_prv_web_links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Web Links',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'ou-field',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_web_links|node|profile|form'] = $field_group;

  return $export;
}
