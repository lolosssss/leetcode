/**
 * Description : Find the Duplicate Number
 *               Given an array nums containing n + 1 integers where each inte-
 *               ger is between 1 and n(inclusive), prove that at least one dup-
 *               licate number must exist. Assume that there is only one duplic-
 *               ate number, find the duplicate one.
 * Author      : Evan Lau
 * Date        : 2016/05/01
 */

#include <stdio.h>
#include <string.h>

int findDuplicate(int* nums, int numsSize)
{
    int arr[numsSize];
    int i;

    memset(arr, 0, sizeof(arr));

    for (i = 0; i < numsSize; i++)
    {
        if (arr[nums[i]] == 1)
        {
            return nums[i];
        }
        arr[nums[i]] = 1;
    }

    return 0;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 3, 6};

    printf("%d\n", findDuplicate(arr, 7));

    return 0;
}
