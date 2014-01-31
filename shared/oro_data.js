//Script file added to page output in ou_profile_client_node_view
(function($){

  //Loops through the list of authors and returns their names.
  function get_creators( creators )
  {
    var creatorlist = [];
    $.each( creators, function(key2, creator){
      creatorlist.push( creator.name.given + " " + creator.name.family);
    });
    
    return( creatorlist.join( ", " ) );
  }
  
  //Check for any numbers anywhere in a string
  function hasNumber(t)
  {
    return /\d/.test(t);
  }
  
  //Processes the JSON data and updates the page with data
  function process_oro( oro_data_json )
  {
    $.each(oro_data_json, function(key1, oro_entry){

      switch( oro_entry.type)
      {
        case "article":
          $("#oro .article ul").append( "<strong><a href='" + oro_entry.uri + "'>" + oro_entry.title +"</a> (" + oro_entry.date +") </strong><br />" );
          $("#oro .article ul").append( "" + ( (oro_entry.creators) ? (get_creators( oro_entry.creators ) +"<br />") : "" ) );
          $("#oro .article ul").append( oro_entry.publication + ( (oro_entry.pagerange) ? ( hasNumber( oro_entry.pagerange ) ? (" (pp. " + oro_entry.pagerange + ")" ) : (" " + oro_entry.pagerange ) ) : "" ) );
          $("#oro .article ul").append( "<hr />" );
          break;
		  
		  
        case "book":
          $("#oro .book ul").append( "<strong><a href='" + oro_entry.uri + "'>" + oro_entry.title +"</a> (" + oro_entry.date +") </strong><br />" );
          $("#oro .book ul").append( "" + ( (oro_entry.creators) ? (get_creators( oro_entry.creators ) +"<br />") : "" ) );
          $("#oro .book ul").append( "" + oro_entry.isbn + " : " + oro_entry.publisher + " (" + oro_entry.place_of_pub +")" );
          $("#oro .book ul").append( "<hr />" );
          break;

        case "book_section":
          $("#oro .book_section ul").append( "<strong><a href='" + oro_entry.uri + "'>" + oro_entry.title +"</a> (" + oro_entry.date +") </strong><br />" );
          $("#oro .book_section ul").append( "" + ( (oro_entry.creators) ? (get_creators( oro_entry.creators ) +"<br />") : "" ) );
          $("#oro .book_section ul").append( oro_entry.book_title + "<br /> " + oro_entry.isbn + " : " + oro_entry.publisher + " (" + oro_entry.place_of_pub +")" );
          $("#oro .book_section ul").append( "<hr />" );
          break;
		  
        case "bookedit":
          $("#oro .bookedit ul").append( "<strong><a href='" + oro_entry.uri + "'>" + oro_entry.title +"</a> (" + oro_entry.date +") </strong><br />" );
          $("#oro .bookedit ul").append( "" + ( (oro_entry.creators) ? (get_creators( oro_entry.creators ) +"<br />") : "" ) );
          $("#oro .bookedit ul").append( "" + oro_entry.isbn + " : " + oro_entry.publisher + " (" + oro_entry.place_of_pub +")" );
          $("#oro .bookedit ul").append( "<hr />" );
          break;
		  
        case "conference_item":
          $("#oro .conference_item ul").append( "<strong><a href='" + oro_entry.uri + "'>" + oro_entry.title +"</a> (" + oro_entry.date +") </strong><br />" );
          $("#oro .conference_item ul").append( "" + ( (oro_entry.creators) ? (get_creators( oro_entry.creators ) +"<br />") : "" ) );
          $("#oro .conference_item ul").append( "In : " + oro_entry.event_title + " (" + oro_entry.event_dates + ", " + oro_entry.event_location + ")<hr />" );
          break;

        default:
          $("#oro .other ul").append( "<strong><a href='" + oro_entry.uri + "'>" + oro_entry.title +"</a> (" + oro_entry.date +") </strong><br />" );
          $("#oro .other ul").append( "" + ( (oro_entry.creators) ? (get_creators( oro_entry.creators ) +"<br />") : "" ) );
          $("#oro .other ul").append( "<hr />" );
      }
    });
    
    //Add sub-section headings if data was found for those sub-sections
    var add_main_title = false;
    if ($("#oro .article ul").text().length > 0)
    {
      $( "#oro .article" ).prepend( "<h3>Journal articles</h3>" );
      add_main_title = true;
    }
    
    if ($("#oro .book ul").text().length > 0)
    {
      $( "#oro .book" ).prepend( "<h3>Authored books</h3>" );
      add_main_title = true;
    }

    if ($("#oro .bookedit ul").text().length > 0)
    {
      $( "#oro .bookedit" ).prepend( "<h3>Edited book</h3>" );
      add_main_title = true;
    }

    if ($("#oro .book_section ul").text().length > 0)
    {
      $( "#oro .book_section" ).prepend( "<h3>Book chapters</h3>" );
      add_main_title = true;
    }

    if ($("#oro .conference_item ul").text().length > 0)
    {
      $( "#oro .conference_item" ).prepend( "<h3>Conference items</h3>" );
      add_main_title = true;
    }

    if ($("#oro .other ul").text().length > 0)
    {
      $( "#oro .other" ).prepend( "<h3>Other</h3>" );
      add_main_title = true;
    }
    
    //Add main section title if any of the sub-sections contained data
    if( add_main_title )
    {
      $("#oro .oro_title").append( "<h2>Publications</h2>" );
    }
  }

  $( document ).ready(function() {
  
	process_oro( oro_data_json );

/*
    //Get the profile ORO data. NOTE : "oro_link" is declared in node--profile.tpl
    $.ajax({
		url: oro_link,
		dataType: "json",
		success: function( oro_data_json, textStatus )
		{
			process_oro( oro_data_json );
		},
		error: function( jqXHR, textStatus, errorThrown )
		{
			console.log( "Ajax : Request fail for : " + oro_link );
			console.log( "Ajax : " + textStatus + " ERROR: " + errorThrown );
			console.log( "Ajax : " + jqXHR.responseText );
		}
    });
    */
  });
})(jQuery);

