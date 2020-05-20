let getDaysForMonth = (~year, ~month) => {
  let initialDate = Js.Date.makeWithYM(~year=float_of_int(year), ~month=float_of_int(month), ());

  let endOfMonth = DateFns.endOfMonth(initialDate);
  let startOfMonth = DateFns.startOfMonth(initialDate);

  let firstDay = if (DateFns.isSunday(startOfMonth)) {
    startOfMonth;
  } else {
    DateFns.startOfWeek(startOfMonth);
  };

  let lastDay = if (DateFns.isSaturday(endOfMonth)) {
    endOfMonth;
  } else {
    DateFns.endOfWeek(endOfMonth);
  };

  DateFns.eachDayOfInterval({
    start: firstDay,
    end_: lastDay
  });
}