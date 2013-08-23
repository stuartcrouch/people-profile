<?php
$modulepath = drupal_get_path('module', 'ou_profile');
include_once($modulepath . '/includes/people_functions.inc');
//print_r($node->ou_profile['pdata']['group_layout_design']);
global $user;
// global $base_theme_info;
// global $theme;
// global $theme_key;
// print_r($base_theme_info['name']);
// print_r($theme);
// print_r($theme_key);
?>
<!-- start ouprofile node-profile.tpl.php v2.0.1 -->
<div id="node-<?php print $node->nid; ?>" class="node <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print $picture ?>
  <div class="profile-title">
    <h1>
  	  <?php print $title;
  	    if ($node->ou_profile['pdata']['group_header']['field_oup_letters']['value']) {
          print (" - " .$node->ou_profile['pdata']['group_header']['field_oup_letters']['value']['und'][0]['value']);
        } ?>
      </h1>
      <?php
        //if ($account->uid == 1 ) {
          //print '<a class="profile-button" href="node/' . $node->nid . '/edit">Edit profile</a>';
          /*
          * Check to see if user has permission to edit node/profile
          * If so, present an edit button.
          * Currently works for content owner and admin.
          * TODO: Add a role so that IT/Comms etc can test and access all profile edit options.
          */
          if ((node_access('update', $node, $user) == TRUE) || ($account->uid == 1)) {
            print '<a class="profile-button" href="' . $node->nid . '/edit">Edit profile</a>';
          }
          // node_access('update', $node, $user) - function to check if user had access to view/edit/delete page
        //}
        ?>

  </div>

  <!-- <?php print_r($node->ou_profile['pdata']); ?> -->
  <?php
    $profile_header = '';
    $profile_content = '';
    $profile_sidebar = '';
    $profile_summary = '';
    $inpage_navigation = array();

    //===============================================================
    // Create profile header
    //===============================================================


	  // if ($node->ou_profile['pdata']['group_header']['field_oup_job_title']['value'] || $node->ou_profile['pdata']['group_header']['field_pdat_l1_estab_unit_desc']['value']) {
	  //         $profile_header .= '<div class="profile-title"><h1>';
	  //
	  //         if ($node->ou_profile['pdata']['group_header']['field_oup_job_title']['value']){
	  //             $profile_header .= $node->ou_profile['pdata']['group_header']['field_oup_job_title']['value'];
	  //         }
	  //         elseif ($node->ou_profile['pdata']['group_header']['field_pdat_appt_job_title']['value']) {
	  //             //$profile_header .= $node->ou_profile['pdata']['group_header']['field_pdat_appt_job_title']['value'];
	  //         }
	  //         if ($node->ou_profile['pdata']['group_header']['field_pdat_l1_estab_unit_desc']['value']){
	  //           //$profile_header .= " - " . $node->ou_profile['pdata']['group_header']['field_pdat_l1_estab_unit_desc']['value'];
	  //         }
	  //         $profile_header .= "</h1></div>";
	  //     }


//May need to add below to OUBS page
    if (isset($node->ou_profile['pdata']['group_header']['field_oup_photo']) && $node->ou_profile['pdata']['group_header']['field_oup_photo']['value']) {
        $path = '';
        $alt = '';
        $title = '';
        $profile_sidebar .= '<div class="profile-image">' . theme('imagecache', 'profile_photo', $node->ou_profile['pdata']['group_header']['field_oup_photo']['value'], $alt, $title, $attributes).'</div>';
    }

    if ($node->ou_profile['pdata']['group_layout_design']['field_oup_profile_layout_image']['value']) {
        $path = '';
        $alt = '';
        $title = '';
        $profile_header .= '<div class="profile-photo">' . theme('imagecache', 'profile_image', $node->ou_profile['pdata']['group_layout_design']['field_oup_profile_layout_image']['value'], $alt, $title, $attributes).'</div>';
    }

    if (isset($node->ou_profile['pdata']['group_header']['field_pdat_appt_role_desc']) && $node->ou_profile['pdata']['group_header']['field_pdat_appt_role_desc']['value']) {
        $profile_summary .= '<li>'.$node->ou_profile['pdata']['group_header']['field_pdat_appt_role_desc']['value'].'</li>';
    }

    if ($node->ou_profile['pdata']['group_header']['field_oup_job_title']['value'] || $node->ou_profile['pdata']['group_header']['field_pdat_appt_job_title']['value']) {
        $profile_summary .= '<li>';

        if ($node->ou_profile['pdata']['group_header']['field_oup_job_title']['value']){
            $profile_summary .= $node->ou_profile['pdata']['group_header']['field_oup_job_title']['value'];
        }
        elseif ($node->ou_profile['pdata']['group_header']['field_pdat_appt_job_title']['value']) {
            $profile_summary .= $node->ou_profile['pdata']['group_header']['field_pdat_appt_job_title']['value'];
        }
        $profile_summary .= "</li>";
    }

	  // if ($node->ou_profile['pdata']['group_header']['field_pdat_appt_job_title']['value']) {
	  //         $profile_summary .= "<li>".$node->ou_profile['pdata']['group_header']['field_pdat_appt_job_title']['value']."</li>";
	  //     }
	if (isset($node->ou_profile['pdata']['group_header']['field_pims_l1_estab_unit_desc']) &&
	    isset($node->ou_profile['pdata']['group_header']['field_pims_l1_estab_unit_desc']['value'])){
	      $profile_summary .= "</li>" . $node->ou_profile['pdata']['group_header']['field_pims_l1_estab_unit_desc']['value']['und'][0]['value'].'</li>';
	}
	if (isset($node->ou_profile['pdata']['group_header']['field_pims_l1_estab_unit_name']) &&
	    isset($node->ou_profile['pdata']['group_header']['field_pims_l1_estab_unit_name']['value'])) {
        $profile_summary .= "<li>".$node->ou_profile['pdata']['group_header']['field_pims_l1_estab_unit_name']['value']['und'][0]['value']."</li>";
    }
    if (isset($node->ou_profile['pdata']['group_header']['field_pims_l2_estab_unit_name']) &&
        isset($node->ou_profile['pdata']['group_header']['field_pims_l2_estab_unit_name']['value'])) {
        $profile_summary .= "<li>".$$node->ou_profile['pdata']['group_header']['field_pims_l2_estab_unit_name']['value']['und'][0]['value']."</li>";
    }
	if (isset($node->ou_profile['pdata']['group_header']['field_pims_l3_estab_unit_name']) &&
	    isset($node->ou_profile['pdata']['group_header']['field_pims_l3_estab_unit_name']['value'])) {
        $profile_summary .= "<li>".$node->ou_profile['pdata']['group_header']['field_pims_l3_estab_unit_name']['value']['und'][0]['value']."</li>";
    }
    if (isset($node->ou_profile['pdata']['group_header']['field_pims_l4_estab_unit_name']) &&
	    isset($node->ou_profile['pdata']['group_header']['field_pims_l4_estab_unit_name']['value'])) {
        $profile_summary .= "<li>".$node->ou_profile['pdata']['group_header']['field_pims_l4_estab_unit_name']['value']['und'][0]['value']."</li>";
    }
    if (isset($node->ou_profile['pdata']['group_header']['field_pims_ou_email_address']) &&
		isset($node->ou_profile['pdata']['group_header']['field_pims_ou_email_address']['value'])) {
        $profile_summary .= '<li><a href="mailto:'.$node->ou_profile['pdata']['group_header']['field_pims_ou_email_address']['value'].'@open.ac.uk">'.$node->ou_profile['pdata']['group_header']['field_pdat_ou_email_address']['value'] ."</a></li>\n";
    }
	if (isset($node->ou_profile['pdata']['group_header']['field_oup_alternative_email']) &&
		isset($node->ou_profile['pdata']['group_header']['field_oup_alternative_email']['value'])) {
        $profile_summary .= '<li><a href="mailto:'.$node->ou_profile['pdata']['group_header']['field_oup_alternative_email']['value'].'@open.ac.uk">'.$node->ou_profile['pdata']['group_header']['field_oup_alternative_email']['value'] ."</a></li>\n";
    }



    //===============================================================
    // Create inline navigation and populate profile content variable
    //
    // Setup inline anchor navigation
    // loop through 'group_teaching_research_interest' group
    //===============================================================
	if ($node->ou_profile['pdata']['group_teaching_research_interest'])
	{
		foreach ($node->ou_profile['pdata']['group_teaching_research_interest'] as $item) {
			if ($item['value']) {
			  $inpage_navigation[] .= '<li><a href="#'.$item['label'].'">'.$item['label'].'</a></li>';
				if (is_array($item['value'])){
					foreach ($item['value'] as $fields) {
						if ($fields['value']) {
						  $fields_item .= '<li>'.$fields['value'].'</li>';
						}
					  }
					$profile_content .= '<h2 id="'.$item['label'].'">'.$item['label'].'</h2>'."\n<ul>".$fields_item."</ul>";
				} else {
					$profile_content .= '<h2 id="'.$item['label'].'">'.$item['label'].'</h2>';
					$profile_content .= $item['value'];
				}
			}
		  }

		//===============================================================
		// Create weblinks
		//===============================================================
		$weblinks = '';
		$text_links = '';

		if($weblink = $node->ou_profile['pdata']['group_external_profiles_accounts']['field_pdat_personal_website']['value']){
			$text_links .= '<li><a href="'.$weblink.'">'.$node->ou_profile['pdata']['group_external_profiles_accounts']['field_pdat_personal_website']['label'].'</a></li>';
		}

		if($node->ou_profile['pdata']['group_external_profiles_accounts']['field_oup_web_links']['value']){
			foreach ($node->ou_profile['pdata']['group_external_profiles_accounts']['field_oup_web_links']['value'] as $item) {
				if ($item['url']) {
					if ($item['url']) {
					  $text_links .= '<li><a href="'.$item['url'].'">';
					  if ($item['title']) {
						 $text_links .= $item['title'];
					  } else {
						 $text_links .= $item['url'];
					  }
					  $text_links .= "</a></li>";
					}
				}
		  }
		}

		// append other web links
		$other_links = array('field_oup_linkedin','field_oup_slideshare','field_oup_blog','field_oup_flickr');
		foreach ($other_links as $link_field) {
		    if (isset($node->ou_profile['pdata']['group_external_profiles_accounts'][$link_field]['value']['und'][0])) {
    		    $link_info = $node->ou_profile['pdata']['group_external_profiles_accounts'][$link_field]['value']['und'][0];
    			if (isset($link_info['url'])) {
    				$weblinks .= '<li class="'.$link_field.'"><a href="'. $link_info['url'] .'">'.$link_info['title'].'</a></li>';
    			}
		    }
		}
		// including Twitter
		// NB: Lee Austin asks - Why are we using a different class name here compared to the loop above?!!?
		if ($weblink = $node->ou_profile['pdata']['group_external_profiles_accounts']['field_oup_twitter']['value']['und'][0]['value']) {
			$weblinks .= '<li class="twitter"><a href="http://twitter.com/'.$weblink.'">Follow @'.$weblink.' on Twitter</a></li>';
		}
		if ($weblinks) {
			$inpage_navigation[] .= '<li><a href="#weblinks">Web links</a></li>';
			//$profile_sidebar .= '<div class="profile-summary"><h2>Profile summary</h2><ul>'.$profile_summary.'</ul></div>';
			$profile_sidebar .= '<div class="profile-text-links"><ul class="profile-text-links">'.$text_links.'</ul></div>';
			$profile_sidebar .= '<div class="profile-web-links"><h2>Web links</h2><div class="icons"><ul>'.$weblinks.'</ul></div></div>';
		}

		if ($profile_summary) {
		   $profile_sidebar .=  '<div class="profile-summary"><h2>Profile summary</h2><ul>'.$profile_summary.'</ul></div>';
	   }

		//===============================================================
		// Now render the inline profile navigation and content
		//===============================================================
		 if ($profile_header) {
		   print $profile_header;
	   }

		 print '<div class="profile"><div class="wrap clearfix">';
		 if (count($inpage_navigation)>1) {
        print '<div class="profile-menu" id="profile-menu">'."<h2>Skip to</h2>\n";
        //print "<p>See below for ".$title."'s:</p>\n";
        print "<ul>";
        foreach($inpage_navigation as $item) print $item;
        print "</ul></div>\n";
  		 }
		 if ($profile_sidebar) {
		   print '<div class="profile-sidebar"><div class="wrap">'.$profile_sidebar.'</div></div>';
	   }
		 if ($profile_content) {
		   print '<div class="profile-content"><div class="wrap">'.$profile_content.'</div></div>';
	   }
		print '</div></div>';
	}
  ?>
  </div>
  <?php
    // Only display the wrapper div if there are links.
    $links = render($content['links']);
    if ($links):
  ?>
    <div class="link-wrapper">
      <?php print $links; ?>
    </div>
  <?php endif; ?>
<!-- /#node-<?php print $node->nid; ?> -->
<!-- end node-profile.tpl.php -->
