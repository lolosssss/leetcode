/**
 * Description : N-Queens
 *               The n-queens puzzle is the problem of placing n queens on an
 *               nxn chessboard such that no two queens attack each other.
 * Author      : Evan Lau
 * Date        : 2016/04/13
 */

#include <stdio.h>
#include <stdlib.h>

#define ABS(x) ((x) >= 0 ? (x) : -(x))

int check(int* sol, int* nums, int pos, int n)
{
    if (pos == 0)
    {
        return 0;
    }
    if (nums[n] == 0)
    {
        return -1;
    }
    for (int i = 0; i < pos; i++)
    {
        if (ABS(n - sol[i]) == ABS(pos - i))
        {
            return -1;
        }
    }

    return 0;
}

void dfs(int n, int* sol, int* nums, char*** ret, int* size, int dp)
{
    int i, j;

    if (dp == n)
    {
        ret[*size] = (char **)malloc(sizeof(char *) * n);
        for (i = 0; i < n; i++)
        {
            ret[*size][i] = (char *)malloc(sizeof(char) * (n + 1));
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (j == sol[i])
                {
                    ret[*size][i][j] = 'Q';
                }
                else
                {
                    ret[*size][i][j] = '.';
                }
            }
            ret[*size][i][j] = '\0';
        }

        (*size)++;
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (check(sol, nums, dp, i) == 0)
        {
            sol[dp] = i;
            nums[i] = 0;
            dfs(n, sol, nums, ret, size, dp + 1);
            nums[i] = 1;
        }
    }
}

char*** solveNQueens(int n, int* returnSize)
{
    char*** ret = (char ***)malloc(sizeof(char **) * 2048);
    int* sol = (int *)malloc(sizeof(int) * n);
    int* nums = (int *)malloc(sizeof(int) * n);

    *returnSize = 0;
    for (int i = 0; i < n; i++)
    {
        nums[i] = 1;
    }

    dfs(n, sol, nums, ret, returnSize, 0);

    return ret;
}

int main(void)
{
    int size;
    int n = 5;
    int i;
    int row, col;
    char*** res = solveNQueens(n, &size);

    printf("size = %d\n", size);
    for (i = 0; i < size; i++)
    {
        for (row = 0; row < n; row++)
        {
            for (col = 0; col < n; col++)
            {
                printf("%c ", res[i][row][col]);
            }
            printf("\n");
            free(res[i][row]);
        }
        printf("\n");
        free(res[i]);
    }
    free(res);

    return 0;
}
