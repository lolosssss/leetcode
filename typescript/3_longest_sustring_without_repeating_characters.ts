function lengthOfLongestSubstring(s: string): number {
  let head = 0,
    tail = 0;
  let max = 0;
  let alpha = new Set();
  while (tail < s.length) {
    if (alpha.has(s[tail])) {
      max = max > tail - head ? max : tail - head;
      alpha.delete(s[head]);
      head++;
    } else {
      alpha.add(s[tail]);
      tail++;
    }
  }

  return max > tail - head ? max : tail - head;
}
