type pageComponent = React.component(Js.t({.}));
type pageProps = Js.t({.});

type props = {
  .
  "Component": pageComponent,
  "pageProps": pageProps,
};

[@bs.obj]
external makeProps:
  (~component: pageComponent, ~pageProps: pageProps, ~key: string=?, unit) =>
  props;

let make = (props: props): React.element => {
  let component = props##"Component";
  let pageProps = props##pageProps;
  let content = React.createElement(component, pageProps);

  let (reminders, setReminders) = React.useState(_ => None);

  React.useEffect0(() => {
    let stringReminders =
      Dom_storage.getItem("reminders", Dom.Storage.localStorage)
      ->Belt.Option.getWithDefault("[]");

    switch (stringReminders->Js.Json.parseExn->ReminderStore.state_decode) {
    | Ok(value) => setReminders(_ => Some(value))
    | _ => setReminders(_ => Some([]))
    };

    None;
  });

  switch (reminders) {
  | Some(value) => <ReminderStore initialState=value> content </ReminderStore>
  | None => content
  };
};
