// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var Tag$BsTagsReact = require("../Tag.bs.js");

function Test(Props) {
  var match = React.useState((function () {
          return /* [] */0;
        }));
  return React.createElement(Tag$BsTagsReact.make, {
              tags: match[0],
              setTags: match[1]
            });
}

var make = Test;

exports.make = make;
/* react Not a pure module */
