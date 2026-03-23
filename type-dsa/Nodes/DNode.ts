class DNode<T> {
  value: T;
  next: DNode<T> | null = null;
  prev: DNode<T> | null = null;
  constructor(value: T) {
    this.value = value;
  }
}

export default DNode;
