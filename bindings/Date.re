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

[@bs.module "date-fns/endOfWeek"] external endOfWeek: date => date = "default";

[@bs.module "date-fns/isToday"] external isToday: date => bool = "default";

[@bs.module "date-fns/format"]
external format: (date, string) => string = "default";

[@bs.module "date-fns/isSameDay"]
external isSameDay: (date, date) => bool = "default";

[@bs.module "date-fns/parseISO"]
external parseISO: string => Js.Date.t = "default";

let formatAsFullDate = date => {
  format(date, "EEEE, MMM do, yyyy");
};

let isSaturday = date => {
  Js.Date.getDay(date) == 6.;
};

let isSunday = date => {
  Js.Date.getDay(date) == 0.;
};

let isWeekend = date => {
  isSaturday(date) || isSunday(date);
};

let isBefore = (dateA, dateB) => {
  Js.Date.getTime(dateA) < Js.Date.getTime(dateB);
};

let encoder: Decco.encoder(Js.Date.t) =
  date => Js.Date.toISOString(date)->Decco.stringToJson;

let decoder: Decco.decoder(Js.Date.t) =
  json => {
    switch (Decco.stringFromJson(json)) {
    | Belt.Result.Ok(v) => parseISO(v)->Ok
    | Belt.Result.Error(_) as err => err
    };
  };

let codec = (encoder, decoder);