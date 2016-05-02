/**
 * Description : Plus One
 *               Given a non-negative number represented as an array of digits,
 *               plus one to the number.
 * Author      : Evan Lau
 * Date        : 2016/05/02
 */

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int carry = 1;
    int i = digitsSize - 1;
    int *ret = NULL;

    while (carry && i >= 0)
    {
        digits[i] += carry;
        carry = digits[i] / 10;
        digits[i] %= 10;
        i--;
    }

    if (carry)
    {
        ret = (int *)malloc(sizeof(int) * (digitsSize + 1));
        ret[0] = 1;
        for (i = 0; i < digitsSize; i++)
        {
            ret[i+1] = digits[i];
        }
        *returnSize = digitsSize + 1;
    }
    else
    {
        ret = (int *)malloc(sizeof(int) * digitsSize);
        for (i = 0; i < digitsSize; i++)
        {
            ret[i] = digits[i];
        }
        *returnSize = digitsSize;
    }

    return ret;
}

int main(void)
{
    int digits[] = {9, 9, 9};
    int size = 0;
    int *res = NULL;

    res = plusOne(digits, 3, &size);

    for (int i = 0; i < size; i++)
    {
        printf("%d", res[i]);
    }
    printf("\n");
    free(res);

    return 0;
}
