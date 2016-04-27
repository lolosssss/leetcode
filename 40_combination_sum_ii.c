/**
 * Description : Combination Sum II
 *               Given a collection of candidate numbers (C) and a target number
 *               (T), find all unique combinations in C where the candidate
 *               numbers sums to T. Each number in C may only be used once in
 *               the combination.
 * Author      : Evan Lau
 * Date        : 2016/04/09
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
        if (candidates[l] > target)
            break;

        while (l > pos && candidates[l] == candidates[l - 1])
            l++;

        a[dp] = candidates[l];
        dfs(candidates, l + 1, candidatesSize, target - candidates[l], \
            columSizes, i, returnSize, ans, dp + 1, a);
    }

    if (dp == 0)
    {
        *returnSize = *i;
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target,
                     int** columnSizes, int* returnSize)
{
    int i, j;
    int a[16];
    int **ret = (int **)malloc(sizeof(int *) * 128);

    *columnSizes = (int *)malloc(sizeof(int) * 128);

    for (i = 0; i < 128; i++)
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
    int c2[] = {1, 1};
    int t2 = 1;
    int c3[] = {5, 10, 8, 4, 3, 12, 9};
    int t3 = 27;
    int c4[] = {7, 12, 5, 10, 9, 4, 6, 8};
    int t4 = 32;
    int c5[] = {29,19,14,33,11,5,9,23,23,33,12,9,25,25,12,21,14,11,20,30,17,19,5,6,6,5,5,11,12,25,31,28,31,33,27,7,33,31,17,13,21,24,17,12,6,16,20,16,22,5};
    int t5 = 28;

    int **res = NULL;
    int *columSizes = NULL;
    int size = 0;

    res = combinationSum2(c1, 4, t1, &columSizes, &size);
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
    for (int i = 0; i < 128; i++)
    {
        free(res[i]);
    }
    free(res);
    free(columSizes);

    res = combinationSum2(c2, 2, t2, &columSizes, &size);
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
    for (int i = 0; i < 128; i++)
    {
        free(res[i]);
    }
    free(res);
    free(columSizes);

    res = combinationSum2(c3, 7, t3, &columSizes, &size);
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
    for (int i = 0; i < 128; i++)
    {
        free(res[i]);
    }
    free(res);
    free(columSizes);

    res = combinationSum2(c4, 8, t4, &columSizes, &size);
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
    for (int i = 0; i < 128; i++)
    {
        free(res[i]);
    }
    free(res);
    free(columSizes);

    res = combinationSum2(c5, 50, t5, &columSizes, &size);
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
    for (int i = 0; i < 128; i++)
    {
        free(res[i]);
    }
    free(res);
    free(columSizes);

    return 0;
}
