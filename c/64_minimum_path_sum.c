/**
 * Description : Minimum Path Sum
 *               Given a m x n grid filled with non-negative numbers, find a
 *               path from top left to bottom right which minimizes the sum of
 *               all numbers along its path.
 * Author      : Evan Lau
 * Date        : 2016/05/22
 */

#include <stdio.h>
#include <stdlib.h>

int min(int x, int y)
{
    return x < y ? x : y;
}

int minPathSum(int **grid, int gridRowSize, int gridColSize)
{
    int i, j;

    if (gridRowSize == 0 || gridColSize == 0)
        return 0;

    for (j = 1; j < gridColSize; j++)
        grid[0][j] += grid[0][j-1];
    for (i = 1; i < gridRowSize; i++)
        grid[i][0] += grid[i-1][0];

    for (i = 1; i < gridRowSize; i++)
    {
        for (j = 1; j < gridColSize; j++)
        {
            grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
        }
    }

    return grid[gridRowSize-1][gridColSize-1];
}

int main(void)
{
    int **grid = (int **)malloc(sizeof(int *) * 2);
    for (int i = 0; i < 2; i++)
        grid[i] = (int *)malloc(sizeof(int) * 2);

    grid[0][0] = 1;
    grid[0][1] = 2;
    grid[1][0] = 1;
    grid[1][1] = 1;

    printf("%d\n", minPathSum(grid, 2, 2));

    return 0;
}
