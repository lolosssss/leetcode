/**
 * Description : Remove Duplicates from Sorted Array
 *               Given a sorted array, remove the duplicates in place such that
 *               each element appear only once and return the new length.
 *               Do not allocate extra space for another array, you must do this
 *               in place with constant memory.
 * Author      : Evan Lau
 * Date        : 2016/03/09
 */

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
    int index = 0;

    if (numsSize == 0)
        return 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != nums[index])
        {
            nums[++index] = nums[i];
        }
    }

    return index + 1;
}

int main(void)
{
    int arr[10] = {1, 1, 1, 2, 2, 2, 3, 3, 4, 5};
    int len = removeDuplicates(arr, 0);

    printf("len = %d\n", len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
