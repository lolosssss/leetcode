/**
 * Description : Reverse Integer
 *               Reverse digits of an integer.
 * Example     : x = 123, return 321
 *               x = -123, return -321
 * Spoilers    : Here are some good questions to ask before coding. 
 *               Bonus points for you if you have already thought throught this!
 *               Did you notice that the reversed integer might overflow? Assume 
 *               the input is a 32-bit integer, then the reverse of 10000000003
 *               overflows. How should you handle such cases? For the purpose of 
 *               this problem, assume that your function returns 0 when the reversed
 *               integer overflows.
 * Author      : Evan Lau
 * Date        : 2015.10.17
 */

#include <stdio.h>

int reverse(int x)
{
    int flag = 0;
    int arr[10] = {0};
    int index = 0;
    int ret = 0;

    if (0 == x)
        return x;

    
    
    if (x < 0)
    {
        flag = 1;
        x = -x;
    }

    do
    {
        arr[index++] = x % 10;
        x = x / 10;
    } while (x);

    for (int i = 0; i < index; i++)
    {
        ret = ret * 10 + arr[i];
    }

    if (flag == 1)
        ret = -ret;

    return ret;
}

int main()
{
    printf("%d\n", reverse(123));
    printf("%d\n", reverse(-123));
    
    return 0;
}


