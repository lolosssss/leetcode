/**
 * Description : Integer to Roman
 *               Given an integer, convert it to a roman numeral.
 *               Input is guaranteed to be within the range from 1 to 3999.
 * Author      : Evan Lau
 * Date        : 2016.02.25
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num)
{
    int values[] = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4,
        1
    };

    char symbols[13][13] = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV",
        "I"
    };

    char *ret = (char *)malloc(sizeof(char) * 32);
    int i = 0;
    int j = 0;
    int cur = 0;
    int len = 0;

    memset(ret, 0, sizeof(char) * 32);

    while (num > 0)
    {
        int k = num / values[i];
        for (j = 0; j < k; j++)
        {
            len = strlen(symbols[i]);
            strncat(ret + cur, symbols[i], len);
            cur += len;
            num -= values[i];
        }
        i++;
    }

    return ret;
}

int main()
{
    int n;

    scanf("%d", &n);
    printf("%s\n", intToRoman(n));

    return 0;
}


