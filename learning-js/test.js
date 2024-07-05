const jsdom = require("jsdom");
const {JSDOM} = jsdom;
const {click_hide, click_hide_addListener} = require("./jquery.js");
const fs = require("fs");

const html = fs.readFileSync("index.html", "utf-8");
// resources: 'usable'代表js脚本在外部  
// runScripts:'dangerously'不添加会导致选项控制不起作用
const dom = new JSDOM(html, {resources: 'usable', runScripts: 'dangerously'});

// 确保所有资源加载完成后执行脚本
dom.window.onload = () => {
    const document = dom.window.document;
    click_hide_addListener("#button", "p");
    
    const button = document.getElementById("button1");
    button.click();
    console.log(document.getElementById("first-id").hidden);
};
