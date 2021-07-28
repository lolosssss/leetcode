/**
 * Description : Move Zeroes
 *               Given an array nums, write a function to move all 0's to the
 *               end of it while maintaining the relative order of the non-zero
 *               elements.
 *               For example, given nums = [0, 1, 0, 3, 12], after calling your
 *               function, nums should be [1, 3, 12, 0, 0].
 * Author      : Evan Lau
 * Date        : 2016/03/27
 */

#include <stdio.h>

void moveZeroes(int* nums, int numsSize)
{
    int i = 0;
    int j = 0;

    while (i < numsSize && j < numsSize)
    {
        if (nums[i] == 0)
        {
            j = i;
            while (nums[j] == 0)
            {
                j++;
                if (j >= numsSize)
                {
                    return;
                }
            }
            nums[i] = nums[j];
            nums[j] = 0;
        }
        i++;
    }
}

int main(void)
{
    int arr1[] = {0, 1, 0, 3, 12};
    int arr2[] = {1, 2, 3, 4, 5};
    int arr3[] = {0, 0, 0, 0, 1};
    int arr4[] = {1, 0};

    moveZeroes(arr1, 5);
    moveZeroes(arr2, 5);
    moveZeroes(arr3, 5);
    moveZeroes(arr4, 2);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    for (int i = 0; i < 2; i++)
    {
        printf("%d ", arr4[i]);
    }
    printf("\n");

    return 0;
}
