/**
 * Description : Ugly Number
 *               Write a program to check whether a given number is an ugly
 *               number. Ugly numbers are positive numbers whose prime factors
 *               only include 2, 3, 5. Note that 1 is typically treated as an
 *               ugly number.
 * Author      : Evan Lau
 * Date        : 2016/04/26
 */

#include <stdio.h>
#include <stdbool.h>

bool isUgly(int num)
{
    if (num == 0)
        return false;
    if (num == 1)
        return true;

    while (num % 2 == 0)
    {
        num /= 2;
        if (num == 1)
            return true;
    }

    while (num % 3 == 0)
    {
        num /= 3;
        if (num == 1)
            return true;
    }

    while (num % 5 == 0)
    {
        num /= 5;
        if (num == 1)
            return true;
    }

    return false;
}

int main(void)
{
    for (int i = 0; i < 20; i++)
    {
        printf("%.2d is ugly ? %d\n", i, isUgly(i));
    }

    return 0;
}
