/**
 * Description : House Robber
 *               You are a professional robber to rob houses along a street.
 *               Each house has a certain amount of money stashed, the only
 *               constraint stopping you from robbing each of them is that
 *               adjacent houses have security system connected and it will
 *               automatically contact the police if two adjacent houses were
 *               broken into on the same night. Given a list of non-negative
 *               integers representing the amount of money of each house, deter-
 *               mine the maximum amount of money you can rob tonight without
 *               alerting the police.
 * Author      : Evan Lau
 * Date        : 2016/04/12
 */

#include <stdio.h>

int rob(int* nums, int numsSize)
{
    if (numsSize == 0)
    {
        return 0;
    }

    if (numsSize == 1)
    {
        return nums[0];
    }

    int arr[numsSize];
    int i;

    for (int i = 0; i < numsSize; i++)
    {
        arr[i] = 0;
    }


    for (i = 0; i < numsSize; i++)
    {
        if (i - 2 < 0 && i - 3 < 0)
        {
            arr[i] = nums[i];
        }
        else
        {
            if (i - 3 < 0)
            {
                arr[i] = arr[i - 2] + nums[i];
            }
            else
            {
                if (arr[i - 2] > arr[i - 3])
                {
                    arr[i] = arr[i - 2] + nums[i];
                }
                else
                {
                    arr[i] = arr[i - 3] + nums[i];
                }
            }
        }
    }

    if (arr[i - 1] > arr[i - 2])
    {
        return arr[i - 1];
    }
    else
    {
        return arr[i - 2];
    }
}

int main(void)
{
    int arr1[] = {1, 3, 2, 4, 5, 8, 7};
    int arr2[] = {1, 1, 1};
    int arr3[] = {0};

    printf("%d\n", rob(arr1, 7));
    printf("%d\n", rob(arr2, 3));
    printf("%d\n", rob(arr3, 1));

    return 0;
}
