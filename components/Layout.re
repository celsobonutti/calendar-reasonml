[@react.component]
let make = (~title, ~children) => {
  <div>
    <Next.Head>
      <title> title->React.string </title>
      <meta charSet="utf-8" />
      <meta name="viewport" content="initial-scale=1.0, width=device-width" />
    </Next.Head>
    <main> children </main>
    <footer>
      <div className=[%tw "w-full flex justify-center"]>
        <p className=[%tw "pb-4"]> "Made by"->React.string </p>
        <a href="https://cel.so"> "Celso Bonutti"->React.string </a>
        <p> ", 2020"->React.string </p>
      </div>
    </footer>
  </div>;
};
