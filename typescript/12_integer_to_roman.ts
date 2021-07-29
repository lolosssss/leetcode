function intToRoman(num: number): string {
  let values: number[] = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
  let symbols: string[] = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I'];

  let ret = '';
  let idx = 0;
  let v = 0;

  while (num > 0) {
    v = Math.floor(num / values[idx]);
    if (v === 0) {
      idx++;
      continue;
    }
    for (let j = 0; j < v; j++) {
      ret += symbols[idx];
    }
    num = num % values[idx];
    idx++;
  }
  return ret;
}
