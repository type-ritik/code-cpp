import StackNode from "../Nodes/StackNode";

class Stack<T> {
  private head: StackNode<T> | null = null;
  private height: number = 0;

  size() {
    return this.height;
  }

  isEmpty() {
    return this.height === 0;
  }

  push(value: T) {
    var newNode = new StackNode(value);
    if (this.isEmpty()) {
      this.head = newNode;
    } else {
      if (this.head) {
        newNode.next = this.head;
        this.head = newNode;
      }
    }

    this.height = this.height + 1;
  }

  pop() {
    if (this.isEmpty()) {
      console.log("Empty Stack.");
    } else {
      if (this.head) {
        this.head = this.head.next;
        this.height = this.height - 1;
      }
    }
  }

  top() {
    if (this.isEmpty()) {
      console.log("Empty Stack.");
    } else {
      if (this.head) {
        return this.head.value;
      }
    }
  }

  traverse() {
    if (this.isEmpty()) {
      console.log("Empty Stack.");
    } else {
      var temp: StackNode<T> | null = this.head;

      while (temp) {
        console.log(temp.value);
        temp = temp.next;
      }
    }
  }

  search(value: T) {
    if (this.isEmpty()) {
      console.log("Empty Stack.");
    } else {
      var temp: StackNode<T> | null = this.head;

      while (temp) {
        if (temp.value === value) {
          return true;
        }
        temp = temp.next;
      }
    }
    return false;
  }
}

export default Stack;
