"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var DNode = /** @class */ (function () {
    function DNode(value) {
        this.next = null;
        this.prev = null;
        this.value = value;
    }
    return DNode;
}());
exports.default = DNode;
