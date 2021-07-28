/**
 * Description : Triangle
 *               Given a triangle, find the minimum path sum from top to bottom.
 *               Each step you may move to adjacent numbers on the row below.
 * Author      : Evan Lau
 * Date        : 2016/04/30
 */

#include <stdio.h>
#include <stdlib.h>

int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes)
{
    int i, j;
    int min;
    int arr[triangleRowSize][triangleRowSize];

    if (triangleRowSize == 1)
    {
        return triangle[0][0];
    }

    arr[0][0] = triangle[0][0];
    for (i = 1; i < triangleRowSize - 1; i++)
    {
        arr[i][0] = arr[i-1][0] + triangle[i][0];
        arr[i][triangleColSizes[i]-1] = arr[i-1][triangleColSizes[i]-2] + \
                triangle[i][triangleColSizes[i]-1];
        for (j = 1; j < triangleColSizes[i] - 1; j++)
        {
            if (arr[i-1][j-1] < arr[i-1][j])
            {
                arr[i][j] = arr[i-1][j-1] + triangle[i][j];
            }
            else
            {
                arr[i][j] = arr[i-1][j] + triangle[i][j];
            }
        }
    }

    arr[i][0] = arr[i-1][0] + triangle[i][0];
    min = arr[i][0];
    arr[i][triangleColSizes[i]-1] = arr[i-1][triangleColSizes[i]-2] + \
            triangle[i][triangleColSizes[i]-1];
    if (arr[i][triangleColSizes[i] - 1] < min)
    {
        min = arr[i][triangleColSizes[i] - 1];
    }
    for (j = 1; j < triangleColSizes[i] - 1; j++)
    {
        if (arr[i-1][j-1] < arr[i-1][j])
        {
            arr[i][j] = arr[i-1][j-1] + triangle[i][j];
        }
        else
        {
            arr[i][j] = arr[i-1][j] + triangle[i][j];
        }
        if (arr[i][j] < min)
        {
            min = arr[i][j];
        }
    }

    return min;
}

int main(void)
{
    int triangleColSizes[] = {1, 2, 3, 4};
    int **triangle = (int **)malloc(sizeof(int *) * 4);

    for (int i = 0; i < 4; i++)
    {
        triangle[i] = (int *)malloc(sizeof(int) * triangleColSizes[i]);
    }

    triangle[0][0] = 2;
    triangle[1][0] = 3;
    triangle[1][1] = 4;
    triangle[2][0] = 6;
    triangle[2][1] = 5;
    triangle[2][2] = 7;
    triangle[3][0] = 4;
    triangle[3][1] = 1;
    triangle[3][2] = 8;
    triangle[3][3] = 3;

    printf("%d\n", minimumTotal(triangle, 4, triangleColSizes));

    return 0;
}
