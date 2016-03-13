/**
 * Description : Rotate Array
 *               Rotate an array of n elements to the right by k steps.
 * Author      : Evan Lau
 * Date        : 2016/03/13
 */

#include <stdio.h>

void rotate(int* nums, int numsSize, int k)
{
    int begin = 0;
    int end = numsSize - 1;
    int tmp;

    if (k % numsSize == 0)
    {
        return;
    }

    k = k % numsSize;

    while (begin < end)
    {
        tmp = nums[begin];
        nums[begin] = nums[end];
        nums[end] = tmp;
        begin++;
        end--;
    }

    begin = 0;
    end = k - 1;
    while (begin < end)
    {
        tmp = nums[begin];
        nums[begin] = nums[end];
        nums[end] = tmp;
        begin++;
        end--;
    }

    begin = k;
    end = numsSize - 1;
    while (begin < end)
    {
        tmp = nums[begin];
        nums[begin] = nums[end];
        nums[end] = tmp;
        begin++;
        end--;
    }
}

int main(void)
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    rotate(arr, 10, 2);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
