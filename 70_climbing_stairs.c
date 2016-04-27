/**
 * Description : Climbing Stairs
 *               You are climbing a stair case. It takes n steps to reach to the
 *               top. Each time you can either climb 1 or 2 steps. In how many
 *               distinct ways can you climb to the top?
 * Author      : Evan Lau
 * Date        : 2016/04/25
 */

#include <stdio.h>

int climbStairs(int n)
{
    int i = 0;
    int arr[n];

    if (n < 4)
    {
        return n;
    }

    arr[0] = 1;
    arr[1] = 2;
    i = 2;
    while (i < n)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        i++;
    }

    return arr[i - 1];
}

int main(void)
{
    for (int i = 1; i < 20; i++)
    {
        printf("%d : %d\n", i, climbStairs(i));
    }

    return 0;
}
