/**
 * Description : Permutations II
 *               Given a collection of numbers that might contain duplicates,
 *               return all possible unique permutations.
 * Author      : Evan Lau
 * Date        : 2016/05/18
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *nums, int m, int n)
{
    int tmp = nums[m];
    nums[m] = nums[n];
    nums[n] = tmp;
}

void recursive(int *nums, int start, int end, int ***ret, int *returnSize,
               int numsSize)
{
    int i;
    if (start == end)
    {
        for (i = 0; i < *returnSize; i++)
        {
            if (memcmp(nums, (*ret)[i], numsSize * sizeof(int)) == 0)
                return;
        }

        int *t = (int *)malloc(sizeof(int) * numsSize);
        memcpy(t, nums, numsSize * sizeof(int));
        (*returnSize)++;
        *ret = realloc(*ret, sizeof(int *) * (*returnSize));
        (*ret)[*returnSize-1] = t;
        return;
    }

    for (i = start; i <= end; i++)
    {
        swap(nums, start, i);
        recursive(nums, start + 1, end, ret, returnSize, numsSize);
        swap(nums, start, i);
    }
}

int **permuteUnique(int *nums, int numsSize, int *returnSize)
{
    int **ret = NULL;
    *returnSize = 0;
    recursive(nums, 0, numsSize - 1, &ret, returnSize, numsSize);

    return ret;
}

int main(void)
{
    int arr[] = {1, 1, 2};
    int **res = NULL;
    int size = 0;
    int i, j;

    res = permuteUnique(arr, 3, &size);
    for (i = 0; i < size; i++)
    {
        printf("[");
        for (j = 0; j < 3; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("]\n");
    }

    return 0;
}
