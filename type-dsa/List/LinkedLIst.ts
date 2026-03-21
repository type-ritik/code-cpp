import ListNode from "../Nodes/Node";

class LinkedList<T> {
  protected head: ListNode<T> | null = null;
  protected tail: ListNode<T> | null = null;
  protected size: number = 0;

  // Add node to the end of the list
  append(value: T): void {
    const newNode = new ListNode(value);

    if (this.head == null) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      if (this.tail) {
        this.tail.next = newNode;
        this.tail = newNode;
      }
    }
    this.size = this.size + 1;
  }

  // Add node, start of the list
  prepend(value: T): void {
    const newNode = new ListNode(value);

    if (this.head == null) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      newNode.next = this.head;
      this.head = newNode;
    }
    this.size = this.size + 1;
  }

  // Add node at position
  insertAt(value: T, position: number): void {
    const newNode = new ListNode(value);

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
    } else if (this.size < position - 1) {
      // Position is greater than size
      console.log("Position out of bounds.");
      return;
    } else {
      // Position is less than size
      var temp: ListNode<T> | null = this.head;
      var count: number = 0;
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
  }

  // Size of list
  length(): number {
    return this.size;
  }

  // List is empty
  isEmpty(): boolean {
    return this.size === 0;
  }

  // remove node at end of the list
  pop(): void {
    if (this.isEmpty()) {
      console.log("Empty LinkedList.");
      return;
    }
    if (this.tail === this.head) {
      this.head = null;
      this.tail = null;
      this.size = this.size - 1;
    } else {
      var temp: ListNode<T> | null = this.head;
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
  }

  // remove node at start of the list
  shift(): void {
    if (this.isEmpty()) {
      console.log("Empty LinkedList.");
      return;
    }
    if (this.tail === this.head) {
      this.head = null;
      this.tail = null;
      this.size = this.size - 1;
    } else {
      if (this.head) {
        this.head = this.head.next;
        this.size = this.size - 1;
      }
    }
  }

  // remove node at index-based
  removeAt(position: number): void {
    if (this.isEmpty()) {
      console.log("Empty LinkedList.");
      return;
    }

    if (this.head?.next == null && position !== 1) {
      console.log("Position out of bounds.");
      return;
    }

    if (this.head?.next == null && position === 1) {
      this.head = null;
      this.tail = null;
      this.size = this.size - 1;
      return;
    }

    if (this.size === position || this.size > position) {
      var temp: ListNode<T> | null = this.head;
      var count: number = 0;

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
  }

  search(value: T): boolean {
    if (this.isEmpty()) {
      console.log("Empty LinkedList.");
    }

    var temp: ListNode<T> | null = this.head;

    while (temp) {
      if (temp.value === value) {
        return true;
      }
      temp = temp.next;
    }
    return false;
  }

  // Remove node via data
  remove(value: T): void {
    if (this.isEmpty()) {
      console.log("Empty LinkedList.");
    }

    if (!this.search(value)) {
      console.log("Value not found in the list.");
    }

    if (this.head?.value === value) {
      if (this.head === this.tail) {
        this.head = null;
        this.tail = null;
      } else {
        this.head = this.head.next;
      }
      this.size = this.size - 1;
      return;
    } else {
      var temp: ListNode<T> | null = this.head;
      while (temp) {
        if (temp?.next?.value === value) {
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
  }

  // Traverse all nodes
  traverse(): void {
    var temp: ListNode<T> | null = this.head;

    if (this.isEmpty()) {
      console.log("Empty LinkedList.");
      return;
    }
    while (temp) {
      console.log(`${temp.value}->`);
      temp = temp.next;
    }
    console.log("NULL");
  }
}

export default LinkedList;
