let getDaysForMonth = (~year, ~month) => {
  let initialDate = Js.Date.makeWithYM(~year=float_of_int(year), ~month=float_of_int(month), ());

  let endOfMonth = Date.endOfMonth(initialDate);
  let startOfMonth = Date.startOfMonth(initialDate);

  let firstDay = if (Date.isSunday(startOfMonth)) {
    startOfMonth;
  } else {
    Date.startOfWeek(startOfMonth);
  };

  let lastDay = if (Date.isSaturday(endOfMonth)) {
    endOfMonth;
  } else {
    Date.endOfWeek(endOfMonth);
  };

  Date.eachDayOfInterval({
    start: firstDay,
    end_: lastDay
  });
}