let monthNames = [|
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December",
|];

let getMonthName = month => {
  switch (Belt.Array.get(monthNames, month)) {
  | Some(value) => value
  | None => "Invalid month."
  };
};

[@react.component]
let make = (~month, ~year, ~onIncrease, ~onDecrease) => {
  <div className=[%tw "flex flex-row w-56 justify-between items-center m-4"]>
    <button type_="button" onClick={_ => onDecrease()}>
      <Feather.ArrowLeft size=30 color="black" />
    </button>
    <div className=[%tw "flex flex-col justify-between items-center"]>
      <h2 className=[%tw "text-gray-800 font-semibold text-lg"]>
        {month->getMonthName->React.string}
      </h2>
      <h3 className=[%tw "text-blue-500 font-bold text-xl"]>
        {year->string_of_int->React.string}
      </h3>
    </div>
    <button type_="button" onClick={_ => onIncrease()}>
      <Feather.ArrowRight size=30 color="black" />
    </button>
  </div>;
};
