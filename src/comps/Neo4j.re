let str = ReasonReact.string;

type state = {
  items: list(TodoType.item),
};

type action = 
  | Query(string); 

let component = ReasonReact.reducerComponent("Neo4j");

// DB access

[@bs.module "./jstest"] [@bs.val] external neo4j_create : string => unit = "";
[@bs.module "./jstest"] [@bs.val] external neo4j_match : string => string = "";

let queryDB = q => {
    //let q = "CREATE (ee:Person { name: \"Emil600\", from: \"Sweden\", klout: 600 })";
    neo4j_match(q);
    {TodoType.id: 0, text: "query completed", completed: false}

  }

  
// Make
  
let make = (~message, _children) => {
  ...component,
  initialState: () => { items: [{id: 0, text: "first item", completed: false }]},
  reducer: (action, {items}) => 
    switch (action) {
      | Query(text) =>  ReasonReact.Update({items: [ queryDB(text), ...items]})
      },
  render: self =>
      <div>
        <div className="Neo4j">
            (ReasonReact.string(message)) 
        </div>        
        <p/>
          
        <div className="title">
            (str("Neo4j DB Query: "))
            <Input onSubmit= ((text) => self.send(Query(text))) />
        </div>

    </div>
};
