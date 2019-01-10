let component = ReasonReact.statelessComponent("ToDo");

let make = (~message, _children) => {
  ...component,
  render: _self =>
      <div className="Todo">
          
          (ReasonReact.string(message))
    </div>,
};
