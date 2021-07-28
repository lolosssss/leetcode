/**
 * Description : Contains Duplicate II
 *               Given an array of integers and an integer k, find out whether
 *               there are two distinct indices i and j in the array such that
 *               nums[i] = nums[j] and the difference between i and j is at most
 *               k.
 * Author      : Evan Lau
 * Date        : 2016/05/06
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
    int arr[1000];
    int i;

    memset(arr, 0, sizeof(arr));

    for (i = 0; i < numsSize; i++)
    {
        if (arr[nums[i] + 100] == 0)
        {
            arr[nums[i] + 100] = i + 1;
        }
        else
        {
            if (i + 1 - arr[nums[i] + 100] <= k)
            {
                return true;
            }
            else
            {
                arr[nums[i] + 100] = i + 1;
            }
        }
    }
    return false;
}

int main(void)
{
    int arr[] = {1, 0, 1, 1};

    printf("%d\n", containsNearbyDuplicate(arr, 4, 1));

    return 0;
}
