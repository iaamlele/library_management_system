# 一 概念介绍
## 1.jQuery库的功能-操作DOM
1.HTML元素选取;
2.HTML元素操作
3.CSS操作
4.HTML事件函数
5.JavaScript特效和动画
6.HTML DOM遍历和修改
7.AJAX
8.Utilities
## 环境基础知识
### 什么是node.js
简单的说 Node.js 就是运行在服务端的 JavaScript。
Node.js 是一个基于 Chrome JavaScript 运行时建立的一个平台。
Node.js 是一个事件驱动 I/O 服务端 JavaScript 环境，基于 Google 的 V8 引擎，V8 引擎执行 Javascript 的速度非常快，性能非常好。
#### Node的多重含义
根据不同上下文，Node有多种含义：
1.节点(DOM)：在DOM的上下文中，节点是节点树中的单个点。文档本身，元素，文本以及注释都是节点。
2.节点(网络)：在网络中，节点是网络中的一个连接点。在物理网络中，节点通常是一个设备，如计算机或路由器。
3.Node.js的简称：
Node(正式名：Node.js)是一个开源的，跨平台的运行时环境，使开发者可以搭建服务器端的JS应用程序。此运行时主要用于浏览器上下文之外。该环境省略了一些浏览器专用JS API，同时增加了对更传统的OS API的支持。
### npm与nodejs的关系，功能
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


### 什么是jsdom
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
## Web机制
### 互联网是如何工作的
#### 互联网的历史
简短:它始于 1960 年美国军方资助的研究项目。1980 年在许多公共大学和公司的支持下，它演变为一种公共基础设施。
维基百科:1960年，[美国国防部](https://zh.wikipedia.org/wiki/%E7%BE%8E%E5%9B%BD%E5%9B%BD%E9%98%B2%E9%83%A8)[高等研究计划署](https://zh.wikipedia.org/wiki/%E5%9B%BD%E9%98%B2%E9%AB%98%E7%AD%89%E7%A0%94%E7%A9%B6%E8%AE%A1%E5%88%92%E7%BD%B2)（DARPA）出于[冷战](https://zh.wikipedia.org/wiki/%E5%86%B7%E6%88%98)考虑建立的[ARPANET](https://zh.wikipedia.org/wiki/ARPANET)引发技术进步并使其成为互联网发展的中心。ARPANET的发展始于两个网络节点，由[伦纳德·克莱因罗克](https://zh.wikipedia.org/wiki/%E4%BC%A6%E7%BA%B3%E5%BE%B7%C2%B7%E5%85%8B%E8%8E%B1%E5%9B%A0%E7%BD%97%E5%85%8B)带领的[加利福尼亚大学洛杉矶分校](https://zh.wikipedia.org/wiki/%E5%8A%A0%E5%88%A9%E7%A6%8F%E5%B0%BC%E4%BA%9E%E5%A4%A7%E5%AD%B8%E6%B4%9B%E6%9D%89%E7%A3%AF%E5%88%86%E6%A0%A1)的网络测量中心与[加利福尼亚州门罗帕克](https://zh.wikipedia.org/wiki/%E9%97%A8%E6%B4%9B%E5%B8%95%E5%85%8B_(%E5%8A%A0%E5%88%A9%E7%A6%8F%E5%B0%BC%E4%BA%9A%E5%B7%9E))[斯坦福国际研究院](https://zh.wikipedia.org/w/index.php?title=%E6%96%AF%E5%9D%A6%E7%A6%8F%E5%9C%8B%E9%9A%9B%E7%A0%94%E7%A9%B6%E9%99%A2&action=edit&redlink=1)（SRI）[道格拉斯·恩格尔巴特](https://zh.wikipedia.org/wiki/%E9%81%93%E6%A0%BC%E6%8B%89%E6%96%AF%C2%B7%E6%81%A9%E6%A0%BC%E5%B0%94%E5%B7%B4%E7%89%B9)的NLS系统两个节点之间连接。第三个节点是[加利福尼亚大学圣塔芭芭拉分校](https://zh.wikipedia.org/wiki/%E5%8A%A0%E5%88%A9%E7%A6%8F%E5%B0%BC%E4%BA%9E%E5%A4%A7%E5%AD%B8%E8%81%96%E5%A1%94%E8%8A%AD%E8%8A%AD%E6%8B%89%E5%88%86%E6%A0%A1)，第四个节点是[犹他大学](https://zh.wikipedia.org/wiki/%E7%8A%B9%E4%BB%96%E5%A4%A7%E5%AD%A6)。到1971年底，已经有15个节点连接到ARPANET[[4]](https://zh.wikipedia.org/wiki/%E4%BA%92%E8%81%94%E7%BD%91#cite_note-4)[[5]](https://zh.wikipedia.org/wiki/%E4%BA%92%E8%81%94%E7%BD%91#cite_note-5)。
1974年，[罗伯特·卡恩](https://zh.wikipedia.org/wiki/%E7%BD%97%E4%BC%AF%E7%89%B9%C2%B7%E5%8D%A1%E6%81%A9)和[文顿·瑟夫](https://zh.wikipedia.org/wiki/%E6%96%87%E9%A0%93%C2%B7%E7%91%9F%E5%A4%AB)提出[TCP/IP](https://zh.wikipedia.org/wiki/TCP/IP)，定义在电脑网络之间传送报文的方法（他们在2004年也因此获得[图灵奖](https://zh.wikipedia.org/wiki/%E5%9B%BE%E7%81%B5%E5%A5%96)[[9]](https://zh.wikipedia.org/wiki/%E4%BA%92%E8%81%94%E7%BD%91#cite_note-9)[[10]](https://zh.wikipedia.org/wiki/%E4%BA%92%E8%81%94%E7%BD%91#cite_note-10)）。1986年，[美国国家科学基金会](https://zh.wikipedia.org/wiki/%E7%BE%8E%E5%9B%BD%E5%9B%BD%E5%AE%B6%E7%A7%91%E5%AD%A6%E5%9F%BA%E9%87%91%E4%BC%9A)建立了[美国国家超级计算机应用中心](https://zh.wikipedia.org/wiki/%E5%9B%BD%E5%AE%B6%E8%B6%85%E7%BA%A7%E7%94%B5%E8%84%91%E5%BA%94%E7%94%A8%E4%B8%AD%E5%BF%83)与学术机构之间互联基于TCP/IP技术的骨干网络[NSFNET](https://zh.wikipedia.org/w/index.php?title=NSFNET&action=edit&redlink=1)，速度由最初的56kbit/s，接着为T1（1.5Mbit/s），最后发展至T3（45Mbit/s）[[11]](https://zh.wikipedia.org/wiki/%E4%BA%92%E8%81%94%E7%BD%91#cite_note-11)。NSFNET于1988至1989年扩展到欧洲、澳大利亚、新西兰和日本的学术和研究组织[[12]](https://zh.wikipedia.org/wiki/%E4%BA%92%E8%81%94%E7%BD%91#cite_note-12)[[13]](https://zh.wikipedia.org/wiki/%E4%BA%92%E8%81%94%E7%BD%91#cite_note-13)[[14]](https://zh.wikipedia.org/wiki/%E4%BA%92%E8%81%94%E7%BD%91#cite_note-14)[[15]](https://zh.wikipedia.org/wiki/%E4%BA%92%E8%81%94%E7%BD%91#cite_note-15)。商业[互联网服务提供商](https://zh.wikipedia.org/wiki/%E4%BA%92%E8%81%AF%E7%B6%B2%E6%9C%8D%E5%8B%99%E6%8F%90%E4%BE%9B%E5%95%86)（ISP）于1989年在美国和澳大利亚成立[[16]](https://zh.wikipedia.org/wiki/%E4%BA%92%E8%81%94%E7%BD%91#cite_note-16)。ARPANET于1990年退役[[17]](https://zh.wikipedia.org/wiki/%E4%BA%92%E8%81%94%E7%BD%91#cite_note-17)。
1989年中期，MCI Mail和[CompuServe](https://zh.wikipedia.org/wiki/CompuServe)与互联网建立连接，并且向50万大众提供电子邮件服务[[18]](https://zh.wikipedia.org/wiki/%E4%BA%92%E8%81%94%E7%BD%91#cite_note-18)。
#### 互联网工作方式
##### 一个简单的网络
互联网确保所有的电脑之间的连接，无论发生什么他们依旧保持连接。
电脑连接方式:有线(网线),无线(WIFI,蓝牙)
1.网线太多->路由器
2.距离太远->将路由器彼此连接     
3.建立自己的网络->与已有的电缆连接起来(电话,电线)->调制解调器(可以把网络信息变成电话设施可以处理的信息)

调制解调器:是一种用于数据通信的设备，主要作用是将数字信号转换为模拟信号（调制），以及将模拟信号转换为数字信号（解调），以便在计算机与其他设备之间传输数据。主要用于互联网连接、远程通信和数据传输，如家庭宽带上网、企业专线、卫星通信等。

4.把信息发送到目的地->把我们的网络连接到互联网服务提供商(ISP,ISP 是一家可以管理一些特殊的路由器的公司，这些路由器连接其他 ISP 的_路由器_)->你的网络消息可以被 ISP 捕获并发送到相应的网络
![1.png](https://cdn.nlark.com/yuque/0/2024/png/26307378/1721530828991-f886297c-de9d-47c5-89ff-391e0d9b9479.png#averageHue=%23e8e8e8&clientId=u323c3b5b-a9e0-4&from=ui&id=u28d101f1&originHeight=1293&originWidth=340&originalType=binary&ratio=1&rotation=0&showTitle=false&size=22273&status=done&style=none&taskId=u919be810-724f-4525-a039-be61416de63&title=)
##### 寻找电脑
IP地址与DNS域名

##### 服务
互联网承载着众多应用程序和服务，包括[万维网](https://zh.wikipedia.org/wiki/%E5%85%A8%E7%90%83%E8%B3%87%E8%A8%8A%E7%B6%B2)、[社交媒体](https://zh.wikipedia.org/wiki/%E7%A4%BE%E7%BE%A4%E5%AA%92%E9%AB%94)、[电子邮件](https://zh.wikipedia.org/wiki/%E9%9B%BB%E5%AD%90%E9%83%B5%E4%BB%B6)、[移动应用程序](https://zh.wikipedia.org/wiki/%E8%A1%8C%E5%8B%95%E6%87%89%E7%94%A8%E7%A8%8B%E5%BC%8F)、[多人电子游戏](https://zh.wikipedia.org/wiki/%E5%A4%9A%E4%BA%BA%E7%94%B5%E5%AD%90%E6%B8%B8%E6%88%8F)、[互联网通话](https://zh.wikipedia.org/wiki/VoIP)、[文件分享](https://zh.wikipedia.org/wiki/%E6%AA%94%E6%A1%88%E5%88%86%E4%BA%AB)和[流媒体](https://zh.wikipedia.org/wiki/%E4%B8%B2%E6%B5%81%E5%AA%92%E9%AB%94)服务等。提供这些服务的大多数[服务器](https://zh.wikipedia.org/wiki/%E4%BC%BA%E6%9C%8D%E5%99%A8)托管于[数据中心](https://zh.wikipedia.org/wiki/%E8%B3%87%E6%96%99%E4%B8%AD%E5%BF%83)，并且通过高性能的[内容分发网络](https://zh.wikipedia.org/wiki/%E5%85%A7%E5%AE%B9%E5%82%B3%E9%81%9E%E7%B6%B2%E8%B7%AF)访问。

互联网和Web:
_互联网_是基础设施，_Web_ 是建立在这种基础设施之上的服务。值得注意的是，一些其他服务也同样运行在互联网之上，比如邮箱和 [IRC](https://developer.mozilla.org/zh-CN/docs/Glossary/IRC)。
互联网是一种基础的技术，它允许我们把成千上万的电脑连接在一起。在这些电脑中，有一些电脑（我们称之为 _Web 服务器_）可以发送一些浏览器可以理解的信息。

##### 内联网和外联网
内联网（Intranet）是仅限于特定组织成员使用的_专用_网络。它们通常用于为成员提供一个门户，以便安全地访问共享资源、进行协作和交流。例如，一个组织的_内联网_可能包含用于共享部门或团队信息的网页、用于管理关键文档和文件的共享驱动器、用于执行业务管理任务的门户网站，以及维基、讨论板和消息系统等协作工具。
外联网（Extranet）与内联网非常相似，只是它们开放了全部或部分专用网络，允许与其他组织共享和协作。外联网通常用于安全可靠地与客户和与企业密切合作的利益相关者共享信息。其功能通常与内联网类似：信息和文件共享、协作工具、讨论板等。
内联网和外联网都在与互联网相同的基础设施上运行，并使用相同的协议。因此，经授权的成员可以从不同的物理位置访问它们。
![image.png](https://cdn.nlark.com/yuque/0/2024/png/26307378/1721531317026-53a686e0-3be0-4e45-9d36-feda1e844696.png#averageHue=%23f3f3f3&clientId=u323c3b5b-a9e0-4&from=paste&height=507&id=uf0f91cfa&originHeight=507&originWidth=388&originalType=binary&ratio=1&rotation=0&showTitle=false&size=30675&status=done&style=none&taskId=u3edd1cf8-18b9-46b0-8e83-7c3ba42b756&title=&width=388)
#### 互联网协议套件
（英语：Internet Protocol Suite，缩写IPS）[[1]](https://zh.wikipedia.org/wiki/TCP/IP%E5%8D%8F%E8%AE%AE%E6%97%8F#cite_note-1)，是一种网络通信模型，以及用于[网络传输的协议](https://zh.wikipedia.org/wiki/%E7%BD%91%E7%BB%9C%E4%BC%A0%E8%BE%93%E5%8D%8F%E8%AE%AE)集合，为[网际网络](https://zh.wikipedia.org/wiki/%E7%BD%91%E9%99%85%E7%BD%91%E7%BB%9C)的基础通信架构，被应用于各种网络通信中。它常通称为**TCP/IP协议族**（英语：TCP/IP Protocol Suite，或TCP/IP Protocols），简称**TCP/IP**[[2]](https://zh.wikipedia.org/wiki/TCP/IP%E5%8D%8F%E8%AE%AE%E6%97%8F#cite_note-2)。因为该协议家族的两个核心协议：**TCP（**[**传输控制协议**](https://zh.wikipedia.org/wiki/%E4%BC%A0%E8%BE%93%E6%8E%A7%E5%88%B6%E5%8D%8F%E8%AE%AE)**）**和**IP（**[**网际协议**](https://zh.wikipedia.org/wiki/%E7%BD%91%E9%99%85%E5%8D%8F%E8%AE%AE)**）**
**(图片来源:**[**https://zh.wikipedia.org/wiki/TCP/IP%E5%8D%8F%E8%AE%AE%E6%97%8F**](https://zh.wikipedia.org/wiki/TCP/IP%E5%8D%8F%E8%AE%AE%E6%97%8F)**)**
#### ![image.png](https://cdn.nlark.com/yuque/0/2024/png/26307378/1721528297432-30c8ecf2-d24e-458b-b4c1-6ce596ac7ebd.png#averageHue=%23ecf0f5&clientId=u323c3b5b-a9e0-4&from=paste&height=513&id=uc7acdf16&originHeight=513&originWidth=576&originalType=binary&ratio=1&rotation=0&showTitle=false&size=103313&status=done&style=none&taskId=u8cce5338-95bd-424a-9344-1027445410b&title=&width=576)![image.png](https://cdn.nlark.com/yuque/0/2024/png/26307378/1721528390194-8f353be5-36c3-498e-beb5-d915422b307a.png#averageHue=%23dce3e1&clientId=u323c3b5b-a9e0-4&from=paste&height=478&id=u38727fd1&originHeight=478&originWidth=898&originalType=binary&ratio=1&rotation=0&showTitle=false&size=170790&status=done&style=none&taskId=uc010ad85-1d24-467a-8aca-cc9be66bd54&title=&width=898)
### 万维网是如何工作的
**互联网**并不等同[**万维网**](https://zh.wikipedia.org/wiki/%E4%B8%87%E7%BB%B4%E7%BD%91)。互联网是指[网络](https://zh.wikipedia.org/wiki/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C)与网络之间所串而连成的一个逻辑上的单一巨大国际网络，这些网络以一组通用的协议相连。万维网是一个由许多互相链接的[超文本](https://zh.wikipedia.org/wiki/%E8%B6%85%E6%96%87%E6%9C%AC)组成的系统，可以理解为互联网的一项服务，通过互联网访问。
[万维网](https://zh.wikipedia.org/wiki/%E5%85%A8%E7%90%83%E8%B3%87%E8%A8%8A%E7%B6%B2)是[文件](https://zh.wikipedia.org/wiki/%E9%9B%BB%E8%85%A6%E6%AA%94%E6%A1%88)、[图片](https://zh.wikipedia.org/wiki/%E5%9C%96%E7%89%87)、[多媒体](https://zh.wikipedia.org/wiki/%E5%A4%9A%E5%AA%92%E9%AB%94)和其他资源的全球集合，在逻辑上通过[超链接](https://zh.wikipedia.org/wiki/%E8%B6%85%E9%80%A3%E7%B5%90)互相连接，并使用[统一资源标志符](https://zh.wikipedia.org/wiki/%E7%B5%B1%E4%B8%80%E8%B3%87%E6%BA%90%E6%A8%99%E8%AA%8C%E7%AC%A6)标识，统一资源标志符提供了一个全球命名标识系统，象征性地标识服务、[网页服务器](https://zh.wikipedia.org/wiki/%E7%B6%B2%E9%A0%81%E4%BC%BA%E6%9C%8D%E5%99%A8)、数据库以及提供的文件和资源。[超文本传输协议](https://zh.wikipedia.org/wiki/%E8%B6%85%E6%96%87%E6%9C%AC%E5%82%B3%E8%BC%B8%E5%8D%94%E8%AD%B0)（HTTP）是万维网的主要访问协议，万维网的服务使用HTTP在软件系统之间进行通信和资料传输[[30]](https://zh.wikipedia.org/wiki/%E4%BA%92%E8%81%94%E7%BD%91#cite_note-30)。
### 互联网，因特网，万维网的区别
互联网：泛指由通信设备（如计算机、手机等）组成的网络。
因特网：指由成千上万台设备组成的数据网络，属于互联网中的其中一种。
万维网：由不同的文档、多媒体文件连通而形成的逻辑网络；万维网其中的每个节点都是一个顶级域名，即我们所获取的网站）。
按照范围排序的关系：互联网 > 因特网 > 万维网
### 网页，网站，网络服务器和搜索引擎的区别
#### [网页（webpage）](https://developer.mozilla.org/zh-CN/docs/Learn/Common_questions/Web_mechanics/Pages_sites_servers_and_search_engines#%E7%BD%91%E9%A1%B5%EF%BC%88webpage%EF%BC%89)
一份能够显示在网络浏览器（如 Firefox、Google Chrome、Opera、Microsoft Edge 或 Apple 的 Safari）上的文档。网页也常被称作“web page”（网页）或者就叫“page”（页面）。
#### [网站（website）](https://developer.mozilla.org/zh-CN/docs/Learn/Common_questions/Web_mechanics/Pages_sites_servers_and_search_engines#%E7%BD%91%E7%AB%99%EF%BC%88website%EF%BC%89)
一个由许多网页组合在一起，并常常以各种方式相互连接的网页组成的集合。网站常被称作“web site”（网站）或简称“site”（站点）。
#### [Web 服务器（web server）](https://developer.mozilla.org/zh-CN/docs/Learn/Common_questions/Web_mechanics/Pages_sites_servers_and_search_engines#web_%E6%9C%8D%E5%8A%A1%E5%99%A8%EF%BC%88web_server%EF%BC%89)
一个_网络服务器_是一台托管一个或多个网站的计算机。“托管”意思是所有的网页和它们的支持文件在那台计算机上都可用。网络服务器会根据每位用户的请求，将任意网页从托管的网站中发送到任意用户的浏览器中。
别把_网站_和_网络服务器_弄混了。例如，当你听到某人说：“我的网站没有响应”，这实际上指的是_网络服务器_没响应，并因此导致_网站_不可用。更重要的是，自从一个网络服务器能够托管多个网站，“网络服务器”这个术语从来都没被用来指定一个网站，因为这可能导致很大的混乱。在上面的例子中，如果我们说，“我的网络服务器没有响应”，这就指的是在那台网络服务器上的所有网页都不可用。
#### [搜索引擎（search engine）](https://developer.mozilla.org/zh-CN/docs/Learn/Common_questions/Web_mechanics/Pages_sites_servers_and_search_engines#%E6%90%9C%E7%B4%A2%E5%BC%95%E6%93%8E%EF%BC%88search_engine%EF%BC%89)
搜索引擎是帮助你查找其他网页的网络服务，例如 Google、Bing、Yahoo 或 DuckDuckGo。
许多网上的初学者将搜索引擎和浏览器混淆了。让我们明确一下：浏览器是一个接收并显示网页的软件，搜索引擎则是一个帮助用户从其他网站中寻找网页的网站。这种混淆之所以出现是因为当一个人打开一个浏览器的时候，浏览器展现的是一个搜索引擎的主页。这有什么意义呢？很明显，因为你打开浏览器要做的第一件事就是去寻找一个网站。不要把基础设施（浏览器）和服务（搜索引擎）混淆。这种区分会对你很有帮助，但是甚至有些专业人员也还把它们说得很宽泛，所以不用对这种区分太过谨慎。
#### 类比理解
将图书馆与 Web 服务器进行比较：

- 图书馆就像一个 Web 服务器。它有几个部分，类似于一个 Web 服务器托管多个网站。
- 图书馆中的不同部分（科学、数学、历史等）就像网站。每个部分就像一个独特的网站（两个部分不包含相同的书）。
- 每个部分中的书籍就像网页。一个网站可能有几个网页，例如，科学部分（网站）将有关于热、声音、热力学、静力学等的书籍（网页）。每个网页都可以在唯一的位置（URL）找到。
- 搜索索引就像搜索引擎。每本书在图书馆中有自己唯一的位置（两本书不能放在同一个地方），这由目录号指定。
### 什么是超链接
早在 1989 年，网络发明人蒂姆·伯纳斯·李（Tim Berners-Lee）就提出了 Web 的三大支柱：

1. [URL](https://developer.mozilla.org/zh-CN/docs/Glossary/URL)：跟踪 Web 文档的地址系统
2. [HTTP](https://developer.mozilla.org/zh-CN/docs/Glossary/HTTP)：通过给定 URL 来查找文档的传输协议
3. [HTML](https://developer.mozilla.org/zh-CN/docs/Glossary/HTML)：允许嵌入_超链接_的文档格式

链接是一段链接到 URL 的文本，我们使用链接来跳转到另一个文档。
#### 链接的类型
[内链](https://developer.mozilla.org/zh-CN/docs/Learn/Common_questions/Web_mechanics/What_are_hyperlinks#%E5%86%85%E9%93%BE)
内链是你的网页之间的链接。没有内部链接，就没有网站（当然，除非是只有一页的网站）。
[外链](https://developer.mozilla.org/zh-CN/docs/Learn/Common_questions/Web_mechanics/What_are_hyperlinks#%E5%A4%96%E9%93%BE)
外链是从你的网页链接到其他人的网页的链接。没有外部链接，就没有 web，因为 web 是网页的网络。使用外部链接提供除你自己维护的内容之外的信息。
[传入链接](https://developer.mozilla.org/zh-CN/docs/Learn/Common_questions/Web_mechanics/What_are_hyperlinks#%E4%BC%A0%E5%85%A5%E9%93%BE%E6%8E%A5)
传入链接是从其他人的网页链接到你的网页的链接。这只是从被链接者的角度看到的外部链接。请注意，当有人链接到你的网站时，你不必链接回去。
#### [锚](https://developer.mozilla.org/zh-CN/docs/Learn/Common_questions/Web_mechanics/What_are_hyperlinks#锚)
大多数链接将两个网页相连。而**锚**将一个网页中的两个段落相连。当你点击指向锚点的链接时，浏览器跳转到当前文档的另一部分，而不是加载新文档。但是，你可以像使用其他链接一样制作和使用锚点。
#### [链接和搜索引擎](https://developer.mozilla.org/zh-CN/docs/Learn/Common_questions/Web_mechanics/What_are_hyperlinks#链接和搜索引擎)
链接对你的用户和搜索引擎都很重要。每次搜索引擎抓取一个网页时，他们都会按照网页上提供的链接对网站进行索引。搜索引擎不仅可以通过链接来发现网站的各种页面，还可以使用链接的可见文本来确定哪些搜索查询适合到达目标网页。
所以链接会影响搜索引擎链接到你的网站的方式。麻烦的是，很难衡量搜索引擎的活动。公司自然希望他们的网站在搜索结果中排名很高，所有研究结果至少可以说明一些事情：

- 链接的_可见文本_会影响哪些搜索查询会找到给定的网址。
- 一个网页所拥有的_传入链接_越多，它在搜索结果中排名越高。
- _外链_影响源和目标网页的搜索排名，但有多少不明确。
### 什么是URL

### 运营网站的花费
软件：文本编辑器，图像编辑器，媒体编辑器
浏览器
网络访问：电脑/调制解调器，互联网提供商连接
主机：理解带宽，域名，自己动手托管与"打包"托管，免费托管与付费托管对比
专业网站机构和托管
### 什么是web服务
软件+硬件
静态web服务器，动态web服务器
深入探索：托管文件，通过HTTP交流，静态和动态内容

### 需要什么软件来构建一个网站
需求：创建和编辑网页;上传文件到你的web服务器;浏览你的网站
### 使用Github Pages实时发布网站代码
## js语言知识
### 异步js
**同步编程-**>很可能遇到一个耗时的同步函数，导致程序阻塞不动

**事件处理程序**->事件处理程序实际上就是异步编程的一种形式：你提供的函数（事件处理程序）将在事件发生时被调用（而不是立即被调用）。

**回调**->事件处理程序是一种特殊类型的回调函数。而回调函数则是一个被传递到另一个函数中的会在适当的时候被调用的函数。正如我们刚刚所看到的：回调函数曾经是 JavaScript 中实现异步函数的主要方式。但是，当回调函数本身需要调用其他同样接受回调函数的函数时，基于回调的代码会变得难以理解，在一些地方这被称为“回调地狱”或“厄运金字塔”。

实上，JavaScript 中异步编程的基础是 Promise
#### 异步与eventloop，以及eventloop与setTimeout的关系
事件循环是JavaScript处理异步编程的核心机制。它负责协调代码执行、事件和回调函数的调度。

setTimeout是JavaScript中用于调度异步任务的一个函数。它接受两个参数：一个回调函数和一个延迟时间（以毫秒为单位）。在指定的时间后，回调函数会被加入消息队列。

JavaScript通过事件循环模型管理异步操作。setTimeout将任务调度到消息队列中，并在指定时间后执行。事件循环确保在处理异步任务时，主线程能够继续执行其他任务，从而保持应用的响应性。

#### js异步编程->什么是Promise

### js对象
### js类
#### 定义类
类表达式和类声明(没有提升：不能在声明之前是有类)
#### 类主体
可以从以下三个方面表述一个类元素的特征：

- 种类：getter、setter、方法、字段
- 位置：静态的或位于实例上
- 可见性：公有或私有

它们总共有 16 种可能的组合：
1.方法的定义
    公有的实例方法
2.getter
    公有的实例 getter 方法
3.setter
    公有的实例 setter 方法
4.类公有字段
    公有的实例字段
5.static
    公有的静态方法、静态 getter、静态 setter 和静态字段
6.私有属性
    所有私有的元素
7.构造函数
[constructor](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Classes/constructor) 方法是用于创建和初始化一个由类创建的对象的特殊方法。一个类只能拥有一个名为“constructor”的特殊方法。如果类包含多个 `constructor` 方法，将会抛出一个 [SyntaxError](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/SyntaxError)。
构造函数可以使用 [super](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/super) 关键字来调用父类的构造函数。
或者，如果实例属性的值不依赖构造函数的参数，那么你可以把它们定义为[类字段](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Classes#%E5%AD%97%E6%AE%B5%E5%A3%B0%E6%98%8E)。

类字段/字段声明：
类字段与对象属性相似，不属于变量，所以我们不需要使用诸如 `const` 一类的关键字去声明它们。
```
class Rectangle {
  height = 0;
  width;
  constructor(height, width) {
    this.height = height;
    this.width = width;
  }
}

```

私有属性--暂未深入
静态初始化块--暂未深入
继承--暂未深入
#### js构造函数与普通函数区别
this

构造函数:是专门用来创建新实例的，不是用来重新初始化已有实例的。
#### 类和原型的关系
总结：
1.原型链是JavaScript对象的继承机制，通过对象的__proto__属性链接原型对象，形成链式结构。
2.原型对象是通过构造函数的prototype属性定义的，用于存储共享的方法和属性。
3.类是ES6引入的一种语法糖，简化了构造函数和原型方法的定义，但其本质依然基于原型继承机制。
4.类定义的方法实际上是添加到构造函数的原型对象（prototype）上的，这样通过类创建的实例对象可以通过原型链访问这些方法。

**当我们使用class关键字定义类时，JavaScript在背后做了以下几件事情：**
**    1.创建一个函数，这个函数就是类的构造函数。**
**    2.创建一个对象，这个对象就是类的原型对象（prototype），并将构造函数的prototype属性指向这个对象。**
**    3.将在类定义中声明的所有方法添加到原型对象上。**

### js HTML DOM
DOM HTML
DOM CSS
DOM 事件
DOM EventListener
DOM 元素
HTML Collection对象
NodeList对象

#### window.onload和$(document).ready()的区别
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
#### document.addEventListener('DOMContentLoaded', f, false);
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
### js正则表达式
创建，正则表达式，匹配

### js作用域


### 立即调用函数表达式
定义自执行匿名函数是在定义后立即执行的 [JavaScript](https://developer.mozilla.org/zh-CN/docs/Glossary/JavaScript)[函数](https://developer.mozilla.org/zh-CN/docs/Glossary/Function)，也被称作[立即调用函数表达式](https://developer.mozilla.org/zh-CN/docs/Glossary/IIFE)（IIFE）。
```
()();
举例：
1.(function() {
})();
2.(()=> {
})();
```

作用域的特点..
### 如何使得共享对象方法，而不是每次调用函数都创建一个对象呢？
这种方法不正确，不能达到目的，因为只要每次$()就会创建一个新的对象，每个新的对象的方法就相互独立。思路：将方法放在共享的原型对象中
```
$.prototype.hide = $().hide;
$.prototype.show = $().show;
$.prototype.ready = $().ready;
```
### 函数
#### 定义函数
函数表达式和函数声明(有提升)
#### 函数副作用
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

#### 调用函数创建新的对象
> 每次调用函数都会创建新的对象，主要是由于 JavaScript 中函数的作用域和对象的创建机制。以下是详细解释：
> 1. 函数作用域和变量
> 每次调用函数时，都会创建一个新的作用域（scope），在这个作用域内声明的变量和定义的函数都是这个作用域的局部变量。这意味着这些变量和函数在函数执行结束后会被销毁，除非被返回或者被其他引用保存。
> 2. 内部函数的作用域链
> 内部函数在定义时，会捕获其所在作用域的变量和函数。这使得这些内部函数在函数执行结束后，即使在外部调用，它们依然可以访问这些局部变量和函数。
> 3. 返回新的对象
> 当一个函数返回一个对象时，这个对象包含的所有方法和属性都是该函数执行时创建的。每次调用函数时，返回的对象都是一个全新的实例，因为函数的每次执行都会创建一个新的作用域和新的变量。

## 



### 闭包
_**闭包**_是由函数以及声明该函数的词法环境组合而成的。该环境包含了这个闭包创建时作用域内的任何局部变量。
**闭包**是指在创建时能够记住其词法作用域的函数，即使这个函数是在其词法作用域之外被调用的。在你的代码中，闭包的概念得到了很好的体现。
举例：
```
function makeSizer(size) {
  return function () {
    document.body.style.fontSize = size + "px";
  };
}

var size12 = makeSizer(12);
var size14 = makeSizer(14);
var size16 = makeSizer(16);

```
这个示例展示了闭包的以下特性：

1. **函数内部函数访问外部函数变量**：匿名函数可以访问 `makeSizer` 函数中的 `size` 参数。
2. **函数在其词法作用域外仍能访问词法作用域中的变量**：即使 `makeSizer` 函数已经执行完毕，返回的匿名函数仍然可以访问并使用 `size` 变量。

用闭包模拟私有方法--暂未深入
在循环中创建闭包：一个常见错误--暂未深入
性能考量--暂未深入

## 复刻jq时的思路历程
1.function()形式,每次调用创建对象,对象间方法独立.(避免函数副作用！)
TypeError: $ is not a function    
        $是一个对象，对象访问属性只能.    函数()每次调用要创建多个对象   思路：单例-》只创建一个对象，且能用()的方式调用？
        在class内部创建实例,并且把这个实例作为一个函数来处理
        如何把这个实例作为一个函数来处理
        instance声明问题->如何声明在一个更高的作用域中而不是函数中
2.class形式,单例模式,每次只创建一个对象,对象方法共享

## FP语言(Functional Programming)
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
### ![1.png](https://cdn.nlark.com/yuque/0/2024/png/26307378/1721115514337-552fa7e6-8107-4b72-9731-775440d24091.png#averageHue=%23f5f5f1&clientId=u7fb7d905-061e-4&from=ui&id=nPYum&originHeight=775&originWidth=902&originalType=binary&ratio=1&rotation=0&showTitle=false&size=764826&status=done&style=none&taskId=uf87aa7ff-87b4-48b8-b78d-32157aa6bde&title=)图灵完备性
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
## 7.DOM只有在浏览器中才能使用
在vscode中不能通过这种方式获取html元素：let x = document.getElementById("first");会出现报错：ReferenceError: document is not defined
原因：js脚本的运行环境只有浏览器环境和Node.js两种，document.属于DOM应用，对于DOM和BOM的操作只能在浏览器环境下才能进行;在vscode中使用Nodejs环境，因此报错不能使用
解决办法：

## 8.判断是否需要event参数
事件监听器的回调函数可以接受一个事件对象作为参数，这个事件对象包含了关于事件的各种信息。在 addEventListener 方法中，这个事件对象通常被命名为 event 或 e，但如果回调函数不需要使用这个事件对象，可以省略它。
如果你不需要访问事件对象中的任何信息（如事件的目标元素、事件类型等），可以省略 event 参数。这是完全有效的写法，只要你不需要使用事件对象中的信息。
```
window.addEventListener("load", (event) => {
  log.textContent += "load\n";
});
```
## 9.事件监听器的正确使用-函数调用&函数定义
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

## 10.document多处定义导致事件监听器无法正确添加
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
