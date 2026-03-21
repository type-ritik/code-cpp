"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var LinkedLIst_1 = require("./List/LinkedLIst");
// Create a new LinkedList
var list = new LinkedLIst_1.default();
list.append(5);
list.append(10);
list.append(15);
list.append(20);
list.append(25);
list.append(30);
list.traverse();
