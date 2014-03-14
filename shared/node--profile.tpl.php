<?php
/*
error_reporting(E_ALL);
ini_set('display_errors', TRUE);
ini_set('display_startup_errors', TRUE);
*/

// $Id: node.tpl.php,v 3.1 2012/06/29 09:00:00 laustin (07779 146104) $
/**
 * @file node.tpl.php
 *
 * Theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: Node body or teaser depending on $teaser flag.
 * - $picture: The authors picture of the node output from
 *   theme_user_picture().
 * - $date: Formatted creation date (use $created to reformat with
 *   format_date()).
 * - $links: Themed links like "Read more", "Add new comment", etc. output
 *   from theme_links().
 * - $name: Themed username of node author output from theme_user().
 * - $node_url: Direct url of the current node.
 * - $terms: the themed list of taxonomy term links output from theme_links().
 * - $submitted: themed submission information output from
 *   theme_node_submitted().
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 *   Node Elements
 *
 * - $node->field_image[0]['data']['title']
 * - $node->field_use_tokens[0]['value']
 * - $node->content[body]['#value']
 * - $node->field_video[0]['embed']
 * Node status variables:
 * - $teaser: Flag for the teaser state.
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 */
?>
<?php 
global $user;
if (!isset($node->ou_profile)):
  return;
endif;
?>

<!-- start node.tpl.php -->
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print $user_picture; ?>

  <?php print render($title_prefix); ?>
  <h1>
    <?php print $title;
    if( isset( $node->ou_profile['pdata']['group_sss_overrides']['group_letters_after_name']['field_oup_letters']['value']['und']) )
	{
      print (" " .$node->ou_profile['pdata']['group_sss_overrides']['group_letters_after_name']['field_oup_letters']['value']['und'][0]['value']);
    }
    ?>
  </h1>
  <?php print render($title_suffix); ?>
  <?php
    /*
    * Check to see if user has permission to edit node/profile
    * If so, present an edit button.
    * Currently works for content owner and admin.
    * TODO: Add a role so that IT/Comms etc can test and access all profile edit options.
    */
    print( ou_profile_edit_profile_link( $node, $user ) );
  ?>

  <div class="content clearfix"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      // If OUBrand module being used
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_media']);
      hide($content['field_blockquote']);
      hide($content['field_image']);
      
    ?>
 
 <?php
    $profile_header = '';
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
    if (isset($node->ou_profile['pdata']['group_sss_info']['group_photograph']['field_oup_photo']) &&
        isset($node->ou_profile['pdata']['group_sss_info']['group_photograph']['field_oup_photo']['value']['und'][0]['uri'])) {
        $path = '';
        $alt = '';
        $title = '';
        $profile_sidebar .= '<div class="profile-image">' . 
          ou_profile_request_image('profile_photo', $node->ou_profile['pdata']['group_sss_info']['group_photograph']['field_oup_photo']['value']['und'][0]['uri']) .
          //'<img src="' $request_url . 'sites/www.open.ac.uk.sac76/files/styles/profile_photo/public/' . $node->ou_profile['pdata']['group_sss_info']['group_photograph']['field_oup_photo']['value']['und'][0]['uri'] . '" />"' .
          //theme_image_style(array('style_name' => 'profile_photo', 'path' => $node->ou_profile['pdata']['group_sss_info']['group_photograph']['field_oup_photo']['value']['und'][0]['uri'])) .
          
          '</div>';
    }

    if (isset($node->ou_profile['pdata']['group_layout_design']['group_image']['field_oup_profile_layout_image']['value']['und'][0]['uri'])) {
        $path = '';
        $alt = '';
        $title = '';
        $profile_header .= '<div class="profile-photo">' . 
          ou_profile_request_image('profile_image', $node->ou_profile['pdata']['group_layout_design']['group_image']['field_oup_profile_layout_image']['value']['und'][0]['uri']) .
          //theme_image_style(array('style_name' => 'profile_image', 'path' => $node->ou_profile['pdata']['group_layout_design']['group_image']['field_oup_profile_layout_image']['value']['und'][0]['uri'])) .
          '</div>';
    }

    if (isset($node->ou_profile['pdata']['group_sss_info']['group_appt_role_desc']['field_pdat_appt_role_desc']) && 
        isset($node->ou_profile['pdata']['group_sss_info']['group_appt_role_desc']['field_pdat_appt_role_desc']['value']['und'][0]['value'])) {
        $profile_summary .= '<li>'.$node->ou_profile['pdata']['group_sss_info']['group_appt_role_desc']['field_pdat_appt_role_desc']['value']['und'][0]['value'].'</li>';
    }

    if (isset($node->ou_profile['pdata']['group_sss_overrides']['group_unab_job_title']['field_oup_job_title']['value']['und'][0]['value']) || 
        isset($node->ou_profile['pdata']['group_sss_info']['group_appt_job_title']['field_pdat_appt_job_title']['value']['und'][0]['value'])) {
        $profile_summary .= '<li>';

        if (isset($node->ou_profile['pdata']['group_sss_overrides']['group_unab_job_title']['field_oup_job_title']['value']['und'][0]['value'])){
            $profile_summary .= $node->ou_profile['pdata']['group_sss_overrides']['group_unab_job_title']['field_oup_job_title']['value']['und'][0]['value'];
        }
        elseif (isset($node->ou_profile['pdata']['group_sss_info']['group_appt_job_title']['field_pdat_appt_job_title']['value']['und'][0]['value'])) {
            $profile_summary .= $node->ou_profile['pdata']['group_sss_info']['group_appt_job_title']['field_pdat_appt_job_title']['value']['und'][0]['value'];
        }
        $profile_summary .= "</li>";
    }

    // if ($node->ou_profile['pdata']['group_header']['field_pdat_appt_job_title']['value']) {
    //         $profile_summary .= "<li>".$node->ou_profile['pdata']['group_header']['field_pdat_appt_job_title']['value']."</li>";
    //     }
  if (isset($node->ou_profile['pdata']['group_header']['group_sss_info']['field_pims_l1_estab_unit_desc']) &&
      isset($node->ou_profile['pdata']['group_header']['group_sss_info']['field_pims_l1_estab_unit_desc']['value']['und'][0]['value'])){
    $profile_summary .= "</li>" . $node->ou_profile['pdata']['group_header']['group_sss_info']['field_pims_l1_estab_unit_desc']['value']['und'][0]['value'].'</li>';
  }
  // TODO: THIS DOESNT GET ADDED TO THE ARRAY - Maybe doesnt exist?
  //if (isset($node->ou_profile['pdata']['group_header']['field_pims_l1_estab_unit_name']) &&
  //    isset($node->ou_profile['pdata']['group_header']['field_pims_l1_estab_unit_name']['value'])) {
  //      $profile_summary .= "<li>".$node->ou_profile['pdata']['group_header']['field_pims_l1_estab_unit_name']['value']['und'][0]['value']."</li>";
  //}
  if (isset($node->ou_profile['pdata']['group_header']['group_sss_info']['field_pims_l2_estab_unit_name']) &&
      isset($node->ou_profile['pdata']['group_header']['group_sss_info']['field_pims_l2_estab_unit_name']['value']['und'][0]['value'])) {
    $profile_summary .= "<li>".$node->ou_profile['pdata']['group_header']['group_sss_info']['field_pims_l2_estab_unit_name']['value']['und'][0]['value']."</li>";
  }

  if (isset($node->ou_profile['pdata']['group_header']['group_sss_info']['field_pims_l3_estab_unit_name']) &&
      isset($node->ou_profile['pdata']['group_header']['group_sss_info']['field_pims_l3_estab_unit_name']['value']['und'][0]['value'])) {
    $profile_summary .= "<li>".$node->ou_profile['pdata']['group_header']['group_sss_info']['field_pims_l3_estab_unit_name']['value']['und'][0]['value']."</li>";
  }

  if (isset($node->ou_profile['pdata']['group_header']['group_sss_info']['field_pims_l4_estab_unit_name']['und'][0]['value']) &&
    isset($node->ou_profile['pdata']['group_header']['group_sss_info']['field_pims_l4_estab_unit_name']['value']['und'][0]['value'])) {
      $profile_summary .= "<li>".$node->ou_profile['pdata']['group_header']['group_sss_info']['field_pims_l4_estab_unit_name']['value']['und'][0]['value']."</li>";
  }

  if (isset($node->ou_profile['pdata']['group_header']['group_sss_info']['field_pims_ou_email_address']) &&
      isset($node->ou_profile['pdata']['group_header']['group_sss_info']['field_pims_ou_email_address']['value']['und'][0]['value'])) {
      $profile_summary .= '<li><a href="mailto:' . $node->ou_profile['pdata']['group_header']['group_sss_info']['field_pims_ou_email_address']['value']['und'][0]['value'] . '@open.ac.uk">' .
      $node->ou_profile['pdata']['group_header']['group_sss_info']['field_pims_ou_email_address']['value']['und'][0]['value'] . 
      "</a></li>\n";
      
  }

  if (isset($node->ou_profile['pdata']['group_sss_overrides']['group_alt_email_add']['field_oup_alternative_email']) &&
    isset($node->ou_profile['pdata']['group_sss_overrides']['group_alt_email_add']['field_oup_alternative_email']['value']['und'][0]['value'])) {
        $profile_summary .= '<li><a href="mailto:'.$node->ou_profile['pdata']['group_sss_overrides']['group_alt_email_add']['field_oup_alternative_email']['value']['und'][0]['value'] . 
        '@open.ac.uk">' . $node->ou_profile['pdata']['group_sss_overrides']['group_alt_email_add']['field_oup_alternative_email']['value']['und'][0]['value'] . 
        "</a></li>\n";
    }

    //===============================================================
    // Create inline navigation and populate profile content variable
    //
    // Setup inline anchor navigation
    // loop through 'group_teaching_research_interest' group
    //===============================================================


  //This is for the "Profile" Tab
  $profile_bio = "";
  if( isset( $node->ou_profile['pdata']['group_teaching_research_interest'] ) )
  {
    //Remove the openlearn bio (Remove this line for sites that require the bio).
    unset( $node->ou_profile['pdata']['group_teaching_research_interest']['group_openlearn_bio'] );

    foreach ($node->ou_profile['pdata']['group_teaching_research_interest'] as $item) {
      // This is now an array of one element, so step into it
      $item = reset($item);
      if ($item['value']) {
        if (is_array($item['value'])){
          $fields_item = NULL;
          foreach ($item['value'] as $fields) {
            $fields = reset($fields);
            if (isset($fields['value'])) {
			  if( trim( $fields['value'] ) != '' )
			  {
                $fields_item .= $fields['value'];
              }
            }
          }
		  if( !empty( $fields_item ) )
		  {
			  $profile_bio .= '<h2 id="'.$item['label'].'">'.$item['label'].'</h2>'."\n<ul>".$fields_item."</ul>";
			  $inpage_navigation[] .= '<li><a href="#'.$item['label'].'">'.$item['label'].'</a></li>';
		  }
		  
        } else {
		  if( !empty( $item['value'] ) )
		  {
		      $profile_bio .= '<h2 id="'.$item['label'].'">'.$item['label'].'</h2>';
              $profile_bio .= $item['value'];
		  }
        }
      }
    }
	if( $profile_bio != "" )
	{
      $profile_content['Profile'] = $profile_bio;
	}
  }

  //This is for the "Media" tab, uncomment this is required by the site
  /*
  $media_bio = "";
  if( isset( $node->ou_profile['pdata']['group_content_groups']['group_media_expert'] ) )
  {

	$item = $node->ou_profile['pdata']['group_content_groups']['group_media_expert']['field_oup_media_relations_bio'];

      if ($item['value'])
	  {
        if (is_array($item['value']))
		{
          $fields_item = NULL;
          foreach ($item['value'] as $fields)
		  {
            $fields = reset($fields);
            if (isset($fields['value']))
			{
              $fields_item .= $fields['value'];
            }
          }
          $media_bio .= '<h2 id="media_bio">Biography</h2>'."\n<ul>".$fields_item."</ul>";
        } else {
          $media_bio .= '<h2 id="media_bio">Biography</h2>';
          $media_bio .= $item['value'];
        }
      }
    
	if( $media_bio != "" )
	{
      $profile_content['Media Profile'] = $media_bio;
	}
  }
  */

  //Display RPS data
  if( isset( $node->ou_profile['rps_data'] ) )
  {
     $profile_content['Research Activity'] = $node->ou_profile['rps_data']['#markup'];
  }
  
  //Get ORO data
  $oro = _ou_profile_generate_oro_html( $node );
  if( $oro <> "" )
  {
    $profile_content['Publications'] = $oro;
  }
   

    //===============================================================
    // Create weblinks
    //===============================================================
    $weblinks = '';
    $text_links = '';

//    if($weblink = $node->ou_profile['pdata']['group_external_profiles_accounts']['field_pdat_personal_website']['value']){
//      $text_links .= '<li><a href="'.$weblink.'">'.$node->ou_profile['pdata']['group_external_profiles_accounts']['field_pdat_personal_website']['label'].'</a></li>';
//    }
    
    if(isset($node->ou_profile['pdata']['group_external_profiles_accounts']['group_web_links']['field_oup_web_links']['value']['und'])){
      foreach ($node->ou_profile['pdata']['group_external_profiles_accounts']['group_web_links']['field_oup_web_links']['value']['und'] as $item) {
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

    // append other web links
    //$other_links = array('field_oup_linkedin','field_oup_slideshare','field_oup_blog','field_oup_flickr');
    $other_links = array('linkedin','slideshare','blog','flickr','twitter');
    foreach ($other_links as $link_field) {
        if (isset($node->ou_profile['pdata']['group_external_profiles_accounts']['group_' . $link_field]['field_oup_' .$link_field]['value']['und'][0])) {
          
          // Grab the array contents for easier processing
          $link_info = $node->ou_profile['pdata']['group_external_profiles_accounts']['group_' . $link_field]['field_oup_' .$link_field]['value']['und'][0];
		  
		  //Check if first item in array is empty (pims import creates empty fields. When profile is save for first time, they are deleted.)
		  $first_value = reset( $link_info );
		  if( !empty( $first_value ) )
		  {
			  // If we are twitter, it only asks for the name so do it different
			  // NB: Lee Austin asks - Why are we using a different class name here.
			  if ($link_field == 'twitter') {
				$weblinks .= '<li class="twitter"><a href="http://twitter.com/' . $link_info['value'] . '">Follow @' . $link_info['value'] . ' on Twitter</a></li>';
			  }
			  else {
				// Display the links.
				if (isset($link_info['url'])) {
				  $weblinks .= '<li class="'.$link_field.'"><a href="'. $link_info['url'] .'">'.$link_info['title'].'</a></li>';
				}
			  }
		  }
        }
    }
    if ( $weblinks != "" || $text_links != "" ) {
      $inpage_navigation[] .= '<li><a href="#weblinks">Web links</a></li>';
      //$profile_sidebar .= '<div class="profile-summary"><h2>Profile summary</h2><ul>'.$profile_summary.'</ul></div>';
      
      if( $text_links != "" ) {
        $profile_sidebar .= '<div class="profile-text-links"><ul class="profile-text-links">'.$text_links.'</ul></div>';
      }
      if( $weblinks != "" ) {
        $profile_sidebar .= '<div class="profile-web-links"><h2>Web links</h2><div class="icons"><ul>'.$weblinks.'</ul></div></div>';
      }
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
	 
	 
	 if( isset( $profile_content ) )
	 {
	   $profile_content_html = "";
	   
       $profile_content_html = '<div class="profile-content"><div class="wrap">';
	   
	   $profile_tabs = '<ul class="ou-sections tabs">';
       $profile_tabs_content = '<div class="ou-binder">';
       $tab = 1;
	   foreach( $profile_content as $tab_title => $tab_content )
	   {
	      if( $tab == 1 )
		  {
            $profile_tabs .="<li><a class='ou-selected' href='#tab".$tab."'>".$tab_title."</a></li> \n";
            $profile_tabs_content .='<div class="tab-content selected tab'.$tab.'">'.$tab_content.'</div>';
          } else {
            $profile_tabs .="<li><a href='#tab".$tab."'>".$tab_title."</a></li> \n";
            $profile_tabs_content .='<div class="tab-content tab'.$tab.'">'.$tab_content.'</div>';
		  }
		  
		  $tab++;
	   }
	   $profile_tabs .= '</ul>';
	   $profile_tabs_content .='</div>';

	   $profile_content_html .= $profile_tabs;
	   $profile_content_html .= $profile_tabs_content;
	   
	   $profile_content_html .= '</div></div>';
	   
	   print $profile_content_html;
     }
	 
	 
    print '</div></div>';
	
  ?>
  </div>

  <div class="clearfix">
    <?php if (!empty($content['links'])): ?>
      <div class="links"><?php print render($content['links']); ?></div>
    <?php endif; ?>

    <?php print render($content['comments']); ?>
  </div>

</div>
<!-- /#node-<?php print $node->nid; ?> -->
