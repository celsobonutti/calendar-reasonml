let colors = [|
  "#993333",
  "#ff9900",
  "#ffcc33",
  "#33cc66",
  "#669933",
  "#006699",
  "#0099cc",
  "#996699",
  "#cc6699",
  "#999999",
|];

module ColorDot = {
  [@react.component]
  let make = (~color, ~onChange, ~isSelected) => {
    <button
      style={ReactDOMRe.Style.make(
        ~backgroundColor=isSelected ? "white" : color,
        ~border="4px solid" ++ color,
        (),
      )}
      onClick={_ => {onChange(color)}}
      className=[%tw "h-8 w-8 rounded-full m-2"]
      type_="button"
    />;
  };
};

[@react.component]
let make = (~value=?, ~onChange) => {
  <div>
    {colors
     ->Belt.Array.map(color =>
         <ColorDot
           color
           onChange
           isSelected={color == Belt.Option.getWithDefault(value, "")}
           key={"color__dot__" ++ color}
         />
       )
     ->React.array}
  </div>;
};
