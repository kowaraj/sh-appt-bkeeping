let str = ReasonReact.string;

/* [@bs.module "./jstest"] [@bs.val] external x : unit => unit = ""; */
/* x(); */


/* [@bs.module "./jstest"] [@bs.val] external xx : unit => string = "";  */
/* let xx = xx();  */
/* Js.log(xx); */
/* /\* [@bs.module "./jstest"] [@bs.val] external init : unit => unit = ""; *\/ */
/* /\* init(); *\/ */

/* [@bs.module "./jstest"] [@bs.val] external neo4j_create : string => unit = ""; */
/* [@bs.module "./jstest"] [@bs.val] external neo4j_match : string => string = ""; */

/* let str = ReasonReact.string; */
/* let q = "CREATE (ee:Person { name: \"Emil600\", from: \"Sweden\", klout: 600 })"; */
/* neo4j_create(q); */


/* let m = "MATCH (ee:Person) WHERE ee.name = \"Emil600\" RETURN ee"; */
/* let m_ret = neo4j_match(m); */
/* Js.log(m_ret); */

[%bs.raw {|require('./app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

type page =
  | Page1
  | Page2
  | Page(int);


module type Mapper = {
  let toPage: ReasonReact.Router.url => page;
  let toUrl: page => string;
};
module Mapper: Mapper = {
  let toPage = (url: ReasonReact.Router.url) => {
    /* Js.log("mapper.toPage: " ++ url.path)      */
    switch (url.path) {
    | ["page1"] => Page1
    | ["page", id] => Page(int_of_string(id))
    | _ => Page2
    }
      };
  let toUrl = page =>
    switch (page) {
    | Page1 => "page1"
    | Page(id) => "page"++string_of_int(id)
    | _ => "page2"
    };
};


type state = {route: page};
type action = 
  | ChangeRoute(page)
  | ChangeRouteNN(int);

//let component = ReasonReact.statelessComponent("App");
let component = ReasonReact.reducerComponent("App");


let make = (~message, _children) => {
  ...component,
  initialState: () => {
    route: ReasonReact.Router.dangerouslyGetInitialUrl() 
    |> Mapper.toPage,
  },
  
  reducer: (action, _state) => {
    switch (action) {
      | ChangeRoute(a_route) => {   ReasonReact.Update({route: a_route})  }
      | ChangeRouteNN(id) => ReasonReact.Update({ route: Page(id) })
    }
      },

  didMount: self => {
    /* let watcherID = ReasonReact.Router.watchUrl( url => { */
    /*   switch (url.hash) { */
    /*     | ("page1") => self.send(ChangeRoute(Page1)) */
    /*     | ("page2") => self.send(ChangeRoute(Page2)) */
    /*   } */
    /* }); */
    let watcherID = ReasonReact.Router.watchUrl(
      url => { self.send(ChangeRoute(Mapper.toPage(url)))
    });
    self.onUnmount( () => ReasonReact.Router.unwatchUrl(watcherID) );
    },

  render: _self =>
    <div className="App">
      <div className="App-header-2">
        <img src=logo className="App-logo" alt="logo" />
        <h2> (ReasonReact.string(message)) </h2>
      </div>
      <div className="App-header-2">
        <h1>
          <a href="page1"> (str("PAGE1"))</a>
          (str("- - -"))
          <a href="page2"> (str("PAGE2"))</a>
          (str("- - -"))
//          <a href=Mapper.toUrl(Page())> (str("PAGENN"))</a>
          <a href=Mapper.toUrl( _self.state.route )> (str("PAGENN"))</a>
//          <a href="page9"> (str("PAGENN"))</a>
          <Input onSubmit= ((id) => _self.send(ChangeRouteNN(int_of_string(id)))) />

        </h1>
        <h2> (ReasonReact.string(message)) </h2>
      </div>

      <div className="App-intro">
        /* (ReasonReact.string("To get started, edit")) */
        /* <code> (ReasonReact.string(" src/app.re ")) </code> */
        /* (ReasonReact.string("and save to reload.")) */
          (
          {
          Js.log("current route: "++ Mapper.toUrl(_self.state.route))
          switch (_self.state.route) {
            | Page1 => <ToDo message="hi"/>
            | Page2 => <Neo4j message="hi neo"/>
            | Page(a_id) => <p> (str(string_of_int(a_id)))  </p>
          }
              }
    
          )
        </div>
        
    </div>,
};
