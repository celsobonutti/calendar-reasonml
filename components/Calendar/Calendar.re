module CalendarGrid = {
  [@react.component]
  let make = (~children) => {
    <div className=[%tw "grid grid-cols-7"]> children </div>;
  };
};

[@react.component]
let make = (~year, ~month) => {
  let days = Utils.getDaysForMonth(~year, ~month);

  <div className=[%tw "max-w-4xl w-full rounded-md overflow-hidden"]>
    <CalendarGrid>
      {[|"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"|]
       ->Belt.Array.map(weekday =>
           <div key={j|weekday__$weekday|j} className="bg-blue-400 py-2">
             <p className="text-center text-white">
               {React.string(weekday)}
             </p>
           </div>
         )
       ->React.array}
    </CalendarGrid>
    <CalendarGrid>
      {days
       ->Belt.Array.map(day => {
           let outOfMonth =
             Js.Date.getMonth(day) !== float_of_int(month);

           <CalendarDay outOfMonth day />;
         })
       ->React.array}
    </CalendarGrid>
  </div>;
};
