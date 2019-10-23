[%bs.raw {|require('./style.scss')|}];

[@react.component]
let make = (~tags=[], ~setTags) => {
  let (text, setText) = React.useState(() => "");

  let removeSpaceText = (text: string) =>
    Js.String.slice(~from=0, ~to_=String.length(text) - 1, text);

  let addTags = () => {
    let newTags =
      Array.map(
        tagValue => Js.String.make(tagValue),
        Js.String.split(" ", text),
      );
    setTags(_ => List.append(Array.to_list(newTags), tags));
    setText(_ => "");
  };

  let removeTag = index => {
    let newTags =
      tags->Belt.List.filterWithIndex((_, indexTag) => indexTag !== index);

    setTags(_ => newTags);
  };
  let renderTags = () =>
    List.mapi(
      (index, item) =>
        <li className="tag" key={Js.String.make(index)}>
          <span className="tag-title"> {item |> React.string} </span>
          <span className="tag-close-icon" onClick={_ => removeTag(index)}>
            {"x" |> React.string}
          </span>
        </li>,
      tags,
    )
    ->Array.of_list
    ->React.array;

  let validEvent = event => {
    let keyCode = ReactEventRe.Keyboard.keyCode(event);
    switch (keyCode) {
    | 13 => true
    | 32 => true
    | _ => false
    };
  };

  let handleTextChange = event => {
    let valueChange = ReactEvent.Form.target(event)##value;
    let lastChar =
      Js.String.charAt(String.length(valueChange) - 1, valueChange);
    let valueText =
      switch (lastChar) {
      | " " => removeSpaceText(Js.String.make(valueChange))
      | _ => valueChange
      };
    setText(_ => valueText);
  };

  <div className="tags-input">
    <ul id="tags"> {renderTags()} </ul>
    <input
      type_="text"
      value=text
      onChange=handleTextChange
      onKeyUp={event => validEvent(event) === true ? addTags() : ()}
      placeholder="Pressione a tecla enter ou espaço"
    />
  </div>;
};