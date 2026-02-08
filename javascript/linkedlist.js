class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
  }

  createNode(value) {
    return new Node(value);
  }

  append(value) {
    let node = this.createNode(value);

    if (this.head === null) {
      this.head = node;
      this.tail = node;
      this.count = 1;
      return;
    }

    this.tail.next = node;
    this.tail = node;
    return;
  }

  insertAt(position, value) {
    if (this.head === null && position !== 1) {
      console.log("Invalid position");
      return;
    }

    if (position < 1) {
      console.log("Invalid posititon");
      return;
    }

    let node = this.createNode(value);

    if (this.head === null && position === 1) {
      this.head = node;
      this.tail = node;
      return;
    }

    let count = 0;
    let current = this.head;

    while (current.next !== null && count !== position - 2) {
      current = current.next;
      count = count + 1;
    }

    if (current.next !== null && count === position - 2) {
      node.next = current.next;
      current.next = node;
      return;
    }

    if (current.next === null && count === position - 2) {
      current.next = node;
      this.tail = node;
      return;
    }

    if (current.next === null && count !== position - 2) {
      console.log("Invalid position");
      return;
    }
  }

  prepend(value) {
    let node = this.createNode(value);
    if (this.head === null) {
      this.head = node;
      this.tail = node;
      return;
    }

    node.next = this.head;
    this.head = node;
    return;
  }

  remove(value) {
    if (this.head.value === value && this.tail.value === value) {
      this.head = null;
      this.tail = null;
      return;
    }

    if (this.head.value === value) {
      let temp = this.head;
      this.head = this.head.next;
      temp.next = null;
      return;
    }

    let current = this.head;

    while (current.next !== null && current.next.value !== value) {
      current = current.next;
    }

    if (current.next !== null && current.next.value === value) {
      if (current.next.next === null) {
        this.tail = current;
        current.next = null;
        return;
      }

      let temp = current.next;
      current.next = current.next.next;
      temp.next = null;
      return;
    }
  }

  removeAt(position) {
    if (this.head === null) {
      console.log("Invalid posititon");
      return;
    }

    if (position < 1) {
      console.log("Invalid posititon");
      return;
    }

    if (this.head.next === null && position !== 1) {
      console.log("Invalid position");
      return;
    }

    if (position === 1 && this.head.next === null) {
      this.head = null;
      this.tail = null;
      return;
    }

    if (position === 1 && this.head !== null) {
      let temp = this.head;
      this.head = this.head.next;
      temp.next = null;
      return;
    }

    let current = this.head;
    let count = 0;

    while (current.next !== null && count !== position - 2) {
      current = current.next;
      count = count + 1;
    }

    if (current.next === null) {
      console.log("Invalid position");
      return;
    }

    if (current.next !== null && count === position - 2) {
      if (current.next.next === null) {
        this.tail = current;
        current.next = null;
        return;
      }
      let temp = current.next;
      current.next = current.next.next;
      temp.next = null;
      return;
    }
  }

  pop() {
    if (this.head === null) {
      console.log("List is empty");
      return;
    }

    if (this.head.next === null) {
      this.head = null;
      this.tail = null;
      return;
    }

    let current = this.head;
    while (current.next.next !== null) {
      current = current.next;
    }

    this.tail = current;
    current.next = null;
    return;
  }

  shift() {
    if (this.head === null) {
      console.log("List is empty");
      return;
    }

    if (this.head.next === null) {
      this.head = null;
      this.tail = null;
      return;
    }

    let temp = this.head;
    this.head = this.head.next;
    temp.next = null;
    return;
  }

  getFirst() {
    if (this.head === null) {
      console.log("List is empty");
      return;
    }

    return this.head.value;
  }

  getLast() {
    if (this.head === null) {
      console.log("List is empty");
      return;
    }

    return this.tail.value;
  }

  isEmpty() {
    return this.head === null;
  }

  contain(value) {
    if (this.isEmpty()) {
      console.log("List is empty");
      return;
    }

    if (this.head.value === value || this.tail.value === value) {
      return true;
    }

    let current = this.head;

    while (current !== null) {
      if (current.value === value) {
        return true;
      }
      current = current.next;
    }

    return false;
  }

  get(index) {
    if (this.isEmpty()) {
      console.log("List is empty");
      return;
    }

    if (index < 0) {
      console.log("Invalid index");
      return;
    }

    if (this.head.next === null && index !== 0) {
      console.log("Invalid index");
      return;
    }

    if (this.head.next === null && index === 0) {
      return this.head.value;
    }

    let current = this.head;
    let count = 0;

    while (current !== null && count !== index) {
      current = current.next;
      count = count + 1;
    }

    if (current !== null && count === index) {
      return current.value;
    }

    if (current === null) {
      console.log("Invalid index");
      return;
    }
  }

  traverse() {
    let current = this.head;

    while (current !== null) {
      console.log(current.value);
      current = current.next;
    }
  }
}

module.exports = LinkedList;
