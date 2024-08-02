<a name="FPdoK"></a>
# simplijq - A JavaScript Library to Simulate jQuery
<a name="mm03G"></a>
## Description
simplijq is a lightweight JavaScript library that simulates the basic functionalities of jQuery.
<a name="PzpGv"></a>
## Installation
```
npm install simplijq
```
<a name="kMaaj"></a>
## Usage
<a name="JqG4S"></a>
### Basic Usage
```
import jq from 'simplijq';

const $ = jq;

$(document).ready(function() {
  $(".btn").hide();
});
```
<a name="TlPIn"></a>
### Methods

- **ready(callback)**: Executes the callback function when the DOM is fully loaded.
- **hide()**: Hides the selected elements.
- **show()**: Shows the selected elements.
<a name="LCJTM"></a>
### Example
Here is an example of using `simplijq` in an HTML file:
```
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Test Library simplijq</title>
</head>
<body>
  <button class="btn">click me!</button>
  <script src="bundle.js"></script>
</body>
</html>

```
And in your JavaScript file:
```
import jq from 'simplijq';

const $ = jq;

$(document).ready(function() {
  $(".btn").hide();
});

```
<a name="OkTkx"></a>
## Development
<a name="linking-locally"></a>
### Linking Locally
1.In the library project directory, run:
```
npm link
```
2.In the test project directory, run:
```
npm link jq
```
3.Now you can import and use `simplijq` in your test project.
<a name="build-and-serve"></a>
### Build and Serve
To build and serve the library, run the following commands in the library directory:
```
npm run build
npm run start
```
This will build the library and start a development server.
