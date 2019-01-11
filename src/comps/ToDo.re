let str = ReasonReact.string;

type state = {
  items: list(TodoType.item),
};

type action = 
  | AddItem
  | AddItemWithName(string);

let component = ReasonReact.reducerComponent("ToDo");

let lastId = ref(0);

let newItem = () => {
  lastId := lastId^ + 1;
  {TodoType.id: lastId^, text: "default text", completed: false}
};

let newItemWithName = (text) => {
  lastId := lastId^ + 1;
  {TodoType.id: lastId^, text: text, completed: false}
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
        <Input onSubmit= ((text) => self.send(AddItemWithName(text))) />
      </div>

      <div className="items">
        (
          ReasonReact.array(Array.of_list(
              List.map((itemXX) => <TodoItem itemX=itemXX />, self.state.items)
          ))
        )
      </div>

    </div>
};
