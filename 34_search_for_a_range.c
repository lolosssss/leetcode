/**
 * Description : Search for a Range
 *               Given a sorted array of integers, find the starting and ending
 *               position of a given target value. Your algorithm's runtime
 *               complexity must be in the order of O(log n). If the target is
 *               not found in the array, return [-1, -1].
 * Author      : Evan Lau
 * Date        : 2016/03/21
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int *ret = (int *)malloc(sizeof(int) * 2);
    int begin = 0;
    int end = numsSize - 1;
    *returnSize = 2;

    while (nums[begin] != target && begin < numsSize)
    {
        begin++;
    }
    if (begin == numsSize)
    {
        *ret = -1;
        *(ret + 1) = -1;
        return ret;
    }
    while (nums[end] != target)
    {
        end--;
    }
    *ret = begin;
    *(ret + 1) = end;
    return ret;
}

int main(void)
{
    int arr[] = {2, 3, 4, 5, 8, 8, 9, 10};
    int *res = NULL;
    int size;

    res = searchRange(arr, 8, 8, &size);
    printf("begin at: %d\nend at: %d\n", *res, *(res + 1));
    free(res);
    res = NULL;

    return 0;
}
