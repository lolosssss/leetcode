/**
 * Description : Maximal Square
 *               Given a 2D binary filled with 0's and 1's, find the largest
 *               square containing all 1's and return its area.
 * Author      : Evan Lau
 * Date        : 2016/05/28
 */

#include <stdio.h>
#include <stdlib.h>

int maximalSquare(char **matrix, int matrixRowSize, int matrixColSize)
{
    if (matrixRowSize < 1 || matrixColSize < 1)
        return 0;

    int area[matrixRowSize][matrixColSize];
    int i, j, t;
    int max = 0;

    for (i = 0; i < matrixRowSize; i++)
    {
        for (j = 0; j < matrixColSize; j++)
        {
            if (!i || !j)
            {
                area[i][j] = matrix[i][j] == '1' ? 1 : 0;
            }
            else if (matrix[i][j] == '0')
            {
                area[i][j] = 0;
            }
            else if (matrix[i-1][j] == '0' || matrix[i][j-1] == '0')
            {
                area[i][j] = 1;
            }
            else
            {
                t = area[i-1][j-1];
                if (area[i-1][j] < t)
                    t = area[i-1][j];
                if (area[i][j-1] < t)
                    t = area[i][j-1];
                area[i][j] = t + 1;
            }

            t = area[i][j]  * area[i][j];
            if (t > max)
                max = t;
        }
    }

    return max;
}

int main(void)
{
    char arr[][5] = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    char **matrix = (char **)malloc(sizeof(char *) * 4);
    for (int i = 0; i < 4; i++)
    {
        matrix[i] = arr[i];
    }

    printf("%d\n", maximalSquare(matrix, 4, 5));

    return 0;
}
