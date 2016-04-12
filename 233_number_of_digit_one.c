/**
 * Description : Number of Digit One
 *               Given an integer n, count the total number of digit 1 appearing
 *               in all non-negative integers less than or equal to n.
 * Author      : Evan Lau
 * Date        : 2016/04/11
 */

#include <stdio.h>

int countDigitOne(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n >= 1 && n <= 9)
    {
        return 1;
    }

    int x = n;
    int v = 1;

    while (x >= 10)
    {
        x /= 10;
        v *= 10;
    }

    if (x != 1)
    {
        return x * countDigitOne(v - 1) + countDigitOne(n % v) + v;
    }
    else
    {
        return countDigitOne(v - 1) + countDigitOne(n % v) + n % v + 1;
    }
}

int main(void)
{
    printf("n = 13, countDigitOne = %d\n", countDigitOne(13));
    printf("n = 824883294, countDigitOne = %d\n", countDigitOne(824883294));

    return 0;
}
