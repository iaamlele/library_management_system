// 1.js怎么与网页连接->把js放在html中
// 2.js怎么获取网页中的元素->js HTML DOM->jsdom  这样不方便->浏览器
// 3.实现显示和隐藏功能


//hide  jquery:$(selector).hide(speed,callback);    speed，hide方式，callback怎么实现？
export function click_hide(element) {
    const hide_element = document.querySelector(element);
    if(hide_element === "") {
        console.log("Failed to get element");
    }else {
        hide_element.style.visibility = 'hidden';
    }
    
}

export function click_hide_addListener(elem1, elem2) {
    const element1 = document.querySelector(elem1);
    if(element1 === "") {
        console.log("Failed to get element");
    }else {
        element1.addEventListener("click", function() {
            click_hide(elem2);
        });
    }
}

//show
export function click_show(element) {
    const show_element = document.querySelector(element);
    if(show_element === "") {
        console.log("Failed to get element");
    }else {
        show_element.style.visibility = 'visible';
    }    
}

export function click_show_addListener(elem1, elem2) {
    const element1 = document.querySelector(elem1);
    if(element1 === "") {
        console.log("Failed to get element");
    }else {
        element1.addEventListener("click", function() {
            click_show(elem2);
        });
    }    
}

//toggle
export function toggle_addListener(elem1, elem2) {
    const element1 = document.querySelector(elem1);
    if(element1 === "") {
        console.log("Failed to get element");
    }else {
        const is_hide = document.querySelector(elem2).style.visibility;
        if(is_hide === "hide" || is_hide === "") {
            click_show(elem2);
        }else if(is_hide === "visible") {
            click_hide(elem2);
        }
    }
}