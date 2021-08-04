let NUMBER_ALPHAS = {
  '2': ['a', 'b', 'c'],
  '3': ['d', 'e', 'f'],
  '4': ['g', 'h', 'i'],
  '5': ['j', 'k', 'l'],
  '6': ['m', 'n', 'o'],
  '7': ['p', 'q', 'r', 's'],
  '8': ['t', 'u', 'v'],
  '9': ['w', 'x', 'y', 'z'],
};

function letterCombinations(digits: string): string[] {
  let ret = [];
  let keys = [];
  for (let i = 0; i < digits.length; i++) {
    keys.push(digits[i]);
  }

  combine(keys, 0, [], ret);

  return ret;
}

function combine(digits: string[], depth: number, alphas: string[], res: string[]) {
  if (depth === digits.length) {
    if (alphas.length > 0) {
      res.push(alphas.join(''));
    }
    return;
  }

  for (let i = 0; i < NUMBER_ALPHAS[digits[depth]].length; i++) {
    alphas.push(NUMBER_ALPHAS[digits[depth]][i]);
    combine(digits, depth + 1, alphas, res);
    alphas.pop();
  }
}

console.log(letterCombinations(''));
console.log(letterCombinations('234'));
console.log(letterCombinations('2234'));
