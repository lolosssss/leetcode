/**
 * Description : Maximum Subarray
 *               Find the contiguous subarray within an array (containing at
 *               least one number) which has the largest sum.
 * Author      : Evan Lau
 * Date        : 2016/04/15
 */

#include <stdio.h>
#include <assert.h>

int maxSubarray(int* nums, int numsSize)
{
    int max = nums[0];
    int sum = 0;
    int i;

    for (i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        if (sum > max)
        {
            max = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }

    return max;
}

int main(void)
{
    int arr1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int arr2[] = {0};

    assert(maxSubarray(arr1, 9) == 6);
    assert(maxSubarray(arr2, 1) == 0);

    printf("All passed\n");

    return 0;
}
