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

  let (modalElement, setModalElement) = React.useState(() => Nothing);

  let (reminders, _) = ReminderContext.useReminders();

  let increaseMonth = () => {
    setMonth(month =>
      if (month == 11) {
        setYear(year => year + 1);
        0;
      } else {
        month + 1;
      }
    );
  };

  let decreaseMonth = () => {
    setMonth(month =>
      if (month == 0) {
        setYear(year => year - 1);
        11;
      } else {
        month - 1;
      }
    );
  };

  <>
    {switch (modalElement) {
     | Nothing => React.null
     | Date(date) => <Modal> <DaySummary date reminders /> </Modal>
     | Form => <Modal> <h1> "Form"->React.string </h1> </Modal>
     }}
    <Layout title="Calendar 2020">
      <div
        className=[%tw
          "w-full flex flex-col justify-start items-center sm:p-8 md:px-16 md:py-4"
        ]>
        <Selector
          month
          year
          onIncrease=increaseMonth
          onDecrease=decreaseMonth
        />
        <Calendar
          month
          year
          onDateClicked={date => setModalElement(_ => Date(date))}
        />
      </div>
    </Layout>
  </>;
};

let default = make;