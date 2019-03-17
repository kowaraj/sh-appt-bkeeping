[@bs.deriving abstract]
type jsProps = {
  className: string,
  [@bs.as "type"] type_: string,
  value: Js.nullable(int),
};


[@bs.module] external apploader : ReasonReact.reactClass = "./Apploader";

let make = (~className, ~type_, ~value=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=apploader,
    ~props=jsProps(
      ~className,
      ~type_,
      ~value=Js.Nullable.fromOption(value),
    ),
    children,
  );
