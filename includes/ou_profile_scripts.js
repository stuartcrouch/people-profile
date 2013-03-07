jQuery(function () {
	addSelectAllRadio();
	addClickEvent();
	findclasses();
	zebra();
});

function addSelectAllRadio(){

	jQuery(document).ready(function(){
	
		groups = $('fieldset.[class^="group-"] legend');
		for (i = 0; i < groups.length; i++) {

			group = groups[i];
		
			// The first value of the parent is the group name
			// If its not empty, create a radio selector and assign it to this group
			attribs = group.parentNode.className.split(" ");
			if (attribs[0].length > 0)
			{
				$('fieldset.' + attribs[0] +' legend').after(
					'<div class="header-radios"><strong>Select All:</strong> ' +
					'Private <input type="radio" id="" name="' + attribs[0] +'" value="" class="form-radio private ' + attribs[0] +'"> &#124; ' +
					'Intranet <input type="radio" id="" name="' + attribs[0] +'" value="" class="form-radio intranet ' + attribs[0] +'"> &#124; ' +
					'Public <input type="radio" id="" name="' + attribs[0] +'" value="" class="form-radio public ' + attribs[0] +'"></div>'
				);
			}
		}
	});

	
};

function findclasses(){
	 jQuery(document).ready(function(){
		$('fieldset.group-header > div.fieldset-wrapper > div[class*=" form-item-p-"]').each( function() {
		   var classID = null;
		   var classes = $(this).attr('class').split( ' ' );
		    for (var i = 0, len = classes.length; i < len; i++) {
				var classname = classes[i];
				if (classname.match( /^form-item-p-/ )) {
					classID = classname.replace("form-item-p-",'');
					wrapper(classname);
					break;
 		    	}
 		    }
			if (classID) {
			}
		});
		
		$('fieldset.group-teaching-research-interest > div.fieldset-wrapper > div[class*=" form-item-p-"]').each( function() {
		   var classID = null;
		   var classes = $(this).attr('class').split( ' ' );
		    for (var i = 0, len = classes.length; i < len; i++) {
				var classname = classes[i];
				if (classname.match( /^form-item-p-/ )) {
					classID = classname.replace("form-item-p-",'');
					wrapper(classname);
					break;
 		    	}
 		    }
			if (classID) {
			}
		});
		
		$('fieldset.group-external-profiles-accounts > div.fieldset-wrapper > div[class*=" form-item-p-"]').each( function() {
		   var classID = null;
		   var classes = $(this).attr('class').split( ' ' );
		    for (var i = 0, len = classes.length; i < len; i++) {
				var classname = classes[i];
				if (classname.match( /^form-item-p-/ )) {
					classID = classname.replace("form-item-p-",'');
					wrapper(classname);
					break;
 		    	}
 		    }
			if (classID) {
			}
		});
		
	});
};

function wrapper($classname){
	var divs = $('.'+$classname+'');
	var _test = ':not(.'+$classname+')';
	//$('.stripeMe tr:even').addClass('alt');
	for(var i=0; i<divs.length;) {
	   i += divs.eq(i).nextUntil(''+_test+'').andSelf().wrapAll('<div />').length;
	}
}

function zebra(){
	 jQuery(document).ready(function(){
		if ($.browser.msie) {
			$('fieldset.[class^="group-"] > div:odd').addClass('ou-odd');
			$('fieldset.[class^="group-"] > div:even').addClass('ou-even');
		} else {
			$('fieldset.[class^="group-"] > div.fieldset-wrapper > div:odd').addClass('ou-odd');
			$('fieldset.[class^="group-"] > div.fieldset-wrapper > div:even').addClass('ou-even');
		}
	});
};

function addClickEvent(){
	jQuery(document).ready(function(){
	
		$('fieldset.[class^="group-"] > div.header-radios input').click(function () { 
			if ($(this).is(':checked')) {
				attribs = this.className.split(" ");
				radios = jQuery('fieldset.' + attribs[2] + ' > div.fieldset-wrapper > div.[class*="ou-"] ');
				radionum = 0;
				switch (attribs[1]) {
					case 'private':
						radionum = 0;
					break;
					case 'intranet':
						radionum = 1;
					break;
					case 'public':
						radionum = 2;
					break;
				}
				radios.each( function(index) {
					radio = $('input:radio:eq('+radionum+')');
					$('input:radio:eq('+radionum+')', this).attr("checked", "checked");
				});
			}
		});

	});

};