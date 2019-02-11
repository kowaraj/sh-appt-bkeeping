let str = ReasonReact.string;

type state = {
  text: string
};

type action = 
  | Req;
  
let component = ReasonReact.reducerComponent("Text");

[@bs.module "./jstest_http"] [@bs.val] external http_req : (string, (string => unit)) => string = "";

let message_body = ref("default message body")

let cbX = msg => {
    Js.log("RETURN ====== ")
    Js.log(msg)
    message_body := msg  
  }
  
let req = () => {
    http_req("teststring", cbX);
  }

  
let make = (~message, ~id=0, _children) => {
  ...component,
  initialState: () => { text: "default state"},
  reducer: (action, state) =>
    switch (action) {
      | Req =>  ReasonReact.Update({text: req()})
      },
  render: self =>
    <div className="Neo4j">
      // Add Item button
      <button onClick=((_evt) => self.send(Req)) >
          (str("req!"))
      </button>
      <div>
          (ReasonReact.string(message_body^))
      </div>
    </div>
};
