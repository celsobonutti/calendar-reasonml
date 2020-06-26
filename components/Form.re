open BsReform;

module StateLenses = [%lenses
  type state = {
    title: string,
    datetime: Js.Date.t,
    color: string,
  }
];

module ReminderForm = ReForm.Make(StateLenses);

module FieldString = {
  [@react.component]
  let make = (~field, ~label) => {
    <ReminderForm.Field
      field
      render={({handleChange, error, value}) =>
        <div className=[%tw "my-2"]>
          <label className=[%tw "text-lg"] htmlFor=label>
            {React.string(label)}
          </label>
          <input
            name=label
            className=[%tw
              "block border-gray-400 focus:border-black border-2 p-2 rounded-sm w-full my-2"
            ]
            value
            onChange={Helpers.handleChange(handleChange)}
          />
          <p className=[%tw "text-red-600"]>
            {error->Belt.Option.getWithDefault("")->React.string}
          </p>
        </div>
      }
    />;
  };
};

[@react.component]
let make =
    (~initialReminder: option(Reminder.t)=?, ~initialDate=?, ~onSubmit) => {
  let date =
    switch (initialReminder, initialDate) {
    | (Some({datetime}), _) => datetime
    | (None, Some(date)) => date
    | (_, _) => Js.Date.make()
    };

  let reform =
    ReminderForm.use(
      ~validationStrategy=OnDemand,
      ~schema={
        ReminderForm.Validation.Schema([|
          StringMin(Title, 5),
          StringMax(Title, 20),
          StringRegExp(Color, "#[0-9A-Fa-f]{6}"),
        |]);
      },
      ~onSubmit=
        ({state}) => {
          let reminder : Reminder.data = {
            title: state.values.title,
            color: state.values.color,
            datetime: state.values.datetime
          };
          onSubmit(reminder);
          None;
        },
      ~initialState={title: "", datetime: date, color: ""},
      (),
    );

  <div className=[%tw "px-8 pb-2 max-w-full w-96"]>
    <h1 className=[%tw "text-2xl"]> "Add a new reminder:"->React.string </h1>
    <ReminderForm.Provider value=reform>
      <form
        onSubmit={event => {
          ReactEvent.Synthetic.preventDefault(event);
          reform.submit();
        }}>
        <FieldString field=StateLenses.Title label="Title" />
        <ReminderForm.Field
          field=StateLenses.Color
          render={({handleChange, error, value}) =>
            <div className=[%tw "mt-4"]>
              <label className=[%tw "text-lg"]>
                "Pick a color:"->React.string
              </label>
              <ColorPicker onChange={color => handleChange(color)} value />
              <p className=[%tw "text-red-600"]>
                {error->Belt.Option.getWithDefault("")->React.string}
              </p>
            </div>
          }
        />
        <ReminderForm.Field
          field=StateLenses.Datetime
          render={({handleChange, error, value}) =>
            <div className=[%tw "mt-4"]>
              <label className=[%tw "text-lg"]>
                "Pick your date:"->React.string
              </label>
              <DatePicker onChange={date => handleChange(date)} value />
              <p className=[%tw "text-red-600"]>
                {error->Belt.Option.getWithDefault("")->React.string}
              </p>
            </div>
          }
        />
        <button
          type_="submit"
          className=[%tw
            "py-2 mt-4 bg-blue-400 w-full rounded-md text-white font-semibold"
          ]>
          "Create reminder"->React.string
        </button>
      </form>
    </ReminderForm.Provider>
  </div>;
};
