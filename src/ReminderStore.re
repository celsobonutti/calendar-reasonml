open Decco;

type reminder = Reminder.t;

[@decco]
type state = list(Reminder.t);

type action =
  | Add(reminder)
  | Remove(string)
  | Edit(string, reminder)
  | RemoveAllFromDate(Js.Date.t);

let reducer = (state, action) => {
  let newState =
    switch (action) {
    | Add(reminder) => [reminder, ...state]
    | Remove(id) => state->Belt.List.keep(el => el.id != id)
    | Edit(id, reminder) =>
      state->Belt.List.map(el => {el.id == id ? reminder : el})
    | RemoveAllFromDate(date) =>
      state->Belt.List.keep(el => Date.isSameDay(el.datetime, date))
    };

  let encodedState = newState->state_encode;

  switch (stringFromJson(encodedState)) {
  | Ok(reminders) =>
    Dom.Storage.setItem("reminders", reminders, Dom.Storage.localStorage)
  | Error(_) => ()
  };

  newState;
};