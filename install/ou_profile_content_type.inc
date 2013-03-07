<?php
/**
 * @file
 * The profile content type
 */

$content['type']  = array(
  'name' => 'OU Profile',
  'type' => 'ou_profile',
  'description' => 'Reference node that identifies a person\'s OU profile.',
  'title_label' => 'Title',
  'body_label' => 'About me',
  'min_word_count' => '0',
  'help' => '',
  'node_options' => 
  array(
    'status' => TRUE,
    'promote' => TRUE,
    'sticky' => FALSE,
    'revision' => FALSE,
  ),
  'old_type' => 'ou_profile',
  'orig_type' => '',
  'module' => 'node',
  'custom' => '1',
  'modified' => '1',
  'locked' => '0',
  'comment' => '2',
  'comment_default_mode' => '4',
  'comment_default_order' => '1',
  'comment_default_per_page' => '50',
  'comment_controls' => '3',
  'comment_anonymous' => 0,
  'comment_subject_field' => '1',
  'comment_preview' => '1',
  'comment_form_location' => '0',
);
$content['fields']  = array(
  0 => 
  array(
    'label' => 'PIMS unique ID ',
    'field_name' => 'field_pims_unique_id',
    'type' => 'text',
    'widget_type' => 'text_textfield',
    'change' => 'Change basic information',
    'weight' => '3',
    'rows' => 5,
    'size' => '60',
    'description' => '',
    'default_value' => 
    array(
      0 => 
      array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pims_unique_id][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => NULL,
    'group' => FALSE,
    'required' => 1,
    'multiple' => '0',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'op' => 'Save field settings',
    'module' => 'text',
    'widget_module' => 'text',
    'columns' => 
    array(
      'value' => 
      array(
        'type' => 'text',
        'size' => 'big',
        'not null' => FALSE,
        'sortable' => TRUE,
        'views' => TRUE,
      ),
    ),
    'display_settings' => 
    array(
      'label' => 
      array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array(
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array(
        'format' => 'default',
        'exclude' => 0,
      ),
      2 => 
      array(
        'format' => 'default',
        'exclude' => 0,
      ),
      3 => 
      array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
);
$content['extra']  = array(
  'title' => '-5',
  'body_field' => '-3',
  'revision_information' => '-1',
  'author' => '-2',
  'options' => '0',
  'comment_settings' => '1',
  'menu' => '-4',
);

