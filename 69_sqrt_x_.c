/**
 * Description : Sqrt(x)
 *               Implement int sqrt(int x).
 * Author      : Evan Lau
 * Date        : 2016/05/10
 */

#include <stdio.h>

int mySqrt(x)
{
    if (x == 0)
        return 0;

    double tmp = 0;
    double y = 1;

    while (y != tmp)
    {
        tmp = y;
        y = (y + x / y) / 2;
    }

    return (int)y;
}

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        printf("sqrt(%d) = %d\n", i, mySqrt(i));
    }

    return 0;
}
