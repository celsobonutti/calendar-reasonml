[@react.component]
let make = (~title, ~children) => {
  <div>
    <Next.Head>
      <title> title->React.string </title>
      <meta charSet="utf-8" />
      <meta name="viewport" content="initial-scale=1.0, width=device-width" />
    </Next.Head>
    children
    <footer>
      <div> <p> "Made by Celso, 2020"->React.string </p> </div>
    </footer>
  </div>;
};