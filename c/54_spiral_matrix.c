/**
 * Description : Spiral Matrix
 *               Given a matrix of m x n elements (m rows, n columns), return
 *               all elements of the matrix in spiral order.
 * Author      : Evan Lau
 * Date        : 2016/04/13
 */

#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize)
{
    int* ret = (int *)malloc(sizeof(int) * matrixRowSize * matrixColSize);
    int i;
    int count = 0;
    int m = 0;
    int n = -1;

    while (1)
    {
        for (i = 0; i < matrixColSize; i++)
        {
            ret[count++] = matrix[m][++n];
        }
        if (--matrixRowSize <= 0)
        {
            break;
        }

        for (i = 0; i < matrixRowSize; i++)
        {
            ret[count++] = matrix[++m][n];
        }
        if (--matrixColSize <= 0)
        {
            break;
        }

        for (i = 0; i < matrixColSize; i++)
        {
            ret[count++] = matrix[m][--n];
        }
        if (--matrixRowSize <= 0)
        {
            break;
        }

        for (i = 0; i < matrixRowSize; i++)
        {
            ret[count++] = matrix[--m][n];
        }
        if (--matrixColSize <= 0)
        {
            break;
        }
    }

    return ret;
}

int main(void)
{
    int** arr = NULL;
    int i, j;
    int* res = NULL;

    arr = (int **)malloc(sizeof(int *) * 3);
    for (i = 0; i < 3; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * 3);
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            arr[i][j] = i * 3 + j;
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    res = spiralOrder(arr, 3, 3);

    for (i = 0; i < 9; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
