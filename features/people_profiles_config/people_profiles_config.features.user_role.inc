<?php
/**
 * @file
 * people_profiles_config.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function people_profiles_config_user_default_roles() {
  $roles = array();

  // Exported role: DRPPME.
  $roles['DRPPME'] = array(
    'name' => 'DRPPME',
    'weight' => 5,
  );

  return $roles;
}
