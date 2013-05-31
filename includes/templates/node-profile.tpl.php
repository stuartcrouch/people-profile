<?php
// $Id: node-ou_profile.tpl.php,v 1.1 2011/08/22 09:00:00 laustin $
$modulepath = drupal_get_path('module', 'ou_profile');
include_once($modulepath . '/includes/people_functions.inc');
?>
<!-- start ou_profile node-profile.tpl.php -->
<div id="node-<?php print $node->nid; ?>" class="node <?php print $node_classes; ?>">
  <?php print $picture ?>
  <h1 class="title">
	<?php print $title; 
	if ($node->ou_profile['pdata']['group_header']['field_oup_letters']['value']) {
        print (" - " .$node->ou_profile['pdata']['group_header']['field_oup_letters']['value']);
    } 
	?>
  </h1>
 
  <div class="content">
  <!-- <?php print_r($node->ou_profile['pdata']); ?> -->
  <?php



    $profile_header = '';
    $profile_content = '';
    $inpage_navigation = array();
    
    //===============================================================
    // Create profile header
    //===============================================================
	    
    if ($node->ou_profile['pdata']['group_header']['field_oup_photo']['value']) {
        $profile_header .= '<div class="profilephoto">'.$node->ou_profile['pdata']['group_header']['field_oup_photo']['value'].'</div>';
    }
    
    if ($node->ou_profile['pdata']['group_header']['field_oup_job_title']['value'] || $node->ou_profile['pdata']['group_header']['field_pdat_l1_estab_unit_desc']['value']) {
        $profile_header .= '<h2>';
        
        if ($node->ou_profile['pdata']['group_header']['field_oup_job_title']['value'])
            $profile_header .= $node->ou_profile['pdata']['group_header']['field_oup_job_title']['value'];
        else if ($node->ou_profile['pdata']['group_header']['field_pdat_appt_job_title']['value'])
            $profile_header .= $node->ou_profile['pdata']['group_header']['field_pdat_appt_job_title']['value'];
            
        if  ($node->ou_profile['pdata']['group_header']['field_pdat_l1_estab_unit_desc']['value'])
            $profile_header .= " - " . $node->ou_profile['pdata']['group_header']['field_pdat_l1_estab_unit_desc']['value'];
        
        $profile_header .= "</h2>";
    }
	
	if ($node->ou_profile['pdata']['group_header']['field_pdat_appt_role_desc']['value']) {
        $profile_header .= '<h3>'.$node->ou_profile['pdata']['group_header']['field_pdat_appt_role_desc']['value'].'</h3>';
    }
	
    
    if ($centre = $node->ou_profile['pdata']['group_header']['field_pdat_l2_estab_unit_name']['value']) {
        $profile_header .= "<h3>".$centre."</h3>";
    }
	
	if ($centre = $node->ou_profile['pdata']['group_header']['field_pdat_l3_estab_unit_name']['value']) {
        $profile_header .= "<h3>".$centre."</h3>";
    }
	
	if ($centre = $node->ou_profile['pdata']['group_header']['field_pdat_l4_estab_unit_name']['value']) {
       $profile_header .= "<h3>".$centre."</h3>";
    }
   /* 
    if ($node->ou_profile['pdata']['group_header']['field_pdat_ou_email_address']['value']) {
        $profile_header .= '<p>You can <a href="mailto:'.$node->ou_profile['pdata']['group_header']['field_pdat_ou_email_address']['value'].'@open.ac.uk">email '.$node->title."</a> directly; ";
        $profile_header .= 'but for media enquiries please contact a member of <a href="http://www3.open.ac.uk/media/contacts.aspx">'."The Open University's Media Relations team</a>.</p>\n";
    }
    */
		
	if ($node->ou_profile['pdata']['group_header']['field_pdat_ou_email_address']['value']) {
        $profile_header .= '<p><a href="mailto:'.$node->ou_profile['pdata']['group_header']['field_pdat_ou_email_address']['value'].'@open.ac.uk">'.$node->ou_profile['pdata']['group_header']['field_pdat_ou_email_address']['value'] ."</a></p>\n";
    }
	
	if ($node->ou_profile['pdata']['group_header']['field_oup_alternative_email']['value']) {
        $profile_header .= '<p><a href="mailto:'.$node->ou_profile['pdata']['group_header']['field_oup_alternative_email']['value'].'@open.ac.uk">'.$node->ou_profile['pdata']['group_header']['field_oup_alternative_email']['value'] ."</a></p>\n";
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
					$profile_content .= '<h3 id="'.$item['label'].'">'.$item['label'].'</h3>'."\n<ul>".$fields_item."</ul>";
				} else {
					$profile_content .= '<h3 id="'.$item['label'].'">'.$item['label'].'</h3>';
					$profile_content .= $item['value'];
				}
			}
		  }
		
		//===============================================================
		// Create weblinks
		//===============================================================
		$weblinks = "";
		
		if($weblink = $node->ou_profile['pdata']['group_external_profiles_accounts']['field_pdat_personal_website']['value']){
			$weblinks .= '<li><a href="'.$weblink.'">'.$node->ou_profile['pdata']['group_external_profiles_accounts']['field_pdat_personal_website']['label'].'</a></li>';
		}
		
		if($node->ou_profile['pdata']['group_external_profiles_accounts']['field_oup_web_links']['value']){
			foreach ($node->ou_profile['pdata']['group_external_profiles_accounts']['field_oup_web_links']['value'] as $item) {
				if ($item['url']) {
					if ($item['url']) {
					  $weblinks .= '<li><a href="'.$item['url'].'">';
					  if ($item['title']) {
						 $weblinks .= $item['title'];
					  } else {
						 $weblinks .= $item['url'];
					  }
					  $weblinks .= "</a></li>";
					}
				}
			  }
		}
		

		// append other web links
		$other_links = array('field_oup_linkedin','field_oup_slideshare','field_oup_blog','field_oup_flickr');
		foreach ($other_links as $link_field) {
			if ($weblink = $node->ou_profile['pdata']['group_external_profiles_accounts'][$link_field]['value']['url']) {
				$weblinks .= '<li><a href="'.$weblink.'">'.$node->ou_profile['pdata']['group_external_profiles_accounts'][$link_field]['label'].'</a></li>';
			}
		}
		// including Twitter
		if ($weblink = $node->ou_profile['pdata']['group_external_profiles_accounts']['field_oup_twitter']['value']) {
			$weblinks .= '<li><a href="http://twitter.com/'.$weblink.'">Follow @'.$weblink.' on Twitter</a></li>';
		}

		if ($weblinks) {
			$inpage_navigation[] .= '<li><a href="#weblinks">Web links</a></li>';
			$profile_content .= '<h3 id="weblinks">Web links</h3>'."\n<ul>".$weblinks."</ul>";
		}
		
		//===============================================================
		// Now render the inline profile navigation and content
		//===============================================================
		 if ($profile_header) print '<div class="profile-header">'.$profile_header."</div>\n";
		 if (count($inpage_navigation)>1) {
			print '<div class="profile-navigation">'."<h2>Staff profile</h2>\n";
			print "<p>See below for ".$title."'s:</p>\n";
			print "<ul>";
			foreach($inpage_navigation as $item) print $item;
			print "</ul></div>\n";
		 }
		if ($profile_content) print '<div class="profile-content">'.$profile_content."</div>\n";
	}
  ?>
  </div>
  <?php if ($terms): ?>
  <div class="terms">
    <?php print $terms; ?>
  </div>
  <?php endif;?>
  <?php if ($links): ?>
  <div class="links">
    <?php print $links; ?>
  </div>
  <?php endif; ?>
  <?php if ($node_bottom && !$teaser): ?>
  <div id="node-bottom">
    <?php print $node_bottom; ?>
  </div>
  <?php endif; ?>
  
   <div class="meta">
    <?php if ($submitted): ?>
    <span class="submitted"><?php print $submitted ?></span>
    <?php endif; ?>
  </div>
</div>
<!-- /#node-<?php print $node->nid; ?> -->
<!-- end node-profile.tpl.php -->