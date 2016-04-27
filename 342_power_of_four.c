/**
 * Description : Power of Four
 *               Given an integer (signed 32 bits), write a function to check
 *               whether it is a power of 4.
 * Author      : Evan Lau
 * Date        : 2016/04/18
 */

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool isPowerOfFour(int num)
{
    while (num)
    {
        if (num == 1)
            return true;
        if (num % 4)
            return false;
        num /= 4;
    }
}

int main(void)
{
    assert(isPowerOfFour(16) == true);
    assert(isPowerOfFour(5) == false);
    assert(isPowerOfFour(-2147483648) == false);
    assert(isPowerOfFour(20) == false);

    printf("All passed\n");

    return 0;
}
