/**
 * Description : Single Number
 *               Given an array of integers, every element appears twice except
 *               for one. Find that single one.
 * Author      : Evan Lau
 * Date        : 2016/04/27
 */

#include <stdio.h>
#include <string.h>

int singleNumber(int* nums, int numsSize)
{
    int arr[65535];
    int n = 0;
    int i = 0;

    memset(arr, 0, sizeof(arr));

    for (i = 0; i < numsSize; i++)
    {
        if (arr[nums[i] + 10000] == 0)
        {
            arr[nums[i] + 10000] = 1;
            n += nums[i];
        }
        else
        {
            n -= nums[i];
        }
    }

    return n;
}

int main(void)
{
    int arr[] = {1, 2, 3, -1, -2, -3, 1, 2, -1, -3, -2};

    printf("%d\n", singleNumber(arr, 11));

    return 0;
}
