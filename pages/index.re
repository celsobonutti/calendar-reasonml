type modal =
  | Nothing
  | Form
  | Date(Js.Date.t);

[@react.component]
let make = () => {
  let today = Js.Date.make();
  let (month, setMonth) =
    React.useState(() => Js.Date.getMonth(today)->int_of_float);
  let (year, setYear) =
    React.useState(() => Js.Date.getFullYear(today)->int_of_float);

  let (modal, setModal) = React.useState(() => Nothing);

  let (reminders, dispatch) = ReminderContext.useReminders();

  let increaseMonth = () => {
    setMonth(currentMonth =>
      if (currentMonth == 11) {
        setYear(year => year + 1);
        0;
      } else {
        currentMonth + 1;
      }
    );
  };

  let decreaseMonth = () => {
    setMonth(currentMonth =>
      if (currentMonth == 0) {
        setYear(year => year - 1);
        11;
      } else {
        currentMonth - 1;
      }
    );
  };

  <React.Fragment>
    {switch (modal) {
     | Nothing => React.null
     | Date(date) =>
       let dateReminders =
         reminders
         ->Belt.List.keep(reminder => Date.isSameDay(reminder.datetime, date))
         ->Belt.List.sort((reminderA, reminderB) =>
             Date.isBefore(reminderA.datetime, reminderB.datetime) ? (-1) : 1
           );
       <Modal onClosed={_ => setModal(_ => Nothing)}>
         <DaySummary date reminders=dateReminders />
       </Modal>;
     | Form =>
       <Modal onClosed={_ => setModal(_ => Nothing)}>
         <Form onSubmit={data => {
           let reminder = Reminder.fromData(data);
           dispatch(Add(reminder));
           setModal(_ => Nothing);
         }}/>
       </Modal>
     }}
    <Layout title="Calendar 2020">
      <div
        className=[%tw
          "w-full flex flex-col justify-start items-center sm:p-8 md:px-16 md:py-4 relative"
        ]>
        <Selector
          month
          year
          onIncrease=increaseMonth
          onDecrease=decreaseMonth
        />
        <button
          className=[%tw "mb-4 flex items-center gap-2"]
          onClick={_ => setModal(_ => Form)}>
          <Feather.PlusCircle size=30 color="black" />
          <span className=[%tw "font-semibold"]>
            "Add Reminder"->React.string
          </span>
        </button>
        <div className=[%tw "px-2 w-full flex justify-center"]>
          <Calendar
            month
            year
            onDateClicked={date => setModal(_ => Date(date))}
          />
        </div>
      </div>
    </Layout>
  </React.Fragment>;
};

let default = make;
