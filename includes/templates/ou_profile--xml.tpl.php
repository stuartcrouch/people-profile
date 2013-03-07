<?php
// $Id: ou_profile--xml.tpl.php,v 1.4.2.1 2009/08/10 10:48:33 goba Exp $

/**
 * @file ou_profile--xml.tpl.php
 *
 * Theme implementation to display a node.
 *
 * Available variables:
 *  $title
 *  $content
 *  $picture
 *  $date 
 *  $links
 *	$name 
 *  $node_url
 *  $oucu
 *  $submitted
 *  $node
 *  $type
 *  $nid
 *  $fields
 *
 */

?>
<root>
     <fields>
     <?php
	  foreach ($fields as $key => $value) {
	  
	  //print "<$key>$value</$key>\n";
	  print ou_profile_render_content_as_xml($key, $value);
	  
	  
	  } 
	 ?>
     </fields>

</root>
<?php



?>
