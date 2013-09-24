<?php
/**
 * @file
 * Maps the Pims CSV file positions to database field names
 *
 */


/* Changelog
	12-Dec-2010 - pdixon
		First version
	13-Dec-2010 - pdixon
		appt_job_title changed from columns 421:475 to columns 899:1248 to reflect changes in acceptance test PIMS data file.
		
 */


/* Schema for PIMS data file
 * field_name => start_col:end_col
 * e.g. staff_id is columns 1 to 8 in the PIMS data file.
 *
 * Edit $a_pims_schema to change the schema.
 */
$a_pims_schema = array(
  'staff_id' => '1:8',
  'staff_title' => '9:15',
  'staff_initials' => '16:19',
  'staff_surname' => '20:44',
  'staff_forenames' => '45:74',         
  'pref_surname' => '75:99',
  'pref_forenames' => '100:129',
  'ou_email_address' => '132:163',
  'oucu' => '164:171',
  'personal_website' => '172:271',
  'appt_role_desc' => '371:420',
  'appt_job_title' => '421:475',
  'l1_estab_unit_code' => '477:480',
  'l1_estab_unit_desc' => '481:505',
  'l2_estab_unit_name' => '510:534',
  'l3_estab_unit_name' => '539:563',
  'l4_estab_unit_name' => '568:592',
  'appt_responsibility_desc' => '899:1248',  
  'sal_con_emp_strt_date' => '1795:1805',
  'appt_start_date' => '272:282',
  'unit_job_code_desc' => '1254:1303',
  'appt_term_date' => '283:293',
  'full_or_part_time' => '476:476',
  'fte' => '1784:1788',
  'hrs_worked_per_week' => '1789:1794',
  'gender' => '130:130',
  'perm_staff_flag' => '131:131',
  'appt_role_code' => '367:370',
);


/*
 *
 * Do not edit below here.
 *
 */

# From the schema above, create an array of field names with the start column and column length
$a_pims_fields = array();
foreach ($a_pims_schema as $field => $cols) {
  $a_cols = explode(':', $cols);
  $a_pims_fields[$field]['start'] = $a_cols[0] - 1;
  $a_pims_fields[$field]['length'] = $a_cols[1] - $a_cols[0] + 1;
}

