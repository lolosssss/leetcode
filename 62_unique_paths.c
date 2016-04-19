/**
 * Description : Unique Paths
 * Author      : Evan Lau
 * Date        : 2016/04/19
 */

#include <stdio.h>

int uniquePaths(int m, int n)
{
    int p = m < n ? m - 1 : n - 1;
    int q = m + n - 2;
    int pro1 = 1;
    long pro2 = 1;
    int i = p;

    while (i--)
    {
        pro1 *= p--;
        pro2 *= q--;
    }
    return pro2 / pro1;
}

int main(void)
{
    printf("%d\n", uniquePaths(7, 3));
    printf("%d\n", uniquePaths(10, 10));

    return 0;
}
