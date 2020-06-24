[@react.component]
let make = (~reminders: list(Reminder.t), ~date) => {
  <div>
    <h1> {Date.formatAsFullDate(date)->React.string} </h1>
    {reminders
     ->Belt.List.toArray
     ->Belt.Array.map(reminder => <p> reminder.title->React.string </p>)
     ->React.array}
  </div>;
};