// This is a manifest file that'll be compiled into application.js, which will include all the files
// listed below.
//
// Any JavaScript/Coffee file within this directory, lib/assets/javascripts, or any plugin's
// vendor/assets/javascripts directory can be referenced here using a relative path.
//
// It's not advisable to add code directly here, but if you do, it'll appear at the bottom of the
// compiled file. JavaScript code in this file should be added after the last require_* statement.
//
// Read Sprockets README (https://github.com/rails/sprockets#sprockets-directives) for details
// about supported directives.
//
//= require rails-ujs
//= require activestorage
//= require turbolinks
//= require_tree .


window.onload = function() {
  // Parse the DOT syntax into a graphlib object.
  var g = graphlibDot.parse(document.getElementById("dot").value);
  // Render the graphlib object using d3.
  var renderer = new dagreD3.Renderer();
  renderer.run(g, d3.select("svg g"));
  // Optional - resize the SVG element based on the contents.
  var svg = document.querySelector('#graphContainer');
  var bbox = svg.getBBox();
  svg.style.width = bbox.width + 40.0 + "px";
  svg.style.height = bbox.height + 40.0 + "px";
}
