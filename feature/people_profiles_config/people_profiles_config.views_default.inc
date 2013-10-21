<?php
/**
 * @file
 * people_profiles_config.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function people_profiles_config_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ordered_privacy_settings';
  $view->description = 'Creates the privacy option on profile fields';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Privacy value (field_privacy_value) */
  $handler->display->display_options['sorts']['field_privacy_value_value']['id'] = 'field_privacy_value_value';
  $handler->display->display_options['sorts']['field_privacy_value_value']['table'] = 'field_data_field_privacy_value';
  $handler->display->display_options['sorts']['field_privacy_value_value']['field'] = 'field_privacy_value_value';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'privacy_value' => 'privacy_value',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;

  /* Display: References */
  $handler = $view->new_display('references', 'References', 'references_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'references_style';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'references_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['ordered_privacy_settings'] = $view;

  $view = new view();
  $view->name = 'profile_search';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 50;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_oup_profile_layout_image' => 'field_oup_profile_layout_image',
    'title' => 'title',
    'field_pdat_appt_job_title' => 'field_pdat_appt_job_title',
    'field_pdat_l1_estab_unit_desc' => 'field_pdat_l1_estab_unit_desc',
    'field_pdat_l2_estab_unit_name' => 'field_pdat_l2_estab_unit_name',
    'field_pdat_pref_forenames' => 'field_pdat_pref_forenames',
    'field_pdat_pref_surname' => 'field_pdat_pref_surname',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_oup_profile_layout_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pdat_appt_job_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pdat_l1_estab_unit_desc' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pdat_l2_estab_unit_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pdat_pref_forenames' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pdat_pref_surname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_oup_photo_fid']['id'] = 'field_oup_photo_fid';
  $handler->display->display_options['fields']['field_oup_photo_fid']['table'] = 'node_data_field_oup_photo';
  $handler->display->display_options['fields']['field_oup_photo_fid']['field'] = 'field_oup_photo_fid';
  $handler->display->display_options['fields']['field_oup_photo_fid']['label'] = 'Photograph';
  $handler->display->display_options['fields']['field_oup_photo_fid']['hide_empty'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_pdat_appt_job_title_value']['id'] = 'field_pdat_appt_job_title_value';
  $handler->display->display_options['fields']['field_pdat_appt_job_title_value']['table'] = 'node_data_field_pdat_appt_job_title';
  $handler->display->display_options['fields']['field_pdat_appt_job_title_value']['field'] = 'field_pdat_appt_job_title_value';
  $handler->display->display_options['fields']['field_pdat_appt_job_title_value']['label'] = 'Appt job title ';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_pdat_l1_estab_unit_desc_value']['id'] = 'field_pdat_l1_estab_unit_desc_value';
  $handler->display->display_options['fields']['field_pdat_l1_estab_unit_desc_value']['table'] = 'node_data_field_pdat_l1_estab_unit_desc';
  $handler->display->display_options['fields']['field_pdat_l1_estab_unit_desc_value']['field'] = 'field_pdat_l1_estab_unit_desc_value';
  $handler->display->display_options['fields']['field_pdat_l1_estab_unit_desc_value']['label'] = 'Level 1 Establishment Unit Desc';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_pdat_l2_estab_unit_name_value']['id'] = 'field_pdat_l2_estab_unit_name_value';
  $handler->display->display_options['fields']['field_pdat_l2_estab_unit_name_value']['table'] = 'node_data_field_pdat_l2_estab_unit_name';
  $handler->display->display_options['fields']['field_pdat_l2_estab_unit_name_value']['field'] = 'field_pdat_l2_estab_unit_name_value';
  $handler->display->display_options['fields']['field_pdat_l2_estab_unit_name_value']['label'] = 'Level 2 Establishment Unit name';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_pdat_staff_forenames_value']['id'] = 'field_pdat_staff_forenames_value';
  $handler->display->display_options['fields']['field_pdat_staff_forenames_value']['table'] = 'node_data_field_pdat_staff_forenames';
  $handler->display->display_options['fields']['field_pdat_staff_forenames_value']['field'] = 'field_pdat_staff_forenames_value';
  $handler->display->display_options['fields']['field_pdat_staff_forenames_value']['label'] = 'Staff Forenames';
  $handler->display->display_options['fields']['field_pdat_staff_forenames_value']['exclude'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_pdat_staff_surname_value']['id'] = 'field_pdat_staff_surname_value';
  $handler->display->display_options['fields']['field_pdat_staff_surname_value']['table'] = 'node_data_field_pdat_staff_surname';
  $handler->display->display_options['fields']['field_pdat_staff_surname_value']['field'] = 'field_pdat_staff_surname_value';
  $handler->display->display_options['fields']['field_pdat_staff_surname_value']['label'] = 'Staff Surname';
  $handler->display->display_options['fields']['field_pdat_staff_surname_value']['exclude'] = TRUE;
  /* Sort criterion: Content: Preferred Staff Forenames (field_pdat_pref_forenames) */
  $handler->display->display_options['sorts']['field_pdat_pref_forenames_value']['id'] = 'field_pdat_pref_forenames_value';
  $handler->display->display_options['sorts']['field_pdat_pref_forenames_value']['table'] = 'field_data_field_pdat_pref_forenames';
  $handler->display->display_options['sorts']['field_pdat_pref_forenames_value']['field'] = 'field_pdat_pref_forenames_value';
  /* Sort criterion: Content: Preferred Staff Surname (field_pdat_pref_surname) */
  $handler->display->display_options['sorts']['field_pdat_pref_surname_value']['id'] = 'field_pdat_pref_surname_value';
  $handler->display->display_options['sorts']['field_pdat_pref_surname_value']['table'] = 'field_data_field_pdat_pref_surname';
  $handler->display->display_options['sorts']['field_pdat_pref_surname_value']['field'] = 'field_pdat_pref_surname_value';
  /* Contextual filter: Content: Level 1 Establishment Unit Desc (field_pdat_l1_estab_unit_desc) */
  $handler->display->display_options['arguments']['field_pdat_l1_estab_unit_desc_value']['id'] = 'field_pdat_l1_estab_unit_desc_value';
  $handler->display->display_options['arguments']['field_pdat_l1_estab_unit_desc_value']['table'] = 'field_data_field_pdat_l1_estab_unit_desc';
  $handler->display->display_options['arguments']['field_pdat_l1_estab_unit_desc_value']['field'] = 'field_pdat_l1_estab_unit_desc_value';
  $handler->display->display_options['arguments']['field_pdat_l1_estab_unit_desc_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_pdat_l1_estab_unit_desc_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_pdat_l1_estab_unit_desc_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_pdat_l1_estab_unit_desc_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_pdat_l1_estab_unit_desc_value']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = '0';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'profile' => 'profile',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Profile visibility (field_oup_visibility) */
  $handler->display->display_options['filters']['field_oup_visibility_value']['id'] = 'field_oup_visibility_value';
  $handler->display->display_options['filters']['field_oup_visibility_value']['table'] = 'field_data_field_oup_visibility';
  $handler->display->display_options['filters']['field_oup_visibility_value']['field'] = 'field_oup_visibility_value';
  $handler->display->display_options['filters']['field_oup_visibility_value']['value'] = array(
    2 => '2',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Photograph */
  $handler->display->display_options['fields']['field_oup_photo']['id'] = 'field_oup_photo';
  $handler->display->display_options['fields']['field_oup_photo']['table'] = 'field_data_field_oup_photo';
  $handler->display->display_options['fields']['field_oup_photo']['field'] = 'field_oup_photo';
  $handler->display->display_options['fields']['field_oup_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_oup_photo']['settings'] = array(
    'image_style' => 'profile_thumb',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  /* Field: Content: Appt job title  */
  $handler->display->display_options['fields']['field_pdat_appt_job_title']['id'] = 'field_pdat_appt_job_title';
  $handler->display->display_options['fields']['field_pdat_appt_job_title']['table'] = 'field_data_field_pdat_appt_job_title';
  $handler->display->display_options['fields']['field_pdat_appt_job_title']['field'] = 'field_pdat_appt_job_title';
  $handler->display->display_options['fields']['field_pdat_appt_job_title']['label'] = 'Job Title';
  /* Field: Content: Level 1 Establishment Unit Desc */
  $handler->display->display_options['fields']['field_pdat_l1_estab_unit_desc']['id'] = 'field_pdat_l1_estab_unit_desc';
  $handler->display->display_options['fields']['field_pdat_l1_estab_unit_desc']['table'] = 'field_data_field_pdat_l1_estab_unit_desc';
  $handler->display->display_options['fields']['field_pdat_l1_estab_unit_desc']['field'] = 'field_pdat_l1_estab_unit_desc';
  $handler->display->display_options['fields']['field_pdat_l1_estab_unit_desc']['label'] = 'Unit';
  /* Field: Content: Level 2 Establishment Unit name */
  $handler->display->display_options['fields']['field_pdat_l2_estab_unit_name']['id'] = 'field_pdat_l2_estab_unit_name';
  $handler->display->display_options['fields']['field_pdat_l2_estab_unit_name']['table'] = 'field_data_field_pdat_l2_estab_unit_name';
  $handler->display->display_options['fields']['field_pdat_l2_estab_unit_name']['field'] = 'field_pdat_l2_estab_unit_name';
  $handler->display->display_options['fields']['field_pdat_l2_estab_unit_name']['label'] = 'Sub Unit';
  /* Field: Content: Preferred Staff Forenames */
  $handler->display->display_options['fields']['field_pdat_pref_forenames']['id'] = 'field_pdat_pref_forenames';
  $handler->display->display_options['fields']['field_pdat_pref_forenames']['table'] = 'field_data_field_pdat_pref_forenames';
  $handler->display->display_options['fields']['field_pdat_pref_forenames']['field'] = 'field_pdat_pref_forenames';
  $handler->display->display_options['fields']['field_pdat_pref_forenames']['exclude'] = TRUE;
  /* Field: Content: Preferred Staff Surname */
  $handler->display->display_options['fields']['field_pdat_pref_surname']['id'] = 'field_pdat_pref_surname';
  $handler->display->display_options['fields']['field_pdat_pref_surname']['table'] = 'field_data_field_pdat_pref_surname';
  $handler->display->display_options['fields']['field_pdat_pref_surname']['field'] = 'field_pdat_pref_surname';
  $handler->display->display_options['fields']['field_pdat_pref_surname']['exclude'] = TRUE;
  $handler->display->display_options['path'] = 'search/%';
  $handler->display->display_options['menu']['title'] = 'Search test';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'primary-links';
  $export['profile_search'] = $view;

  return $export;
}
