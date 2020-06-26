[@decco]
type t = {
  title: string,
  id: string,
  datetime: [@decco.codec Date.codec] Js.Date.t,
  color: string,
};

type data = {
  title: string,
  datetime: Js.Date.t,
  color: string
};

let fromData = (data) => {
  {
    title: data.title,
    datetime: data.datetime,
    color: data.color,
    id: UUID.v4()
  };
};

type action =
  | Add(t)
  | Remove(string)
  | Edit(string, t)
  | RemoveAllFromDate(Js.Date.t);

let encode = t_encode;

let decode = t_decode;