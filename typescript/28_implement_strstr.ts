function strStr(haystack: string, needle: string): number {
  let i = 0;
  let ptr = 0;

  if (needle.length === 0) return 0;

  while (ptr <= haystack.length - needle.length) {
    i = 0;
    for (; i < needle.length; i++) {
      if (haystack[ptr + i] !== needle[i]) {
        break;
      }
    }
    if (i === needle.length) {
      return ptr;
    }

    ptr++;
  }

  return -1;
}

console.log(strStr('hello', 'll'));
console.log(strStr('aaaaa', 'bba'));
console.log(strStr('', ''));
console.log(strStr('c', 'c'));
console.log(strStr('abc', 'c'));
