function convert(s: string, numRows: number): string {
  if (numRows === 1) {
    return s;
  }
  let ret = [];
  let len = s.length;
  let idx = 0;
  let step = 1;
  for (let i = 0; i < numRows; i++) {
    ret.push('');
  }
  for (let i = 0; i < len; i++) {
    ret[idx] += s[i];
    idx += step;
    if ((i + 1) % (numRows - 1) === 0) {
      step = 0 - step;
    }
  }
  return ret.join('');
}
