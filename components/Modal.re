[@react.component]
let make = (~children, ~onClosed) => {
  React.useEffect0(() => {
    let document = Webapi.Dom.Document.asEventTarget(Webapi.Dom.document);

    let onEscape = (event: Dom.keyboardEvent) =>
      if (Webapi.Dom.KeyboardEvent.key(event) == "Escape") {
        onClosed();
      };

    Webapi.Dom.EventTarget.addKeyDownEventListener(onEscape, document);

    Some(
      () =>
        Webapi.Dom.EventTarget.removeEventListener(
          "keydown",
          key => {Js.log(key)},
          document,
        ),
    );
  });

  <div
    onClick={_ => onClosed()}
    className=[%tw
      "h-full w-full absolute bg-black bg-opacity-25 inset-0 z-10 grid"
    ]>
    <div
      onClick={e => ReactEvent.Mouse.stopPropagation(e)}
      className=[%tw
        "rounded-md bg-white m-auto sm:w-screen relative h-screen w-screen md:max-h-1/2 md:w-auto"
      ]>
      <Feather.XCircle
        color="black"
        size=26
        onClick={_ => onClosed()}
        className=[%tw "ml-auto mr-2 mt-2"]
      />
      <div> children </div>
    </div>
  </div>;
};
