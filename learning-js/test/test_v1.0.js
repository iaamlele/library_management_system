import {click_hide_addListener, click_hide, click_show_addListener, toggle_addListener } from "./jquery_V1.0.js";
// 确保所有资源加载完成后执行脚本
window.onload = () => {
    // hide
    const btn_hide = document.getElementById("button1");
    click_hide_addListener("#button1", "#first-id");
    btn_hide.click();
    console.log(document.getElementById("first-id").style.visibility);

    //show
    const btn_show = document.getElementById("button2");
    click_show_addListener("#button2", "#first-id");
    btn_show.click();
    console.log(document.getElementById("first-id").style.visibility);

    //toggle
    const btn_hide_show = document.getElementById("button3");
    toggle_addListener("#button3", "#first-id");
    btn_hide_show.click();
    console.log(document.getElementById("first-id").style.visibility);
    toggle_addListener("#button3", "#first-id");
    btn_hide_show.click();
    console.log(document.getElementById("first-id").style.visibility);

};

