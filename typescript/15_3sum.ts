function threeSum(nums: number[]): number[][] {
  let ret = [];
  nums.sort((a, b) => a - b);

  let len = nums.length;

  for (let idx = 0; idx < len - 2; ) {
    let target = -nums[idx];
    let left = idx + 1;
    let right = len - 1;

    while (left < right) {
      if (nums[left] + nums[right] > target) {
        right--;
      } else if (nums[left] + nums[right] < target) {
        left++;
      } else {
        ret.push([nums[idx], nums[left], nums[right]]);
        left++;
        while (nums[left] === nums[left - 1] && left < right) left++;
      }
    }
    idx++;
    while (nums[idx] === nums[idx - 1] && idx < len - 2) idx++;
  }

  return ret;
}

let case1 = [-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4];
console.log(threeSum(case1));
