// 1.js怎么与网页连接->把js放在html中
// 2.js怎么获取网页中的元素->js HTML DOM->jsdom
// 2.实现每一类功能函数
    // jQuery中所有选择器都以美元符号开头：$()
module.exports = function() {
    click_hide;
    click_hide_addListener;
}

function click_hide(element) {
    const hide_element = document.querySelector(element)
    hide_element.hidden = true;
    console.log(p.hidden);
}

function click_hide_addListener(elem1, elem2) {
    const element1 = document.querySelector(elem1);
    element1.addEventListener("click", click_hide(elem2));
}


