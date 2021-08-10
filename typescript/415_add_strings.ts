function addStrings(num1: string, num2: string): string {
  let result = '';
  let carry = 0;
  let len1 = num1.length,
    len2 = num2.length;
  let idx1 = len1 - 1,
    idx2 = len2 - 1;

  while (idx1 >= 0 && idx2 >= 0) {
    let n1 = parseInt(num1[idx1]);
    let n2 = parseInt(num2[idx2]);

    result = `${(n1 + n2 + carry) % 10}${result}`;
    carry = n1 + n2 + carry > 9 ? 1 : 0;

    idx1--;
    idx2--;
  }

  while (idx1 >= 0) {
    let n1 = parseInt(num1[idx1]);
    result = `${(n1 + carry) % 10}${result}`;
    carry = n1 + carry > 9 ? 1 : 0;
    idx1--;
  }

  while (idx2 >= 0) {
    let n2 = parseInt(num2[idx2]);
    result = `${(n2 + carry) % 10}${result}`;
    carry = n2 + carry > 9 ? 1 : 0;
    idx2--;
  }

  if (carry === 1) {
    return '1' + result;
  }

  return result;
}

console.log(addStrings('0', '0'));
console.log(addStrings('999', '234'));
console.log(addStrings('9', '99'));
