(self["webpackChunklearning"] = self["webpackChunklearning"] || []).push([["main"],{

/***/ "./src/index.js":
/*!**********************!*\
  !*** ./src/index.js ***!
  \**********************/
/***/ (() => {

// 训练编码能力，原型可优化，先自己优化。打算看看github上别人的写法，先自己写，再借鉴学习。
class Class_${
    constructor(arg) {
        this.arg = arg;

        const elements = [];
        this.elements = elements;

        if(typeof arg === "string") {
            const arg_class = new RegExp("^\\..*");
            const arg_id = new RegExp("^#.*");
            const arg_tag = new RegExp("^[a-zA-Z][a-zA-z0-9]*");
            if(arg_class.test(arg)) {
                const classes = document.getElementsByClassName(arg.slice(1));
                elements.push(classes);
            }else if(arg_id.test(arg)) {
                const ids = document.getElementById(arg.slice(1));
                elements.push(ids);
                elements[1] = 1;
            }else if(arg_tag.test(arg)) {
                const tags = document.getElementsByTagName(arg);
                elements.push(tags);
            }
        }else if(typeof arg === "object") {
            elements.push(arg);
        }

        if(!Class_$.instance) {
            Class_$.instance = this;
        }

        return Class_$.instance;             
    }

    entrance(arg) {
        this.elements = [];
        if(typeof arg === "string") {
            const arg_class = new RegExp("^\\..*");
            const arg_id = new RegExp("^#.*");
            const arg_tag = new RegExp("^[a-zA-Z][a-zA-z0-9]*");
            this.elements[1] = 0;
            if(arg_class.test(arg)) {
                const classes = document.getElementsByClassName(arg.slice(1));
                this.elements.push(classes);
            }else if(arg_id.test(arg)) {
                const ids = document.getElementById(arg.slice(1));
                this.elements[0] = ids;
                this.elements[1] = 1;
                
            }else if(arg_tag.test(arg)) {
                const tags = document.getElementsByTagName(arg);
                this.elements.push(tags);
            }
        }else if(typeof arg === "object") {
            this.elements.push(arg);
        }

        if(!Class_$.instance) {
            Class_$.instance = this;
        }

        return this;
    }

    hide() {
        const elem = this.elements[0];
        const is_id = this.elements[1];
        if(is_id === 1) {
            elem.style.visibility = 'hidden';
        }else {
            for(let i = 0; i < elem.length; i++) {
                elem.item(i).style.visibility = 'hidden';
            }
        }
        return this;
    }

    show() {
        const elem = this.elements[0];
        const is_id = this.elements[1];
        if(is_id === 1) {
            elem.style.visibility = 'visible';
        }else {
            for(let i = 0; i < elem.length; i++) {
                elem.item(i).style.visibility = 'visible';
            }
        }
        return this;
    }

    ready(f) {
        const elem = this.elements[0];
        if(elem === document) {
            return document.addEventListener("DOMContentLoaded", f, false);
        }else {
            return null;
        }
        
    }
}

const $ = (function() {
    let instance;
    function init(arg) {
        if(!instance) {
            instance = new Class_$(arg);
        }else {
            instance.entrance(arg);
        }
        return instance;
    }
    return function(arg) {
        return init(arg);
    }
})();

$(document).ready(function() {
    $("#first-id").hide().show();
});

/***/ })

},
/******/ __webpack_require__ => { // webpackRuntimeModules
/******/ var __webpack_exec__ = (moduleId) => (__webpack_require__(__webpack_require__.s = moduleId))
/******/ var __webpack_exports__ = (__webpack_exec__("./src/index.js"));
/******/ }
]);
//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJmaWxlIjoibWFpbi40YzVjNmVlMDgxYjlhNGUyMjM1ZS5qcyIsIm1hcHBpbmdzIjoiOzs7Ozs7OztBQUFBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7O0FBRUE7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQSxhQUFhO0FBQ2I7QUFDQTtBQUNBO0FBQ0EsYUFBYTtBQUNiO0FBQ0E7QUFDQTtBQUNBLFNBQVM7QUFDVDtBQUNBOztBQUVBO0FBQ0E7QUFDQTs7QUFFQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0EsYUFBYTtBQUNiO0FBQ0E7QUFDQTtBQUNBO0FBQ0EsYUFBYTtBQUNiO0FBQ0E7QUFDQTtBQUNBLFNBQVM7QUFDVDtBQUNBOztBQUVBO0FBQ0E7QUFDQTs7QUFFQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQSxTQUFTO0FBQ1QsMkJBQTJCLGlCQUFpQjtBQUM1QztBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQSxTQUFTO0FBQ1QsMkJBQTJCLGlCQUFpQjtBQUM1QztBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBO0FBQ0EsU0FBUztBQUNUO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBLFNBQVM7QUFDVDtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBLENBQUM7O0FBRUQ7QUFDQTtBQUNBLENBQUMiLCJzb3VyY2VzIjpbIndlYnBhY2s6Ly9sZWFybmluZy8uL3NyYy9pbmRleC5qcyJdLCJzb3VyY2VzQ29udGVudCI6WyIvLyDorq3nu4PnvJbnoIHog73lipvvvIzljp/lnovlj6/kvJjljJbvvIzlhYjoh6rlt7HkvJjljJbjgILmiZPnrpfnnIvnnItnaXRodWLkuIrliKvkurrnmoTlhpnms5XvvIzlhYjoh6rlt7HlhpnvvIzlho3lgJ/pibTlrabkuaDjgIJcbmNsYXNzIENsYXNzXyR7XG4gICAgY29uc3RydWN0b3IoYXJnKSB7XG4gICAgICAgIHRoaXMuYXJnID0gYXJnO1xuXG4gICAgICAgIGNvbnN0IGVsZW1lbnRzID0gW107XG4gICAgICAgIHRoaXMuZWxlbWVudHMgPSBlbGVtZW50cztcblxuICAgICAgICBpZih0eXBlb2YgYXJnID09PSBcInN0cmluZ1wiKSB7XG4gICAgICAgICAgICBjb25zdCBhcmdfY2xhc3MgPSBuZXcgUmVnRXhwKFwiXlxcXFwuLipcIik7XG4gICAgICAgICAgICBjb25zdCBhcmdfaWQgPSBuZXcgUmVnRXhwKFwiXiMuKlwiKTtcbiAgICAgICAgICAgIGNvbnN0IGFyZ190YWcgPSBuZXcgUmVnRXhwKFwiXlthLXpBLVpdW2EtekEtejAtOV0qXCIpO1xuICAgICAgICAgICAgaWYoYXJnX2NsYXNzLnRlc3QoYXJnKSkge1xuICAgICAgICAgICAgICAgIGNvbnN0IGNsYXNzZXMgPSBkb2N1bWVudC5nZXRFbGVtZW50c0J5Q2xhc3NOYW1lKGFyZy5zbGljZSgxKSk7XG4gICAgICAgICAgICAgICAgZWxlbWVudHMucHVzaChjbGFzc2VzKTtcbiAgICAgICAgICAgIH1lbHNlIGlmKGFyZ19pZC50ZXN0KGFyZykpIHtcbiAgICAgICAgICAgICAgICBjb25zdCBpZHMgPSBkb2N1bWVudC5nZXRFbGVtZW50QnlJZChhcmcuc2xpY2UoMSkpO1xuICAgICAgICAgICAgICAgIGVsZW1lbnRzLnB1c2goaWRzKTtcbiAgICAgICAgICAgICAgICBlbGVtZW50c1sxXSA9IDE7XG4gICAgICAgICAgICB9ZWxzZSBpZihhcmdfdGFnLnRlc3QoYXJnKSkge1xuICAgICAgICAgICAgICAgIGNvbnN0IHRhZ3MgPSBkb2N1bWVudC5nZXRFbGVtZW50c0J5VGFnTmFtZShhcmcpO1xuICAgICAgICAgICAgICAgIGVsZW1lbnRzLnB1c2godGFncyk7XG4gICAgICAgICAgICB9XG4gICAgICAgIH1lbHNlIGlmKHR5cGVvZiBhcmcgPT09IFwib2JqZWN0XCIpIHtcbiAgICAgICAgICAgIGVsZW1lbnRzLnB1c2goYXJnKTtcbiAgICAgICAgfVxuXG4gICAgICAgIGlmKCFDbGFzc18kLmluc3RhbmNlKSB7XG4gICAgICAgICAgICBDbGFzc18kLmluc3RhbmNlID0gdGhpcztcbiAgICAgICAgfVxuXG4gICAgICAgIHJldHVybiBDbGFzc18kLmluc3RhbmNlOyAgICAgICAgICAgICBcbiAgICB9XG5cbiAgICBlbnRyYW5jZShhcmcpIHtcbiAgICAgICAgdGhpcy5lbGVtZW50cyA9IFtdO1xuICAgICAgICBpZih0eXBlb2YgYXJnID09PSBcInN0cmluZ1wiKSB7XG4gICAgICAgICAgICBjb25zdCBhcmdfY2xhc3MgPSBuZXcgUmVnRXhwKFwiXlxcXFwuLipcIik7XG4gICAgICAgICAgICBjb25zdCBhcmdfaWQgPSBuZXcgUmVnRXhwKFwiXiMuKlwiKTtcbiAgICAgICAgICAgIGNvbnN0IGFyZ190YWcgPSBuZXcgUmVnRXhwKFwiXlthLXpBLVpdW2EtekEtejAtOV0qXCIpO1xuICAgICAgICAgICAgdGhpcy5lbGVtZW50c1sxXSA9IDA7XG4gICAgICAgICAgICBpZihhcmdfY2xhc3MudGVzdChhcmcpKSB7XG4gICAgICAgICAgICAgICAgY29uc3QgY2xhc3NlcyA9IGRvY3VtZW50LmdldEVsZW1lbnRzQnlDbGFzc05hbWUoYXJnLnNsaWNlKDEpKTtcbiAgICAgICAgICAgICAgICB0aGlzLmVsZW1lbnRzLnB1c2goY2xhc3Nlcyk7XG4gICAgICAgICAgICB9ZWxzZSBpZihhcmdfaWQudGVzdChhcmcpKSB7XG4gICAgICAgICAgICAgICAgY29uc3QgaWRzID0gZG9jdW1lbnQuZ2V0RWxlbWVudEJ5SWQoYXJnLnNsaWNlKDEpKTtcbiAgICAgICAgICAgICAgICB0aGlzLmVsZW1lbnRzWzBdID0gaWRzO1xuICAgICAgICAgICAgICAgIHRoaXMuZWxlbWVudHNbMV0gPSAxO1xuICAgICAgICAgICAgICAgIFxuICAgICAgICAgICAgfWVsc2UgaWYoYXJnX3RhZy50ZXN0KGFyZykpIHtcbiAgICAgICAgICAgICAgICBjb25zdCB0YWdzID0gZG9jdW1lbnQuZ2V0RWxlbWVudHNCeVRhZ05hbWUoYXJnKTtcbiAgICAgICAgICAgICAgICB0aGlzLmVsZW1lbnRzLnB1c2godGFncyk7XG4gICAgICAgICAgICB9XG4gICAgICAgIH1lbHNlIGlmKHR5cGVvZiBhcmcgPT09IFwib2JqZWN0XCIpIHtcbiAgICAgICAgICAgIHRoaXMuZWxlbWVudHMucHVzaChhcmcpO1xuICAgICAgICB9XG5cbiAgICAgICAgaWYoIUNsYXNzXyQuaW5zdGFuY2UpIHtcbiAgICAgICAgICAgIENsYXNzXyQuaW5zdGFuY2UgPSB0aGlzO1xuICAgICAgICB9XG5cbiAgICAgICAgcmV0dXJuIHRoaXM7XG4gICAgfVxuXG4gICAgaGlkZSgpIHtcbiAgICAgICAgY29uc3QgZWxlbSA9IHRoaXMuZWxlbWVudHNbMF07XG4gICAgICAgIGNvbnN0IGlzX2lkID0gdGhpcy5lbGVtZW50c1sxXTtcbiAgICAgICAgaWYoaXNfaWQgPT09IDEpIHtcbiAgICAgICAgICAgIGVsZW0uc3R5bGUudmlzaWJpbGl0eSA9ICdoaWRkZW4nO1xuICAgICAgICB9ZWxzZSB7XG4gICAgICAgICAgICBmb3IobGV0IGkgPSAwOyBpIDwgZWxlbS5sZW5ndGg7IGkrKykge1xuICAgICAgICAgICAgICAgIGVsZW0uaXRlbShpKS5zdHlsZS52aXNpYmlsaXR5ID0gJ2hpZGRlbic7XG4gICAgICAgICAgICB9XG4gICAgICAgIH1cbiAgICAgICAgcmV0dXJuIHRoaXM7XG4gICAgfVxuXG4gICAgc2hvdygpIHtcbiAgICAgICAgY29uc3QgZWxlbSA9IHRoaXMuZWxlbWVudHNbMF07XG4gICAgICAgIGNvbnN0IGlzX2lkID0gdGhpcy5lbGVtZW50c1sxXTtcbiAgICAgICAgaWYoaXNfaWQgPT09IDEpIHtcbiAgICAgICAgICAgIGVsZW0uc3R5bGUudmlzaWJpbGl0eSA9ICd2aXNpYmxlJztcbiAgICAgICAgfWVsc2Uge1xuICAgICAgICAgICAgZm9yKGxldCBpID0gMDsgaSA8IGVsZW0ubGVuZ3RoOyBpKyspIHtcbiAgICAgICAgICAgICAgICBlbGVtLml0ZW0oaSkuc3R5bGUudmlzaWJpbGl0eSA9ICd2aXNpYmxlJztcbiAgICAgICAgICAgIH1cbiAgICAgICAgfVxuICAgICAgICByZXR1cm4gdGhpcztcbiAgICB9XG5cbiAgICByZWFkeShmKSB7XG4gICAgICAgIGNvbnN0IGVsZW0gPSB0aGlzLmVsZW1lbnRzWzBdO1xuICAgICAgICBpZihlbGVtID09PSBkb2N1bWVudCkge1xuICAgICAgICAgICAgcmV0dXJuIGRvY3VtZW50LmFkZEV2ZW50TGlzdGVuZXIoXCJET01Db250ZW50TG9hZGVkXCIsIGYsIGZhbHNlKTtcbiAgICAgICAgfWVsc2Uge1xuICAgICAgICAgICAgcmV0dXJuIG51bGw7XG4gICAgICAgIH1cbiAgICAgICAgXG4gICAgfVxufVxuXG5jb25zdCAkID0gKGZ1bmN0aW9uKCkge1xuICAgIGxldCBpbnN0YW5jZTtcbiAgICBmdW5jdGlvbiBpbml0KGFyZykge1xuICAgICAgICBpZighaW5zdGFuY2UpIHtcbiAgICAgICAgICAgIGluc3RhbmNlID0gbmV3IENsYXNzXyQoYXJnKTtcbiAgICAgICAgfWVsc2Uge1xuICAgICAgICAgICAgaW5zdGFuY2UuZW50cmFuY2UoYXJnKTtcbiAgICAgICAgfVxuICAgICAgICByZXR1cm4gaW5zdGFuY2U7XG4gICAgfVxuICAgIHJldHVybiBmdW5jdGlvbihhcmcpIHtcbiAgICAgICAgcmV0dXJuIGluaXQoYXJnKTtcbiAgICB9XG59KSgpO1xuXG4kKGRvY3VtZW50KS5yZWFkeShmdW5jdGlvbigpIHtcbiAgICAkKFwiI2ZpcnN0LWlkXCIpLmhpZGUoKS5zaG93KCk7XG59KTsiXSwibmFtZXMiOltdLCJzb3VyY2VSb290IjoiIn0=