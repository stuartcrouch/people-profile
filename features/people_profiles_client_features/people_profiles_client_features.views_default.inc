<?php
/**
 * @file
 * people_profiles_client_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function people_profiles_client_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'people';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'People';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Find staff members by name';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
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
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<div id="list-top" class="item-list atoz_list"></div>';
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
  /* Field: Title (Hidden) */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title (Hidden)';
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
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[title]<br />
[field_oup_job_title]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Surname (field_pims_pref_surname) */
  $handler->display->display_options['sorts']['field_pims_pref_surname_value']['id'] = 'field_pims_pref_surname_value';
  $handler->display->display_options['sorts']['field_pims_pref_surname_value']['table'] = 'field_data_field_pims_pref_surname';
  $handler->display->display_options['sorts']['field_pims_pref_surname_value']['field'] = 'field_pims_pref_surname_value';
  /* Contextual filter: Content: Surname (field_pims_pref_surname) */
  $handler->display->display_options['arguments']['field_pims_pref_surname_value']['id'] = 'field_pims_pref_surname_value';
  $handler->display->display_options['arguments']['field_pims_pref_surname_value']['table'] = 'field_data_field_pims_pref_surname';
  $handler->display->display_options['arguments']['field_pims_pref_surname_value']['field'] = 'field_pims_pref_surname_value';
  $handler->display->display_options['arguments']['field_pims_pref_surname_value']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_pims_pref_surname_value']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['field_pims_pref_surname_value']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['field_pims_pref_surname_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_pims_pref_surname_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_pims_pref_surname_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_pims_pref_surname_value']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['field_pims_pref_surname_value']['limit'] = '1';
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
  $export['people'] = $view;

  return $export;
}
