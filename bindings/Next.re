module Link = {
  [@bs.module "next/link"] [@react.component]
  external make:
    (
      ~href: string=?,
      ~_as: string=?,
      ~prefetch: option(bool)=?,
      ~replace: option(bool)=?,
      ~shallow: option(bool)=?,
      ~passHref: option(bool)=?,
      ~children: React.element
    ) =>
    React.element =
    "default";
};

module Head = {
  [@bs.module "next/head"] [@react.component]
  external make: (~children: React.element) => React.element = "default";
};

module Error = {
  [@bs.module "next/head"] [@react.component]
  external make: (~statusCode: int, ~children: React.element) => React.element =
    "default";
};

module Router = {
  type t = {
    pathname: string,
    query: Js.Dict.t(string),
    asPath: string,
  };

  type pushOptions = {
    shallow: bool,
    getInitialProps: option(bool),
  };

  [@bs.send]
  external push:
    (t, ~url: string, ~asUrl: string=?, ~options: pushOptions=?, unit) => unit =
    "push";

  [@bs.send]
  external replace:
    (t, ~url: string, ~asUrl: string=?, ~options: pushOptions=?, unit) => unit =
    "replace";
};

[@bs.module "next/router"] external useRouter: unit => Router.t = "useRouter";