[@react.component]
let make = () => {
  let router = Next.useRouter();

  let date = router.query->Js.Dict.get("date");

  switch (date) {
  | None => <p> "Ops tem algo de errado aqui hein."->React.string </p>
  | Some(value) => <div />
  };
};

let default = make;