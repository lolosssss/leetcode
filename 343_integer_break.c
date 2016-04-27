/**
 * Description : Integer Break
 *               Given a positive integer n, break it into the sum of at least
 *               two positive integers and maximize the product of those
 *               integers. Return the maximum product you can get.
 * Author      : Evan Lau
 * Date        : 2016/04/20
 */

#include <stdio.h>

int integerBreak(int n)
{
    int i = 0;
    int ret = 1;

    if (n == 2)
    {
        return 1;
    }
    if (n == 3)
    {
        return 2;
    }

    switch (n % 3)
    {
        case 1:
            i = n / 3 - 1;
            ret *= 4;
            break;
        case 2:
            i = n / 3;
            ret *= 2;
            break;
        default:
            i = n / 3;
            break;
    }

    while (i--)
    {
        ret *= 3;
    }

    return ret;
}

int main(void)
{
    for (int i = 2; i < 21; i++)
    {
        printf("i = %d : %d\n", i, integerBreak(i));
    }

    return 0;
}
