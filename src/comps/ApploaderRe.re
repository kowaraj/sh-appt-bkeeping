[@bs.deriving abstract]
type jsProps = {
  value: Js.nullable(int),
};


//IMPORTANT! This fails: [@bs.module] external apploader : ReasonReact.reactClass = "./Apploader";
[@bs.module "./Apploader"] external apploader : ReasonReact.reactClass = "default";

let make = (~value_=?, children) => {
  let jsp = jsProps(~value=Js.Nullable.fromOption(value_));

  ReasonReact.wrapJsForReason(
    ~reactClass=apploader,
    ~props=Js.Obj.empty(),
    children,
  );
};

