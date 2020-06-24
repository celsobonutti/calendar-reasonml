[@react.component]
let make = () => {
  let today = Js.Date.make();
  let (month, setMonth) =
    React.useState(() => Js.Date.getMonth(today)->int_of_float);
  let (year, setYear) =
    React.useState(() => Js.Date.getFullYear(today)->int_of_float);

  let increaseMonth = () => {
    setMonth(month =>
      if (month == 11) {
        setYear(year => year + 1);
        0;
      } else {
        month + 1;
      }
    );
  };

  let decreaseMonth = () => {
    setMonth(month =>
      if (month == 0) {
        setYear(year => year - 1);
        11;
      } else {
        month - 1;
      }
    );
  };

  <Layout title="Calendar 2020">
    <div
      className=[%tw
        "w-full h-screen flex flex-col justify-start items-center sm:p-8 md:p-16"
      ]>
      <Selector month year onIncrease=increaseMonth onDecrease=decreaseMonth />
      <Calendar month year />
    </div>
  </Layout>;
};

let default = make;