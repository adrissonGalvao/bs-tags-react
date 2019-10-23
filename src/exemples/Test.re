[@react.component]
let make = () => {
  let (tags, setTags) = React.useState(() => []);

  <Tag tags setTags />;
};