/**
 * Description : Jump Game II
 *               Given an array of non-negative integers, you are initially
 *               positioned at the first index of the array. Each element in the
 *               array represents your maximum jump length at that position.
 *               Your goal is to reach the last index in the minimum number of
 *               jumps.
 * Author      : Evan Lau
 * Date        : 2016/04/16
 */

#include <stdio.h>

int jump(int* nums, int numsSize)
{
    int step = 1;
    int stepPos = nums[0];
    int max = nums[0];
    int i = 0;

    if (numsSize == 1)
    {
        return 0;
    }

    while (max < numsSize - 1)
    {
        step++;

        while (i <= stepPos)
        {
            if (nums[i] + i > max)
            {
                max = nums[i] + i;
            }
            i++;
        }

        stepPos = max;
    }

    return step;
}

int main(void)
{
    int arr1[] = {2, 3, 1, 1, 4};
    int arr2[] = {7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3};
    int arr3[] = {1, 1, 1, 1, 1};

    printf("%d\n", jump(arr1, 5));
    printf("%d\n", jump(arr2, 15));
    printf("%d\n", jump(arr3, 5));

    return 0;
}
