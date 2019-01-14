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

        // Test button
        <button onClick=((_evt) => Js.log("didn't add something")) >
            (str("Add something"))
        </button>
        <p/>

        // Add Item button
        <button onClick=((_evt) => self.send(AddItem)) >
            (str("Add more of something "))
        </button>
        <p/>

        // Add Item input
        <div className="title">
            (str("What to do"))
            <Input onSubmit= ((text) => self.send(AddItemWithName(text))) />
        </div>

        // List of Items
        <div className="items">
        (
          ReasonReact.array(Array.of_list(
            List.map((itemXX) => {
                     let i : TodoType.item = itemXX;
                     <li key= string_of_int(i.id) >
                       <TodoItem itemX=itemXX />
                     </li>}
                     , self.state.items)
          ))
        )
        </div>

        

    </div>
};
