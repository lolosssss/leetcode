/**
 * Description : Reverse Bits
 *               Reverse bits of a given 32 bits unsigned integer.
 * Author      : Evan Lau
 * Date        : 2016/03/01
 */

#include <stdio.h>
#include <inttypes.h>

uint32_t reverseBits(uint32_t n)
{
    uint32_t ret = 0;

    for (int i = 0; i < 32; i++)
    {
        ret = (ret << 1) | (n & 0x0001);
        n >>= 1;
    }

    return ret;
}

int main(void)
{
    uint32_t a = 43261596;

    printf("%d\n", reverseBits(a));

    return 0;
}
