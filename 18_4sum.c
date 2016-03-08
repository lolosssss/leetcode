/**
 * Description : 4 Sum
 *               Given an array S of n integers, are there elements a, b, c, and
 *               d in S such that a+b+c+d=target? Find all uniqe quadruplets in
 *               the array which gives the sum of target.
 * Author      : Evan Lau
 * Date        : 2016/03/01
 */

#include <stdio.h>
#include <stdlib.h>

void quick_sort(int* arr, int left, int right)
{
    int i, j, t;
    int tmp;

    if (left > right)
        return;

    tmp = arr[left];
    i = left;
    j = right;

    while (i < j)
    {
        while (arr[j] >= tmp && i < j)
            j--;
        while (arr[i] <= tmp && i < j)
            i++;

        if (i < j)
        {
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    arr[left] = arr[i];
    arr[i] = tmp;

    quick_sort(arr, left, i - 1);
    quick_sort(arr, i + 1, right);
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize)
{
    int left = 0;
    int right = 0;
    int** ret = NULL;

    if (numsSize < 4)
    {
        return NULL;
    }

    ret = (int**)malloc(sizeof(int*) * 64);
    for (int i = 0; i < 64; i++)
    {
        ret[i] = (int*)malloc(sizeof(int) * 4);
    }

    quick_sort(nums, 0, numsSize - 1);

    for (int i = 0; i < numsSize - 3; i++)
    {
        if (i > 0 && (*returnSize) > 0 && nums[i] == ret[(*returnSize) - 1][0])
            continue;

        for (int j = i + 1; j < numsSize - 2; j++)
        {
            if (j > i + 1 && (*returnSize) > 0 && nums[i] == ret[(*returnSize) - 1][0] && nums[j] == ret[(*returnSize) - 1][1])
                continue;

            left = j + 1;
            right = numsSize - 1;

            while (left < right)
            {
                if (nums[i] + nums[j] + nums[left] + nums[right] < target)
                {
                    left++;
                }
                else if (nums[i] + nums[j] + nums[left] + nums[right] > target)
                {
                    right--;
                }
                else
                {
                    ret[*returnSize][0] = nums[i];
                    ret[*returnSize][1] = nums[j];
                    ret[*returnSize][2] = nums[left];
                    ret[*returnSize][3] = nums[right];
                    (*returnSize)++;
                    left++;
                    while (nums[left] == nums[left - 1] && left < right)
                        left++;
                }
            }
        }
    }

    return ret;
}

int main(void)
{
    int nums[] = {-4, -1, 0, -5, -2, 5, 0, 2};
    //int nums[] = {-4, 2, -11, -5, 7, 8, 9, 5, -11, -8};
    int** res = NULL;
    int size = 0;

    res = fourSum(nums, 8, 3, &size);

    if (res == NULL)
    {
        printf("zero\n");
        return 1;
    }

    if (size == 0)
    {
        printf("empty\n");
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d %d %d %d\n", res[i][0], res[i][1], res[i][2], res[i][3]);
        }
    }

    for (int i = 0; i < 64; i++)
    {
        free(res[i]);
        res[i] = NULL;
    }

    free(res);
    res = NULL;

    return 0;
}
