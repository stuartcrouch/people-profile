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

  // Exported role: PP0031.
  $roles['PP0031'] = array(
    'name' => 'PP0031',
    'weight' => 36,
  );

  // Exported role: PP0060.
  $roles['PP0060'] = array(
    'name' => 'PP0060',
    'weight' => 22,
  );

  // Exported role: PP0065.
  $roles['PP0065'] = array(
    'name' => 'PP0065',
    'weight' => 14,
  );

  // Exported role: PP0066.
  $roles['PP0066'] = array(
    'name' => 'PP0066',
    'weight' => 17,
  );

  // Exported role: PP0076.
  $roles['PP0076'] = array(
    'name' => 'PP0076',
    'weight' => 10,
  );

  // Exported role: PP0077.
  $roles['PP0077'] = array(
    'name' => 'PP0077',
    'weight' => 19,
  );

  // Exported role: PP0086.
  $roles['PP0086'] = array(
    'name' => 'PP0086',
    'weight' => 6,
  );

  // Exported role: PP0088.
  $roles['PP0088'] = array(
    'name' => 'PP0088',
    'weight' => 39,
  );

  // Exported role: PP0105.
  $roles['PP0105'] = array(
    'name' => 'PP0105',
    'weight' => 13,
  );

  // Exported role: PP0107.
  $roles['PP0107'] = array(
    'name' => 'PP0107',
    'weight' => 20,
  );

  // Exported role: PP0108.
  $roles['PP0108'] = array(
    'name' => 'PP0108',
    'weight' => 23,
  );

  // Exported role: PP0109.
  $roles['PP0109'] = array(
    'name' => 'PP0109',
    'weight' => 25,
  );

  // Exported role: PP0110.
  $roles['PP0110'] = array(
    'name' => 'PP0110',
    'weight' => 0,
  );

  // Exported role: PP0111.
  $roles['PP0111'] = array(
    'name' => 'PP0111',
    'weight' => 15,
  );

  // Exported role: PP0120.
  $roles['PP0120'] = array(
    'name' => 'PP0120',
    'weight' => 34,
  );

  // Exported role: PP0127.
  $roles['PP0127'] = array(
    'name' => 'PP0127',
    'weight' => 16,
  );

  // Exported role: PP0131.
  $roles['PP0131'] = array(
    'name' => 'PP0131',
    'weight' => 18,
  );

  // Exported role: PP0153.
  $roles['PP0153'] = array(
    'name' => 'PP0153',
    'weight' => 0,
  );

  // Exported role: PP0173.
  $roles['PP0173'] = array(
    'name' => 'PP0173',
    'weight' => 26,
  );

  // Exported role: PP0194.
  $roles['PP0194'] = array(
    'name' => 'PP0194',
    'weight' => 32,
  );

  // Exported role: PP0195.
  $roles['PP0195'] = array(
    'name' => 'PP0195',
    'weight' => 29,
  );

  // Exported role: PP0315.
  $roles['PP0315'] = array(
    'name' => 'PP0315',
    'weight' => 31,
  );

  // Exported role: PP0620.
  $roles['PP0620'] = array(
    'name' => 'PP0620',
    'weight' => 35,
  );

  // Exported role: PP0640.
  $roles['PP0640'] = array(
    'name' => 'PP0640',
    'weight' => 28,
  );

  // Exported role: PP0641.
  $roles['PP0641'] = array(
    'name' => 'PP0641',
    'weight' => 11,
  );

  // Exported role: PP0642.
  $roles['PP0642'] = array(
    'name' => 'PP0642',
    'weight' => 9,
  );

  // Exported role: PP0643.
  $roles['PP0643'] = array(
    'name' => 'PP0643',
    'weight' => 12,
  );

  // Exported role: PP0698.
  $roles['PP0698'] = array(
    'name' => 'PP0698',
    'weight' => 7,
  );

  // Exported role: PP0699.
  $roles['PP0699'] = array(
    'name' => 'PP0699',
    'weight' => 30,
  );

  // Exported role: PP0701.
  $roles['PP0701'] = array(
    'name' => 'PP0701',
    'weight' => 24,
  );

  // Exported role: PP0702.
  $roles['PP0702'] = array(
    'name' => 'PP0702',
    'weight' => 38,
  );

  // Exported role: PP0706.
  $roles['PP0706'] = array(
    'name' => 'PP0706',
    'weight' => 21,
  );

  // Exported role: PP0707.
  $roles['PP0707'] = array(
    'name' => 'PP0707',
    'weight' => 33,
  );

  // Exported role: PP0710.
  $roles['PP0710'] = array(
    'name' => 'PP0710',
    'weight' => 37,
  );

  // Exported role: PP0856.
  $roles['PP0856'] = array(
    'name' => 'PP0856',
    'weight' => 8,
  );

  // Exported role: PP0861.
  $roles['PP0861'] = array(
    'name' => 'PP0861',
    'weight' => 27,
  );

  return $roles;
}
