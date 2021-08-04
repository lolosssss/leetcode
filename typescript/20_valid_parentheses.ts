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

console.log(isValid('()[]{}'));
console.log(isValid('('));
console.log(isValid('([)]'));
