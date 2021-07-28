function beautifulArray(n: number): number[] {
  let ret = [1];
  while (ret.length < n) {
    ret = [...ret.map((i) => i * 2 - 1), ...ret.map((i) => i * 2)];
  }
  return ret.filter((i) => i <= n);
}
