let str = ReasonReact.string;

[%bs.raw {|require('./app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

type page =
  | Page1
  | Page2
  | Text
  | Text2
  | PageAMSLaptopAntivirus
  | Page(int);


module type Mapper = {
  let toPage: ReasonReact.Router.url => page;
  let toUrl: page => string;
};
module Mapper: Mapper = {
  let toPage = (url: ReasonReact.Router.url) => {
    switch (url.path) {
    | ["page1"] => Page1
    | ["text"] => Text
    | ["text2"] => Text2
    | ["pageAMSLaptopAntivirus"] => PageAMSLaptopAntivirus
    | ["page", id] => Page(int_of_string(id))
    | _ => Page2
    }
      };
  let toUrl = page =>
    switch (page) {
    | Page1 => "page1"
    | PageAMSLaptopAntivirus => "pageAMSLaptopAntivirus"
    | Page(id) => "page"++string_of_int(id)
    | _ => "page2"
    };
};


type state = {route: page};
type action = 
  | ChangeRoute(page)
  | ChangeRouteNN(int);

let component = ReasonReact.reducerComponent("App");


let make = (~message, _children) => {
  ...component,
  initialState: () => {
    route: ReasonReact.Router.dangerouslyGetInitialUrl() 
    |> Mapper.toPage,
  },
  
  reducer: (action, _state) =>
    switch (action) {
      | ChangeRoute(a_route) => ReasonReact.Update({route: a_route})
      | ChangeRouteNN(id) => ReasonReact.Update({ route: Page(id) })
    },

  didMount: self => {
    let watcherID = ReasonReact.Router.watchUrl(
      url => { self.send(ChangeRoute(Mapper.toPage(url)))
    });
    self.onUnmount( () => ReasonReact.Router.unwatchUrl(watcherID) );
    },

  render: _self =>
    <div className="App">

      <div className="App-header-2">
        <h2> (ReasonReact.string(message)) </h2>
        <img src=logo className="App-logo" alt="logo" />
      </div>

      <div className="App-header-2">
        <h1>
          <a href="page1"> (str("Todo List"))</a>
          (str(" ..  "))
          <a href="page2"> (str("Neo4j"))</a>
          (str(" ..  "))
          <a href="text"> (str("T1"))</a>
          (str(" ..  "))
          <a href="text2"> (str("T2"))</a>
          (str(" ..  "))
          <a href="pageAMSLaptopAntivirus"> (str("AMS LT Antivirus"))</a>
          (str(" ..  "))
          <a href=Mapper.toUrl( _self.state.route )> (str("PAGENN"))</a>
          (str(" ..  "))
          <Input ph="enter a page" onSubmit= ((id) => _self.send(ChangeRouteNN(int_of_string(id)))) />
        </h1>
      </div>

      /* <div> */
      /*   <h1> */
      /*     <a href="http://localhost:60300/pageHawaii"> (str("Science data transfer to Hawaii")) </a> */
      /*   </h1> */
      /* </div> */




    
      <div className="App-intro"> (
          switch (_self.state.route) {
          | Page1 => <ToDo message="hi"/>
          | Page2 => <Neo4j message="hi neo"/>
          | Text => <p> (str("Test page #666")) </p>
          | Text2 => <TextPage message="hi"/>
          | PageAMSLaptopAntivirus => <ClamAV message="hi clamav"/>
          | Page(666) => <p> (str("Test page #666")) </p>
          | Page(a_id) => <p> (str(string_of_int(a_id)))  </p>
          })
        </div>
        
    </div>,
};
