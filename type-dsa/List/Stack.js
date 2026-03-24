"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var StackNode_1 = require("../Nodes/StackNode");
var Stack = /** @class */ (function () {
    function Stack() {
        this.head = null;
        this.height = 0;
    }
    Stack.prototype.size = function () {
        return this.height;
    };
    Stack.prototype.isEmpty = function () {
        return this.height === 0;
    };
    Stack.prototype.push = function (value) {
        var newNode = new StackNode_1.default(value);
        if (this.isEmpty()) {
            this.head = newNode;
        }
        else {
            if (this.head) {
                newNode.next = this.head;
                this.head = newNode;
            }
        }
        this.height = this.height + 1;
    };
    Stack.prototype.pop = function () {
        if (this.isEmpty()) {
            console.log("Empty Stack.");
        }
        else {
            if (this.head) {
                this.head = this.head.next;
                this.height = this.height - 1;
            }
        }
    };
    Stack.prototype.top = function () {
        if (this.isEmpty()) {
            console.log("Empty Stack.");
        }
        else {
            if (this.head) {
                return this.head.value;
            }
        }
    };
    Stack.prototype.traverse = function () {
        if (this.isEmpty()) {
            console.log("Empty Stack.");
        }
        else {
            var temp = this.head;
            while (temp) {
                console.log(temp.value);
                temp = temp.next;
            }
        }
    };
    Stack.prototype.search = function (value) {
        if (this.isEmpty()) {
            console.log("Empty Stack.");
        }
        else {
            var temp = this.head;
            while (temp) {
                if (temp.value === value) {
                    return true;
                }
                temp = temp.next;
            }
        }
        return false;
    };
    return Stack;
}());
exports.default = Stack;
