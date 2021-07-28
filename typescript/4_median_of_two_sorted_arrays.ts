function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
  let nums = [...nums1, ...nums2].sort((a, b) => a - b);
  let len = nums.length;
  if (len % 2 === 1) {
    return nums[Math.floor(len / 2)];
  } else {
    return (nums[len / 2] + nums[len / 2 - 1]) / 2;
  }
}
