/**
 * Description : Count Primes
 *               Count the number of prime numbers less than a non-negative
 *               number n.
 * Author      : Evan Lau
 * Date        : 2016/05/20
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int countPrimes(int n)
{
    int k = 2;
    int nk;
    int sqn = sqrt(n);
    int cnt = 0;
    int *arr = (int *)calloc(n, sizeof(int));

    arr[0] = 1;
    while (k <= sqn)
    {
        if (k < 463441)
            for (nk = k * k; nk < n; nk += k)
                arr[nk-1] = 1;

        k++;
        while (k < n && arr[k-1])
            k++;
    }

    for (int i = 2; i < n; i++)
    {
        if (!arr[i-1])
            cnt++;
    }

    free(arr);

    return cnt;
}

int main(void)
{
    for (int i = 1; i < 10000; i++)
    {
        countPrimes(i);
    }

    printf("done\n");

    return 0;
}
