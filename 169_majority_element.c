/**
 * Description : Majority Element
 *               Given an array of size n, find the majority element. The
 *               majority element is the element that appears more than n/2
 *               times. You may assume that the array is non-empty and the
 *               majority element always exist in the array.
 * Author      : Evan Lau
 * Date        : 2016/03/27
 */

#include <stdio.h>

int majorityElement(int* nums, int numsSize)
{
    int ret;
    int count = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (count == 0)
        {
            ret = nums[i];
        }
        if (ret == nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return ret;
}

int main(void)
{
    int arr[] = {1, 4, 5, 1, 8, 5, 5, 5, 5, 5};

    printf("The majority element of the array is %d\n", majorityElement(arr, 10));

    return 0;
}
