/**
 * Description : Permutations
 *               Given a collection of distinct numbers, return all possible
 *               permutations.
 * Author      : Evan Lau
 * Date        : 2016/04/13
 */

#include <stdio.h>
#include <stdlib.h>

void fun(int *nums, int numsSize, int *tmp, int *arr,
         int **res, int *i, int dp)
{
    int l;

    if (dp == numsSize)
    {
        for (l = 0; l < numsSize; l++)
        {
            res[*i][l] = tmp[l];
        }
        (*i)++;
        return;
    }

    for (l = 0; l < numsSize; l++)
    {
        if (arr[l] == 1)
        {
            tmp[dp] = nums[l];
            arr[l] = 0;
            fun(nums, numsSize, tmp, arr, res, i, dp + 1);
            arr[l] = 1;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize)
{
    int i;
    int arr[numsSize];
    int tmp[numsSize];
    int** ret = NULL;

    i = numsSize;
    *returnSize = 1;
    while (i)
    {
        *returnSize *= i--;
    }

    ret = (int **)malloc(sizeof(int *) * *returnSize);
    for (i = 0; i < *returnSize; i++)
    {
        ret[i] = (int *)malloc(sizeof(int) * numsSize);
    }

    for (i = 0; i < numsSize; i++)
    {
        arr[i] = 1;
    }

    i = 0;
    fun(nums, numsSize, tmp, arr, ret, &i, 0);

    return ret;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int **res = NULL;
    int size = 0;
    int i, j;

    res = permute(arr, 3, &size);
    printf("size = %d\n", size);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
        free(res[i]);
    }
    free(res);

    res = permute(arr, 4, &size);
    printf("\nsize = %d\n", size);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
        free(res[i]);
    }
    free(res);

    res = permute(arr, 5, &size);
    printf("\nsize = %d\n", size);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
        free(res[i]);
    }
    free(res);

    return 0;
}
