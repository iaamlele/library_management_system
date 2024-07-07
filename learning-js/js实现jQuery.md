# 一 概念介绍
## 1.jQuery库的功能
1.HTML元素选取
2.HTML元素操作
3.CSS操作
4.HTML事件函数
5.JavaScript特效和动画
6.HTML DOM遍历和修改
7.AJAX
8.Utilities
## 2.什么是node.js
简单的说 Node.js 就是运行在服务端的 JavaScript。
Node.js 是一个基于 Chrome JavaScript 运行时建立的一个平台。
Node.js 是一个事件驱动 I/O 服务端 JavaScript 环境，基于 Google 的 V8 引擎，V8 引擎执行 Javascript 的速度非常快，性能非常好。


## 3.npm与nodejs的关系，功能
> Node.js和npm是两种密切相关但有不同用途的软件工具。它们在现代JavaScript开发中都扮演着重要角色。下面是对它们的详细解释：
> Node.js:
>     1.什么是Node.js？
>     Node.js是一个开源的、跨平台的JavaScript运行时环境，它允许你在服务器端运行JavaScript代码。由Ryan Dahl于2009年首次发布，它基于Google的V8 JavaScript引擎构建。
>     2.功能和特点：
>     服务器端JavaScript执行环境： 允许开发者使用JavaScript编写服务器端代码。
>     事件驱动和非阻塞I/O： Node.js采用事件驱动和非阻塞I/O模型，使其非常适合处理需要高并发的应用程序，如实时聊天、流媒体服务器等。
>     单线程架构： 虽然Node.js运行在单线程中，但通过事件循环和异步I/O操作来实现高效的并发处理。
>     庞大的包生态系统： 通过npm（Node Package Manager）可以访问成千上万个开源库和工具，极大地扩展了Node.js的功能。
>     3.典型用途：
>     Web服务器
>     API服务器
>     实时应用程序（如聊天应用、在线游戏）
>     命令行工具
> 
> 什么是npm？
>     1.npm（Node Package Manager）是Node.js的包管理工具和包仓库。它也是开源的，并且通常随着Node.js一起安装。
>     2.功能和特点：
>     包管理： 允许开发者轻松地安装、更新和管理Node.js项目所依赖的第三方库和工具。
>     包发布： 开发者可以通过npm发布和分享自己的包。
>     项目脚本管理： 通过package.json文件，开发者可以定义项目的元数据和脚本，用于自动化任务（如构建、测试、部署等）。
>     版本控制： npm帮助管理不同版本的包，确保项目在不同环境中的一致性。
>     3.典型用途：
>     安装和管理Node.js项目依赖
>     发布和分享JavaScript库
>     运行构建和自动化脚本
> 
> 关系
>     依赖关系： Node.js是运行JavaScript代码的环境，而npm是用于管理Node.js项目的包管理器。换句话说，Node.js提供了运行时，npm提供了管理和分享代码的工具。
>     共同安装： 通常情况下，当你安装Node.js时，npm会自动一起安装，因为npm是Node.js生态系统中不可或缺的一部分。


## 4.什么是jsdom：
jsdom是一个流行的JavaScript库，用于在Node.js环境中模拟浏览器的DOM（文档对象模型）。它允许你在没有浏览器的情况下，使用Node.js在服务器端处理和操作HTML文档。
jsdom使用方法
1.
const jsdom = require("jsdom");
const { JSDOM } = jsdom;
> const jsdom = require("jsdom");
>     require("jsdom")：这是Node.js中的一种方法，用于导入一个模块或库。在这里，我们导入的是jsdom库。(js模块化：nodejs中导入模块或者库的两种规范/方法：esm与commonjs，jsdom中使用commonjs)
>     const jsdom：使用const声明一个常量jsdom，它包含了从jsdom模块导入的所有内容。
>     jsdom是一个流行的JavaScript库，用于在Node.js环境中模拟浏览器的DOM（文档对象模型）。它允许你在没有浏览器的情况下，使用Node.js在服务器端处理和操作HTML文档。
> 
> const { JSDOM } = jsdom;
>     这行代码使用解构赋值的语法，从jsdom对象中提取JSDOM类，并将其赋值给常量JSDOM。
>     JSDOM类是jsdom库中的一个主要类，提供了一个接口来创建和操作虚拟的DOM文档。你可以使用JSDOM类创建一个新的DOM实例，模拟浏览器中的HTML文档结构，并在其中执行JavaScript代码。

## 5.DOM概述
### 5.1什么是DOM
文档对象模型（DOM）是web上构成文档结构和内容的对象的数据表示，是一个网络文档的编程接口。它代表页面，以便程序可以改变文档的结构，风格和内容。DOM把文档表示为节点和对象，这样，编程语言就可以与页面交互。
所有可用于操作和创建网页的属性，方法和事件都被组织到对象中。DOM是使用多个API构建的，他们一起工作。核心DOM定义了描述任何文档和其中对象的实体。
DOM不是js语言的一部分，而是用于建立网站的Web API。
js也可以在其他情况下使用。例如，Node.js在计算机上运行js程序，提供了一套不同的API，并且DOM API不是node.js运行时的核心部分

### 5.2DOM的基本数据类型
### 5.3DOM接口
### 5.4DOM核心接口
> document 和 window 对象是你在 DOM 编程中最常使用的接口对象。简单来说，window 对象代表类似浏览器的东西，而 document 对象是文档本身的根。Element 继承自通用的 Node 接口，这两个接口一起提供了许多你在单个元素上使用的方法和属性。这些元素也可以有特定的接口来处理这些元素持有的数据种类，如上一节中的 table 对象的示例。
> 
> 下面是在 web 和 XML 页面脚本中使用 DOM 时，一些常用的 API 简要列表。
>     document.querySelector()
>     document.querySelectorAll()
>     document.createElement()
>     Element.innerHTML
>     Element.setAttribute()
>     Element.getAttribute()
>     EventTarget.addEventListener()
>     HTMLElement.style
>     Node.appendChild()
>     window.onload
>     window.scrollTo()
> 

### 5.6DOM如何在内存中表示HTML文档
## 6.Node与npm
根据不同上下文，Node有多种含义：
1.节点(DOM)：在DOM的上下文中，节点是节点树中的单个点。文档本身，元素，文本以及注释都是节点。
2.节点(网络)：在网络中，节点是网络中的一个连接点。在物理网络中，节点通常是一个设备，如计算机或路由器。
3.Node.js的简称：
Node(正式名：Node.js)是一个开源的，跨平台的运行时环境，使开发者可以搭建服务器端的JS应用程序。此运行时主要用于浏览器上下文之外。该环境省略了一些浏览器专用JS API，同时增加了对更传统的OS API的支持。

npm是一个与Node.js一并下载和捆绑的包管理器。其命令行（CLI）客户端 npm 可用于下载、配置和创建用于 Node.js 项目的包。下载的包可以通过 ES import 和 CommonJS require() 导入，而无需包含它们下载到的依赖目录 node_modules/，因为 Node.js 在导入中未指定相对或绝对路径时会解析包。
## 7.互联网是如何工作的
## 8.万维网是如何工作的
## 9.互联网，因特网，万维网的区别
互联网：泛指由通信设备（如计算机、手机等）组成的网络。
因特网：指由成千上万台设备组成的数据网络，属于互联网中的其中一种。
万维网：由不同的文档、多媒体文件连通而形成的逻辑网络；万维网其中的每个节点都是一个顶级域名，即我们所获取的网站）。
按照范围排序的关系：互联网 > 因特网 > 万维网
## 10.网页，网站，网络服务器和搜索引擎的区别
## 11.运营网站的花费
软件：文本编辑器，图像编辑器，媒体编辑器
浏览器
网络访问：电脑/调制解调器，互联网提供商连接
主机：理解带宽，域名，自己动手托管与"打包"托管，免费托管与付费托管对比
专业网站机构和托管
## 12.什么是web服务
软件+硬件
静态web服务器，动态web服务器
深入探索：托管文件，通过HTTP交流，静态和动态内容

## 13.需要什么软件来构建一个网站
需求：创建和编辑网页;上传文件到你的web服务器;浏览你的网站
## 14.使用Github Pages实时发布网站代码
## 15.异步js
**同步编程-**>很可能遇到一个耗时的同步函数，导致程序阻塞不动

**事件处理程序**->事件处理程序实际上就是异步编程的一种形式：你提供的函数（事件处理程序）将在事件发生时被调用（而不是立即被调用）。

**回调**->事件处理程序是一种特殊类型的回调函数。而回调函数则是一个被传递到另一个函数中的会在适当的时候被调用的函数。正如我们刚刚所看到的：回调函数曾经是 JavaScript 中实现异步函数的主要方式。但是，当回调函数本身需要调用其他同样接受回调函数的函数时，基于回调的代码会变得难以理解，在一些地方这被称为“回调地狱”或“厄运金字塔”。

实上，JavaScript 中异步编程的基础是 Promise
## 16.异步与eventloop，以及eventloop与setTimeout的关系
事件循环是JavaScript处理异步编程的核心机制。它负责协调代码执行、事件和回调函数的调度。

setTimeout是JavaScript中用于调度异步任务的一个函数。它接受两个参数：一个回调函数和一个延迟时间（以毫秒为单位）。在指定的时间后，回调函数会被加入消息队列。

JavaScript通过事件循环模型管理异步操作。setTimeout将任务调度到消息队列中，并在指定时间后执行。事件循环确保在处理异步任务时，主线程能够继续执行其他任务，从而保持应用的响应性。



js异步编程-》什么是Promise
# 二 代码积累
## 1.文档加载时候先运行这段
```
window.onload = () => {

}
```
## 2.<script>在HTML页面中放置的位置
浏览器会按照 <script> 元素在页面中出现的先后顺序，对它们依次进行解析

包含import的文件test.js和包含export的文件jquery.js的在script导入时，在HTML中只需要有<script type="module" src="test.js"></script>，而无需把jquery.js也显式导入。原因：只需要在HTML中引入顶级模块test.js，浏览器会自动解析所有依赖关系。显式导入会导致jquery.js在浏览器中加载两次，一次是通过显式引入，另一次是通过test.js中的import语句。这种情况下，模块可能会被执行两次，导致意想不到的结果。

如何实现边解析页面边下载js：
<script>中增加属性**async**：表示**异步解析脚本**，即表示当前脚本不必等待其他脚本，也不必阻挡文档呈现。（区别于 defer，异步脚本不能按照在页面中的出现的顺序执行）
<script>中增加属性**defer** ：表示**延迟解析脚本**，即让脚本在文档完全呈现后再执行。（延迟脚本总是按照指定它们的顺序执行）

放置位置分析：
1.不能放在<head>内部
报错：TypeError: document.getElementById(...) is null 
原因：阻塞。必须等到全部的javascript代码都被下载、解析和执行完成以后，才能开始呈现页面内容，网页内容呈现滞后，用户体验差。
2.放在<body>尾部
浏览器会先解析完整个HTML页面，再下载js，这样的话，如果js执行出错了，最起码页面中的元素还可以加载出来，因为DOM文档是从上往下的顺序执行的。 但是对于一些高度依赖于js的网页，这样就会显得很慢。
3.不能放在<body>之后
语法错误
## 3.commonjs适用于nodejs，es适用于浏览器
1.使用es时，export与import都要位于模块顶部
2.type="module"：<script type="module" src="jquery.js"></script>
原因：可以使用import和export关键字在模块之间共享代码。
## 4.js中批量导出函数的方法
1.命名导出
```
export function click_hide_addListener() {
    // Function implementation
}
```
2.批量导出与导入：
```
导出：export { click_hide_addListener, anotherFunction };

导入：import { click_hide_addListener, anotherFunction } from "./jquery.js";
```
3.创建一个包含所有函数的对象并默认导出改对象
```
// jquery.js
function click_hide_addListener() {
    // Function implementation
}

function anotherFunction() {
    // Another function implementation
}

// 其他函数的实现

const exportedFunctions = {
    click_hide_addListener,
    anotherFunction,
    // 其他函数
};

export default exportedFunctions;

```

## 5.当代码全部调试完毕，会跳转到211.js这个文件继续
而不会调试结束，原因：
1. 异步代码
如果代码中有异步操作（如setTimeout、setInterval、Promise、async/await、AJAX请求等），这些操作会在主线程的代码执行完毕后继续运行。
2. 事件监听器
如果代码中注册了事件监听器（如click、mousemove等），这些监听器会在事件触发时执行。
3. 外部库
有些外部库会在后台执行一些代码，尤其是大型框架或库，如React、Vue、jQuery等。这些库可能会设置监听器或进行周期性检查。
# 三 遇到的问题
## 1.DOM只有在浏览器中才能使用
在vscode中不能通过这种方式获取html元素：let x = document.getElementById("first");会出现报错：ReferenceError: document is not defined
原因：js脚本的运行环境只有浏览器环境和Node.js两种，document.属于DOM应用，对于DOM和BOM的操作只能在浏览器环境下才能进行;在vscode中使用Nodejs环境，因此报错不能使用
解决办法：

## 2.判断是否需要event参数
事件监听器的回调函数可以接受一个事件对象作为参数，这个事件对象包含了关于事件的各种信息。在 addEventListener 方法中，这个事件对象通常被命名为 event 或 e，但如果回调函数不需要使用这个事件对象，可以省略它。
如果你不需要访问事件对象中的任何信息（如事件的目标元素、事件类型等），可以省略 event 参数。这是完全有效的写法，只要你不需要使用事件对象中的信息。
```
window.addEventListener("load", (event) => {
  log.textContent += "load\n";
});
```
## 3.事件监听器的正确使用-函数调用&函数定义
以下写法导致输出为：
hidden

第二个hidden输出不出来，因为：
element1.addEventListener("click", click_hide(elem2));实际上是在定义事件监听器时立即调用了 click_hide 函数，并将它的返回值（通常是 undefined）作为事件处理器。
为了在点击事件发生时才执行 click_hide 函数，需要将 click_hide 函数调用包装在一个匿名函数中。这样可以确保 click_hide 只在点击事件触发时被调用。
```
function click_hide_addListener(elem1, elem2) {
    const element1 = document.querySelector(elem1);
    element1.addEventListener("click", click_hide(elem2));
}
```
```
dom.window.onload = () => {
    const document = dom.window.document;
    simulate_jquery.click_hide_addListener("#button1", "#first-id");
    
    const button = document.getElementById("button1");
    button.click();

    console.log(document.getElementById("first-id").style.visibility); //不知道为什么这里显示不出来
};
```
改进后：
核心知识补充：
> 在 JavaScript 中，函数调用和函数定义的语义是不同的。理解这一点对于明白为什么使用匿名函数可以确保 click_hide 只在点击事件发生时被调用是至关重要的。
> 函数调用 vs. 函数定义
>     函数调用：
>         当你写 click_hide(elem2) 时，这是一种函数调用。JavaScript 立即执行这个函数，并返回其结果。
> 
>     函数定义：
>         当你写 function() { click_hide(elem2); } 时，这是一种匿名函数的定义。这段代码定义了一个函数，但并没有立即执行它。
> 
> 事件监听器的正确使用
> 当你使用 addEventListener 时，你需要传递一个函数引用，这个函数将在事件发生时被调用。

## 4.document多处定义导致事件监听器无法正确添加
query.js与test.js中同时都包含以下代码。错误原因：模块加载时的 document 与 dom.window.document 之间的引用在不同的作用域内被使用，导致事件监听器无法正确添加。
```
const jsdom = require("jsdom");
const {JSDOM} = jsdom;
const simulate_jquery = require("./jquery.js");
const fs = require("fs");

const html = fs.readFileSync("index.html", "utf-8");
// resources: 'usable'代表js脚本在外部  
// runScripts:'dangerously'不添加会导致选项控制不起作用
const dom = new JSDOM(html, {resources: "usable", runScripts: "dangerously"});
```
