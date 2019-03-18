let str = ReasonReact.string;

type state = {
  selectedFile: string,
  loaded: int
};

type action = 
  | AddItem
  | AddItemWithName(string);

let component = ReasonReact.reducerComponent("ToDo");



let make = (_children) => {
  ...component,
  initialState: () => { selectedFile: "", loaded: 0 },
  reducer: (action, self : state) => 
    switch (action) {
      | AddItem =>  ReasonReact.Update(self)
      | AddItemWithName(text) =>  ReasonReact.Update(self)
      },
  render: self =>
      <div>

        <div>
            <ApploaderRe />
        </div>

      </div>
};
