
let reminderProvider = React.createContext([]: list(Reminder.t));

let makeProps = (~value, ~children, ()) => {
  "value": value,
  "children": children
};

let make = React.Context.provider(reminderProvider);