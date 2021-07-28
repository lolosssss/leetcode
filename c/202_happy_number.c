/**
 * Description : Happy Number
 *               Write an algorithm to determine if a number is "happy".
 *               A happy number is a number defined by the following process:
 *               Starting with any positive integer, replace the number by the
 *               sum of the squares of its digits, and repeat the process until
 *               the number equals 1(where it will stay), or it loops endlessly
 *               in a cycle which does not include 1. Those numbers for which
 *               this process ends in 1 are happy numbers.
 * Author      : Evan Lau
 * Date        : 2016/04/12
 */

#include <stdio.h>
#include <stdbool.h>

bool isHappy(int n)
{
    int len = 0;
    int a[10];
    int sum = n;

    for (int i = 0; i < 10; i++)
    {
        while (sum)
        {
            a[len++] = sum % 10;
            sum /= 10;
        }

        sum = 0;
        while (len)
        {
            len--;
            sum += a[len] * a[len];
        }

        if (sum == 1)
        {
            return true;
        }
    }

    return false;
}

int main(void)
{
    for (int i = 0; i < 20; i++)
    {
        printf("%d\n", isHappy(i));
    }

    return 0;
}
