/**
 * Description : Ugly Number II
 *               Write a program to find the n-th ugly number.
 * Author      : Evan Lau
 * Date        : 2016/05/30
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c)
{
    int m = (a < b) ? a : b;
    return c < m ? c : m;
}

int nthUglyNumber(int n)
{
    int i = 0;
    int m = 0;
    int d2 = 2, d3 = 3, d5 = 5;
    int i2 = 0, i3 = 0, i5 = 0;
    int *p = (int *)malloc(sizeof(int) * n);
    memset(p, 0, sizeof(int) * n);
    p[0] = 1;

    for (i = 1; i < n; i++)
    {
        m = min(d2, d3, d5);
        p[i] = m;

        if (m == d2)
            d2 = 2 * p[++i2];
        if (m == d3)
            d3 = 3 * p[++i3];
        if (m == d5)
            d5 = 5 * p[++i5];
    }

    return p[n-1];
}

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", nthUglyNumber(i));
    }

    return 0;
}
