import QueueNode from "../Nodes/QueueNode";

class Queue<T> {
  private front: QueueNode<T> | null = null;
  private back: QueueNode<T> | null = null;
  private height: number = 0;

  enqueue(value: T) {
    var newNode = new QueueNode(value);

    if (this.isEmpty()) {
      this.front = newNode;
      this.back = newNode;
    } else {
      if (this.back) {
        this.back.next = newNode;
        this.back = newNode;
      }
    }

    this.height = this.height + 1;
  }

  dequeue() {
    if (this.isEmpty()) {
      console.log("Empty queue");
      return;
    }

    if (this.front === this.back) {
      this.front = null;
      this.back = null;
    } else {
      if (this.front) {
        this.front = this.front.next;
      }
    }

    this.height = this.height - 1;
  }

  peek() {
    if (this.isEmpty()) {
      console.log("Empty queue");
      return;
    } else {
      if (this.front) {
        return this.front.value;
      }
    }
  }

  search(value: T) {
    if (this.isEmpty()) {
      console.log("Empty queue");
      return;
    } else {
      var temp: QueueNode<T> | null = this.front;
      while (temp) {
        if (temp.value === value) {
          return true;
        }
        temp = temp.next;
      }
    }

    return false;
  }

  traverse() {
    if (this.isEmpty()) {
      console.log("Empty queue");
      return;
    } else {
      var temp: QueueNode<T> | null = this.front;

      while (temp) {
        console.log(temp.value);
        temp = temp.next;
      }
    }
    return;
  }

  size() {
    return this.height;
  }

  isEmpty() {
    return this.height === 0;
  }
}

export default Queue;

