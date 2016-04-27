/**
 * Description : Valid Sudoku
 *               Determine if a Sudoku is valid.
 *               The Sudoku board could be partially filled, where empty cells
 *               are filled with the character '.'.
 * Author      : Evan Lau
 * Date        : 2016/03/21
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValidSudoku(char** board, int boardRowSize, int boardColSize)
{
    int row[9][9];
    int col[9][9];
    int block[9][9];
    int i, j;

    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(block, 0, sizeof(block));

    for (i = 0; i < boardRowSize; i++)
    {
        for (j = 0; j < boardColSize; j++)
        {
            if (*(*(board + i) + j) != '.')
            {
                if (row[i][*(*(board + i) + j) - '1'] == 0)
                {
                    row[i][*(*(board + i) + j) - '1'] = 1;
                }
                else
                {
                    return false;
                }

                if (col[j][*(*(board + i) + j) - '1'] == 0)
                {
                    col[j][*(*(board + i) + j) - '1'] = 1;
                }
                else
                {
                    return false;
                }

                if (block[i / 3 * 3 + j / 3][*(*(board + i) + j) - '1'] == 0)
                {
                    block[i / 3 * 3+ j / 3][*(*(board + i) + j) - '1'] = 1;
                }
                else
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main(void)
{
    char *board[9] = {
        "....5..1.",
        ".4.3.....",
        ".....3..1",
        "8......2.",
        "..2.7....",
        ".15......",
        ".....2...",
        ".2.9.....",
        "..4......"
    };
    char *board2[9] = {
        ".87654321",
        "2........",
        "3........",
        "4........",
        "5........",
        "6........",
        "7........",
        "8........",
        "9........",
    };

    if (isValidSudoku(board, 9, 9))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    if (isValidSudoku(board2, 9, 9))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    return 0;
}
