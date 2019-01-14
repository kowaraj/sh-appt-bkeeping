let str = ReasonReact.string;

let component = ReasonReact.statelessComponent("TodoItem");
let make = (~itemX : TodoType.item, children) => {
    ...component,
    render: (self) =>
      <div className="item">
        <input
          type_="checkbox"

          checked=(itemX.completed)
          /* TODO make interactive */
          onChange=( unit => { "ok"; ()} )
        />
        (str(itemX.text))
      </div>
  };

