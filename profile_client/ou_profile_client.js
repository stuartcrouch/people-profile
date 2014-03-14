(function($){
	$( document ).ready(function() {
		
		var atoz_list = new Array();
		atoz_list[ 'A' ] = '';
		atoz_list[ 'B' ] = '';
		atoz_list[ 'C' ] = '';
		atoz_list[ 'D' ] = '';
		atoz_list[ 'E' ] = '';
		atoz_list[ 'F' ] = '';
		atoz_list[ 'G' ] = '';
		atoz_list[ 'H' ] = '';
		atoz_list[ 'I' ] = '';
		atoz_list[ 'J' ] = '';
		atoz_list[ 'K' ] = '';
		atoz_list[ 'L' ] = '';
		atoz_list[ 'M' ] = '';
		atoz_list[ 'N' ] = '';
		atoz_list[ 'O' ] = '';
		atoz_list[ 'P' ] = '';
		atoz_list[ 'Q' ] = '';
		atoz_list[ 'R' ] = '';
		atoz_list[ 'S' ] = '';
		atoz_list[ 'T' ] = '';
		atoz_list[ 'U' ] = '';
		atoz_list[ 'V' ] = '';
		atoz_list[ 'W' ] = '';
		atoz_list[ 'X' ] = '';
		atoz_list[ 'Y' ] = '';
		atoz_list[ 'Z' ] = '';

		var atoz = '<ul class="AtoZ">';

		for( key in atoz_list )
		{
			heading = $( '#'+key+'.ou_profile_atoz_heading' );
			if( heading.length )
			{
				atoz = atoz + '<li><a href="#'+key+'">'+key+'</a></li>';
			} else {
				atoz = atoz + '<li>'+key+'</li>';
			}
			
		}
		
		atoz = atoz + '</ul>';
		
		//Add A to Z list at top
		$( atoz ).appendTo( '.atoz_list' );

	});
})(jQuery);
