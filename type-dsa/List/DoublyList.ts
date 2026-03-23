import DNode from "../Nodes/DNode";

class DoublyList<T> {
  private head: DNode<T> | null = null;
  private tail: DNode<T> | null = null;
  private size: number = 0;

  private invariantViolated(): boolean {
    if (this.head == null && this.tail != null) {
      return true;
    }

    if (this.head != null && this.tail == null) {
      return true;
    }

    return false;
  }

  isEmpty() {
    return this.size === 0;
  }

  length() {
    return this.size;
  }

  append(value: T) {
    if (this.invariantViolated()) {
      console.log("Invariant Violated.");
      return;
    }

    const newNode = new DNode(value);

    if (this.isEmpty()) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      if (this.tail) {
        this.tail.next = newNode;
        newNode.prev = this.tail;
        this.tail = newNode;
      }
    }
    this.size = this.size + 1;
  }

  prepend(value: T) {
    if (this.invariantViolated()) {
      console.log("Invariant Violated.");
      return;
    }

    const newNode = new DNode(value);

    if (this.isEmpty()) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      if (this.head) {
        newNode.next = this.head;
        this.head.prev = newNode;
        this.head = newNode;
      }
    }

    this.size = this.size + 1;
  }

  traverse() {
    if (this.invariantViolated()) {
      console.log("Invariant Violated.");
      return;
    }

    if (this.isEmpty()) {
      console.log("List is empty.");
      return;
    }

    var temp: DNode<T> | null = this.head;

    while (temp) {
      console.log(temp.value);
      temp = temp.next;
    }
  }

  pop() {
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
    } else {
      if (this.tail) {
        this.tail = this.tail.prev;
        if (this.tail) {
          this.tail.next = null;
        }
      }
    }
    this.size = this.size - 1;
  }

  shift() {
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
    } else {
      if (this.head) {
        this.head = this.head.next;

        if (this.head) {
          this.head.prev = null;
        }
      }
    }

    this.size = this.size - 1;
  }

  insert(value: T, position: number) {
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
    } else if (position === this.length() + 1) {
      this.append(value);
      return;
    } else {
      const newNode = new DNode(value);

      var temp: DNode<T> | null = this.head;
      let count = 1;

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
  }

  delete(value: T) {
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

    var temp: DNode<T> | null = this.head;
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
  }

  delete_at(position: number) {
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

    var temp: DNode<T> | null = this.head;
    let count = 1;

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
  }
}

export default DoublyList;
