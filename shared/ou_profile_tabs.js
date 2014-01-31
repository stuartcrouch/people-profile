//**********************************************************
// File : ou_profile_tabs.js
// Version : 1.0
// Created : 2014/01/04
// Author: Sirnjeet Kalwan
//
// Script for animating the tabbed navigation on a profile
//*********************************************************

(function($){
	$( document ).ready(function() {
		
		//Add click event for tabs
		$( "ul.ou-sections.tabs a" ).click( function(){
			//Deselect current tab
			$( "ul.ou-sections.tabs a" ).removeClass( "ou-selected" );
			//Select new tab
			$( this ).addClass( "ou-selected" );

			//Work out the tab selected (e.g. "tab2")
			var thistabLink = $( this ).attr( "href" );
			var thistab = thistabLink.substr( 1, thistabLink.length - 1 );
			
			//Hide the current tab content
			$( "div.ou-binder div.tab-content" ).removeClass( "selected" );
			
			//Show the selected tab content
			$( "div.ou-binder div.tab-content." + thistab ).addClass( "selected" );
			
		});
	});
})(jQuery);
