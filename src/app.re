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
