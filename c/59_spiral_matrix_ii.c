/**
 * Description : Spiral Matrix II
 *               Given an integer n, generate a square matrix filled with elem-
 *               ents from 1 to n^2 in spiral order.
 * Author      : Evan Lau
 * Date        : 2016/05/08
 */

#include <stdio.h>
#include <stdlib.h>

int** generateMatrix(int n)
{
    int i;
    int row = n;
    int col = n;
    int cnt = 1;
    int x = 0;
    int y = -1;
    int **ret = (int **)malloc(sizeof(int *) * n);

    for (i = 0; i < n; i++)
    {
        ret[i] = (int *)malloc(sizeof(int) * n);
    }

    while (1)
    {
        for (i = 0; i < col; i++)
            ret[x][++y] = cnt++;
        if(--row <= 0)
            break;
        for (i = 0; i < row; i++)
            ret[++x][y] = cnt++;
        if (--col <= 0)
            break;
        for (i = 0; i < col; i++)
            ret[x][--y] = cnt++;
        if (--row <= 0)
            break;
        for (i = 0; i < row; i++)
            ret[--x][y] = cnt++;
        if(--col <= 0)
            break;
    }

    return ret;
}

int main(void)
{
    int i, j;
    int n = 6;
    int **res = generateMatrix(n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%.2d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
