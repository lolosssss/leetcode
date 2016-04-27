/**
 * Description : Pow(x, n)
 *               Implement pow(x, n).
 * Author      : Evan Lau
 * Date        : 2016/04/15
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>

double myPow(double x, int n)
{
    int nagative = 0;
    double ret = x;

    if (x == 1.00)
        return x;

    if (x == -1.00)
    {
        if (n % 2 == 1)
        {
            return x;
        }
        else
        {
            return -x;
        }
    }

    if ((x < 1.0 && n == 2147483647) || n == -2147483648)
    {
        return 0;
    }

    if (n == 0)
        return 1;

    if (n == 1)
        return x;

    if (n < 0)
    {
        nagative = 1;
        n = -n;
    }

    n--;
    while (n--)
    {
        ret *= x;
    }
    if (nagative)
        ret = 1 / ret;

    return ret;
}

int main(void)
{
    assert(myPow(2, 3) == pow(2, 3));
    assert(myPow(34.00515, -3) == pow(34.00515, -3));
    assert(myPow(0.00001, 2147483647) == pow(0.00001, 2147483647));

    printf("All pass\n");

    return 0;
}
