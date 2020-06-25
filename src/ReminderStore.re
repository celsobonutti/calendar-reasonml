open Decco;

type reminder = Reminder.t;

[@decco]
type state = list(Reminder.t);

let reducer = (state, action: Reminder.action) => {
  let newState =
    switch (action) {
    | Add(reminder) => [reminder, ...state]
    | Remove(id) => state->Belt.List.keep(el => el.id != id)
    | Edit(id, reminder) =>
      state->Belt.List.map(el => {el.id == id ? reminder : el})
    | RemoveAllFromDate(date) =>
      state->Belt.List.keep(el => Date.isSameDay(el.datetime, date))
    };

  switch (newState->state_encode->stringFromJson) {
  | Ok(reminders) =>
    Dom.Storage.setItem("reminders", reminders, Dom.Storage.localStorage)
  | Error(_) => ()
  };

  newState;
};

[@react.component]
let make = (~children, ~initialState) => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  <ReminderContext.Provider value=(state, dispatch)>
    children
  </ReminderContext.Provider>;
};