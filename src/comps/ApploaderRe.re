/* [@bs.deriving abstract] */
/* type jsProps = { */
/*   className: string, */
/*   [@bs.as "type"] type_: string, */
/*   value: Js.nullable(int), */
/* }; */
[@bs.deriving abstract]
type jsProps = {
  value: Js.nullable(int),
};


//[@bs.module] external apploader : ReasonReact.reactClass = "./Apploader";
[@bs.module "./Apploader"] external apploader : ReasonReact.reactClass = "default";

let make = (~value_=?, children) => {
  let jsp = jsProps(~value=Js.Nullable.fromOption(value_));

  ReasonReact.wrapJsForReason(
    ~reactClass=apploader,
    ~props=Js.Obj.empty(),
    children,
  );
};

/* let make = (~className, ~type_, ~value=?, children) => */
/*   ReasonReact.wrapJsForReason( */
/*     ~reactClass=apploader, */
/*     ~props=jsProps( */
/*       ~className, */
/*       ~type_, */
/*       ~value=Js.Nullable.fromOption(value), */
/*     ), */
/*     children, */
/*   ); */
