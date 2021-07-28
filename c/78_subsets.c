/**
 * Description : Subsets
 *               Given a set of distinct integers, nums, return all possible
 *               subsets.
 * Author      : Evan Lau
 * Date        : 2016/05/04
 */

#include <stdio.h>
#include <stdlib.h>

void dfs(int* nums, int numsSize, int** columnSizes, int* returnSize,
         int* stack, int top, int** res)
{
    if (numsSize == top)
    {
        int i, cnt = 0;
        (*columnSizes)[*returnSize] = 0;

        for (i = 0; i < top; i++)
        {
            (*columnSizes)[*returnSize] += stack[i];
        }
        res[*returnSize] = (int *)malloc(sizeof(int) * (*columnSizes)[*returnSize]);
        for (i = 0; i < top; i++)
        {
            if (stack[i] == 1)
                res[*returnSize][cnt++] = nums[i];
        }
        (*returnSize)++;
        return;
    }

    stack[top++] = 0;
    dfs(nums, numsSize, columnSizes, returnSize, stack, top, res);
    top--;
    stack[top++] = 1;
    dfs(nums, numsSize, columnSizes, returnSize, stack, top, res);
    top--;
}

void quickSort(int* nums, int start, int end)
{
    if (start >= end)
        return;

    int i = start - 1;
    int x = nums[end];
    int j;
    int tmp;
    for (j = start; j < end; j++)
    {
        if (nums[j] <= x)
        {
            i++;
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }

    tmp = nums[i+1];
    nums[i+1] = nums[j];
    nums[j] = tmp;
    quickSort(nums, start, i);
    quickSort(nums, i + 2, end);
}

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize)
{
    int **ret = (int **)malloc(sizeof(int *) * 5000);
    *columnSizes = (int *)malloc(sizeof(int) * 5000);
    *returnSize = 0;
    int stack[numsSize];
    int top = 0;
    quickSort(nums, 0, numsSize - 1);
    dfs(nums, numsSize, columnSizes, returnSize, stack, top, ret);

    return ret;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 0};
    int **res = NULL;
    int size = 0;
    int *columnSizes = NULL;

    res = subsets(arr, 10, &columnSizes, &size);
    printf("size = %d\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("[");
        for (int j = 0; j < columnSizes[i]; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("]\n");
    }

    return 0;
}
