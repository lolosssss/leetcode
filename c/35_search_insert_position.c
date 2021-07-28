/**
 * Description : Search Insert Position
 *               Given a sorted array and a target value, return the index if
 *               the target is found. If not, return the index where it would be
 *               if it were inserted in order. You may assume no duplicates in
 *               the array.
 * Author      : Evan Lau
 * Date        : 2016/03/21
 */

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target)
{
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == target)
        {
            return i;
        }
        if (nums[i] > target)
        {
            if (i == 0)
            {
                return 0;
            }
            else
            {
                return i;
            }
        }
    }

    return numsSize;
}

int main(void)
{
    int arr[] = {1, 3, 5, 6};
    int targets[] = {5, 2, 7, 0};
    int res[4];
    int i;

    for (i = 0; i < 4; i++)
    {
        res[i] = searchInsert(arr, 4, targets[i]);
    }

    for (i = 0; i < 4; i++)
    {
        printf("%d\n", res[i]);
    }

    return 0;
}
