"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var DNode_1 = require("../Nodes/DNode");
var DoublyList = /** @class */ (function () {
    function DoublyList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }
    DoublyList.prototype.invariantViolated = function () {
        if (this.head == null && this.tail != null) {
            return true;
        }
        if (this.head != null && this.tail == null) {
            return true;
        }
        return false;
    };
    DoublyList.prototype.isEmpty = function () {
        return this.size === 0;
    };
    DoublyList.prototype.length = function () {
        return this.size;
    };
    DoublyList.prototype.append = function (value) {
        if (this.invariantViolated()) {
            console.log("Invariant Violated.");
            return;
        }
        var newNode = new DNode_1.default(value);
        if (this.isEmpty()) {
            this.head = newNode;
            this.tail = newNode;
        }
        else {
            if (this.tail) {
                this.tail.next = newNode;
                newNode.prev = this.tail;
                this.tail = newNode;
            }
        }
        this.size = this.size + 1;
    };
    DoublyList.prototype.prepend = function (value) {
        if (this.invariantViolated()) {
            console.log("Invariant Violated.");
            return;
        }
        var newNode = new DNode_1.default(value);
        if (this.isEmpty()) {
            this.head = newNode;
            this.tail = newNode;
        }
        else {
            if (this.head) {
                newNode.next = this.head;
                this.head.prev = newNode;
                this.head = newNode;
            }
        }
        this.size = this.size + 1;
    };
    DoublyList.prototype.traverse = function () {
        if (this.invariantViolated()) {
            console.log("Invariant Violated.");
            return;
        }
        if (this.isEmpty()) {
            console.log("List is empty.");
            return;
        }
        var temp = this.head;
        while (temp) {
            console.log(temp.value);
            temp = temp.next;
        }
    };
    DoublyList.prototype.pop = function () {
        if (this.invariantViolated()) {
            console.log("Invariant Violated.");
            return;
        }
        if (this.isEmpty()) {
            console.log("List is empty.");
            return;
        }
        if (this.head === this.tail) {
            this.tail = null;
            this.head = null;
        }
        else {
            if (this.tail) {
                this.tail = this.tail.prev;
                if (this.tail) {
                    this.tail.next = null;
                }
            }
        }
        this.size = this.size - 1;
    };
    DoublyList.prototype.shift = function () {
        if (this.invariantViolated()) {
            console.log("Invariant Violated.");
            return;
        }
        if (this.isEmpty()) {
            console.log("List is empty.");
            return;
        }
        if (this.head === this.tail) {
            this.head = null;
            this.tail = null;
        }
        else {
            if (this.head) {
                this.head = this.head.next;
                if (this.head) {
                    this.head.prev = null;
                }
            }
        }
        this.size = this.size - 1;
    };
    DoublyList.prototype.insert = function (value, position) {
        if (this.invariantViolated()) {
            console.log("Invariant Violated.");
            return;
        }
        if (this.isEmpty()) {
            console.log("List is empty.");
            return;
        }
        if (position > this.size + 1) {
            console.log("Position should be less than or equal to size of list.");
            return;
        }
        if (position < 1) {
            console.log("Position should be greater than or equal to 1.");
            return;
        }
        console.log("My position", position);
        if (position === 1) {
            this.prepend(value);
            return;
        }
        else if (position === this.length() + 1) {
            this.append(value);
            return;
        }
        else {
            var newNode = new DNode_1.default(value);
            var temp = this.head;
            var count = 1;
            while (temp) {
                if (count === position) {
                    if (temp.prev) {
                        temp.prev.next = newNode;
                        newNode.prev = temp.prev;
                    }
                    newNode.next = temp;
                    temp.prev = newNode;
                    break;
                }
                count = count + 1;
                temp = temp.next;
            }
        }
        this.size = this.size + 1;
    };
    DoublyList.prototype.delete = function (value) {
        if (this.invariantViolated()) {
            console.log("Invariant Violated.");
        }
        if (this.isEmpty()) {
            console.log("List is empty.");
        }
        if (this.head) {
            if (this.head.value === value) {
                this.shift();
                return;
            }
        }
        if (this.tail) {
            if (this.tail.value === value) {
                this.pop();
                return;
            }
        }
        var temp = this.head;
        var count = 1;
        while (temp) {
            if (temp.value === value) {
                if (temp.prev) {
                    temp.prev.next = temp.next;
                }
                if (temp.next) {
                    temp.next.prev = temp.prev;
                }
                break;
            }
            temp = temp.next;
            count++;
        }
        console.log(count);
        console.log(this.length());
        if (count >= this.size) {
            console.log("Value not found in list.");
            return;
        }
        this.size = this.size - 1;
    };
    DoublyList.prototype.delete_at = function (position) {
        if (this.invariantViolated()) {
            console.log("Invariant Violated.");
        }
        if (this.isEmpty()) {
            console.log("List is empty.");
        }
        if (position === 1) {
            this.shift();
            return;
        }
        if (position === this.size) {
            this.pop();
            return;
        }
        if (position > this.size) {
            console.log("Position should be less than or equal to size of list.");
            return;
        }
        var temp = this.head;
        var count = 1;
        while (temp) {
            if (count === position) {
                if (temp.prev) {
                    temp.prev.next = temp.next;
                }
                if (temp.next) {
                    temp.next.prev = temp.prev;
                }
                break;
            }
            count = count + 1;
            temp = temp.next;
        }
        this.size = this.size - 1;
    };
    return DoublyList;
}());
exports.default = DoublyList;
