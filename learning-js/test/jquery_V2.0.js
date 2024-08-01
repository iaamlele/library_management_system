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

function jqeury() {
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
}
