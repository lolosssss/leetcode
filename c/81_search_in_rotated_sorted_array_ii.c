/**
 * Description : Search in Rotated Sorted Array II
 * Author      : Evan Lau
 * Date        : 2016/04/24
 */

#include <stdio.h>
#include <stdbool.h>

bool search(int* nums, int numsSize, int target)
{
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == target)
        {
            return true;
        }
    }

    return false;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 11, 11, 12};

    printf("%d\n", search(arr, sizeof(arr), 10));

    return 0;
}
