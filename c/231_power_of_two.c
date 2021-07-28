/**
 * Description : Power of Two
 *               Given an integer, write a function to determine if it is a pow-
 *               er of two.
 * Author      : Evan Lau
 * Date        : 2016/05/04
 */

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n)
{
    if (n < 1)
        return false;
    return ((n & (n - 1)) == 0);
}

int main(void)
{
    for (int i = 0; i < 1025; i++)
    {
        if (isPowerOfTwo(i))
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
