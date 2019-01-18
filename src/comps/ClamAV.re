let str = ReasonReact.string;

type state = {
  text: string
};

type action = 
  | Query(string); 

let component = ReasonReact.reducerComponent("ClamAV");

// FS access

//[@bs.module "./readfile"] [@bs.val] external read_file : unit => string = "";
//let x = read_file();

let make = (~message, _children) => {
  ...component,
  initialState: () => { text: "Welcome to ClamAV"},
  reducer: (action, {text}) => 
    switch (action) {
      | Query(text) =>  ReasonReact.Update({text: text})
      },
  render: self =>
      <div>
        <div className="ClamAV">
            {
              (ReasonReact.string(message))
            } 

        </div>        
        <p/>
    </div>
};
