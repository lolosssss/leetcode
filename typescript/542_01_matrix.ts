function updateMatrix(mat: number[][]): number[][] {
  const w = mat.length;
  const h = mat[0].length;
  let ret = [];

  for (let i = 0; i < w; i++) {
    ret[i] = [];
    for (let j = 0; j < h; j++) {
      ret[i][j] = 10000;
      if (mat[i][j]) {
        if (j > 0) ret[i][j] = Math.min(ret[i][j], ret[i][j - 1] + 1);
        if (i > 0) ret[i][j] = Math.min(ret[i][j], ret[i - 1][j] + 1);
      } else {
        ret[i][j] = 0;
      }
    }
  }

  for (let i = w - 1; i >= 0; i--) {
    for (let j = h - 1; j >= 0; j--) {
      if (mat[i][j]) {
        if (i < w - 1) ret[i][j] = Math.min(ret[i][j], ret[i + 1][j] + 1);
        if (j < h - 1) ret[i][j] = Math.min(ret[i][j], ret[i][j + 1] + 1);
      }
    }
  }

  return ret;
}
