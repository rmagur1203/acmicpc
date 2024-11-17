/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  const used = new Map();
  for (let i = 0; i < nums.length; i++) {
    const fr = used.get(target - nums[i]);
    if (fr !== undefined) {
      return [fr, i];
    }
    used.set(nums[i], i);
  }
};
