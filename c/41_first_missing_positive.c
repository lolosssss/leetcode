/**
 * Description : First Missing Positive
 *               Given an unsorted integer array, find the first missing
 *               positive integer.
 * Author      : Evan Lau
 * Date        : 2016/04/09
 */

#include <stdio.h>

int firstMissingPositive(int* nums, int numsSize)
{
    int arr[1000];
    int i;

    for (i = 0; i < 1000; i++)
    {
        arr[i] = 0;
    }

    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
        {
            arr[nums[i]] = 1;
        }
    }

    for (i = 1; i < 1000; i++)
    {
        if (arr[i] == 0)
        {
            return i;
        }
    }
}

int main(void)
{
    int a1[] = {1, 2, 0};
    int a2[] = {3, 4, -1, 1};

    printf("%d\n", firstMissingPositive(a1, 3));
    printf("%d\n", firstMissingPositive(a2, 4));

    return 0;
}
