"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var QueueNode_1 = require("../Nodes/QueueNode");
var Queue = /** @class */ (function () {
    function Queue() {
        this.front = null;
        this.back = null;
        this.height = 0;
    }
    Queue.prototype.enqueue = function (value) {
        var newNode = new QueueNode_1.default(value);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        }
        else {
            if (this.back) {
                this.back.next = newNode;
                this.back = newNode;
            }
        }
        this.height = this.height + 1;
    };
    Queue.prototype.dequeue = function () {
        if (this.isEmpty()) {
            console.log("Empty queue");
            return;
        }
        if (this.front === this.back) {
            this.front = null;
            this.back = null;
        }
        else {
            if (this.front) {
                this.front = this.front.next;
            }
        }
        this.height = this.height - 1;
    };
    Queue.prototype.peek = function () {
        if (this.isEmpty()) {
            console.log("Empty queue");
            return;
        }
        else {
            if (this.front) {
                return this.front.value;
            }
        }
    };
    Queue.prototype.search = function (value) {
        if (this.isEmpty()) {
            console.log("Empty queue");
            return;
        }
        else {
            var temp = this.front;
            while (temp) {
                if (temp.value === value) {
                    return true;
                }
                temp = temp.next;
            }
        }
        return false;
    };
    Queue.prototype.traverse = function () {
        if (this.isEmpty()) {
            console.log("Empty queue");
            return;
        }
        else {
            var temp = this.front;
            while (temp) {
                console.log(temp.value);
                temp = temp.next;
            }
        }
        return;
    };
    Queue.prototype.size = function () {
        return this.height;
    };
    Queue.prototype.isEmpty = function () {
        return this.height === 0;
    };
    return Queue;
}());
exports.default = Queue;
