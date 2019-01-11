/* [@bs.module "./jstest"] [@bs.val] external x : unit => unit = ""; */
/* x(); */

[@bs.module "./jstest"] [@bs.val] external xx : unit => string = ""; 
let xx = xx(); 
Js.log(xx);
/* [@bs.module "./jstest"] [@bs.val] external init : unit => unit = ""; */
/* init(); */

[@bs.module "./jstest"] [@bs.val] external neo4j_create : string => unit = "";
[@bs.module "./jstest"] [@bs.val] external neo4j_match : string => string = "";

let str = ReasonReact.string;
let q = "CREATE (ee:Person { name: \"Emil600\", from: \"Sweden\", klout: 600 })";
neo4j_create(q);

let m = "MATCH (ee:Person) WHERE ee.name = \"Emil600\" RETURN ee";
let m_ret = neo4j_match(m);
Js.log(m_ret);

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
      <div> 
          <h2> (str ("|||")) (str(m_ret)) (str("|||")) </h2>
      </div>
    </div>,
};
