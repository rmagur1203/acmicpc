export function shortestSubarray(nums: number[], k: number): any {
  let sum = 0;
  let min = Infinity;
  let s = 0,
    e = 0;

  let candidate: [number, number, number][] = [];
  for (; e < nums.length; e++) {
    sum += nums[e];
    if (sum < 0) {
      sum = 0;
      s = e + 1;
    }
    console.log(nums.slice(s, e + 1), sum);
    if (sum >= k) {
      min = Math.min(min, e - s + 1);
      candidate.push([s, e, sum]);
    }
  }

  if (min === Infinity) return -1;

  while (candidate.length > 0) {
    let [s, e, sum] = candidate.shift()!;
    console.log("candidate", nums.slice(s, e + 1));

    while (s < e) {
      sum -= nums[s];
      if (sum >= k) {
        console.log("short", nums.slice(s, e + 1), sum);
        min = Math.min(min, e - s);
      }
      s++;
    }
  }

  return min;
}
