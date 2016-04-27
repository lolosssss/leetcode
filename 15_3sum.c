/**
 * Description : 3 Sum
 *               Given an array S of n integers, are there elements a, b, c
 *               in S such that a + b + c = 0? Find all unique triplets in
 *               the array which gives the sum of zero.
 *        Note : Elements in a triplet (a, b, c) must be in non-descending
 *               order.(ie, a <= b <= c)
 *               The solution set must not contain duplicate triplets.
 * Author      : Evan Lau
 * Date        : 2016/02/26
 */

#include <stdio.h>
#include <stdlib.h>

void quick_sort(int* arr, int left, int right)
{
    int i, j, t;
    int tmp;

    if (left > right)
    {
        return;
    }

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
 * Note : The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize)
{
    int **ret = NULL;
    int target = 0;
    int left = 0;
    int right = 0;

    if (numsSize < 3)
    {
        return NULL;
    }

    *returnSize = 0;
    ret = (int **)malloc(sizeof(int *) * numsSize * 2);
    for (int i = 0; i < numsSize * 2; i++)
    {
        ret[i] = malloc(sizeof(int) * 3);
    }

    quick_sort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    for (int i = 0; i < numsSize - 2;)
    {
        target = -nums[i];
        left = i + 1;
        right = numsSize - 1;

        while (left < right)
        {
            if (nums[left] + nums[right] > target)
            {
                right--;
            }
            else if (nums[left] + nums[right] < target)
            {
                left++;
            }
            else
            {
                ret[*returnSize][0] = nums[i];
                ret[*returnSize][1] = nums[left];
                ret[*returnSize][2] = nums[right];
                (*returnSize)++;
                left++;
                while (nums[left] == nums[left - 1] && left < right)
                    left++;
            }
        }

        i++;
        while (nums[i] == nums[i - 1] && i < numsSize - 2)
            i++;
    }

    return ret;
}

int main()
{
    int arr[] = {-7, -4, -6, 6, 4, -6, -9, -10, -7, 5, 3, -1, -5, 8, -1, -2, -8, -1, 5, -3, -5, 4, 2, -5, -4, 4, 7};
    int **res = NULL;
    int size;

    res = threeSum(arr, 27, &size);

    for (int i = 0; i < size; i++)
    {
        printf("(%d, %d, %d)\n", res[i][0], res[i][1], res[i][2]);
    }

    for (int i = 0; i < size; i++)
    {
        free(res[i]);
    }
    free(res);

    return 0;
}
