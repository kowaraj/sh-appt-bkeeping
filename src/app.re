//[@bs.module "./jstest.js"] external jstest : string => string = "jstest.js";
//[@bs.module] external jstest : string = "./jstest.js";
/* //[@bs.val] [@bs.scope "jstest"] external x : unit => unit = "x"; */
/* [@bs.module] external jstest : string = "./jstest.js"; */
/* [@bs.val] external x : int = "x"; */
/* [@bs.val] [@bs.scope "jstest"] external x : int = "x"; */

//[%bs.raw {|var q = require('./jstest.js');|}];
//[%bs.raw {| import { x } from 'jstest'; |}];

//let q1 = q.x;
//let q = jstest.y();

[@bs.module "./jstest"] [@bs.val] external x : unit => unit = "";
x();
[@bs.module "./jstest"] [@bs.val] external init : unit => unit = "";
init();

[%bs.raw {|require('./app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

let component = ReasonReact.statelessComponent("App");

let make = (~message, _children) => {
  ...component,
  render: _self =>
    <div className="App">
      <div className="App-header-2">
        <img src=logo className="App-logo" alt="logo" />
        <h2> (ReasonReact.string(message)) </h2>
      </div>
      <div className="App-intro">
        /* (ReasonReact.string("To get started, edit")) */
        /* <code> (ReasonReact.string(" src/app.re ")) </code> */
        /* (ReasonReact.string("and save to reload.")) */
          <ToDo message="hi"/>
      </div>
    </div>,
};
