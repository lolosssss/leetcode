function longestPalindrome(s: string): string {
  const len = s.length;
  let head = 0,
    tail = 0;
  let i = 0,
    j = 0;
  let max = 0;

  for (i = 0; i < len; i++) {
    for (j = 0; i - j >= 0 && i + j < len; j++) {
      if (s[i - j] != s[i + j]) {
        break;
      }
    }
    if (2 * j + 1 > max) {
      max = 2 * j + 1;
      head = i - j + 1;
      tail = i + j;
    }

    for (j = 0; i - j >= 0 && i + j + 1 < len; j++) {
      if (s[i - j] != s[i + j + 1]) {
        break;
      }
    }
    if (2 * j + 2 > max) {
      max = 2 * j + 2;
      head = i - j + 1;
      tail = i + j + 1;
    }
  }

  return s.substring(head, tail);
}
