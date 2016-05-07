/**
 * Description : Given an array nums, there is a sliding window of size k which
 *               is moving from the very left of the array to the very right.
 *               You can only see the k numbers in the window. Each time the
 *               sliding window moves right by one position.
 * Author      : Evan Lau
 * Date        : 2016/05/07
 */

#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    int i = 0;
    int maxQue[numsSize];
    int start = 0;
    int end = -1;
    int cnt = 0;
    int *ret = NULL;

    if (numsSize == 0)
    {
        *returnSize = 0;
        return ret;
    }

    *returnSize = numsSize - k + 1;
    ret = (int *)malloc(sizeof(int) * *returnSize);

    if (k <= 1)
    {
        for (i = 0; i < numsSize; i++)
        {
            ret[i] = nums[i];
        }
        return ret;
    }

    while (i < k)
    {
        while (end >= start && nums[maxQue[end]] <= nums[i])
            end--;
        end++;
        maxQue[end] = i;
        i++;
    }

    while (i < numsSize)
    {
        ret[cnt++] = nums[maxQue[start]];
        while (end >= start && nums[maxQue[end]] <= nums[i])
            end--;
        end++;
        maxQue[end] = i;
        while (end >= start && maxQue[start] <= i - k)
            start++;
        i++;
    }

    ret[cnt] = nums[maxQue[start]];

    return ret;
}

int main(void)
{
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int *res = NULL;
    int size;

    res = maxSlidingWindow(arr, 8, 3, &size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    free(res);

    return 0;
}
