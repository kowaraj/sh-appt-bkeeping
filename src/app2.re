//[%bs.raw {|require('./app.css')|}];

//[@bs.module] external logo : string = "./logo.svg";

let component = ReasonReact.statelessComponent("App2");

let make = (~message, _children) => {
  ...component,
  render: _self =>
    <div>
        <p>
        (ReasonReact.string("app2"))
      </p>
    </div>,
};
