/**
 * Description : Jump Game
 *               Given an array of non-negative integers, you are initially
 *               positioned at the first index of the array. Each element in the
 *               array represents your maximum jump length at that position.
 *               Determine if you are albe to reach the last index.
 * Author      : Evan Lau
 * Date        : 2016/04/16
 */

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool canJump(int* nums, int numsSize)
{
    int i;
    int pos = 0;

    if (numsSize == 1)
        return true;

    for (i = 0; i < numsSize - 1; i++)
    {
        if (pos >= i)
        {
            if (nums[i] + i > pos)
                pos = nums[i] + i;
            if (pos >= numsSize - 1)
                return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

int main(void)
{
    int arr1[] = {2, 3, 1, 1, 4};
    int arr2[] = {3, 2, 1, 0, 4};
    int arr3[] = {0, 2, 3};
    int arr4[] = {0};
    int arr5[] = {3, 0, 8, 2, 0, 0, 1};

    assert(canJump(arr1, 5) == true);
    assert(canJump(arr2, 5) == false);
    assert(canJump(arr3, 3) == false);
    assert(canJump(arr4, 1) == true);
    assert(canJump(arr5, 7) == true);

    printf("All passed\n");

    return 0;
}
