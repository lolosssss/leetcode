/**
 * Description : Combination Sum
 *               Given a set of candidate numbers (C) and a target number (T),
 *               find all unique combinations in C where the candidate numbers
 *               sums to T. The same repeated number may be chosen from C
 *               unlimited number of times.
 * Author      : Evan Lau
 * Date        : 2016/03/25
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 *       caller calls free().
 */

void dfs(int* candidates, int pos, int candidatesSize, int target,
        int** columSizes, int* i, int* returnSize, int **ans, int dp, int* a)
{
    if (target == 0)
    {
        for (int l = 0; l < dp; l++)
        {
            ans[*i][l] = a[l];
        }
        (*columSizes)[*i] = dp;
        (*i)++;
        return;
    }

    if (candidates[pos] > target)
    {
        return;
    }

    for (int l = pos; l < candidatesSize; l++)
    {
        a[dp] = candidates[l];
        dfs(candidates, l, candidatesSize, target - candidates[l], \
            columSizes, i, returnSize, ans, dp + 1, a);
    }

    if (dp == 0)
    {
        *returnSize = *i;
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int** columnSizes, int* returnSize)
{
    int i, j;
    int a[16];
    int **ret = (int **)malloc(sizeof(int *) * 256);

    *columnSizes = (int *)malloc(sizeof(int) * 256);

    for (i = 0; i < 256; i++)
    {
        ret[i] = (int *)malloc(sizeof(int) * 16);
    }

    for (i = 0; i < candidatesSize - 1; i++)
    {
        for (j = i + 1; j < candidatesSize; j++)
        {
            if (candidates[i] > candidates[j])
            {
                int tmp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = tmp;
            }
        }
    }

    i = 0;
    dfs(candidates, 0, candidatesSize, target, \
        columnSizes, &i, returnSize, ret, 0, a);

    return ret;
}

int main(void)
{
    int c1[] = {2, 3, 6, 7};
    int t1 = 7;
    int c2[] = {5, 4, 3, 2, 1};
    int t2 = 5;
    int c3[] = {5, 10, 8, 4, 3, 12, 9};
    int t3 = 27;
    int c4[] = {7, 12, 5, 10, 9, 4, 6, 8};
    int t4 = 32;

    int **res = NULL;
    int *columSizes = NULL;
    int size = 0;

    res = combinationSum(c1, 4, t1, &columSizes, &size);
    printf("size : %d\n", size);
    printf("Begin:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < columSizes[i]; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    printf("End\n");
    for (int i = 0; i < 256; i++)
    {
        free(res[i]);
    }
    free(res);
    free(columSizes);

    res = combinationSum(c2, 5, t2, &columSizes, &size);
    printf("size : %d\n", size);
    printf("Begin:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < columSizes[i]; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    printf("End\n");
    for (int i = 0; i < 256; i++)
    {
        free(res[i]);
    }
    free(res);
    free(columSizes);

    res = combinationSum(c3, 7, t3, &columSizes, &size);
    printf("size : %d\n", size);
    printf("Begin:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < columSizes[i]; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    printf("End\n");
    for (int i = 0; i < 256; i++)
    {
        free(res[i]);
    }
    free(res);
    free(columSizes);

    res = combinationSum(c4, 8, t4, &columSizes, &size);
    printf("size : %d\n", size);
    printf("Begin:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < columSizes[i]; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    printf("End\n");
    for (int i = 0; i < 256; i++)
    {
        free(res[i]);
    }
    free(res);
    free(columSizes);

    return 0;
}
