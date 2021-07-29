function isPalindrome(x: number): boolean {
  if (x < 0) return false;
  if (x < 10) return true;

  const s = x.toString();
  let head = 0;
  let tail = s.length - 1;
  while (head < tail) {
    if (s[head++] !== s[tail--]) {
      return false;
    }
  }
  return true;
}
