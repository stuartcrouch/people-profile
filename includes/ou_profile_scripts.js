jQuery(function () {
  addSelectAllRadio();
  addClickEvent();
  });

function addSelectAllRadio(){

  jQuery(document).ready(function($){
  
    // Get all of the field-group-tab(s) with the "privacy_options" class
    groups = $('fieldset.privacy_options');
    for (i = 0; i < groups.length; i++) {
      group = groups[i];
    
      // The second value of the parent is the group name
      // If its not empty, create a radio selector and assign it to this group
      attribs = group.className.split(" ");
      if (attribs[1].length > 0)
      {
        // Add some radios to toggle all other radios within this group
        $('fieldset.[class="' + group.className +'"] legend:first' ).after(
          '<div class="header-radios"><strong>Set all privacy values on this tab to :</strong> ' +
          'Private <input type="radio" id="" name="' + attribs[1] +'" value="" class="form-radio private ' + attribs[1] +'"> &#124; ' +
          'Intranet <input type="radio" id="" name="' + attribs[1] +'" value="" class="form-radio intranet ' + attribs[1] +'"> &#124; ' +
          'Public <input type="radio" id="" name="' + attribs[1] +'" value="" class="form-radio public ' + attribs[1] +'"></div>'
        );
      }
    }
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

function addClickEvent(){
  jQuery(document).ready(function($){
  
    // Set a click watch on the "header-radios" for each tab with "privacy_options" class
    $('fieldset.privacy_options > div.header-radios input').click(function () { 
      if ($(this).is(':checked')) {
        attribs = this.className.split(" ");
        
        // figure out which radio was clicked and use that to set the others
        // This relies on the orders being the same
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
        
        // Loop through all the radios with an id containing prv (for privacy)
        // for the field-group-tab for the header-radio we clicked
        radios = jQuery('fieldset.' + attribs[2] + ' > div.fieldset-wrapper div.form-radios[id*="prv"]');
        radios.each( function(index, value) {
          // Set the active radio in this radio group to match the one clicked in the parent
          $('input:radio:eq('+radionum+')', this).attr("checked", "checked");
        });
      }
    });

  });

};