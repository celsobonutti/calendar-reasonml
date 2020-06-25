[@react.component]
let make = (~children) => {
  <div className=[%tw "h-full w-full bg-black opacity-25 inset-0"]>
    <div className=[%tw "rounded-md bg-white"]> children </div>
  </div>;
};