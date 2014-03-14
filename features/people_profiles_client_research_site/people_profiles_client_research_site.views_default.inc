<?php
/**
 * @file
 * people_profiles_client_research_site.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function people_profiles_client_research_site_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'faculties';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Research - People Profiles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Faculties';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: PIMs unit lv 1 */
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['id'] = 'field_pims_l1_estab_unit_desc';
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['table'] = 'field_data_field_pims_l1_estab_unit_desc';
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['field'] = 'field_pims_l1_estab_unit_desc';
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['label'] = '';
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: PIMs unit lv 1 (field_pims_l1_estab_unit_desc) */
  $handler->display->display_options['sorts']['field_pims_l1_estab_unit_desc_value']['id'] = 'field_pims_l1_estab_unit_desc_value';
  $handler->display->display_options['sorts']['field_pims_l1_estab_unit_desc_value']['table'] = 'field_data_field_pims_l1_estab_unit_desc';
  $handler->display->display_options['sorts']['field_pims_l1_estab_unit_desc_value']['field'] = 'field_pims_l1_estab_unit_desc_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ou_profile' => 'ou_profile',
  );

  /* Display: Faculties */
  $handler = $view->new_display('page', 'Faculties', 'faculties');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: PIMs unit lv 1 */
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['id'] = 'field_pims_l1_estab_unit_desc';
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['table'] = 'field_data_field_pims_l1_estab_unit_desc';
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['field'] = 'field_pims_l1_estab_unit_desc';
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['label'] = '';
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['alter']['text'] = '<a href="/people/faculties/[field_pims_l1_estab_unit_desc]">[field_pims_l1_estab_unit_desc]</a>';
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['alter']['path'] = 'people/faculties/[field_pims_l1_estab_unit_desc]';
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['element_default_classes'] = FALSE;
  $handler->display->display_options['path'] = 'people/faculties';
  $handler->display->display_options['menu']['title'] = 'People by faculty';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-people-profiles';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Faculty Departments */
  $handler = $view->new_display('page', 'Faculty Departments', 'faculty_depts');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Faculty Departments';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_pims_l2_estab_unit_name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: PIMs unit lv2 (Hidden) */
  $handler->display->display_options['fields']['field_pims_l2_estab_unit_name']['id'] = 'field_pims_l2_estab_unit_name';
  $handler->display->display_options['fields']['field_pims_l2_estab_unit_name']['table'] = 'field_data_field_pims_l2_estab_unit_name';
  $handler->display->display_options['fields']['field_pims_l2_estab_unit_name']['field'] = 'field_pims_l2_estab_unit_name';
  $handler->display->display_options['fields']['field_pims_l2_estab_unit_name']['ui_name'] = 'PIMs unit lv2 (Hidden)';
  $handler->display->display_options['fields']['field_pims_l2_estab_unit_name']['label'] = '';
  $handler->display->display_options['fields']['field_pims_l2_estab_unit_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pims_l2_estab_unit_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pims_l2_estab_unit_name']['element_default_classes'] = FALSE;
  /* Field: PIMs job title (Hidden) */
  $handler->display->display_options['fields']['field_pims_appt_job_title']['id'] = 'field_pims_appt_job_title';
  $handler->display->display_options['fields']['field_pims_appt_job_title']['table'] = 'field_data_field_pims_appt_job_title';
  $handler->display->display_options['fields']['field_pims_appt_job_title']['field'] = 'field_pims_appt_job_title';
  $handler->display->display_options['fields']['field_pims_appt_job_title']['ui_name'] = 'PIMs job title (Hidden)';
  $handler->display->display_options['fields']['field_pims_appt_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_pims_appt_job_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pims_appt_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pims_appt_job_title']['element_default_classes'] = FALSE;
  /* Field: Job Title (Hidden) */
  $handler->display->display_options['fields']['field_oup_job_title']['id'] = 'field_oup_job_title';
  $handler->display->display_options['fields']['field_oup_job_title']['table'] = 'field_data_field_oup_job_title';
  $handler->display->display_options['fields']['field_oup_job_title']['field'] = 'field_oup_job_title';
  $handler->display->display_options['fields']['field_oup_job_title']['ui_name'] = 'Job Title (Hidden)';
  $handler->display->display_options['fields']['field_oup_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_oup_job_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_oup_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oup_job_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_oup_job_title']['empty'] = '[field_pims_appt_job_title]';
  /* Field: Name */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Name';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br/>[field_oup_job_title]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: PIMs unit lv 2 (field_pims_l2_estab_unit_name) */
  $handler->display->display_options['sorts']['field_pims_l2_estab_unit_name_value']['id'] = 'field_pims_l2_estab_unit_name_value';
  $handler->display->display_options['sorts']['field_pims_l2_estab_unit_name_value']['table'] = 'field_data_field_pims_l2_estab_unit_name';
  $handler->display->display_options['sorts']['field_pims_l2_estab_unit_name_value']['field'] = 'field_pims_l2_estab_unit_name_value';
  /* Sort criterion: Content: Surname (field_pims_pref_surname) */
  $handler->display->display_options['sorts']['field_pims_pref_surname_value']['id'] = 'field_pims_pref_surname_value';
  $handler->display->display_options['sorts']['field_pims_pref_surname_value']['table'] = 'field_data_field_pims_pref_surname';
  $handler->display->display_options['sorts']['field_pims_pref_surname_value']['field'] = 'field_pims_pref_surname_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: PIMs unit lv 1 (field_pims_l1_estab_unit_desc) */
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['id'] = 'field_pims_l1_estab_unit_desc_value';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['table'] = 'field_data_field_pims_l1_estab_unit_desc';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['field'] = 'field_pims_l1_estab_unit_desc_value';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['title'] = '%1';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['default_argument_options']['argument'] = 'Arts';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['transform_dash'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ou_profile' => 'ou_profile',
  );
  /* Filter criterion: Content: PIMs unit lv 2 (field_pims_l2_estab_unit_name) */
  $handler->display->display_options['filters']['field_pims_l2_estab_unit_name_value']['id'] = 'field_pims_l2_estab_unit_name_value';
  $handler->display->display_options['filters']['field_pims_l2_estab_unit_name_value']['table'] = 'field_data_field_pims_l2_estab_unit_name';
  $handler->display->display_options['filters']['field_pims_l2_estab_unit_name_value']['field'] = 'field_pims_l2_estab_unit_name_value';
  $handler->display->display_options['filters']['field_pims_l2_estab_unit_name_value']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'people/faculties/%';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h3>Other</h3>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: PIMs job title (Hidden) */
  $handler->display->display_options['fields']['field_pims_appt_job_title']['id'] = 'field_pims_appt_job_title';
  $handler->display->display_options['fields']['field_pims_appt_job_title']['table'] = 'field_data_field_pims_appt_job_title';
  $handler->display->display_options['fields']['field_pims_appt_job_title']['field'] = 'field_pims_appt_job_title';
  $handler->display->display_options['fields']['field_pims_appt_job_title']['ui_name'] = 'PIMs job title (Hidden)';
  $handler->display->display_options['fields']['field_pims_appt_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_pims_appt_job_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pims_appt_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pims_appt_job_title']['element_default_classes'] = FALSE;
  /* Field: Job Title (Hidden) */
  $handler->display->display_options['fields']['field_oup_job_title']['id'] = 'field_oup_job_title';
  $handler->display->display_options['fields']['field_oup_job_title']['table'] = 'field_data_field_oup_job_title';
  $handler->display->display_options['fields']['field_oup_job_title']['field'] = 'field_oup_job_title';
  $handler->display->display_options['fields']['field_oup_job_title']['ui_name'] = 'Job Title (Hidden)';
  $handler->display->display_options['fields']['field_oup_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_oup_job_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_oup_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oup_job_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_oup_job_title']['empty'] = '[field_pims_appt_job_title]';
  /* Field: Name */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Name';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br/>[field_oup_job_title]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Surname (field_pims_pref_surname) */
  $handler->display->display_options['sorts']['field_pims_pref_surname_value']['id'] = 'field_pims_pref_surname_value';
  $handler->display->display_options['sorts']['field_pims_pref_surname_value']['table'] = 'field_data_field_pims_pref_surname';
  $handler->display->display_options['sorts']['field_pims_pref_surname_value']['field'] = 'field_pims_pref_surname_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: PIMs unit lv 1 (field_pims_l1_estab_unit_desc) */
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['id'] = 'field_pims_l1_estab_unit_desc_value';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['table'] = 'field_data_field_pims_l1_estab_unit_desc';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['field'] = 'field_pims_l1_estab_unit_desc_value';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['default_argument_options']['argument'] = 'Arts';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_pims_l1_estab_unit_desc_value']['transform_dash'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ou_profile' => 'ou_profile',
  );
  /* Filter criterion: Content: PIMs unit lv 2 (field_pims_l2_estab_unit_name) */
  $handler->display->display_options['filters']['field_pims_l2_estab_unit_name_value']['id'] = 'field_pims_l2_estab_unit_name_value';
  $handler->display->display_options['filters']['field_pims_l2_estab_unit_name_value']['table'] = 'field_data_field_pims_l2_estab_unit_name';
  $handler->display->display_options['filters']['field_pims_l2_estab_unit_name_value']['field'] = 'field_pims_l2_estab_unit_name_value';
  $handler->display->display_options['filters']['field_pims_l2_estab_unit_name_value']['operator'] = 'empty';
  $handler->display->display_options['displays'] = array(
    'faculty_depts' => 'faculty_depts',
    'default' => 0,
    'faculties' => 0,
    'faculty_depts_null' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $export['faculties'] = $view;

  $view = new view();
  $view->name = 'research_profiles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Research Profiles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Find people by name';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'people_by_atoz';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'nothing',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['class'] = 'ou_profile_names';
  $handler->display->display_options['style_options']['wrapper_class'] = 'list-items';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: A-Z + Link to faculties view */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['ui_name'] = 'A-Z + Link to faculties view';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<div id="list-top" class="item-list atoz_list"><ul class="AtoZ"></ul></div>';
  /* Field: PIMs job title (Hidden) */
  $handler->display->display_options['fields']['field_pims_appt_job_title']['id'] = 'field_pims_appt_job_title';
  $handler->display->display_options['fields']['field_pims_appt_job_title']['table'] = 'field_data_field_pims_appt_job_title';
  $handler->display->display_options['fields']['field_pims_appt_job_title']['field'] = 'field_pims_appt_job_title';
  $handler->display->display_options['fields']['field_pims_appt_job_title']['ui_name'] = 'PIMs job title (Hidden)';
  $handler->display->display_options['fields']['field_pims_appt_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_pims_appt_job_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pims_appt_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pims_appt_job_title']['element_default_classes'] = FALSE;
  /* Field: 1st Letter of the surname (Hidden) */
  $handler->display->display_options['fields']['field_pims_pref_surname']['id'] = 'field_pims_pref_surname';
  $handler->display->display_options['fields']['field_pims_pref_surname']['table'] = 'field_data_field_pims_pref_surname';
  $handler->display->display_options['fields']['field_pims_pref_surname']['field'] = 'field_pims_pref_surname';
  $handler->display->display_options['fields']['field_pims_pref_surname']['ui_name'] = '1st Letter of the surname (Hidden)';
  $handler->display->display_options['fields']['field_pims_pref_surname']['label'] = '';
  $handler->display->display_options['fields']['field_pims_pref_surname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pims_pref_surname']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_pims_pref_surname']['alter']['max_length'] = '1';
  $handler->display->display_options['fields']['field_pims_pref_surname']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_pims_pref_surname']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['field_pims_pref_surname']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_pims_pref_surname']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_pims_pref_surname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pims_pref_surname']['element_default_classes'] = FALSE;
  /* Field: 1st Letter of the surname (Grouping) */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = '1st Letter of the surname (Grouping)';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h3 id="[field_pims_pref_surname]" name="[field_pims_pref_surname]" class="ou_profile_atoz_heading">[field_pims_pref_surname]</h3><a class="to-top" href="#list-top">Back to top</a>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Faculty (Hidden) */
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['id'] = 'field_pims_l1_estab_unit_desc';
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['table'] = 'field_data_field_pims_l1_estab_unit_desc';
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['field'] = 'field_pims_l1_estab_unit_desc';
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['ui_name'] = 'Faculty (Hidden)';
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['label'] = '';
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pims_l1_estab_unit_desc']['element_default_classes'] = FALSE;
  /* Field: Name (Hidden) */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Name (Hidden)';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'ou_profile_profile_link';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Job Title (Hidden) */
  $handler->display->display_options['fields']['field_oup_job_title']['id'] = 'field_oup_job_title';
  $handler->display->display_options['fields']['field_oup_job_title']['table'] = 'field_data_field_oup_job_title';
  $handler->display->display_options['fields']['field_oup_job_title']['field'] = 'field_oup_job_title';
  $handler->display->display_options['fields']['field_oup_job_title']['ui_name'] = 'Job Title (Hidden)';
  $handler->display->display_options['fields']['field_oup_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_oup_job_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_oup_job_title']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_oup_job_title']['element_class'] = 'ou_profile_job_title';
  $handler->display->display_options['fields']['field_oup_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oup_job_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_oup_job_title']['empty'] = '[field_pims_appt_job_title]';
  /* Field: Name | Faculty | Position */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Name | Faculty | Position';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[title]<br />
[field_pims_l1_estab_unit_desc] | Position : [field_oup_job_title]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Surname (field_pims_pref_surname) */
  $handler->display->display_options['sorts']['field_pims_pref_surname_value']['id'] = 'field_pims_pref_surname_value';
  $handler->display->display_options['sorts']['field_pims_pref_surname_value']['table'] = 'field_data_field_pims_pref_surname';
  $handler->display->display_options['sorts']['field_pims_pref_surname_value']['field'] = 'field_pims_pref_surname_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ou_profile' => 'ou_profile',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search for a name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
  );

  /* Display: People by A to Z */
  $handler = $view->new_display('page', 'People by A to Z', 'people_by_atoz');
  $handler->display->display_options['path'] = 'people';
  $handler->display->display_options['menu']['title'] = 'People by A-Z';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-people-profiles';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['research_profiles'] = $view;

  return $export;
}
