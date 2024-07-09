//使用对象字面量创建对象$
const $ = {
    hide: function(arg) {
        console.log(arg);
    },
    show: function(arg) {
        console.log(arg);
    }
};

//使用函数构造对象
function $() {
    this.hide = hide;
    this.show = show;
    function hide(arg) {
        console.log(arg + "OKK");
    }
}

var $ = new $();