/**
 * Description : Divide Two Integers
 *               Divide two integers without using multiplication, division and
 *               mod operator.
 *               If it is overflow, return MAX_INT.
 * Author      : Evan Lau
 * Date        : 2016/03/10
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int divide(int dividend, int divisor)
{
    if (divisor == 0)
        return INT_MAX;
    if (divisor == 1)
        return dividend;
    if (divisor == -1)
        return dividend == INT_MIN ? INT_MAX : -dividend;
    if (divisor == INT_MIN)
        return dividend == INT_MIN;

    int ret = 0;
    int sum = 0;
    int cnt;
    int tmp;
    int isNeg = 0;

    if (divisor < 0)
    {
        divisor = -divisor;
        isNeg = !isNeg;
    }

    if (dividend < 0)
    {
        if (dividend == INT_MIN)
        {
            dividend += divisor;
            ret++;
        }
        dividend = -dividend;
        isNeg = !isNeg;
    }

    while (sum <= dividend - divisor)
    {
        tmp = divisor;
        cnt = 1;
        while (sum <= dividend - tmp)
        {
            sum += tmp;
            ret += cnt;
            tmp += tmp;
            cnt += cnt;
        }
    }

    return isNeg ? -ret : ret;
}

int main(void)
{
    int i, j;

    for (i = 0; i < 10; i++)
    {
        for (j = 1; j < 10; j++)
            printf("%d / %d = %d\n", i, j, divide(i, j));
    }

    printf("%d\n", divide(-1010369383, -2147483648));

    return 0;
}
