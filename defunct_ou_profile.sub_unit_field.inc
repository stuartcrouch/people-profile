<?php

/**
 * Implements hook_field_info().
 *
 * Provides the description of the field.
 */
function ou_profile_field_info() {
  return array(
    // We name our field as the associative name of the array.
    'ou_profile_sub_unit' => array(
      'label' => t('OU Sub unit'),
      'description' => t('Select list of OU sub units.'),
      'default_widget' => 'options_select',
      'default_formatter' => 'list_default',
    ),
  );
}

/**
 * Implements hook_field_validate().
 *
 * This hook gives us a chance to validate content that's in our
 * field. We're really only interested in the $items parameter, since
 * it holds arrays representing content in the field we've defined.
 *
 * @see field_example_field_widget_error()
 */
function ou_profile_field_validate($entity_type, $entity, $field, $instance, $langcode, $items, &$errors)
{
	//to do
}


/**
 * Implements hook_field_is_empty().
 *
 * hook_field_is_emtpy() is where Drupal asks us if this field is empty.
 * Return TRUE if it does not contain data, FALSE if it does. This lets
 * the form API flag an error when required fields are empty.
 */
function ou_profile_field_is_empty($item, $field) {
	if (empty($item['value']) && (string) $item['value'] !== '0')
	{
		return TRUE;
	}
	return FALSE; 
}


/**
* Implements hook_field_formatter_info().
*/
function ou_profile_field_formatter_info()
{
	return array(
		'list_default' => array(
			'label' => t('Default'),
			'field types' => array('ou_profile_sub_unit'),
		),
	);
} 

/**
* Implements hook_field_formatter_view().
*/
function my_module_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display)
{
	$element = array();
	//Currently we only have one display option, use switch
	//to prepare for future options.
	switch ($display['type'])
	{
		case 'list_default':
			foreach ($items as $delta => $item)
			{
				if (isset($options[$item['option']]['option']))
				{
					$output = field_filter_xss($options[$item['option']]['option']);
				} else {
					$output = "Not Supplied";
				}
				$element[$delta] = array('#markup' => $output);
			}
			break;
		default:
	}
	return $element;
}


/**
* Implements hook_field_widget_info_alter().
*
* The List module does not implement widgets of its own, but reuses the
* widgets defined in options.module.
*
* @see list_options_list()
*/
function ou_profile_field_widget_info_alter(&$info)
{
	$widgets = array(
		'options_select' => array('ou_profile_sub_unit'),
		'options_buttons' => array('ou_profile_sub_unit'),
		);
	foreach ($widgets as $widget => $field_types)
	{
		$info[$widget]['field types'] = array_merge($info[$widget]['field types'], $field_types);
	}
}


/**
* Implements hook_options_list()
*/
function ou_profile_options_list($field, $instance, $entity_type, $entity)
{
	dsm( $field );
	dsm( $instance );
	dsm( $entity_type );
	dsm( $entity );
	watchdog( "ou_profile", print_r( $entity, true ) );
	$selected = "_none";
	if( isset( $entity->nid ) )
	{
		$this_node = node_load( $entity->nid );
		if( $this_node )
		{
			dsm( $this_node );
			dsm( $this_node->field_ou_unit_ref );
			dsm( isset($this_node->field_ou_unit_ref) );
			$selected = isset($this_node->field_ou_unit_ref) ? $this_node->field_ou_unit_ref['und'][0]['nid'] : "_none";
		}
	}
	dsm( $selected );
	return _ou_profile_get_sub_unit_value( $selected );
}

function ou_profile_ou_unit_callback($form, $form_state)
{
	//watchdog( "ou_profile", print_r( $form, true ) );
	//watchdog( "ou_profile", print_r( $form_state, true ) );
	$selected = isset($form_state['values']['field_ou_unit_ref']) ? $form_state['values']['field_ou_unit_ref']['und'][0]['nid'] : "_none";
	$form['field_test']['und'][0]['value'] = '_none';
	$form['field_test']['und']['#options'] = _ou_profile_get_sub_unit_value( $selected );
	return $form['field_test'];
}

function _ou_profile_get_sub_unit_value( $selected )
{
	
	if( $selected == "_none" )
	{
		$opts = array(
			'_none' => '-- Select Unit Ref first --',
		);
	} else {
	
		$ou_unit = node_load( $selected );
		
		if( $ou_unit )
		{
			if( !empty( $ou_unit->field_sub_units ) )
			{
				$opts['_none'] = '-- Select sub unit --';
				foreach( $ou_unit->field_sub_units['und'] as $sub_unit )
				{
					$opts[ $sub_unit['value'] ] = $sub_unit['value'];
				}
			} else {
				$opts = array( '_none' => '-- NO SUB UNITS FOR THIS UNIT--', );
			}
		} else {
			$opts = array( '_none' => '-- NO SUB UNITS FOUND --' );
		}
	}
	
	return( $opts );
}