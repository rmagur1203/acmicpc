function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
  let i = 0;
  let j = 0;
  let merged: number[] = [];
  while (nums1.length > i && nums2.length > j) {
    if (nums1[i] < nums2[j]) merged.push(nums1[i++]);
    else merged.push(nums2[j++]);
  }
  for (; i < nums1.length; i++) {
    merged.push(nums1[i]);
  }
  for (; j < nums2.length; j++) {
    merged.push(nums2[j]);
  }
  let mid = merged.length / 2;
  if (merged.length % 2) {
    return merged[Math.floor(mid)];
  } else {
    return (merged[mid - 1] + merged[mid]) / 2;
  }
}
