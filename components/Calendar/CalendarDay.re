[@react.component]
let make = (~day, ~outOfMonth) => {
  let info = (Date.isWeekend(day), outOfMonth, Date.isToday(day));
  let textColor =
    switch (info) {
    | (_, true, _) =>
      %tw
      "text-gray-500"
    | (_, false, true) =>
      %tw
      "text-white"
    | (true, _, _) =>
      %tw
      "text-teal-500"
    | _ =>
      %tw
      "text-gray-900"
    };

  let backgroundColor =
    switch (info) {
    | (_, false, true) =>
      %tw
      "bg-teal-400"
    | (true, _, _) =>
      %tw
      "bg-gray-300"
    | _ =>
      %tw
      "bg-gray-100"
    };

  <button
    className={Cn.make([
      [%tw
        "pt-3/4 relative opacity-75 group hover:opacity-100 transition-all duration-200"
      ],
      textColor,
      backgroundColor,
    ])}>
    <div
      className=[%tw
        "absolute w-full h-full p-2 top-0 flex flex-col overflow-x-hidden"
      ]>
      <p className=[%tw "group-hover:font-bold"]>
        {Js.Date.getDate(day)->Js.Float.toString->React.string}
      </p>
    </div>
  </button>;
};