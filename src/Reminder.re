[@decco] type t = {
  title: string,
  id: string,
  datetime: [@decco.codec Date.codec] Js.Date.t,
  color: string,
};

let encode = t_encode;

let decode = t_decode;
