/**
 * Description : N Queens II
 *               Follow up for N Queens problem. Now, instead outputting board
 *               configurations, return the total number of distinct solutions.
 * Author      : Evan Lau
 * Date        : 2016/04/15
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

void dfs(int n, int* sol, int* nums, int *size, int dp)
{
    if (dp == n)
    {
        (*size)++;
    }
    for (int i = 0; i < n; i++)
    {
        if (check(sol, nums, dp, i) == 0)
        {
            sol[dp] = i;
            nums[i] = 0;
            dfs(n, sol, nums, size, dp + 1);
            nums[i] = 1;
        }
    }
}

int totalNQueens(int n)
{
    int* sol = (int *)malloc(sizeof(int) * n);
    int* nums = (int *)malloc(sizeof(int) * n);
    int ret = 0;

    for (int i = 0; i < n; i++)
    {
        nums[i] = 1;
    }

    dfs(n, sol, nums, &ret, 0);

    return ret;
}

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d : %d\n", i, totalNQueens(i));
    }

    return 0;
}
