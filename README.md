# bs-tags-react
ReasonMl component of tags:

  - [Installation](#installation)
  - [Usage](#usage)

## Installation
Need to install css-loader, node-sass, sass-loader, style-loader:
```
yarn add css-loader node-sass sass-loader style-loader --dev
```
```
yarn add bs-tags-react
```
E adicionar na bs config.json os modulo bs-tags-react:

```
"bs-dependencies": [
 "bs-tags-react"
]
```
Then add it to webpack.config.js under plugins:
```
 module: {
    rules: [
      {
        test: /\.scss$/,
        use: ["style-loader", "css-loader", "sass-loader"]
      },
      {
        test: /\.svg$/,
        use: ["@svgr/webpack"]
      }
    ]
  },
```

## Usage

```
open BsTagsReact;

[@react.component]
let make = () => {
  let (tags, setTags) = React.useState(() => []);

  <BsTagsReact.Tag tags setTags />;
};
```