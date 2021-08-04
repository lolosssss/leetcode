function generateParenthesis(n: number): string[] {
  let ret = [];
  recursive(2 * n, 0, ret, []);
  return ret.filter(isValid);
}

function recursive(limit: number, depth: number, res: string[], list: string[]) {
  if (depth === limit) {
    res.push(list.join(''));
    return;
  }

  list.push('(');
  recursive(limit, depth + 1, res, list);
  list.pop();

  list.push(')');
  recursive(limit, depth + 1, res, list);
  list.pop();
}

function isValid(s: string): boolean {
  const len = s.length;
  let stack = [];

  for (let i = 0; i < len; i++) {
    let c = s[i];
    if (c === '(' || c === '{' || c === '[') {
      stack.push(c);
    } else {
      let tmp = stack.pop();
      if ((c === ')' && tmp !== '(') || (c === '}' && tmp !== '{') || (c === ']' && tmp !== '[')) {
        return false;
      }
    }
  }

  return stack.length === 0;
}

console.log(generateParenthesis(3));
