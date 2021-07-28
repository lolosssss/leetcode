/**
 * Description : House Robber II
 * Author      : Evan Lau
 * Date        : 2016/06/06
 */

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int rob(int *nums, int numsSize)
{
    int *dp0 = NULL;
    int *dp1 = NULL;
    int val;
    int i;

    dp0 = (int *)malloc(sizeof(int) * (numsSize + 1));
    dp1 = (int *)malloc(sizeof(int) * (numsSize + 1));

    dp0[0] = 0;
    dp0[1] = nums[0];

    for (i = 2; i <= numsSize; i++)
    {
        dp0[i] = max(dp0[i-1], dp0[i-2] + nums[i-1]);
    }

    if (numsSize > 1)
    {
        dp0[numsSize] = dp0[numsSize-1];
    }

    dp1[0] = 0;
    dp1[1] = 0;
    for (i = 2; i <= numsSize; i++)
    {
        dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i-1]);
    }
    val = max(dp0[numsSize], dp1[numsSize]);

    free(dp0);
    free(dp1);

    return val;
}

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5};

    printf("%d\n", rob(nums, 5));

    return 0;
}
