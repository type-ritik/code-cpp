import DoublyList from "./List/DoublyList";
import LinkedList from "./List/LinkedLIst";
import Stack from "./List/Stack";

// const list = new LinkedList();
// list.append(1);
// list.append(2);
// list.append(3);
// list.insertAt(4,4);
// list.prepend(0);
// console.log("Is Empty: ", list.isEmpty());
// console.log("Size: ", list.length());
// list.traverse();

// list.pop();
// list.shift();
// list.removeAt(2);
// list.remove(2);

// list.traverse();

// const dlist = new DoublyList();
// console.log("Is Empty: ", dlist.isEmpty());
// console.log("Size: ", dlist.length());

// dlist.append(5);
// dlist.traverse();

// dlist.append(10);
// dlist.traverse();

// dlist.append(15);
// dlist.traverse();

// dlist.prepend(0);
// console.log("Is Empty: ", dlist.isEmpty());
// console.log("Size: ", dlist.length());
// dlist.traverse();
// console.log("-------");
// dlist.shift();
// dlist.traverse();
// console.log();
// console.log();

// dlist.shift();
// dlist.traverse();
// console.log();

// dlist.shift();
// dlist.traverse();
// console.log("last one");
// dlist.traverse();
// console.log();
// dlist.insert(2222, 1);
// dlist.traverse();
// console.log();

// dlist.insert(22555, 1);
// dlist.traverse();
// console.log();

// dlist.insert(4282, 2);
// dlist.traverse();
// console.log();

// dlist.insert(225755, 0);
// dlist.traverse();
// console.log();

// console.log("-----Deletion------");

// // dlist.delete(225755);
// // dlist.traverse();
// // console.log();

// // dlist.delete(15);
// // dlist.traverse();
// // console.log();

// // dlist.delete(2222);
// // dlist.traverse();
// // console.log();

// // dlist.delete(2222);
// // dlist.traverse();
// // console.log();

// dlist.delete_at(1);
// dlist.traverse();
// console.log();

// dlist.delete_at(2);
// dlist.traverse();
// console.log();

// dlist.delete_at(dlist.length());
// dlist.traverse();
// console.log();

const stack = new Stack();

stack.push(5);
stack.push(10);
stack.push(15);
stack.push(16);
stack.push(18);
stack.traverse();
console.log(stack.size());
console.log(stack.top());
console.log(stack.search(10));

console.log();
stack.pop();
stack.traverse();
console.log(stack.size());
console.log(stack.top());
console.log(stack.search(18));
