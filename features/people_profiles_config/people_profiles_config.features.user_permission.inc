<?php
/**
 * @file
 * people_profiles_config.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function people_profiles_config_user_default_permissions() {
  $permissions = array();

  // Exported permission: create profile content.
  $permissions['create profile content'] = array(
    'name' => 'create profile content',
    'roles' => array(
      'DRADMIN' => 'DRADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any profile content.
  $permissions['delete any profile content'] = array(
    'name' => 'delete any profile content',
    'roles' => array(
      'DRADMIN' => 'DRADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own profile content.
  $permissions['delete own profile content'] = array(
    'name' => 'delete own profile content',
    'roles' => array(
      'DRADMIN' => 'DRADMIN',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any profile content.
  $permissions['edit any profile content'] = array(
    'name' => 'edit any profile content',
    'roles' => array(
      'DRADMIN' => 'DRADMIN',
      'DRPPME' => 'DRPPME',
      'PP0031' => 'PP0031',
      'PP0060' => 'PP0060',
      'PP0065' => 'PP0065',
      'PP0066' => 'PP0066',
      'PP0076' => 'PP0076',
      'PP0077' => 'PP0077',
      'PP0086' => 'PP0086',
      'PP0088' => 'PP0088',
      'PP0105' => 'PP0105',
      'PP0107' => 'PP0107',
      'PP0108' => 'PP0108',
      'PP0109' => 'PP0109',
      'PP0110' => 'PP0110',
      'PP0111' => 'PP0111',
      'PP0120' => 'PP0120',
      'PP0127' => 'PP0127',
      'PP0131' => 'PP0131',
      'PP0153' => 'PP0153',
      'PP0173' => 'PP0173',
      'PP0194' => 'PP0194',
      'PP0195' => 'PP0195',
      'PP0315' => 'PP0315',
      'PP0620' => 'PP0620',
      'PP0640' => 'PP0640',
      'PP0641' => 'PP0641',
      'PP0642' => 'PP0642',
      'PP0643' => 'PP0643',
      'PP0698' => 'PP0698',
      'PP0699' => 'PP0699',
      'PP0701' => 'PP0701',
      'PP0702' => 'PP0702',
      'PP0706' => 'PP0706',
      'PP0707' => 'PP0707',
      'PP0710' => 'PP0710',
      'PP0856' => 'PP0856',
      'PP0861' => 'PP0861',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own profile content.
  $permissions['edit own profile content'] = array(
    'name' => 'edit own profile content',
    'roles' => array(
      'DRADMIN' => 'DRADMIN',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: use text format filtered_html.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
