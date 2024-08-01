import _ from 'lodash';
import './styles.css';
import printMe from './print.js';

function component() {
    const element = document.createElement('div');
    const btn = document.createElement('button');

    element.classList.add('text');
    element.innerHTML = _.join(['Hello', 'webpack'], ' ');

    btn.classList.add('btn');
    btn.innerHTML = 'click me';
    btn.onclick = printMe;

    element.appendChild(btn);

    return element;
}

// 训练编码能力，原型可优化，先自己优化。打算看看github上别人的写法，先自己写，再借鉴学习。
class Class_${
    constructor(arg) {
        this.elements = [];

        if(typeof arg === "string") {
            const arg_class = new RegExp("^\\..*");
            const arg_id = new RegExp("^#.*");
            const arg_tag = new RegExp("^[a-zA-Z][a-zA-z0-9]*");
            if(arg_class.test(arg)) {
                this.elements = Array.from(document.getElementsByClassName(arg.slice(1)));
            }else if(arg_id.test(arg)) {
                this.elements = Array.from(document.getElementById(arg.slice(1)));
            }else if(arg_tag.test(arg)) {
                this.elements = Array.from(document.getElementsByTagName(arg));
            }
        }else if(typeof arg === "object") {
            this.elements = arg;
        }          
    }

    entrance(arg) {
        this.constructor(arg);
        return this;
    }

    hide() {
        this.elements.forEach(el => el.style.visibility = 'hidden');
        return this;
    }

    show() {
        this.elements.forEach(el => el.style.visibility = 'visible');
        return this;
    }

    ready(f) {
        document.addEventListener("DOMContentLoaded", f, false);
    }
}

function jq(selector) {
    const instance = new Class_$(selector);
    return instance;
}

const $ = jq;
$(document).ready(function() {
    $(".btn").hide();
});


let element = component();
document.body.appendChild(element);

if(module.hot) {
    module.hot.accept('./print.js', function() {
        console.log('正在接受更新后的 printMe 模块！');
        document.body.removeChild(element);
        element = component();
        document.body.appendChild(element);
    })
}