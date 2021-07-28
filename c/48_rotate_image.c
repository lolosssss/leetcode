/**
 * Description : Rotate Image
 *               You are given an n x n 2D  matrix representing an image. Rotate
 *               the image by 90 degrees (clockwise).
 * Author      : Evan Lau
 * Date        : 2016/04/13
 */

#include <stdio.h>
#include <stdlib.h>

void rotate(int** matrix, int matrixRowSize, int matrixColSize)
{
    int i, j;
    int tmp;

    for (i = 0; i < matrixRowSize - 1; i++)
    {
        for (j = i + 1; j < matrixColSize; j++)
        {
            if (i != j)
            {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }

    for (i = 0; i < matrixRowSize; i++)
    {
        for (j = 0; j < matrixColSize / 2; j++)
        {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixColSize - j - 1];
            matrix[i][matrixColSize - j - 1] = tmp;
        }
    }
}

int main(void)
{
    int** arr = NULL;
    int i, j;

    arr = (int **)malloc(sizeof(int *) * 10);
    for (i = 0; i < 10; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * 10);
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            arr[i][j] = i * 10 + j;
        }
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%.2d ", arr[i][j]);
        }
        printf("\n");
    }

    rotate(arr, 10, 10);
    printf("After rotate:\n");

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%.2d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
