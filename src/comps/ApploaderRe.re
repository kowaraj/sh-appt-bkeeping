/* type apploader_cb_retval = { */
/*   fn : string, */
/*   fn_ext : string,  */
/*   status : int, */
/* }; */

[@bs.deriving abstract]
type jsProps = {
  cb: string=>string=>string => string,
  value: Js.nullable(int),
};


//IMPORTANT! This fails: [@bs.module] external apploader : ReasonReact.reactClass = "./Apploader";
[@bs.module "./Apploader"] external apploader : ReasonReact.reactClass = "default";

let make = (~cb_, ~value_=?, children) => {
  let jsp = jsProps(~cb=cb_, ~value=Js.Nullable.fromOption(value_));

  ReasonReact.wrapJsForReason(
    ~reactClass=apploader,
     //~props=Js.Obj.empty(),
    ~props=jsp,
    children,
  );
};

