function reverse(x: number): number {
  const isNegative = x < 0;
  x = Math.abs(x);
  let ret = 0;
  while (x != 0) {
    ret = ret * 10 + (x % 10);
    x = Math.floor(x / 10);
  }
  if (ret > Math.pow(2, 31) - 1) {
    return 0;
  }
  return isNegative ? -ret : ret;
}
