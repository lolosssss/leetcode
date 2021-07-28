/**
 * Description : Power of Three
 *               Given an integer, write a function to determine if it is a
 *               power of three.
 * Author      : Evan Lau
 * Date        : 2016/04/01
 */

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfThree(int n)
{
    while (n % 3 == 0 && n)
    {
        n /= 3;
    }

    if (n == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    for (int i = 0; i < 100; i++)
    {
        if (isPowerOfThree(i) == true)
        {
            printf("%d is power of three\n", i);
        }
    }

    return 0;
}
