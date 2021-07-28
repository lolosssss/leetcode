/**
 * Description : Factorial Trailing Zeroes
 *               Given an integer n, return the number of trailing zeroes in n!.
 * Author      : Evan Lau
 * Date        : 2016/03/01
 */

#include <stdio.h>

int trailingZeroes(int n)
{
    int ret = 0;

    while (n)
    {
        ret += (n / 5);
        n /= 5;
    }

    return ret;
}

int main(void)
{
    int a = 10;

    printf("%d\n", trailingZeroes(a));

    return 0;
}
