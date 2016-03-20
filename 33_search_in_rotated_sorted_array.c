/**
 * Description : Search in Rotated Sorted Array
 *               Suppose a sorted array is rotated at some pivot unknown to you
 *               beforehand. You are given a target value to search. If found in
 *               the array return its index, otherwise return -1.
 * Author      : Evan Lau
 * Date        : 2016/03/20
 */

#include <stdio.h>

int search(int* nums, int numsSize, int target)
{
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main(void)
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};

    printf("%d\n", search(arr, 7, 4));

    return 0;
}
