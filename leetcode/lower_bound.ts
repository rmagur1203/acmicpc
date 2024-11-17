export function lower_bound<T>(
  arr: Array<T>,
  start: number,
  end: number,
  key: T,
  compare: (a: T, b: T) => number = (a, b) => (a > b ? 1 : a < b ? -1 : 0)
): number {
  if (start >= end) {
    return start;
  }
  const mid = Math.floor((start + end) / 2);
  if (compare(arr[mid], key) < 0) {
    return lower_bound(arr, mid + 1, end, key);
  }
  const leftResult = lower_bound(arr, start, mid - 1, key);
  return leftResult !== undefined ? Math.min(leftResult, mid) : mid;
}
