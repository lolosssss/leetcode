/**
 * Description : Next Permutation
 *               Implement next permutation, which rearranges numbers into the
 *               lexicographically next greater permutation of numbers. If such
 *               arrangement is not possible, it must rearrange it as the lowest
 *               possible order(ie, sorted in ascending order).
 * Author      : Evan Lau
 * Date        : 2016/03/20
 */

#include <stdio.h>

void reverse(int *nums, int begin, int end)
{
    int tmp;

    while (begin < end)
    {
        tmp = nums[begin];
        nums[begin] = nums[end];
        nums[end] = tmp;
        begin++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize)
{
    int i;
    int tmp;
    int mark = -1;

    for (i = numsSize - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            mark = i;
            break;
        }
    }

    if (mark == -1)
    {
        reverse(nums, 0, numsSize - 1);
        return;
    }

    for (i = numsSize - 1; i>= mark; i--)
    {
        if (nums[i] > nums[mark])
        {
            tmp = nums[i];
            nums[i] = nums[mark];
            nums[mark] = tmp;
            break;
        }
    }

    reverse(nums, mark + 1, numsSize - 1);
}

int main(void)
{
    int arr[] = {1, 1, 5};
    int size = 3;

    nextPermutation(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d -> ", arr[i]);
    }
    printf("null\n");

    return 0;
}
