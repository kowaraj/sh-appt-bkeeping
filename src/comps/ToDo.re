let str = ReasonReact.string;

type state = {
  selectedFile: string,
  loaded: int,
  retval: string,
};

type action = 
  | AddItem
  | AddItemWithName(string)
  | Up(string);


let component = ReasonReact.reducerComponent("ToDo");


let apploader_cb = (selfsend, fn, fn_ext, ts) => {
  Js.log("Callback triggered!")
  Js.log("fn     = " ++ fn);
  Js.log("fn_ext = " ++ fn_ext);
  Js.log("ts     = " ++ ts);

  selfsend(Up("File: " ++ fn ++" has been stored as: " ++ ts ++ "." ++ fn_ext));

  "dummy return value to ignore";
};
  
let make = (_children) => {
  ...component,
  initialState: () => { selectedFile: "", loaded: 0, retval: "" },
  reducer: (action, self : state) => 
    switch (action) {
    | AddItem =>  ReasonReact.Update(self)
    | AddItemWithName(text) =>  ReasonReact.Update(self)
    | Up(text) => ReasonReact.Update({...self, retval: text})
    },
  render: self =>
    <div>
      <div>
        <ApploaderRe cb_=apploader_cb(self.send)  />
      </div>
      
      <div>
          {str(self.state.retval);}
</div>

      </div>
};
