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



## js异步编程->什么是Promise

## js对象
## js类

## js构造函数与普通函数区别
this


## js HTML DOM
DOM HTML
DOM CSS
DOM 事件
DOM EventListener
DOM 元素
HTML Collection对象
NodeList对象
## js正则表达式->创建，正则表达式，匹配

## js作用域

## 函数副作用
就是运行完对外部影响了
详细解释：函数副作用（side effect）是指函数在执行过程中除了返回值之外，还对外部状态产生了影响。换句话说，函数在执行时除了计算和返回一个结果外，还对函数外部的变量、数据结构、文件、数据库、外部服务等进行了修改。
副作用的存在会导致函数不再是纯函数。纯函数是指对于相同的输入永远会有相同的输出，并且没有任何副作用。

为什么要关注副作用
    可测试性：有副作用的函数难以进行单元测试，因为你需要模拟和检查外部状态的变化。
    可预测性：纯函数总是给定相同的输入返回相同的输出，没有副作用，因此更易预测和理解。
    可复用性：纯函数因为不依赖外部状态，因此更容易在不同的上下文中复用。
代码改进建议
    1.避免修改全局对象:
        使用局部变量存储选择器匹配结果。
        避免在函数中直接修改外部对象的状态。
    2.减少对 DOM 的直接操作:
        使用函数返回新的状态，而不是直接修改 DOM。
    3.保持函数纯净:
        确保函数仅依赖其输入参数并返回结果，而不修改外部状态。

## window.onload和$(document).ready()的区别
$(document).ready()：
**触发时间: **当 DOM 树已构建完毕，但外部资源（如图像、样式表等）可能尚未加载完成。
window.onload：
**触发时间: **当页面上的所有资源（包括 DOM、图像、样式表等）都已完全加载。

每个事件的顺序将总结如下：
1.HTML Parsing: 浏览器开始解析 HTML 文件，并逐渐构建 DOM 树。
2.$(document).ready(): 当 DOM 树已构建完毕时触发。这意味着页面的 HTML 已经完全加载并被解析，但图像和其他资源可能尚未加载。
3.Images and Other Resources Loading: 浏览器继续加载页面中的其他资源（如图像、样式表等）。
4.window.onload: 当页面上的所有资源（包括图像、样式表等）都已完全加载后触发。

$(window).load 最后执行。如果页面加载大量内容，则可能需要一些时间来处理页面。
因此，我认为考虑用户友好性时，使用 $(document).ready() 更好。

## 立即调用函数表达式
定义自执行匿名函数是在定义后立即执行的 [JavaScript](https://developer.mozilla.org/zh-CN/docs/Glossary/JavaScript)[函数](https://developer.mozilla.org/zh-CN/docs/Glossary/Function)，也被称作[立即调用函数表达式](https://developer.mozilla.org/zh-CN/docs/Glossary/IIFE)（IIFE）。
```
()();
举例：
1.(function() {
})();
2.(()=> {
})();
```
## document.addEventListener('DOMContentLoaded', f, false);
参数1：事件类型
参数2：指定当事件触发时要执行的函数。
参数3：选项（useCapture 或 options）
    类型：boolean 或 object
    作用：指定事件是否在捕获阶段执行（如果为 boolean），或是包含多个选项的对象（如果为 object）。
    说明：
        如果是 boolean 类型，值为 true 时表示事件在捕获阶段执行，false 表示事件在冒泡阶段执行。
        如果是 object 类型，可以包含以下选项：
            capture：布尔值，表示事件处理程序是否在捕获阶段执行（与 boolean 类型的作用相同）。
            once：布尔值，表示事件处理程序在第一次调用后是否自动移除。
            passive：布尔值，表示事件处理程序永远不会调用 preventDefault()。

**默认情况下，第三个参数为 false，即事件处理程序在冒泡阶段执行**。

**事件传播的3个阶段：**
1.**捕获阶段（Capture Phase）：**
    事件从 window 对象开始，向下传播到目标元素。这一阶段也称为“事件捕获阶段”。
    在这个阶段，如果事件处理程序被添加到某个父元素，并且 useCapture 参数为 true，事件处理程序会在捕获阶段执行。

2.**目标阶段（Target Phase）：**
    事件在目标元素上触发。
    在目标阶段，事件处理程序会在目标元素上被触发，不论是通过捕获阶段还是冒泡阶段添加的事件处理程序。

3.**冒泡阶段（Bubbling Phase）：**
    事件从目标元素开始，向上冒泡到其祖先元素，直到到达 window 对象。这一阶段也称为“事件冒泡阶段”。
    在这个阶段，如果事件处理程序被添加到某个元素，并且 useCapture 参数为 false（默认值），事件处理程序会在冒泡阶段执行。

## 调用函数创建新的对象
> 每次调用函数都会创建新的对象，主要是由于 JavaScript 中函数的作用域和对象的创建机制。以下是详细解释：
> 1. 函数作用域和变量
> 每次调用函数时，都会创建一个新的作用域（scope），在这个作用域内声明的变量和定义的函数都是这个作用域的局部变量。这意味着这些变量和函数在函数执行结束后会被销毁，除非被返回或者被其他引用保存。
> 2. 内部函数的作用域链
> 内部函数在定义时，会捕获其所在作用域的变量和函数。这使得这些内部函数在函数执行结束后，即使在外部调用，它们依然可以访问这些局部变量和函数。
> 3. 返回新的对象
> 当一个函数返回一个对象时，这个对象包含的所有方法和属性都是该函数执行时创建的。每次调用函数时，返回的对象都是一个全新的实例，因为函数的每次执行都会创建一个新的作用域和新的变量。

### 如何使得共享对象方法，而不是每次调用函数都创建一个对象呢？
这种方法不正确，不能达到目的，因为只要每次$()就会创建一个新的对象，每个新的对象的方法就相互独立。思路：将方法放在共享的原型对象中
```
$.prototype.hide = $().hide;
$.prototype.show = $().show;
$.prototype.ready = $().ready;
```
## FP(Functional Programming)
## FP语言
FP（缩写的Functional Programming），是John Backus创立的支持函数级编程范型的编程语言[2]。它允许消去命名变量。 
在John Backus的一篇图灵奖论文中，描述了FP风格与基于lambda演算的语言有着如何不同：
    FP系统基于了对叫做泛函形式（functional form）的一组固定的组合形式的利用。它们加上简单的定义，就是从现存函数建造新函数的唯一方式；它们不使用变量或替代（substitution）规则，并且它们成为程序相关的代数的运算操作（operation）。FP系统的所有函数都是一种类型的：它们映射对象到对象之上并总是接受一个单一实际参数（argument）。[2]

具体。。。看不懂啊啊啊。。
### 函数式编程/泛函编程
1.主要思想：把计算过程尽量分解成一系列可复用函数的调用
2.主要特征：函数是“第一等公民”：
    函数与其他数据类型一样的地位，可以赋值给其他变量，也可以作为函数参数、函数返回值 
是一种编程范型。简介：函数[头等对象](https://zh.wikipedia.org/wiki/%E5%A4%B4%E7%AD%89%E5%AF%B9%E8%B1%A1)即[头等函数](https://zh.wikipedia.org/wiki/%E5%A4%B4%E7%AD%89%E5%87%BD%E6%95%B0)，这意味着一个函数，既可以作为其它函数的输入参数值，也可以从函数中返回值，被修改或者被分配给一个变量。[λ演算](https://zh.wikipedia.org/wiki/%CE%9B%E6%BC%94%E7%AE%97)是这种范型最重要的基础，λ演算的函数可以接受函数作为输入参数和输出返回值。
### 图灵的基本思想
图灵认为满足以下四个部分组成的一台机器就能模拟人类所能进行的任何计算过程：
### ![1.png](https://cdn.nlark.com/yuque/0/2024/png/26307378/1721115514337-552fa7e6-8107-4b72-9731-775440d24091.png#averageHue=%23f5f5f1&clientId=u7fb7d905-061e-4&from=ui&id=u790e8b80&originHeight=775&originWidth=902&originalType=binary&ratio=1&rotation=0&showTitle=false&size=764826&status=done&style=none&taskId=uf87aa7ff-87b4-48b8-b78d-32157aa6bde&title=)图灵完备性
在[可计算性理论](https://zh.wikipedia.org/wiki/%E5%8F%AF%E8%AE%A1%E7%AE%97%E6%80%A7%E7%90%86%E8%AE%BA)，如果一系列操作数据的规则（如[指令集](https://zh.wikipedia.org/wiki/%E6%8C%87%E4%BB%A4%E9%9B%86)、[编程语言](https://zh.wikipedia.org/wiki/%E7%BC%96%E7%A8%8B%E8%AF%AD%E8%A8%80)、[细胞自动机](https://zh.wikipedia.org/wiki/%E7%BB%86%E8%83%9E%E8%87%AA%E5%8A%A8%E6%9C%BA)）可以用来模拟任何[图灵机](https://zh.wikipedia.org/wiki/%E5%9B%BE%E7%81%B5%E6%9C%BA)，那么它便符合**图灵完备**（**Turing-complete**或**computationally universal**）。这意味着这个系统也可以识别其他数据处理规则集，图灵完备性被用作表达这种数据处理规则集的一种属性。如今，几乎所有编程语言都是具有图灵完备性的。这个词以引入图灵机概念的数学家[艾伦·图灵](https://zh.wikipedia.org/wiki/%E8%89%BE%E4%BC%A6%C2%B7%E5%9B%BE%E7%81%B5)命名。
### λ演算
是一套从数学逻辑中发展，以变量绑定和替换的规则，来研究[函数](https://zh.wikipedia.org/wiki/%E5%87%BD%E6%95%B0)如何抽象化定义、函数如何被应用以及[递归](https://zh.wikipedia.org/wiki/%E9%80%92%E5%BD%92)的[形式系统](https://zh.wikipedia.org/wiki/%E5%BD%A2%E5%BC%8F%E7%B3%BB%E7%B5%B1)。它由数学家[阿隆佐·邱奇](https://zh.wikipedia.org/wiki/%E9%98%BF%E9%9A%86%E4%BD%90%C2%B7%E9%82%B1%E5%A5%87)在20世纪30年代首次发表。lambda演算作为一种广泛用途的计算模型，可以清晰地定义什么是一个可计算函数，而任何可计算函数都能以这种形式表达和求值，它能模拟单一磁带[图灵机](https://zh.wikipedia.org/wiki/%E5%9B%BE%E7%81%B5%E6%9C%BA)的计算过程。
lambda演算可比拟是最根本的编程语言，它包括了一条变换规则（变量替换）和一条将函数抽象化定义的方式。

## Shell
### Shell是什么
Shell 是一个用 C 语言编写的程序，它是用户使用 Linux 的桥梁。Shell 既是一种命令语言，又是一种程序设计语言。
Shell 是指一种应用程序，这个应用程序提供了一个界面，用户通过这个界面访问操作系统内核的服务。
Shell脚本
Shell 脚本（shell script），是一种为 shell 编写的脚本程序。 
业界所说的 shell 通常都是指 shell 脚本，shell 和 shell script 是两个不同的概念。
由于习惯的原因，简洁起见，本文出现的 "shell编程" 都是指 shell 脚本编程，不是指开发 shell 自身。
#### Shell环境
Shell 编程跟 JavaScript、php 编程一样，只要有一个能编写代码的文本编辑器和一个能解释执行的脚本解释器就可以了。
Linux 的 Shell 种类众多，常见的有：

- Bourne Shell（/usr/bin/sh或/bin/sh）
-  Bourne Again Shell（/bin/bash）
- C Shell（/usr/bin/csh）
- K Shell（/usr/bin/ksh）
- Shell for Root（/sbin/sh）
- …… 

本教程关注的是 **Bash**，也就是 Bourne Again Shell，由于易用和免费，Bash 在日常工作中被广泛使用。同时，Bash 也是大多数Linux 系统默认的 Shell。
在一般情况下，人们并不区分 Bourne Shell 和 Bourne Again Shell，所以，像 **#!/bin/sh**，它同样也可以改为 **#!/bin/bash**。
**#! 告诉系统其后路径所指定的程序即是解释此脚本文件的 Shell 程序。**
#### 第一个Shell脚本
在test.sh中：echo "hello haogege"
(echo：向窗口输出文本)
运行：
1.作为可执行程序：chmod -x ./test.sh
2.作为解释器参数：/bin/sh test.sh
### Shell变量
在Shell编程中，变量是用于存储数据值的名称
#### 变量名
定义变量名的规则：
1.变量名不加美元符号$
2.变量名和等号之间不能有空格
3.只包含字母、数字和下划线： 变量名可以包含字母（大小写敏感）、数字和下划线 _，不能包含其他特殊字符。
4.不能以数字开头： 变量名不能以数字开头，但可以包含数字。
5.避免使用 Shell 关键字： 不要使用Shell的关键字（例如 if、then、else、fi、for、while 等）作为变量名，以免引起混淆。
6.使用大写字母表示常量： 习惯上，常量的变量名通常使用大写字母，例如 PI=3.14。
7.避免使用特殊符号： 尽量避免在变量名中使用特殊符号，因为它们可能与 Shell 的语法产生冲突。
8.避免使用空格： 变量名中不应该包含空格，因为空格通常用于分隔命令和参数。
eg:
1.显示赋值：LD_12="/bin/"
2.用语句给变量赋值：
```
for file in $(ls/etc)
do
echo $file
done
```
#### 使用变量
在变量名前面加美元符号即可
变量名外面的花括号是可选的，加不加都行，加花括号是为了帮助解释器识别变量的边界。写花括号是好习惯。
```
your_name="haohao"
echo $your_name
echo ${your_name}
```
变量可重新赋值
#### 只读变量
使用 readonly 命令可以将变量定义为只读变量，只读变量的值不能被改变。
尝试更改只读变量，结果报错：
```
myUrl="http://.."
readonly myUrl
myUrl="www"
```
#### 删除变量
变量被删除后不能再次使用。unset 命令不能删除只读变量。
```
myUrl="http://.."
unset myUrl
echo $myUrl
```
以上实例执行将没有任何输出。
### 变量类型
#### 字符串变量
可以使用单引号 ' 或双引号 " 来定义字符串
#### 整数变量
declare -i my_integer=42
declare用于声明和设置变量的属性
-i将变量声明为整数类型
#### 数组变量
1.整数索引数组：my_array=(1 2 3 4 5)
2.关联数组：declare命令以及关联数组-A是bash的扩展，不是sh，所以要使用bash解释器而不是sh解释器
```
#!/bin/bash
declare -A as_array
as_array["name"]="haohao"
as_array["age"]=23
echo ${as_array["name"]}
```
bash和sh的区别总结
> - **功能与扩展**：Bash 支持更多的功能和扩展，比如数组、命令补全、命令历史等，而 Sh 主要提供基本的命令解释和脚本编写功能。
> - **兼容性**：Sh 通常是指 POSIX 标准 Shell，确保脚本在不同 Unix 系统上的可移植性。Bash 兼容 Bourne Shell 但提供了更多的特性，因此脚本在 Bash 中运行良好但可能不在 Sh 中兼容。
> - **现代化**：Bash 是现代 Shell，具有更多的高级功能和用户友好的特性，而 Sh 更注重简洁和基本功能。

#### 环境变量
echo $PATH
#### 特殊变量
有一些特殊变量在 Shell 中具有特殊含义，例如 $0 表示脚本的名称，$1, $2, 等表示脚本的参数。$#表示传递给脚本的参数数量，$? 表示上一个命令的退出状态等。
### Shell字符串
可用单引号或双引号
单引号的限制：
    1.单引号里的任何字符都会原样输出，单引号字符串中的变量是无效的；
    2.单引号字符串中不能出现单独一个的单引号（对单引号使用转义符后也不行），但可成对出现，作为字符串拼接使用。
双引号的优点：
    1.双引号里可以有变量
    2.双引号里可以出现转义字符
```
#!/bin/bash
your_name="haohao"
str="Hello, I love you \"${your_name}\"!\n"
echo -e $str
```
#### 拼接字符串
使用双引号拼接
```
#!/bin/bash
your_name="haohao"
str1="Hello, I love you \"${your_name}\"!"
str2="Yes, I love you ${your_name}!"
echo $str1 $str2

输出：Hello, I love you "haohao"! Yes, I love you haohao!
```
#### 获取字符串长度
```
#!/bin/bash
your_name="haohao"
echo ${#your_name}
```
#### 提取子字符串
```
#!/bin/bash
your_name="haohao"
echo ${your_name:1:3}
```
#### 查找子字符串
查找字符 **y**或 **o** 或u这三个字母的位置(哪个字母先出现就计算哪个)
```
#!/bin/bash
your_name="haohao, I love you"
echo `expr index "$your_name" you`
```
语法解释：
1.``命令替换：这行代码使用了反引号（`）进行命令替换。命令替换的作用是先执行反引号中的命令，然后将命令的输出结果替换到原位置。也可以使用 $() 语法来进行命令替换。
2.
3.
### Shell数组
定义数组
读取数组
获取数组长度
### Shell注释
多行注释
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

## 6.动画制作
Window：requestAnimationFrame() 方法

cdn(jquery cdn)  分布式的，访问第三方库减少服务器负荷，内网环境用不了
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
