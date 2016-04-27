/**
 * Description : Excel Sheet Column Number
 *               Given a column title as appear in an Excel sheet, return its
 *               corresponding column number.
 * Author      : Evan Lau
 * Date        : 2016/04/23
 */

#include <stdio.h>
#include <string.h>

int titleToNumber(char* s)
{
    int i = strlen(s);
    int ret = 0;
    int n = 1;

    while (i)
    {
        i--;
        ret += (*(s + i) - 'A' + 1) * n;
        n *= 26;
    }

    return ret;
}

int main(void)
{
    printf("%s : %d\n", "Z", titleToNumber("Z"));
    printf("%s : %d\n", "AA", titleToNumber("AA"));
    printf("%s : %d\n", "AB", titleToNumber("AB"));
    printf("%s : %d\n", "AZ", titleToNumber("AZ"));
    printf("%s : %d\n", "BA", titleToNumber("BA"));

    return 0;
}
