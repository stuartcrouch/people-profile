<?php
// $Id: page.tpl.php,v 1.0.1 2013/02/28 09:00:00 laustin $
/**
* @file
* page.tpl.php default page layout
* Drupal 7 theme linking OU web standards and OUICE
* written by Lee Austin - +44 (0)7779 146104
*/
?>

  <div id="ou-site-header">
    <?php if ($site_name || $site_slogan || $logo){
      print '<div id="ou-site-ident">';
      print ($logo ? '<img class="go2" src="'. check_url($logo) .'" alt="'. $site_name .'" id="logo" />' : "");
      print ($site_name ? '<p id="ou-site-title">' . $site_name . '</p>' : '');
      print ($site_slogan ? '<p id="ou-site-description">'. $site_slogan .'</p>' : '');
      print '</div>';
    }; ?>
    <!-- Start of site-header -->
      <?php print ($page['region100'] ? render($page['region100']) : ''); ?>
    <!-- End of site-header -->
    <?php if ($main_menu || $secondary_menu) {
      print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('ou-sections'))));
    }	
    ?>
  </div>
  <div id="ou-site-body">
    <div id="ou-page">
      <!-- Start of region 0 -->
        <?php print ($page['region0'] ? '<div id="ou-region0">'.render($page['region0']).'</div>' : ''); ?>
      <!-- End of region 0 -->
      <!-- Start of region 1 -->
        <div id="ou-region1">
        <?php 
          if ($page['help']){
            print render($page['help']);
          }
        ?>
        <div class="ou-content" id="ou-content">
          <?php if ($tabs && $is_admin): ?><div id="tabs-wrapper" class="clearfix"><?php endif; ?>
          <?php print $feed_icons ?>
          <?php if ($tabs && $is_admin): ?><?php print render($tabs); ?></div><?php endif; ?>
          <?php print render($tabs2); ?>
          <?php print $messages; ?>
          <?php print render($page['help']); ?>
          <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
          <?php print render($page['content']); ?>
        </div>
      </div>
      <!-- End of region 1 -->
      <!-- Start of region 2 -->
        <?php print ($page['region2'] ? '<div id="ou-region2">'.render($page['region2']).'</div>' : ''); ?>
      <!-- End of region 2 -->
      <!-- Start of region 3 -->
        <?php print ($page['region3'] ? '<div id="ou-region3">'.render($page['region3']).'</div>' : ''); ?>
      <!-- End of region 3 -->
    </div>
  </div>
  <div id="ou-site-footer">
    <a href="#ou-content" class="ou-to-top">Back to top</a>
  </div>
