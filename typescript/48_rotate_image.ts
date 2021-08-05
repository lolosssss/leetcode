function rotate(matrix: number[][]): void {
  let len = matrix.length;
  let n = len - 1;
  let m = 0;
  let half = Math.floor(len / 2);

  while (m < half) {
    for (let i = 0; i < n; i++) {
      let tmp = matrix[m][m + i];
      matrix[m][m + i] = matrix[len - m - 1 - i][m];
      matrix[len - m - 1 - i][m] = matrix[len - m - 1][len - m - 1 - i];
      matrix[len - m - 1][len - m - 1 - i] = matrix[m + i][len - m - 1];
      matrix[m + i][len - m - 1] = tmp;
    }
    n -= 2;
    m++;
  }
}

function printMatrix(matrix: number[][]): void {
  matrix.forEach((row: number[]) => {
    console.log(row);
  });
  console.log('---');
}

function createMatrix(n: number): number[][] {
  let ret = [];

  for (let i = 0; i < n; i++) {
    ret[i] = [];
    for (let j = 0; j < n; j++) {
      ret[i].push(n * i + j + 1);
    }
  }

  return ret;
}

for (let i = 0; i < 5; i++) {
  let matrix = createMatrix(i + 1);
  printMatrix(matrix);
  rotate(matrix);
  printMatrix(matrix);
}
