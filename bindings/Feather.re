module XCircle = {
  [@bs.module "@bit/feathericons.react-feather.x-circle"] [@react.component]
  external make:
    (
      ~color: string,
      ~size: int,
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?
    ) =>
    React.element =
    "default";
};

module PlusCircle = {
  [@bs.module "@bit/feathericons.react-feather.plus-circle"] [@react.component]
  external make:
    (
      ~color: string,
      ~size: int,
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?
    ) =>
    React.element =
    "default";
};

module ArrowRight = {
  [@bs.module "@bit/feathericons.react-feather.arrow-right-circle"]
  [@react.component]
  external make:
    (
      ~color: string,
      ~size: int,
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?
    ) =>
    React.element =
    "default";
};

module ArrowLeft = {
  [@bs.module "@bit/feathericons.react-feather.arrow-left-circle"]
  [@react.component]
  external make:
    (
      ~color: string,
      ~size: int,
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?
    ) =>
    React.element =
    "default";
};

module Edit = {
  [@bs.module "@bit/feathericons.react-feather.edit"] [@react.component]
  external make:
    (
      ~color: string,
      ~size: int,
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?
    ) =>
    React.element =
    "default";
};

module Trash = {
  [@bs.module "@bit/feathericons.react-feather.trash-2"] [@react.component]
  external make:
    (
      ~color: string,
      ~size: int,
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?
    ) =>
    React.element =
    "default";
};
