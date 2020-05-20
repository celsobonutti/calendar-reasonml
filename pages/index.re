[@react.component]
let make = () => {
  <div className=[%tw "w-full h-screen flex flex-col justify-center items-center"]>
    <Calendar month=4 year=2020 />
  </div>;
};

let default = make;