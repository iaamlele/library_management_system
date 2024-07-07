import {click_hide_addListener, click_hide, click_show_addListener } from "./jquery.js";
// 确保所有资源加载完成后执行脚本
window.onload = () => {
    const btn_hide = document.getElementById("button1");
    click_hide_addListener("#button1", "#first-id");
    btn_hide.click();
    console.log(document.getElementById("first-id").style.visibility);

    const btn_show = document.getElementById("button2");
    click_show_addListener("#button2", "#first-id");
    btn_show.click();
    console.log(document.getElementById("first-id").style.visibility);
    // click_hide("#second-p");

    
};

