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


let apploader_cb = (selfsend, cb_arg : string) => {
  Js.log("Callback triggered!?  - ")
  Js.log(cb_arg);

  selfsend(Up(cb_arg));

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
