// 1.js怎么与网页连接->把js放在html中
// 2.js怎么获取网页中的元素->js HTML DOM->jsdom
// 2.实现每一类功能函数
module.exports.click_hide = click_hide;
module.exports.click_hide_addListener = click_hide_addListener;

const jsdom = require("jsdom");
const {JSDOM} = jsdom;
const fs = require("fs");
const html = fs.readFileSync("index.html", "utf-8");
const dom = new JSDOM(html, {resources: "usable", runScripts: "dangerously"});
const document = dom.window.document;

function click_hide(element) {
    const hide_element = document.querySelector(element)
    hide_element.style.visibility = 'hidden';
    console.log(hide_element.style.visibility);
}

function click_hide_addListener(elem1, elem2) {
    const element1 = document.querySelector(elem1);
    element1.addEventListener("click", click_hide(elem2));
}


