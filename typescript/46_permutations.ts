function permute(nums: number[]): number[][] {
  let ret = [];
  let flags = [];
  nums.forEach((v, idx) => {
    flags[idx] = false;
  });

  recursive(nums, 0, flags, ret, []);

  return ret;
}

function recursive(nums: number[], depth: number, flags: boolean[], result: number[][], tmp: number[]) {
  if (depth === nums.length) {
    result.push([...tmp]);
    tmp = [];
    return;
  }

  for (let i = 0; i < nums.length; i++) {
    if (flags[i]) continue;

    flags[i] = true;
    tmp.push(nums[i]);
    recursive(nums, depth + 1, flags, result, tmp);
    tmp.pop();
    flags[i] = false;
  }
}

console.log(permute([1, 2]));
console.log(permute([1, 2, 3]));
console.log(permute([1, 2, 3, 4]));
