/**
 * Description : Search a 2D matrix II
 *               Write an efficient algorithm that searches for a value in an
 *               m x n matrix. This matrix has the following properties:
 *               . Integers in each row are sorted in ascending from left to
 *                 right.
 *               . Integers in each column are sorted in ascending from top to
 *                 bottom.
 * Author      : Evan Lau
 * Date        : 2016/04/26
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target)
{
    int i = 0;
    int j = matrixColSize - 1;

    while (i < matrixRowSize && j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] < target)
            i++;
        else
            j--;
    }

    return false;
}

int main(void)
{
    int **matrix = (int **)malloc(sizeof(int *) * 5);

    for (int i = 0; i < 5; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * 5);
    }

    matrix[0][0] = 1;
    matrix[0][1] = 4;
    matrix[0][2] = 7;
    matrix[0][3] = 11;
    matrix[0][4] = 15;

    matrix[1][0] = 2;
    matrix[1][1] = 5;
    matrix[1][2] = 8;
    matrix[1][3] = 12;
    matrix[1][4] = 19;

    matrix[2][0] = 3;
    matrix[2][1] = 6;
    matrix[2][2] = 9;
    matrix[2][3] = 16;
    matrix[2][4] = 22;

    matrix[3][0] = 10;
    matrix[3][1] = 13;
    matrix[3][2] = 14;
    matrix[3][3] = 17;
    matrix[3][4] = 24;

    matrix[4][0] = 18;
    matrix[4][1] = 21;
    matrix[4][2] = 23;
    matrix[4][3] = 26;
    matrix[4][4] = 30;

    printf("%d\n", searchMatrix(matrix, 5, 5, 5));
    printf("%d\n", searchMatrix(matrix, 5, 5, 20));

    for (int i = 0; i < 5; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
