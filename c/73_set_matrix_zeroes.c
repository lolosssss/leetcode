/**
 * Description : Set Matrix Zeroes
 *               Given a m x n matrix, if an element is 0, set its entire row
 *               and column to 0. Do it in place.
 * Author      : Evan Lau
 * Date        : 2016/05/05
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize)
{
    int row[matrixRowSize];
    int col[matrixColSize];
    int i, j;

    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));

    for (i = 0; i < matrixRowSize; i++)
    {
        for (j = 0; j < matrixColSize; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (i = 0; i < matrixRowSize; i++)
    {
        if (row[i] == 1)
        {
            for (j = 0; j < matrixColSize; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    for (j = 0; j < matrixColSize; j++)
    {
        if (col[j] == 1)
        {
            for (i = 0; i < matrixRowSize; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main(void)
{
    int **matrix = (int **)malloc(sizeof(int *) * 1);
    matrix[0] = (int *)malloc(sizeof(int) * 2);

    matrix[0][0] = 0;
    matrix[0][1] = 1;

    setZeroes(matrix, 1, 2);

    for (int i = 0; i < 2; i++)
    {
        printf("%d ", matrix[0][i]);
    }
    printf("\n");

    return 0;
}
