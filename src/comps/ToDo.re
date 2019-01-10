  
let str = ReasonReact.string;

type item  = {
  id : int, 
  text : string, 
  completed: bool
  };

module TodoItem = {
  let component = ReasonReact.statelessComponent("TodoItem");
  let make = (~item, children) => {
    ...component,
    render: (self) =>
      <div className="item">
        <input
          type_="checkbox"
          checked=(item.completed)
          /* TODO make interactive */
        />
        (str(item.text))
      </div>
  };
};

let valueFromEvent = (evt) : string => (
  evt
  |> ReactEventRe.Form.target
  |> ReactDOMRe.domElementToObj
)##value;


module Input = {
  type state = string;
  let component = ReasonReact.reducerComponent("Input");
  let make = (~onSubmit, _) => {
    ...component,
    initialState: () => "",
    reducer: (newText, _text) => ReasonReact.Update(newText),
    render: ({state: text, send}) =>
      <input
        value=text
        type_="text"
        placeholder="Write something to do"
        onChange=((evt) => send(valueFromEvent(evt)))
        onKeyDown=((evt) =>
          if (ReactEventRe.Keyboard.key(evt) == "Enter") {
            onSubmit(text);
            send("")
          }
        )
      />
  };
  };




type state = {
  items: list(item),
};

type action = 
  | AddItem
  | AddItemWithName(string);

let component = ReasonReact.reducerComponent("ToDo");

let lastId = ref(0);

let newItem = () => {
  lastId := lastId^ + 1;
  {id: lastId^, text: "default text", completed: false}
};

let newItemWithName = (text) => {
  lastId := lastId^ + 1;
  {id: lastId^, text: text, completed: false}
};
  
let make = (~message, _children) => {
  ...component,
  initialState: () => { items: [{id: 0, text: "first item", completed: false }]},
  reducer: (action, {items}) => 
    switch (action) {
      | AddItem =>  ReasonReact.Update({items: [ newItem(), ...items]})
      | AddItemWithName(text) =>  ReasonReact.Update({items: [ newItemWithName(text), ...items]})
      },
  render: self =>
      <div>
        <div className="Todo">
            (ReasonReact.string(message)) 
        </div>
        
        <button onClick=((evt) => Js.log("didn't add something")) >
            (str("Add something"))
        </button>
        <p/>
        <button onClick=((evt) => self.send(AddItem)) >
            (str("Add more of something "))
        </button>
        <p/>
        <p/>
        <p/>
      <div className="title">
        (str("What to do"))
        <Input onSubmit=((text) => self.send(AddItemWithName(text))) />
      </div>

      <div className="items">
        (
          ReasonReact.array(Array.of_list(
              List.map((item) => <TodoItem item />, self.state.items)
          ))
        )
      </div>
      </div>
};
