[@react.component]
let make = (~reminders: list(Reminder.t), ~date) => {
  let (_, dispatch) = ReminderContext.useReminders();

  <div className=[%tw "px-8 pb-2 max-w-full"]>
    <h1 className=[%tw "text-2xl"]>
      {Date.formatAsFullDate(date)->React.string}
    </h1>
    <div>
      {if (Belt.List.length(reminders) > 0) {
         <h2 className=[%tw "text-xl mt-2"]>
           "Your reminders are:"->React.string
         </h2>;
       } else {
         <h2 className=[%tw "text-xl mt-2"]>
           "You have no appointments for this day"->React.string
         </h2>;
       }}
      <div className=[%tw "my-2 w-128 max-w-full"]>
        {reminders
         ->Belt.List.toArray
         ->Belt.Array.map(reminder =>
             <div
               key={reminder.id}
               style={ReactDOMRe.Style.make(
                 ~backgroundColor=reminder.color,
                 (),
               )}
               className=[%tw
                 "rounded-sm px-4 py-1 flex items-center justify-between"
               ]>
               <div className=[%tw ""]>
                 <p className=[%tw "text-lg font-bold"]>
                   reminder.title->React.string
                 </p>
                 <p className=[%tw "text-base font-semibold"]>
                   {{
                      reminder.datetime->Date.format("HH:mm");
                    }
                    ->React.string}
                 </p>
               </div>
               <div className=[%tw ""]>
                 <Feather.Trash
                   color="black"
                   size=25
                   onClick={_ => dispatch(Remove(reminder.id))}
                 />
               </div>
             </div>
           )
         ->React.array}
      </div>
    </div>
  </div>;
};
