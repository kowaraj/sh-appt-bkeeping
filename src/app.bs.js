// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var ToDo = require("./comps/ToDo.bs.js");
var React = require("react");
var LogoSvg = require("./logo.svg");
var ReasonReact = require("reason-react/src/ReasonReact.js");

((require('./app.css')));

var component = ReasonReact.statelessComponent("App");

function make(message, _children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (_self) {
              return React.createElement("div", {
                          className: "App"
                        }, React.createElement("div", {
                              className: "App-header-2"
                            }, React.createElement("img", {
                                  className: "App-logo",
                                  alt: "logo",
                                  src: LogoSvg
                                }), React.createElement("h2", undefined, message)), React.createElement("div", {
                              className: "App-intro"
                            }, ReasonReact.element(undefined, undefined, ToDo.make("hi", /* array */[]))));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.make = make;
/*  Not a pure module */
