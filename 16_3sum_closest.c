/**
 * Description : 3 Sum Closest
 *               Given an array S of n integers, find three integers in S such
 *               that the sum is closest to a given number, target. Return the
 *               sum of the three integer. You may assume that each input would
 *               have exactly one solution.
 * Author      : Evan Lau
 * Date        : 2016/02/26
 */

#include <stdio.h>

#define ABS(x) ((x) > 0 ? (x) : -(x))

void quick_sort(int* arr, int left, int right)
{
    int i, j, t;
    int tmp;

    if (left > right)
        return;

    tmp = arr[left];
    i = left;
    j = right;

    while (i < j)
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

    quick_sort(arr, left, i - 1);
    quick_sort(arr, i + 1, right);
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    int tmp = 0;
    int closest = 9999;
    int left = 0;
    int right = 0;

    quick_sort(nums, 0, numsSize - 1);

    for (int i = 0; i < numsSize - 2; i++)
    {
        left = i + 1;
        right = numsSize - 1;

        while (left < right)
        {
            tmp = nums[i] + nums[left] + nums[right] - target;
            if (ABS(tmp) < ABS(closest))
            {
                closest = tmp;
            }
            if (tmp > 0)
            {
                right--;
            }
            else if (tmp < 0)
            {
                left++;
            }
            else
            {
                return target;
            }
        }
    }

    return target + closest;
}

int main()
{
    int arr[3] = {0, 1, 2};

    printf("%d\n", threeSumClosest(arr, 3, 3));

    return 0;
}
