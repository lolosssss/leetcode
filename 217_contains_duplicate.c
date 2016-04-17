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
#include <assert.h>

void quickSort(int* arr, int left, int right)
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

    while (i != j)
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
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

bool containsDuplicate(int* nums, int numsSize)
{
    quickSort(nums, 0, numsSize - 1);

    int i = 1;
    while (i < numsSize)
    {
        if (nums[i] == nums[i - 1])
            return true;
        i++;
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
