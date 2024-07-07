import click_hide_addListener from "./jquery.js";
// 确保所有资源加载完成后执行脚本
dom.window.onload = () => {
    const button = document.getElementById("button1");
    click_hide_addListener(document, "#button1", "#first-id");
    button.click();

    console.log(document.getElementById("first-id").style.visibility); //不知道为什么这里显示不出来
};
