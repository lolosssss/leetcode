/**
 * Description : Remove Duplicates from Sorted Array II
 * Author      : Evan Lau
 * Date        : 2016/05/24
 */

#include <stdio.h>

int removeDuplicates(int *nums, int numsSize)
{
    int arr[1000] = {0};
    int i = 0;
    int j = 0;

    for (i = 0; i < numsSize; i++)
    {
        arr[nums[i]+100]++;
        if (arr[nums[i]+100] < 3)
        {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int main(void)
{
    int arr[] = {1, 1, 1};
    int size;

    size = removeDuplicates(arr, 3);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
