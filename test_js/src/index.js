import jq from 'jq';

console.log(jq); 

const $ = jq;

$(document).ready(function() {
  console.log('Document is ready'); 
  $(".btn").hide().show();
});
