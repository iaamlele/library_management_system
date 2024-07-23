# 一 概念介绍
## webpack
是用于js应用程序的静态模块打包工具.当 webpack 处理应用程序时，它会在内部从一个或多个入口点构建一个 [依赖图(dependency graph)](https://www.webpackjs.com/concepts/dependency-graph/)，然后将你项目中所需的每一个模块组合成一个或多个 _bundles_，它们均为静态资源，用于展示你的内容。
## 核心概念
### 入口(entry)
**入口起点(entry point)** 指示 webpack 应该使用哪个模块，来作为构建其内部 [依赖图(dependency graph)](https://www.webpackjs.com/concepts/dependency-graph/) 的开始。进入入口起点后，webpack 会找出有哪些模块和库是入口起点（直接和间接）依赖的。
默认值是 `./src/index.js`，但你可以通过在 [webpack configuration](https://www.webpackjs.com/configuration) 中配置 `entry` 属性，来指定一个（或多个）不同的入口起点。
#### 语法
1.单个入口(简写)-> entry: string | [string]
2.对象语法-> entry: { <entryChunkName> string | [string] } | {}
3.描述入口的对象-> dependOn, filename, import,library, runtime, publicPath
#### 常见场景
1.分离app(应用程序)和vendor(第三方库)入口
2.多页面应用程序
### 输出(output)
**output** 属性告诉 webpack 在哪里输出它所创建的 _bundle_(告知 webpack 如何向硬盘写入编译文件)，以及如何命名这些文件。主要输出文件的默认值是 `./dist/main.js`，其他生成文件默认放置在 `./dist` 文件夹中。注意，即使可以存在多个 `entry` 起点，但只能指定一个 `output` 配置。
#### 语法
1.多个入口起点

### loader
webpack 只能理解 JavaScript 和 JSON 文件，这是 webpack 开箱可用的自带能力。**loader** 让 webpack 能够去处理其他类型的文件，并将它们转换为有效 [模块](https://www.webpackjs.com/concepts/modules)，以供应用程序使用，以及被添加到依赖图中。loader 可以将文件从不同的语言（如 TypeScript）转换为 JavaScript 或将内联图像转换为 data URL。loader 甚至允许你直接在 JavaScript 模块中 `import` CSS 文件！
#### 两个属性

1. `test` 属性，识别出哪些文件会被转换。
2. `use` 属性，定义出在进行转换时，应该使用哪个 loader。

注意:1.定义在module.rules,而不是rules中；2.正则表达式不要添加引号
#### 两种使用方式

- [配置方式](https://www.webpackjs.com/concepts/loaders/#configuration)（推荐）：在 **webpack.config.js** 文件中指定 loader。
- [内联方式](https://www.webpackjs.com/concepts/loaders/#inline)：在每个 `import` 语句中显式指定 loader。

#### 特性

- loader 支持链式调用。链中的每个 loader 会将转换应用在已处理过的资源上。一组链式的 loader 将按照相反的顺序执行。链中的第一个 loader 将其结果（也就是应用过转换后的资源）传递给下一个 loader，依此类推。最后，链中的最后一个 loader，返回 webpack 所期望的 JavaScript。
- loader 可以是同步的，也可以是异步的。
- loader 运行在 Node.js 中，并且能够执行任何操作。
- loader 可以通过 `options` 对象配置（仍然支持使用 `query` 参数来设置选项，但是这种方式已被废弃）。
- 除了常见的通过 `package.json` 的 `main` 来将一个 npm 模块导出为 loader，还可以在 module.rules 中使用 `loader` 字段直接引用一个模块。
- 插件(plugin)可以为 loader 带来更多特性。
- loader 能够产生额外的任意文件。

...
#### 解析loader
loader 遵循标准 [模块解析](https://www.webpackjs.com/concepts/module-resolution/) 规则。多数情况下，loader 将从 [模块路径](https://www.webpackjs.com/concepts/module-resolution/#module-paths) 加载（通常是从 `npm install`, `node_modules` 进行加载）。
### 插件(plugin)
插件目的在于解决 [loader](https://www.webpackjs.com/concepts/loaders) 无法实现的**其他事**。例如打包优化，资源管理，注入环境变量
想要使用一个插件，你只需要 `require()` 它，然后把它添加到 `plugins` 数组中。多数插件可以通过选项(option)自定义。你也可以在一个配置文件中因为不同目的而多次使用同一个插件，这时需要通过使用 `new` 操作符来创建一个插件实例。
#### 剖析
webpack **插件**是一个具有 [apply](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Function/apply) 方法的 JavaScript 对象。`apply` 方法会被 webpack compiler 调用，并且在 **整个** 编译生命周期都可以访问 compiler 对象。
#### 用法
配置方式:1.webpack.config.js; 2.Node API方式

### 模式(mode)
通过选择 `development`, `production` 或 `none` 之中的一个，来设置 `mode` 参数，你可以启用 webpack 内置在相应环境下的优化。其默认值为 `production`。

### 配置(Configuration)
你可能已经注意到，很少有 webpack 配置看起来完全相同。这是因为 **webpack 的配置文件是 JavaScript 文件，文件内导出了一个 webpack **[**配置的对象**](https://www.webpackjs.com/configuration/)**。** webpack 会根据该配置定义的属性进行处理。
由于 webpack 遵循 CommonJS 模块规范，因此，你**可以在配置中使用**：

- 通过 `require(...)` 引入其他文件
- 通过 `require(...)` 使用 npm 下载的工具函数
- 使用 JavaScript 控制流表达式，例如 `?:` 操作符
- 对 value 使用常量或变量赋值
- 编写并执行函数，生成部分配置
#### 基本配置
#### 多个target
#### 使用其他配置语言

### 模块(Modules)
在[模块化编程](https://en.wikipedia.org/wiki/Modular_programming)中，开发者将程序分解为功能离散的 chunk，并称之为 **模块**。
每个模块都拥有小于完整程序的体积，使得验证、调试及测试变得轻而易举。 精心编写的 **模块** 提供了可靠的抽象和封装界限，使得应用程序中每个模块都具备了条理清晰的设计和明确的目的。

#### 何为webpack模块
与 [Node.js 模块](https://nodejs.org/api/modules.html)相比，webpack 模块能以各种方式表达它们的依赖关系。下面是一些示例：

- [ES2015 import](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/import) 语句
- [CommonJS](http://www.commonjs.org/specs/modules/1.0/)`require()` 语句
- [AMD](https://github.com/amdjs/amdjs-api/blob/master/AMD.md)`define` 和 `require` 语句
- css/sass/less 文件中的 [@import 语句](https://developer.mozilla.org/en-US/docs/Web/CSS/@import)。
- stylesheet `url(...)` 或者 HTML `<img src=...>` 文件中的图片链接。

#### 支持的模块类型
Webpack 天生支持如下模块类型：

- [ECMAScript 模块](https://www.webpackjs.com/guides/ecma-script-modules)
- CommonJS 模块
- AMD 模块
- [Assets](https://www.webpackjs.com/guides/asset-modules)
- WebAssembly 模块

通过 **loader** 可以使 webpack 支持多种语言和预处理器语法编写的模块。**loader** 向 webpack 描述了如何处理非原生 **模块**，并将相关**依赖**引入到你的 **bundles**中。 webpack 社区已经为各种流行的语言和预处理器创建了 _loader_，其中包括：

- [CoffeeScript](http://coffeescript.org)
- [TypeScript](https://www.typescriptlang.org)
- [ESNext (Babel)](https://babeljs.io)
- [Sass](http://sass-lang.com)
- [Less](http://lesscss.org)
- [Stylus](http://stylus-lang.com)
- [Elm](https://elm-lang.org/)

当然还有更多！总得来说，webpack 提供了可定制，强大且丰富的 API，允许在 **任何技术栈** 中使用，同时支持在开发、测试和生产环境的工作流中做到 **无侵入性**。

### 模块解析(Module Resolution)
resolver 是一个帮助寻找模块绝对路径的库。 一个模块可以作为另一个模块的依赖模块，然后被后者引用. 所依赖的模块可以是来自应用程序的代码或第三方库。 resolver 帮助 webpack 从每个 `require`/`import` 语句中，找到需要引入到 bundle 中的模块代码。 当打包模块时，webpack 使用 [enhanced-resolve](https://github.com/webpack/enhanced-resolve) 来解析文件路径。
#### 解析规则
1.绝对路径:由于已经获得文件的绝对路径，因此不需要再做进一步解析。
2.相对路径:在 `import/require` 中给定的相对路径，会拼接此上下文路径，来生成模块的绝对路径。
3.模块路径:在 [resolve.modules](https://www.webpackjs.com/configuration/resolve/#resolvemodules) 中指定的所有目录中检索模块。 你可以通过配置别名的方式来替换初始模块路径，具体请参照 [resolve.alias](https://www.webpackjs.com/configuration/resolve/#resolvealias) 配置选项。
#### 构建目标规则
一旦根据上述规则解析路径后，resolver 将会检查路径是指向文件还是文件夹。如果路径指向文件：

- 如果文件具有扩展名，则直接将文件打包。
- 否则，将使用 [resolve.extensions](https://www.webpackjs.com/configuration/resolve/#resolveextensions) 选项作为文件扩展名来解析，此选项会告诉解析器在解析中能够接受那些扩展名（例如 `.js`，`.jsx`）。

如果路径指向一个文件夹，则进行如下步骤寻找具有正确扩展名的文件：

- 如果文件夹中包含 `package.json` 文件，则会根据 [resolve.mainFields](https://www.webpackjs.com/configuration/resolve/#resolvemainfields) 配置中的字段顺序查找，并根据 `package.json` 中的符合配置要求的第一个字段来确定文件路径。
- 如果不存在 `package.json` 文件或 [resolve.mainFields](https://www.webpackjs.com/configuration/resolve/#resolvemainfields) 没有返回有效路径，则会根据 [resolve.mainFiles](https://www.webpackjs.com/configuration/resolve/#resolvemainfiles) 配置选项中指定的文件名顺序查找，看是否能在 import/require 的目录下匹配到一个存在的文件名。
- 然后使用 [resolve.extensions](https://www.webpackjs.com/configuration/resolve/#resolveextensions) 选项，以类似的方式解析文件扩展名。

Webpack 会根据构建目标，为这些选项提供合理的[默认](https://www.webpackjs.com/configuration/resolve)配置。
#### 解析loader
#### 缓存

### Module Federation
#### 动机
多个独立的构建可以组成一个应用程序，这些独立的构建之间不应该存在依赖关系，因此可以单独开发和部署它们。
这通常被称作微前端，但并不仅限于此。

### 依赖图(dependency graph)
每当一个文件依赖另一个文件时，webpack 都会将文件视为直接存在 _依赖关系_。这使得 webpack 可以获取非代码资源，如 images 或 web 字体等。并会把它们作为 _依赖_ 提供给应用程序。
当 webpack 处理应用程序时，它会根据命令行参数中或配置文件中定义的模块列表开始处理。 从 [入口](https://www.webpackjs.com/concepts/entry-points/) 开始，webpack 会递归的构建一个 _依赖关系图_，这个依赖图包含着应用程序中所需的每个模块，然后将所有模块打包为少量的 _bundle_ —— 通常只有一个 —— 可由浏览器加载。

### target

### 浏览器兼容性
Webpack 支持所有符合 [ES5 标准](https://kangax.github.io/compat-table/es5/) 的浏览器（不支持 IE8 及以下版本）。webpack 的 `import()` 和 `require.ensure()` 需要 `Promise`。

### 环境
Webpack 5 运行于 Node.js v10.13.0+ 的版本。
