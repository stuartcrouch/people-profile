//**********************************************************
// File : ou_profile_tabs.js
// Version : 1.0
// Created : 2014/01/04
// Author: Sirnjeet Kalwan
//
// Script for animating the tabbed navigation on a profile
//*********************************************************

(function($){

	function setTab()
	{
		//Work out the tab selected (e.g. "#tab2")
		var thistab = $(location).attr('hash');
		if( thistab.substr( 0, 4 ) == '#tab' )
		{
			//Deselect current tab
			$( "ul.ou-sections.tabs a" ).removeClass( "ou-selected" );
			//Select new tab
			$( "ul.ou-sections.tabs a[href='"+thistab+"']" ).addClass( "ou-selected" );			
			thistab = thistab.substr( 1, thistab.length - 1 );
			
			//Hide the current tab content
			$( "div.ou-binder div.tab-content" ).removeClass( "selected" );
			
			//Show the selected tab content
			$( "div.ou-binder div.tab-content." + thistab ).addClass( "selected" );
		}

	}

	$( document ).ready(function() {
		setTab();
	});
	
	window.onhashchange = function( e ) {
		setTab();
	}
	
})(jQuery);
