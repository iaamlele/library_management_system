// 1.js怎么与网页连接->把js放在html中
// 2.js怎么获取网页中的元素->js HTML DOM
// 2.实现每一类功能函数
    // jQuery中所有选择器都以美元符号开头：$()

console.log("hello js");

//通过id查找html元素
let x = document.getElementById("first");
console.log(x);
//通过标签名查找html元素
let y = x.getElementsByTagName("p");

let a = document.getElementById("second");
//通过类名查找html元素
let b = a.getElementsByClassName("second-class1");
let c = b.getElementsByTagName("p");
