/**
 * Description : Counting Bits
 *               Given a non negative integer number num. For every numbers i in
 *               the range 0 <= i <= num calculate the number of 1's in their
 *               binary representation and return them as an array.
 * Author      : Evan lau
 * Date        : 2016/03/26
 */

#include <stdio.h>
#include <stdlib.h>

int count(int n)
{
    int cnt = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((n & 0x0001) == 1)
        {
            cnt++;
        }
        n >>= 1;
    }

    return cnt;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize)
{
    int *ret = (int *)malloc(sizeof(int) * (num + 1));

    *returnSize = 0;

    for (int i = 0; i < num + 1; i++)
    {
        ret[(*returnSize)++] = count(i);
    }

    return ret;
}

int main(void)
{
    int i;
    int j;
    int size;
    int *res = NULL;

    for (i = 0; i < 20; i++)
    {
        res = countBits(i, &size);
        printf("[");
        for (j = 0; j < size; j++)
        {
            printf("%d ", res[j]);
        }
        printf("]\n");

        free(res);
        res = NULL;
    }

    return 0;
}
