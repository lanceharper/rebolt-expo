open NavigationConfig;
open Rebolt;
open Style;

module Main = {
  let component = ReasonReact.statelessComponent("Main");
  let make = _children => {
    ...component,
    render: _self =>
      <StackNavigator
        initialState=[|Config.Home|]
        onStateChange=(
          state =>
            AsyncStorage.setItem(
              "$state",
              state |> StackNavigator.Persistence.encode |> Js.Json.stringify,
              (),
            )
            |> ignore
        )>
        ...(
             (~currentRoute, ~navigation) =>
               switch (currentRoute) {
               | Config.Home => <Home navigation />
               /* | Config.Admin => <Admin navigation /> */
               /* | Config.Welcome => <Welcome navigation /> */
               }
           )
      </StackNavigator>,
  };
};

let app = () => <Main />;
  