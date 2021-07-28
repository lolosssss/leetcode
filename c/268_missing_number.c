/**
 * Description : Missing Number
 *               Given an array containing n distinct numbers taken from 0, 1,
 *               2, ..., n, find the one that is missing from the array.
 * Author      : Evan Lau
 * Date        : 2016/04/11
 */

#include <stdio.h>

int missingNumber(int* nums, int numsSize)
{
    int arr[numsSize + 1];
    int i;

    for (i = 0; i < numsSize + 1; i++)
    {
        arr[i] = 0;
    }

    for (i = 0; i < numsSize; i++)
    {
        arr[nums[i]] = 1;
    }

    for (i = 0; i < numsSize + 1; i++)
    {
        if (arr[i] == 0)
        {
            return i;
        }
    }

    return numsSize + 1;
}

int main(void)
{
    int arr1[] = {0, 1, 3};
    int arr2[] = {1, 0};
    int arr3[] = {1};

    printf("%d\n", missingNumber(arr1, 3));
    printf("%d\n", missingNumber(arr2, 2));
    printf("%d\n", missingNumber(arr3, 1));
}
