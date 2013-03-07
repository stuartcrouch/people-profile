<?php
// $Id: page.tpl.php,v 2.0 2010/06/08 09:00:00 laustin and PConolly $
/**
 * @file
 * page.tpl.php default page layout
 * Drupal 6 theme linking OU webstandards, OUICE and Headscape work
 * written by Lee Austin - +44 (0)7779 146104 & Paul Conolly - +44 01634 813182
 * 	
 */
?>
<!DOCTYPE HTML>
<html xmlns="http://www.w3.org/1999/xhtml" lang="en-GB" xml:lang="en-GB">
<head>
<!--- page.tpl v2.0 --->
    <title><?php  print $head_title; ?></title>
    <?php  // get the common header elements (This can be called by all page templates)
	$incfile=drupal_get_path('theme','ou_exstd')."/includes/header.php";
        include($incfile);
    ?>
    <?php print $head ?>
    <?php if (empty($node->nodewords[keywords][value])):
        print '<meta name="keywords" content="'.$node->title.','.$site_name.',Open University" />';
    endif; ?>
    <meta name="robots" content="noodp" />
</head>
<body class="ouice sections i5<?php print ($region2 ? '' : " pure"); ?>">
<div id="org">
    <?php  // INCLUDE THE OU HEADER
        $header_footer_selection = phptemplate_get_header_footer();
        if (!empty($header_footer_selection['header'])):
            include($header_footer_selection['header']);
        else:
			if ($header_footer_selection['header'] != ''):
				print $header_footer_selection['error'];
			endif;
        endif; ?>
    <div id="site">
        <div id="site-header">
            <?php if ($site_name || $site_slogan):
                print '<div id="site-ident">';
                print '<p id="site-title">'. $site_name .'</p>';
                print '<p id="site-description">'. $site_slogan .'</p>';
                print '</div>';
            endif; ?>
			<!-- Start of site-header -->
                <?php if ($region100): ?>
                    <?php print $region100; ?>
                <?php endif; ?>
            <!-- End of site-header -->
            <?php if ($siteheaderbanner): ?>
                <div id="intro">			
                    <div class="grid" id="intro01">
                        <?php print $siteheaderbanner; ?>
                    </div>
                </div>
            <?php endif; ?>
            <?php if (isset($primary_links)):
                print (module_exists('oubrand') ? oubrand_primarylinks($primary_links, array('class' => 'sections')) : phptemplate_primarylinks($primary_links, array('class' => 'sections')));
            endif; ?>
            <?php if (isset($secondary_links)) :
                print theme('links', $secondary_links, array('class' => 'links secondary-links'));
            endif; ?>
        </div>
        <div id="site-body">
            <div id="page">
                <!-- Start of region 0 -->
                <?php if ($region0): ?>
                    <?php print $region0; ?>
                <?php endif; ?>
                <!-- End of region 0 -->
                <!-- Start of region 1 -->
                    <div id="region1">
                        <?php if ($help): ?>
                          <?php print $help; ?>
                        <?php endif; ?>
                        <div id="search_box">
                            <?php print $search_box;?>
                        </div>
                        <?php print $feed_icons ?>
                            <?php //if ($breadcrumb): ?>
                                <?php //print $breadcrumb; ?>
                            <?php //endif; ?>
                            <?php if ($tabs): print '<div id="tabs-wrapper" class="clear-block">'; endif; ?>
                            <?php if ($tabs): print '<ul class="tabs primary">'. $tabs .'</ul></div>'; endif; ?>
                            <?php if ($tabs2): print '<ul class="tabs secondary">'. $tabs2 .'</ul>'; endif; ?>
                            <?php if ($show_messages && $messages): print $messages; endif; ?>
                            <?php print $content; ?>
                    </div>
                <!-- End of region 1 -->
                <!-- Start of region 2 -->
				    <div id="region2">
				        <?php print ($region2 ? $region2 : ""); ?>
                    </div>
                <!-- End of region 2 -->
                <!-- Start of region 3 -->
                    <?php print ($region3 ? '<div id="region3">'.$region3.'</div>' : ''); ?>
                <!-- End of region 3 -->
            </div>
        </div>
        <div id="site-footer">
            <?php if ($footer): ?>
                <?php print $footer; ?>
            <?php endif; ?>
            <?php if ($footer_message): ?>
                <?php print $footer_message; ?>
            <?php endif; ?>
			<a href="#org" class="to-top">Back to top</a>
        </div>
    </div>
    <?php //Get the page footer and common OU elements
    $header_footer_selection = phptemplate_get_header_footer();
    if (!empty($header_footer_selection['footer'])):
        include($header_footer_selection['footer']);
    else:
		if ($header_footer_selection['footer'] != ''):
			print $header_footer_selection['error'];
		endif;
    endif;
    if ($closure):
        print $closure;
    endif; ?>
</div>
<?php  // get the common header elements (This can be called by all page templates)
    $incfile=drupal_get_path('theme','ou_exstd')."/includes/footer.php";
    include($incfile);
?>
</body>
</html>
