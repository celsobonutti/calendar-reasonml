[@decco]
type t = {
  title: string,
  id: string,
  datetime: [@decco.codec Date.codec] Js.Date.t,
  color: string,
};

type action =
  | Add(t)
  | Remove(string)
  | Edit(string, t)
  | RemoveAllFromDate(Js.Date.t);

let encode = t_encode;

let decode = t_decode;