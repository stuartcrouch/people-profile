<?php
/**
 * @file
 * Create a list (array) of PIMS CCK column names in the order they appear in the
 * PIMS data file. Flipping this array will enable looking up the array index for
 * a PIMS variable when the PIMS row is read into an array.
 */

$pims_prefix = "field_pims_";
$pims_field_var_names = array(
  "staff_id",
  "staff_title",
  "staff_initials",
  "staff_surname",
  "staff_forenames",
  "pref_surname",
  "pref_forenames",
  "gender",
  "perm_staff_flag",
  "ou_email_address",
  "oucu",
  "personal_website",
  "appt_start_date",
  "appt_due_end_date",
  "appt_term_date",
  "appt_term_reason_code",
  "appt_term_reason",
  "appt_role_code",
  "appt_role_desc",
  "appt_job_title",
  "full_or_part_time",
  "l1_estab_unit_code",
  "l1_estab_unit_desc",
  "l2_estab_unit_code",
  "l2_estab_unit_name",
  "l3_estab_unit_code",
  "l3_estab_unit_name",
  "l4_estab_unit_code",
  "l4_estab_unit_name",
  "l1_locn_unit_code",
  "l1_locn_unit_name",
  "l2_locn_unit_code",
  "l2_locn_unit_name",
  "l3_locn_unit_code",
  "l3_locn_unit_name",
  "l4_locn_unit_code",
  "l4_locn_unit_name",
  "appt_type",
  "fixed_or_perm_appt",
  "probation_end_date",
  "probation_ext_to_date",
  "probation_review_date",
  "room_number",
  "ou_building_code",
  "ou_building_name",
  "work_locn_int_tel_num",
  "work_locn_ext_tel_num",
  "work_locn_fax_num",
  "appt_rspnsblty_notes",
  "unit_job_code",
  "unit_job_code_desc",
  "l1_est_unit_lng_name",
  "l2_est_unit_lng_name",
  "l3_est_unit_lng_name",
  "l4_est_unit_lng_name",
  "l1_loc_unit_long_name",
  "l2_loc_unit_long_name",
  "l3_loc_unit_long_name",
  "l4_loc_unit_long_name",
  "fte",
  "hrs_worked_per_week",
  "sal_con_emp_strt_date",
  "app_start_reason_code",
  "app_start_desc",
  "appointment_number",
);

$pims_field_index = array_flip($pims_field_var_names);



