type dispatch = Reminder.action => unit;
type contextValue = (list(Reminder.t), dispatch);

let initValue: contextValue = ([], _ => ignore());

let context = React.createContext(initValue);

let useReminders = () => React.useContext(context);

module Provider = {
  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };

  let make = React.Context.provider(context);
};