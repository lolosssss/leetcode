/**
 * Description : Contains Duplicate
 *               Given an array of integers, find if the array contains any
 *               duplicates. Your function should return true if any value
 *               appears at least twice in the array, and it should return false
 *               if every element is distinct.
 * Author      : Evan Lau
 * Date        : 2016/04/17
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

bool containsDuplicate(int* nums, int numsSize)
{
    int arr[1000000];
    int i;

    memset(arr, 0, 1000000);

    for (i = 0; i < numsSize; i++)
    {
        if (arr[nums[i]] == 1)
            return true;
        arr[nums[i]] = 1;
    }

    return false;
}

int main(void)
{
    int arr1[] = {3, 3};
    int arr2[] = {};
    int arr3[] = {0};

    assert(containsDuplicate(arr1, 2) == true);
    assert(containsDuplicate(arr2, 0) == false);
    assert(containsDuplicate(arr3, 1) == false);

    printf("All passed\n");

    return 0;
}
