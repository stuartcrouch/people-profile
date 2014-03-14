<?php
/**
 * @file
 * people_profiles_config.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function people_profiles_config_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_media_expertise'
  $field_bases['field_media_expertise'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_media_expertise',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(
      'tid' => array(
        'columns' => array(
          'tid' => 'tid',
        ),
        'table' => 'taxonomy_term_data',
      ),
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'media_expertise',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_ou_unit_ref'
  $field_bases['field_ou_unit_ref'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ou_unit_ref',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 'ou_unit',
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 0,
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ou_units',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'allowed_sites',
  );

  // Exported field_base: 'field_oup_alternative_email'
  $field_bases['field_oup_alternative_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_alternative_email',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'email',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'email',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_blog'
  $field_bases['field_oup_blog'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_blog',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_expertise'
  $field_bases['field_oup_expertise'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_expertise',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => 'Consumer behaviour
Corporate social responsibility
Entrepreneurship
Ethical marketing
Social marketing
Surveillance
Sustainability',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_flickr'
  $field_bases['field_oup_flickr'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_flickr',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_job_title'
  $field_bases['field_oup_job_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_job_title',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_letters'
  $field_bases['field_oup_letters'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_letters',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => '',
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_linkedin'
  $field_bases['field_oup_linkedin'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_linkedin',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_media_relations_bio'
  $field_bases['field_oup_media_relations_bio'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_media_relations_bio',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_oup_openlearn_bio'
  $field_bases['field_oup_openlearn_bio'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_openlearn_bio',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_oup_oubs_internatl_collabs'
  $field_bases['field_oup_oubs_internatl_collabs'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_oubs_internatl_collabs',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_oubs_public_esteem'
  $field_bases['field_oup_oubs_public_esteem'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_oubs_public_esteem',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_oubs_research_impact'
  $field_bases['field_oup_oubs_research_impact'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_oubs_research_impact',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_oucu'
  $field_bases['field_oup_oucu'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_oucu',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_personal_bio'
  $field_bases['field_oup_personal_bio'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_personal_bio',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_photo'
  $field_bases['field_oup_photo'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_photo',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_profile_layout'
  $field_bases['field_oup_profile_layout'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_profile_layout',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'p2cl' => '2 cols (content, sidebar)',
        'p2cr' => '2 cols (sidebar, content)',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_profile_layout_colour'
  $field_bases['field_oup_profile_layout_colour'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_profile_layout_colour',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'light' => 'light',
        'dark' => 'dark',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_profile_layout_image'
  $field_bases['field_oup_profile_layout_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_profile_layout_image',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_research_interests'
  $field_bases['field_oup_research_interests'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_research_interests',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_slideshare'
  $field_bases['field_oup_slideshare'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_slideshare',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_staff_id'
  $field_bases['field_oup_staff_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_staff_id',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_teaching_interests'
  $field_bases['field_oup_teaching_interests'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_teaching_interests',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_twitter'
  $field_bases['field_oup_twitter'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_twitter',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_visibility'
  $field_bases['field_oup_visibility'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_visibility',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Private (no one can see this information)',
        1 => 'Intranet only',
        2 => 'Public (everyone can see this information)',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_oup_web_links'
  $field_bases['field_oup_web_links'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oup_web_links',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pdat_appt_job_title'
  $field_bases['field_pdat_appt_job_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pdat_appt_job_title',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pdat_appt_role_desc'
  $field_bases['field_pdat_appt_role_desc'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pdat_appt_role_desc',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pdat_l1_estab_unit_desc'
  $field_bases['field_pdat_l1_estab_unit_desc'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pdat_l1_estab_unit_desc',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pdat_l2_estab_unit_name'
  $field_bases['field_pdat_l2_estab_unit_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pdat_l2_estab_unit_name',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pdat_l3_estab_unit_name'
  $field_bases['field_pdat_l3_estab_unit_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pdat_l3_estab_unit_name',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pdat_l4_estab_unit_name'
  $field_bases['field_pdat_l4_estab_unit_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pdat_l4_estab_unit_name',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pdat_ou_email_address'
  $field_bases['field_pdat_ou_email_address'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pdat_ou_email_address',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pdat_personal_website'
  $field_bases['field_pdat_personal_website'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pdat_personal_website',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pdat_pref_forenames'
  $field_bases['field_pdat_pref_forenames'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pdat_pref_forenames',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pdat_pref_surname'
  $field_bases['field_pdat_pref_surname'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pdat_pref_surname',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pdat_staff_forenames'
  $field_bases['field_pdat_staff_forenames'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pdat_staff_forenames',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => '',
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pdat_staff_initials'
  $field_bases['field_pdat_staff_initials'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pdat_staff_initials',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pdat_staff_surname'
  $field_bases['field_pdat_staff_surname'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pdat_staff_surname',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pdat_staff_title'
  $field_bases['field_pdat_staff_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pdat_staff_title',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pims_appt_job_title'
  $field_bases['field_pims_appt_job_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_appt_job_title',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pims_appt_role_code'
  $field_bases['field_pims_appt_role_code'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_appt_role_code',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_pims_appt_role_desc'
  $field_bases['field_pims_appt_role_desc'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_appt_role_desc',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pims_l1_estab_unit_code'
  $field_bases['field_pims_l1_estab_unit_code'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_l1_estab_unit_code',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pims_l1_estab_unit_desc'
  $field_bases['field_pims_l1_estab_unit_desc'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_l1_estab_unit_desc',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pims_l2_estab_unit_code'
  $field_bases['field_pims_l2_estab_unit_code'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_l2_estab_unit_code',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_pims_l2_estab_unit_name'
  $field_bases['field_pims_l2_estab_unit_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_l2_estab_unit_name',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pims_l3_estab_unit_code'
  $field_bases['field_pims_l3_estab_unit_code'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_l3_estab_unit_code',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_pims_l3_estab_unit_name'
  $field_bases['field_pims_l3_estab_unit_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_l3_estab_unit_name',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pims_l4_estab_unit_code'
  $field_bases['field_pims_l4_estab_unit_code'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_l4_estab_unit_code',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_pims_l4_estab_unit_name'
  $field_bases['field_pims_l4_estab_unit_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_l4_estab_unit_name',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pims_ou_email_address'
  $field_bases['field_pims_ou_email_address'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_ou_email_address',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pims_oucu'
  $field_bases['field_pims_oucu'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_oucu',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pims_personal_website'
  $field_bases['field_pims_personal_website'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_personal_website',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pims_pref_forenames'
  $field_bases['field_pims_pref_forenames'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_pref_forenames',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pims_pref_surname'
  $field_bases['field_pims_pref_surname'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_pref_surname',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pims_staff_forenames'
  $field_bases['field_pims_staff_forenames'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_staff_forenames',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pims_staff_id'
  $field_bases['field_pims_staff_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_staff_id',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pims_staff_initials'
  $field_bases['field_pims_staff_initials'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_staff_initials',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pims_staff_surname'
  $field_bases['field_pims_staff_surname'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_staff_surname',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pims_staff_title'
  $field_bases['field_pims_staff_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_staff_title',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pims_unique_id'
  $field_bases['field_pims_unique_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pims_unique_id',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'pims',
  );

  // Exported field_base: 'field_pprv_appt_job_title'
  $field_bases['field_pprv_appt_job_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pprv_appt_job_title',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pprv_appt_role_desc'
  $field_bases['field_pprv_appt_role_desc'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pprv_appt_role_desc',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pprv_l1_estab_unit_desc'
  $field_bases['field_pprv_l1_estab_unit_desc'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pprv_l1_estab_unit_desc',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pprv_l2_estab_unit_name'
  $field_bases['field_pprv_l2_estab_unit_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pprv_l2_estab_unit_name',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pprv_l3_estab_unit_name'
  $field_bases['field_pprv_l3_estab_unit_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pprv_l3_estab_unit_name',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pprv_l4_estab_unit_name'
  $field_bases['field_pprv_l4_estab_unit_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pprv_l4_estab_unit_name',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pprv_ou_email_address'
  $field_bases['field_pprv_ou_email_address'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pprv_ou_email_address',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pprv_personal_website'
  $field_bases['field_pprv_personal_website'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pprv_personal_website',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pprv_pref_forenames'
  $field_bases['field_pprv_pref_forenames'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pprv_pref_forenames',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pprv_pref_surname'
  $field_bases['field_pprv_pref_surname'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pprv_pref_surname',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pprv_staff_forenames'
  $field_bases['field_pprv_staff_forenames'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pprv_staff_forenames',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pprv_staff_initials'
  $field_bases['field_pprv_staff_initials'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pprv_staff_initials',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pprv_staff_surname'
  $field_bases['field_pprv_staff_surname'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pprv_staff_surname',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_pprv_staff_title'
  $field_bases['field_pprv_staff_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pprv_staff_title',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_profile_taxonomy'
  $field_bases['field_profile_taxonomy'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_profile_taxonomy',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'tid' => array(
        'columns' => array(
          'tid' => 'tid',
        ),
        'table' => 'taxonomy_term_data',
      ),
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'profile_taxonomy',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_prv_alternative_email'
  $field_bases['field_prv_alternative_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_alternative_email',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_prv_blog'
  $field_bases['field_prv_blog'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_blog',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_prv_expertise'
  $field_bases['field_prv_expertise'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_expertise',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_prv_flickr'
  $field_bases['field_prv_flickr'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_flickr',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_prv_job_title'
  $field_bases['field_prv_job_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_job_title',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_prv_letters'
  $field_bases['field_prv_letters'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_letters',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_prv_linkedin'
  $field_bases['field_prv_linkedin'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_linkedin',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_prv_openlearn_bio'
  $field_bases['field_prv_openlearn_bio'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_openlearn_bio',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_prv_oro'
  $field_bases['field_prv_oro'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_oro',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_prv_oubs_internatl_collabs'
  $field_bases['field_prv_oubs_internatl_collabs'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_oubs_internatl_collabs',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_prv_oubs_public_esteem'
  $field_bases['field_prv_oubs_public_esteem'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_oubs_public_esteem',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_prv_oubs_research_impact'
  $field_bases['field_prv_oubs_research_impact'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_oubs_research_impact',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_prv_personal_bio'
  $field_bases['field_prv_personal_bio'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_personal_bio',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_prv_photo'
  $field_bases['field_prv_photo'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_photo',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_prv_research_interests'
  $field_bases['field_prv_research_interests'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_research_interests',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feature' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_prv_rps'
  $field_bases['field_prv_rps'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_rps',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_prv_slideshare'
  $field_bases['field_prv_slideshare'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_slideshare',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_prv_teaching_interests'
  $field_bases['field_prv_teaching_interests'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_teaching_interests',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_prv_twitter'
  $field_bases['field_prv_twitter'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_twitter',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_prv_web_links'
  $field_bases['field_prv_web_links'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prv_web_links',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'allowed_sites' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'ou_profile' => 0,
        'ou_unit' => 0,
        'page' => 0,
        'pims' => 0,
        'privacy_value' => 'privacy_value',
        'profile' => 0,
        'profile_page' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'ordered_privacy_settings',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'profile',
  );

  // Exported field_base: 'field_site_path'
  $field_bases['field_site_path'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_site_path',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'allowed_sites',
  );

  // Exported field_base: 'field_site_visibility'
  $field_bases['field_site_visibility'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_site_visibility',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        2 => 'Intranet',
        3 => 'Public',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_text',
    'type_name' => 'allowed_sites',
  );

  // Exported field_base: 'field_unit_code'
  $field_bases['field_unit_code'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_unit_code',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'ou_unit',
  );

  // Exported field_base: 'field_unit_level'
  $field_bases['field_unit_level'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_unit_level',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_unit_name_lv1'
  $field_bases['field_unit_name_lv1'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_unit_name_lv1',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_unit_name_lv2'
  $field_bases['field_unit_name_lv2'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_unit_name_lv2',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_unit_name_lv3'
  $field_bases['field_unit_name_lv3'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_unit_name_lv3',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_unit_name_lv4'
  $field_bases['field_unit_name_lv4'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_unit_name_lv4',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
