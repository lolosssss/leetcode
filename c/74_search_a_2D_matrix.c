/**
 * Description : Search a 2D Matrix
 *               Write an efficient algorithm that searches for a value in an
 *               m x n matrix.
 * Author      : Evan Lau
 * Date        : 2016/05/23
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool searchMatrix(int **matrix, int matrixRowSize, int matrixColSize,
                  int target)
{
    int i = 0;
    int j = matrixColSize - 1;

    while (1)
    {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] < target)
        {
            if (i == matrixRowSize - 1)
                return false;
            else
                i++;
        }
        else
        {
            j--;
            if (j < 0)
                return false;
        }
    }
}

int main(void)
{
    int **arr = (int **)malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * 4);
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = i * 4 + j;
        }
    }

    printf("%d\n", searchMatrix(arr, 3, 4, 12));
    printf("%d\n", searchMatrix(arr, 3, 4, 10));

    return 0;
}
