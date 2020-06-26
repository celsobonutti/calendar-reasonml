[@react.component]
let make = (~value, ~onChange) => {
  let (isCalendarShown, setCalendarShown) = React.useState(() => false);

  let (month, setMonth) =
    React.useState(() => Js.Date.getMonth(value)->int_of_float);

  let (year, setYear) =
    React.useState(() => Js.Date.getFullYear(value)->int_of_float);

  let onIncrease = () => {
    setMonth(currentMonth =>
      if (currentMonth == 11) {
        setYear(year => year + 1);
        0;
      } else {
        currentMonth + 1;
      }
    );
  };

  let onDecrease = () => {
    setMonth(currentMonth =>
      if (currentMonth == 0) {
        setYear(year => year - 1);
        11;
      } else {
        currentMonth - 1;
      }
    );
  };

  <div className=[%tw "relative"]>
    <input
      readOnly=true
      className=[%tw
        "block border-gray-400 focus:border-black border-2 p-2 rounded-sm w-full my-2"
      ]
      onFocus={_ => setCalendarShown(_ => true)}
      value={Date.formatAsFullDate(value)}
    />
    {isCalendarShown
       ? <div
           className=[%tw
             "absolute top-4 left-0 right-0 bg-white flex flex-col items-center z-40"
           ]>
           <Selector month year onIncrease onDecrease />
           <Calendar
             month
             year
             onDateClicked={date => {
               onChange(date);
               setCalendarShown(_ => false);
             }}
           />
         </div>
       : React.null}
  </div>;
};
