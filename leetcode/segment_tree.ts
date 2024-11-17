export class SegmentTree {
  private _size: number;
  private origin: number[];
  private nodes: number[];
  public shortest: Map<number, number> = new Map();

  constructor(origin: number[]) {
    this._size = origin.length;

    this.origin = origin;
    this.nodes = new Array(this._size * 4);

    const init = (node: number, start: number, end: number) => {
      if (start === end) {
        this.nodes[node] = origin[start];
        return;
      }

      const mid = Math.floor((start + end) / 2);
      const left = node * 2;
      const right = node * 2 + 1;

      init(left, start, mid);
      init(right, mid + 1, end);

      this.nodes[node] = this.nodes[left] + this.nodes[right];
    };

    init(1, 0, this._size - 1);
  }

  update(idx: number, val: number) {
    if (idx < 0 || idx >= this._size) return;

    const diff = val - this.origin[idx];
    this.origin[idx] = val;

    const update = (node: number, start: number, end: number) => {
      this.nodes[node] += diff;
      if (start === end) return;

      const mid = Math.floor((start + end) / 2);
      if (idx <= mid) update(node * 2, start, mid);
      else update(node * 2 + 1, mid + 1, end);
    };

    update(1, 0, this._size - 1);
  }

  sum(left: number, right: number) {
    const sum = (node: number, start: number, end: number): number => {
      if (left > end || right < start) return 0;
      if (left <= start && end <= right) return this.nodes[node];

      const mid = Math.floor((start + end) / 2);
      const leftSum = sum(node * 2, start, mid);
      const rightSum = sum(node * 2 + 1, mid + 1, end);

      const val = leftSum + rightSum;

      if (!this.shortest.has(val)) {
        this.shortest.set(val, end - start + 1);
      }

      return val;
    };

    return sum(1, 0, this._size - 1);
  }
}
