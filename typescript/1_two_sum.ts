function twoSum(nums: number[], target: number): number[] {
  if (nums.length < 2) {
    return null;
  }

  for (let i = 0; i < nums.length - 1; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      if (nums[i] + nums[j] === target) {
        return [i, j];
      }
    }
  }

  return null;
}
