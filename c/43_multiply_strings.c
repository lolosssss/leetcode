/**
 * Description : Multiply Strings
 *               Given two numbers represented as strings, return multipication
 *               of the numbers as a string
 * Author      : Evan Lau
 * Date        : 2016/05/15
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* multiply(char* num1, char* num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0;
    int tmp;
    int i, j;
    char *ret = (char *)malloc(sizeof(char) * (len1 + len2 + 2));
    memset(ret, '0', len1 + len2);

    ret[len1+len2] = '\0';
    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            tmp = (ret[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0') + \
                    carry;
            ret[i+j+1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        ret[i] += carry;
    }

    for (i = 0; i < len1 + len2; i++)
    {
        if (ret[i] != '0')
            return ret + i;
    }
    return "0";
}

int main(void)
{
    char num1[] = "12";
    char num2[] = "23";

    printf("%s * %s = %s\n", num1, num2, multiply(num1, num2));

    return 0;
}
