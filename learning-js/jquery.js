// 1.js怎么与网页连接->把js放在html中
// 2.js怎么获取网页中的元素->js HTML DOM->jsdom  这样不方便->浏览器
// 3.实现显示和隐藏功能
module.exports
//隐藏和显示功能
function click_hide(element) {
    const hide_element = document.querySelector(element);
    hide_element.style.visibility = 'hidden';
    console.log(hide_element.style.visibility);
}

function click_hide_addListener(elem1, elem2) {
    const element1 = document.querySelector(elem1);
    element1.addEventListener("click", function() {
        click_hide(elem2);
    });
}