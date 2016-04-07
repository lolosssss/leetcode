/**
 * Description : Sudoku Solver
 *               write a program to solve a Sudoku puzzle by filling the empty
 *               cells. Empty cells are indicated by the character '.'
 *               You may assume that there will be only one unique solution.
 * Author      : Evan Lau
 * Date        : 2016/04/01
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void readSudoku(char ** board, int known[9][9],
                int row[9][9], int col[9][9], int block[9][9])
{
    int i, j;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                known[i][j] = 1;
                row[i][board[i][j] - '1'] = 1;
                col[j][board[i][j] - '1'] = 1;
                block[i / 3 * 3 + j / 3][board[i][j] - '1'] = 1;
            }
        }
    }
}

int cleanCell(char** board, int row[9][9], int col[9][9], int block[9][9],
              int i, int j)
{
    int n;
    if (board[i][j] != '.')
    {
        n = board[i][j] - '0';
        row[i][board[i][j] - '1'] = 0;
        col[j][board[i][j] - '1'] = 0;
        block[i / 3 * 3 + j / 3][board[i][j] - '1'] = 0;
        board[i][j] = '.';
    }
    else
    {
        n = 0;
    }

    return n;
}

bool isAvailable(int row[9][9], int col[9][9], int block[9][9],
                 int i, int j, int n)
{
    return row[i][n-1] == 0 && col[j][n-1] == 0 && block[i/3*3+j/3][n-1] == 0;
}

bool setCell(char** board, int row[9][9], int col[9][9], int block[9][9],
            int i, int j)
{
    int n = cleanCell(board, row, col, block, i, j);

    while (++n <= 9)
    {
        if (isAvailable(row, col, block, i, j, n))
        {
            board[i][j] = n + '0';
            row[i][n - 1] = 1;
            col[j][n - 1] = 1;
            block[i / 3 * 3 + j / 3][n - 1] = 1;
            return true;
        }
    }

    return false;
}

void solveSudoku(char** board, int boardRowSize, int boardColSize)
{
    int col[9][9];
    int row[9][9];
    int block[9][9];
    int pos = 0;
    int known[9][9];

    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(block, 0, sizeof(block));
    memset(known, 0, sizeof(known));

    readSudoku(board, known, row, col, block);

    while (1)
    {
        while (pos < 81 && known[pos / 9][pos % 9])
        {
            pos++;
        }

        if (pos >= 81)
        {
            break;
        }

        if (setCell(board, row, col, block, pos / 9, pos % 9))
        {
            pos++;
        }
        else
        {
            do
            {
                pos--;
            } while (pos >= 0 && known[pos / 9][pos % 9]);
            if (pos < 0)
            {
                break;
            }
        }
    }
}

void printSudoku(char** board)
{
    int i, j;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (j == 3 || j == 6)
            {
                printf("| ");
            }
            printf("%c ", board[i][j]);
        }
        printf("\n");
        if (i == 2 || i == 5)
        {
            printf("- - - - - - - - - - - -\n");
        }
    }
}

int main(void)
{
    char* board[9];
    char* board2[9];
    char* tmp[9] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };
    char* hard[9] = {
        "8........",
        "..36.....",
        ".7..9.2..",
        ".5...7...",
        "....457..",
        "...1...3.",
        "..1....68",
        "..85...1.",
        ".9....4.."
    };

    for (int i = 0; i < 9; i++)
    {
        board[i] = (char *)malloc(sizeof(char) * 9);
        board2[i] = (char *)malloc(sizeof(char) * 9);
        memcpy(board[i], tmp[i], 9);
        memcpy(board2[i], hard[i], 9);
    };

    printSudoku(board);
    solveSudoku(board, 9, 9);
    printf("\nSolved\n");
    printSudoku(board);

    printf("\n\n");
    printSudoku(board2);
    solveSudoku(board2, 9, 9);
    printf("\nSolved\n");
    printSudoku(board2);

    for (int i = 0; i < 9; i++)
    {
        free(board[i]);
        free(board2[i]);
    }

    return 0;
}
