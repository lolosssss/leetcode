function longestCommonPrefix(strs: string[]): string {
  let prefix = strs[0];
  for (let i = 1; i < strs.length; i++) {
    let len = prefix.length;
    if (len === 0) {
      return '';
    }
    let idx = 0;
    while (prefix[idx] === strs[i][idx] && idx < len) {
      idx++;
    }
    prefix = prefix.slice(0, idx);
  }

  return prefix;
}
