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
