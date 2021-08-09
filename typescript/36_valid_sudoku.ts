function isValidSudoku(board: string[][]): boolean {
  let rows = [{}, {}, {}, {}, {}, {}, {}, {}, {}];
  let columns = [{}, {}, {}, {}, {}, {}, {}, {}, {}];
  let grids = [{}, {}, {}, {}, {}, {}, {}, {}, {}];

  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      let v = board[i][j];
      if (v !== '.') {
        if (rows[i][v]) return false;
        rows[i][v] = true;

        if (columns[j][v]) return false;
        columns[j][v] = true;

        let grid = Math.floor(i / 3) * 3 + Math.floor(j / 3);
        if (grids[grid][v]) return false;
        grids[grid][v] = true;
      }
    }
  }

  return true;
}
