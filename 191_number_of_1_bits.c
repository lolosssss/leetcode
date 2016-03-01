/**
 * Description : Number of 1 Bits
 *               Write a function that takes an unsigned integer and returns
 *               the number of '1' bits it has (also known as the Hamming
 *               weight).
 * Author      : Evan Lau
 * Date        : 2016/03/01
 */

#include <stdio.h>
#include <inttypes.h>

int hammingWeight(uint32_t n)
{
    int count = 0;

    for (int i = 0; i < 32; i++)
    {
        if (n & 0x0001)
        {
            count++;
        }

        n >>= 1;
    }

    return count;
}

int main()
{
    uint32_t a = 11;

    printf("%d\n", hammingWeight(a));

    return 0;
}
