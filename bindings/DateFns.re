type interval = {
  start: Js.Date.t,
  [@bs.as "end"]
  end_: Js.Date.t,
};

type date = Js.Date.t;

[@bs.module "date-fns/eachDayOfInterval"]
external eachDayOfInterval: interval => array(date) = "default";

[@bs.module "date-fns/startOfMonth"]
external startOfMonth: date => date = "default";

[@bs.module "date-fns/startOfWeek"]
external startOfWeek: date => date = "default";

[@bs.module "date-fns/endOfMonth"]
external endOfMonth: date => date = "default";

[@bs.module "date-fns/endOfWeek"]
external endOfWeek: date => date = "default";

[@bs.module "date-fns/isSaturday"]
external isSaturday: date => bool = "default";  

[@bs.module "date-fns/isSunday"]
external isSunday: date => bool = "default";  

[@bs.module "date-fns/isToday"]
external isToday: date => bool = "default";

let isWeekend = (date) => {
  isSaturday(date) || isSunday(date);
};