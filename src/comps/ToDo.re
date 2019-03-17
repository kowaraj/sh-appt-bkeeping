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
          <a href="http://ec2-52-211-128-21.eu-west-1.compute.amazonaws.com:8080/"> {str("UPLOADLINK")}</a>
          <form action="http://ec2-52-211-128-21.eu-west-1.compute.amazonaws.com:8080/upload" encType="multipart/form-data" method="post">
            <input type_="file" name="uploadFile">
            </input>
            <input type_="submit" value="Upload">
            </input>
          </form>
        </div>

        <div>
            <Apploader />
        </div>

      </div>
};
