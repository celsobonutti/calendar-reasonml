[@decco]
type t = {
  title: string,
  id: string,
  datetime: Js.Date.t,
  color: string,
};

type date = Js.Date.t;

type action =
  | Add(t)
  | Remove(string)
  | Edit(string, t)
  | RemoveAllFromDate(date);

let reducer = (state, action) => {
  let newState =
    switch (action) {
    | Add(reminder) => [reminder, ...state]
    | Remove(id) => state->Belt.List.keep(el => el.id != id)
    | Edit(id, reminder) =>
      state->Belt.List.map(el => {el.id == id ? reminder : el})
    | RemoveAllFromDate(date) =>
      state->Belt.List.keep(el => !DateFns.isSameDay(el.datetime, date))
    };

  newState;
};