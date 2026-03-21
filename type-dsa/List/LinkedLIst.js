"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var Node_1 = require("../Nodes/Node");
var LinkedList = /** @class */ (function () {
    function LinkedList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }
    // Add node to the end of the list
    LinkedList.prototype.append = function (value) {
        var newNode = new Node_1.default(value);
        if (this.head == null) {
            this.head = newNode;
            this.tail = newNode;
        }
        else {
            if (this.tail) {
                this.tail.next = newNode;
                this.tail = newNode;
            }
        }
        this.size = this.size + 1;
    };
    // Add node, start of the list
    LinkedList.prototype.prepend = function (value) {
        var newNode = new Node_1.default(value);
        if (this.head == null) {
            this.head = newNode;
            this.tail = newNode;
        }
        else {
            newNode.next = this.head;
            this.head = newNode;
        }
        this.size = this.size + 1;
    };
    // Add node at position
    LinkedList.prototype.insertAt = function (value, position) {
        var newNode = new Node_1.default(value);
        // Log out of bound position
        if (this.isEmpty() && position !== 1) {
            console.log("Position out of bounds.");
            return;
        }
        // Head is null and position is 1
        if (this.head == null && position === 1) {
            this.head = newNode;
            this.tail = newNode;
            this.size = this.size + 1;
            return;
        }
        // Head is not null and position is 1
        if (this.head != null && position === 1) {
            newNode.next = this.head;
            this.head = newNode;
            this.size = this.size + 1;
            return;
        }
        // At Last
        if (this.size === position - 1) {
            if (this.tail) {
                this.tail.next = newNode;
                this.tail = newNode;
                this.size = this.size + 1;
                return;
            }
        }
        else if (this.size < position - 1) {
            // Position is greater than size
            console.log("Position out of bounds.");
            return;
        }
        else {
            // Position is less than size
            var temp = this.head;
            var count = 0;
            while (temp) {
                count = count + 1;
                if (count === position - 1) {
                    newNode.next = temp.next;
                    temp.next = newNode;
                    this.size = this.size + 1;
                    return;
                }
                temp = temp.next;
            }
        }
    };
    // Size of list
    LinkedList.prototype.length = function () {
        return this.size;
    };
    // List is empty
    LinkedList.prototype.isEmpty = function () {
        return this.size === 0;
    };
    // remove node at end of the list
    LinkedList.prototype.pop = function () {
        if (this.isEmpty()) {
            console.log("Empty LinkedList.");
            return;
        }
        if (this.tail === this.head) {
            this.head = null;
            this.tail = null;
            this.size = this.size - 1;
        }
        else {
            var temp = this.head;
            while (temp) {
                if (temp.next === this.tail) {
                    temp.next = null;
                    this.tail = temp;
                    this.size = this.size - 1;
                    return;
                }
                temp = temp.next;
            }
        }
    };
    // remove node at start of the list
    LinkedList.prototype.shift = function () {
        if (this.isEmpty()) {
            console.log("Empty LinkedList.");
            return;
        }
        if (this.tail === this.head) {
            this.head = null;
            this.tail = null;
            this.size = this.size - 1;
        }
        else {
            if (this.head) {
                this.head = this.head.next;
                this.size = this.size - 1;
            }
        }
    };
    // remove node at index-based
    LinkedList.prototype.removeAt = function (position) {
        var _a, _b;
        if (this.isEmpty()) {
            console.log("Empty LinkedList.");
            return;
        }
        if (((_a = this.head) === null || _a === void 0 ? void 0 : _a.next) == null && position !== 1) {
            console.log("Position out of bounds.");
            return;
        }
        if (((_b = this.head) === null || _b === void 0 ? void 0 : _b.next) == null && position === 1) {
            this.head = null;
            this.tail = null;
            this.size = this.size - 1;
            return;
        }
        if (this.size === position || this.size > position) {
            var temp = this.head;
            var count = 0;
            while (temp) {
                count = count + 1;
                if (count === position - 1) {
                    temp.next = temp.next ? temp.next.next : null;
                    if (count === this.size - 1) {
                        this.tail = temp;
                    }
                    this.size = this.size - 1;
                    return;
                }
                temp = temp.next;
            }
        }
    };
    LinkedList.prototype.search = function (value) {
        if (this.isEmpty()) {
            console.log("Empty LinkedList.");
        }
        var temp = this.head;
        while (temp) {
            if (temp.value === value) {
                return true;
            }
            temp = temp.next;
        }
        return false;
    };
    // Remove node via data
    LinkedList.prototype.remove = function (value) {
        var _a, _b;
        if (this.isEmpty()) {
            console.log("Empty LinkedList.");
        }
        if (!this.search(value)) {
            console.log("Value not found in the list.");
        }
        if (((_a = this.head) === null || _a === void 0 ? void 0 : _a.value) === value) {
            if (this.head === this.tail) {
                this.head = null;
                this.tail = null;
            }
            else {
                this.head = this.head.next;
            }
            this.size = this.size - 1;
            return;
        }
        else {
            var temp = this.head;
            while (temp) {
                if (((_b = temp === null || temp === void 0 ? void 0 : temp.next) === null || _b === void 0 ? void 0 : _b.value) === value) {
                    temp.next = temp.next ? temp.next.next : null;
                    if (temp.next === null) {
                        this.tail = temp;
                    }
                    this.size = this.size - 1;
                    return;
                }
                temp = temp.next;
            }
        }
    };
    // Traverse all nodes
    LinkedList.prototype.traverse = function () {
        var temp = this.head;
        if (this.isEmpty()) {
            console.log("Empty LinkedList.");
            return;
        }
        while (temp) {
            console.log("".concat(temp.value, "->"));
            temp = temp.next;
        }
        console.log("NULL");
    };
    return LinkedList;
}());
exports.default = LinkedList;
