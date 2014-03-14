<?php
/**
 Functions used by the People Profile Server & Client

Created 

 */

// This code is written all over this module, trying to turn it into a function
function ou_profile_lcreate_name($in_title, $in_forenames, $in_surname, $in_pref_forname, $in_pref_surname) {

  $staff_title = "";
  if ($in_title) {
    $staff_title = $in_title;
    if ($staff_title && $staff_title != "Mr" && $staff_title != "Miss" && $staff_title != "Ms" && $staff_title != "Mrs") {
      $staff_title = preg_replace("/Prof/", "Professor", $staff_title);
    }
    $staff_title .= " ";
  }
    //oupdb("staff title: $staff_title");

    // Add forenames
    $forenames = "";
    if ($in_pref_forname) {
      $forenames = $in_pref_forname . " ";
    }
    else {
      if ($in_forenames) {
        $forenames = $in_forenames . " ";
      }
    }
    //oupdb("forenames: $forenames");

    // Add surname
    $surname = "";
    if ($in_pref_surname) {
      $surname = $in_pref_surname;
    }
    else {
      if ($in_surname) {
        $surname = $in_surname;
      }
    }

    return $staff_title . $forenames . $surname;
}


/////////////////////
// Logging
/////////////////////

define ('OU_PROFILE_REPORT_ERROR', 0);
define ('OU_PROFILE_REPORT_WARNING', 1);
define ('OU_PROFILE_REPORT_INFO', 2);
define ('OU_PROFILE_REPORT_DEBUG', 3);

function ou_profile_log($message, $params = array(), $level = OU_PROFILE_REPORT_DEBUG) {

    $watchdog_type = NULL;
    switch ($level) {
      case OU_PROFILE_REPORT_ERROR:
        $watchdog_type = WATCHDOG_ERROR;
      break;

      case OU_PROFILE_REPORT_WARNING:
        $watchdog_type = WATCHDDOG_WARNING;
      break;

      case OU_PROFILE_REPORT_INFO:
        $watchdog_type = WATCHDOG_INFO;
      break;

      case OU_PROFILE_REPORT_DEBUG:
      default:
        $watchdog_type = WATCHDOG_DEBUG;
      break;
    }

    $ou_profile_reporting = variable_get('ou_profile_reporting', -1);
    if ($level <= $ou_profile_reporting) {
      if ($ou_profile_reporting == 4) {
        print("log - " . strtr($message, $params));
        print("<br />\n");
      }

      watchdog('ou_profile', $message, $params, $watchdog_type, NULL);
    }
}

/**
 * ===== ORO Functions ======
 * Gets data from http://oro.open.ac.uk and presents it in the profile.
 * Tried AJAX, but that won't work as the data is in a different sub-domain.
**/

function _ou_profile_generate_oro_html( $node )
{

	//The profile will already have been checked to see if it is visible
	if( isset( $node->do_not_show ) )
	{
		if( $node->do_not_show )
		{
			return( '' );
		}
	}	
	
	//##################################
	//This field is beging stripped out when displayed on client site 
	//Check privacy
	if( isset( $node->ou_profile["field_prv_oro"]['und'][0]['nid'] ) )
	{
		$oro_priv = $node->ou_profile["privacy_values"][ $node->ou_profile["field_prv_oro"]['und'][0]['nid'] ];
	} else {
		$oro_priv = '1';
	}

	//Don't show if field not set to public
	if( $oro_priv <> '3' )
	{
		return( '' );
	}

	//Get the OUCU
	if( isset( $node->ou_profile['pdata']['field_oup_oucu']['value']['und'][0]['value'] ) )
	{
		$oucu = $node->ou_profile['pdata']['field_oup_oucu']['value']['und'][0]['value'];
	}

	if( isset( $oucu ) )
	{
		return( _ou_profile_generate_oro_html_byoucu( $oucu ) );
	}
}


//Main function to get the ORO data and generate the HTML from the JSON data
function _ou_profile_generate_oro_html_byoucu( $oucu )
{
	//If we have OUCU, we can retrieve the ORO data
	if( $oucu != '' )
	{
		// e.g. http://oro.open.ac.uk/cgi/exportview/person/ma3776/HTML/ma3776.html
		$oro_url = "http://oro.open.ac.uk/cgi/exportview/person/".$oucu."/JSON/".$oucu.".js";
		$oro_data_json = _ou_profile_get_web_page( $oro_url );
		
		//If the page request was successful, process the JSON data
		if( $oro_data_json['errno' ] == 0 )
		{
			$oro_data = json_decode($oro_data_json['content'], true);
			//An invalid URL does not always raise an error from the ORO site(?!). It returns a blank array.
			//If no data, just return a blank string
			if( empty( $oro_data ) )
			{
				return( "" );
			}

			$oro_html = array();
			
			//Loop through the data and generate the HTML
			foreach( $oro_data as $oro_entry )
			{
				$tmp = "<strong><a href='".$oro_entry['uri']."'>".$oro_entry['title']."</a> (".$oro_entry['date'].") </strong><br />";
				if( isset($oro_entry['creators']) )
				{
					$tmp .= _ou_profile_get_creators( $oro_entry['creators'] )."<br />";
				}
				switch( $oro_entry[ 'type' ] )
				{
					case "article":
						$tmp .= $oro_entry['publication'];
						if( isset( $oro_entry['volume'] ) )
						{
							$tmp .= ', '.$oro_entry['volume'];
						}
						if( isset( $oro_entry['article_number'] ) )
						{
							$tmp .= ', Article '.$oro_entry['article_number'];
						}
						if( isset($oro_entry['pagerange']) )
						{
							if( preg_match( '#[0-9]#', substr( $oro_entry['pagerange'], 0, 1 ) ) )
							{
								$tmp .= " (pp. ".$oro_entry['pagerange'].")";
							} else {
								$tmp .= " ".$oro_entry['pagerange']; 
							}
						}
						$tmp .= "<hr />";
						$oro_html["article"][] = $tmp;
					break;
					case "book":
					case "book_section":
					case "bookedit":
						$tmp .= _ou_profile_book_details( $oro_entry );
						$tmp .= "<hr />";
						$oro_html[$oro_entry[ 'type' ]][] = $tmp;
					break;					
					case "conference_item":
						if( isset( $oro_entry['event_title'] ) )
						{
							$tmp .= "In : ".$oro_entry['event_title'];
							if( isset( $oro_entry['event_dates'] ) )
							{
								$tmp .= " (".$oro_entry['event_dates'];
								if( isset( $oro_entry['event_location'] ) )
								{
									$tmp .= ", ".$oro_entry['event_location'];
								}
								$tmp .= ")";
							}
							$tmp .= "<hr />";
						}
						$oro_html["conference_item"][] = $tmp;
					break;
					default:
						$tmp .= "<hr />";
						$oro_html["other"][] = $tmp;
					break;
				}
			}
			
			//Generate the titles if needed for that particular ORO data type (Don't use foreach, output will be in the order that the different types were found)
			$node_oro_html = null;
			if( isset( $oro_html["article"] ) )
			{
				$tmp = implode( "", $oro_html["article"] );
				$node_oro_html .= "<h3>Journal articles</h3><ul>".$tmp."</ul>";
			}
			if( isset( $oro_html["book"] ) )
			{
				$tmp = implode( "", $oro_html["book"] );
				$node_oro_html .= "<h3>Authored books</h3><ul>".$tmp."</ul>";
			}
			if( isset( $oro_html["book_section"] ) )
			{
				$tmp = implode( "", $oro_html["book_section"] );
				$node_oro_html .= "<h3>Book chapters</h3><ul>".$tmp."</ul>";
			}
			if( isset( $oro_html["bookedit"] ) )
			{
				$tmp = implode( "", $oro_html["bookedit"] );
				$node_oro_html .= "<h3>Edited book</h3><ul>".$tmp."</ul>";
			}
			if( isset( $oro_html["conference_item"] ) )
			{
				$tmp = implode( "", $oro_html["conference_item"] );
				$node_oro_html .= "<h3>Conference items</h3><ul>".$tmp."</ul>";
			}
			if( isset( $oro_html["other"] ) )
			{
				$tmp = implode( "", $oro_html["other"] );
				$node_oro_html .= "<h3>Other</h3><ul>".$tmp."</ul>";
			}
			
			//Create the oro tab title
			if( isset( $node_oro_html ) )
			{
				$node_oro_html = "<h2>Publications</h2>".$node_oro_html;
				//Pass final HTML back. tpl file will just print this.
				return( $node_oro_html );
			}
		}
	}
	
	return( "" );
}


/**
 * Get a web file (HTML, XHTML, XML, image, etc.) from a URL.  Return an
 * array containing the HTTP server response header fields and content.
 * We can't get the ORO data via AJAX, so we grab it here
 */
function _ou_profile_get_web_page( $url )
{
	$options = array(
		CURLOPT_RETURNTRANSFER => true,     // return web page
		CURLOPT_HEADER         => false,    // don't return headers
		CURLOPT_FOLLOWLOCATION => true,     // follow redirects
		CURLOPT_ENCODING       => "",       // handle all encodings
		CURLOPT_USERAGENT      => "spider", // who am i
		CURLOPT_AUTOREFERER    => true,     // set referer on redirect
		CURLOPT_CONNECTTIMEOUT => 120,      // timeout on connect
		CURLOPT_TIMEOUT        => 120,      // timeout on response
		CURLOPT_MAXREDIRS      => 10,       // stop after 10 redirects
	);

	$ch      = curl_init( $url );
	curl_setopt_array( $ch, $options );
	$content = curl_exec( $ch );
	$err     = curl_errno( $ch );
	$errmsg  = curl_error( $ch );
	$header  = curl_getinfo( $ch );
	curl_close( $ch );

	$header['errno']   = $err;
	$header['errmsg']  = $errmsg;
	$header['content'] = $content;
	return $header;
}

// Helper agent for _ou_profile_generate_oro_html
// Returns a formatted list of authors for a ORO entry
function _ou_profile_get_creators( $creators )
{
	$creatorlist = array();
	foreach( $creators as $creator)
	{
		$creatorlist[] = $creator[ 'name' ]['given'].' '.$creator['name']['family'];
	}

	return( implode( ", ", $creatorlist ) );
}

// Helper agent for _ou_profile_generate_oro_html
// Returns the isbn, pub & place of pub
function _ou_profile_book_details( $oro_entry )
{
	$tmp = array();
	
	if( isset( $oro_entry['isbn'] ) )
	{
		$tmp[] = "ISBN : ".$oro_entry['isbn'];
	}
	
	if( isset( $oro_entry['publisher'] ) )
	{
		$tmp[] = "Publisher : ".$oro_entry['publisher'];
	}

	if( isset( $oro_entry['place_of_pub'] ) )
	{
		$tmp[] = "Published : ".$oro_entry['place_of_pub'];
	}
	
	$line = implode( " | ", $tmp );
	
	return( $line );
}


function ou_profile_edit_profile_link($node, $user ) {
  $request_url = ou_profile_get_request_url();
  
  if ($GLOBALS['base_url'] == $request_url) {
    if ((node_access('update', $node, $user) == TRUE) || ($user->uid == 1)) {
      return '<a class="profile-button" href="node/' . $node->nid . '/edit">Edit profile</a>';
    }
  }
  
  return '';
}

function ou_profile_get_request_url() {
  $env = strtolower(getenv('OUENV'));
  $request_url = "";
  switch ($env) {
    case 'live':
      $request_url = 'http://www.open.ac.uk/people';
      break;
  
    default:
      $request_url = 'http://www-' . $env . '.open.ac.uk/people';
  }
  
  return $request_url;
  
}


function ou_profile_request_image($style_name, $image_name) {

  $request_url = ou_profile_get_request_url();
  $request_path = 'www.open.ac.uk.people';
  
  if ($GLOBALS['base_url'] == $request_url) {
	//Have to pass NULL width & height as function is expecting them even though theay are optional
    return theme_image_style(array('style_name' => $style_name, 'path' => $image_name, 'width' => null, 'height' => null));
  }
  else {
    //This is for client sites
    $image_name = str_replace("public://", "", $image_name);
	
	switch( $style_name )
	{
	  case 'profile_photo':
	    return '<img src="' . $request_url . '/sites/' . $request_path . '/files/styles/' . $style_name . '/public/' . $image_name . '" width="210" height="181" />';
	  break;
	  
	  case 'profile_image':
	    return '<img src="' . $request_url . '/sites/' . $request_path . '/files/styles/' . $style_name . '/public/' . $image_name . '" width="922" height="300" />';
	  break;
	  
	  default:
        return '<img src="' . $request_url . '/sites/' . $request_path . '/files/styles/' . $style_name . '/public/' . $image_name . '" />';
	  break;
	}
  }
}


?>