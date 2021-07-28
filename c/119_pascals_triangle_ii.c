/**
 * Description : Pascal's Triangle II
 *               Given an index k, return the kth row of the Pascal's triangle.
 * Author      : Evan Lau
 * Date        : 2016/04/29
 */

#include <stdio.h>
#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize)
{
    int *ret = (int *)malloc(sizeof(int) * (rowIndex + 1));
    int tmp;
    int prev;
    int i;
    int j;

    *returnSize = rowIndex + 1;

    ret[0] = 1;

    for (i = 1; i <= rowIndex; i++)
    {
        ret[i] = 1;
        prev = 1;
        for (j = 1; j < i; j++)
        {
            tmp = ret[j];
            ret[j] = ret[j] + prev;
            prev = tmp;
        }
    }

    return ret;
}

int main(void)
{
    int size;
    int *res = NULL;

    res = getRow(3, &size);
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", res[i]);
    }
    printf("]\n");

    return 0;
}
