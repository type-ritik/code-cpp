class StackNode<T> {
  value: T;
  next: StackNode<T> | null = null;
  constructor(value: T) {
    this.value = value;
  }
}

export default StackNode;
