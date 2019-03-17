let str = ReasonReact.string;

type state = {
  text: string,
  text2: ref(string)
};

type action = 
  | Req
  | Req2( action=>unit)
  | Up(string);
  
let component = ReasonReact.reducerComponent("UploadImage");

[@bs.module "./jstest_upload"] [@bs.val] external http_req : (string, (string => unit)) => string = "";


let cbX = msg => {
    Js.log("RETURN ====== ")
    Js.log(msg)
  }

let cbY = (selfsend, msg) => {
    Js.log("RETURN ====== ")
    selfsend(Up(msg))
    Js.log(msg)
  }
  
let req = () => {
    http_req("teststring", cbX);
  }

let req2 = (selfsend) => {
    http_req("teststring", cbY(selfsend));
  }

  
let make = ( ~message, ~id=0, _children) => {

  {
  ...component,
  initialState: () => { text: "default state", text2: ref("default state")},

  reducer: (action, state) =>
    switch (action) {
      | Req =>  {req()
                 ReasonReact.Update({text: "Request sent", text2: ref("Request sent")})
                 }
      | Req2(selfsend) =>  {req2(selfsend)
                 ReasonReact.Update({text: "Request sent", text2: ref("Request sent")})
                 }
      | Up(text) => ReasonReact.Update({text: text, text2: ref(text)})
      },
  
  render: self =>
    <div className="Uploader">

      <button onClick=((_evt) => self.send(Req2(self.send))) >
          (str("req!"))
      </button>
      <div>
          (ReasonReact.string(self.state.text))
    <br/>
          (ReasonReact.string(self.state.text2^))
      </div>
    </div>
    }
};
