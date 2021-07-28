/**
 * Description : Excel Sheet Column Title
 *               Given a positive integer, return its corresponding column title
 *               as appear in an Excel sheet.
 * Author      : Evan Lau
 * Date        : 2016/04/22
 */

#include <stdio.h>
#include <stdlib.h>

char* convertToTitle(int n)
{
    int i = 0;
    char* ret = (char *)malloc(sizeof(char) * 8);

    i = 7;
    ret[i--] = '\0';
    while (n)
    {
        ret[i--] = (n - 1) % 26 + 'A';
        n = (n - 1) / 26;
    }

    return ret + i + 1;
}

int main(void)
{
    printf("%s\n", convertToTitle(26));
    printf("%s\n", convertToTitle(27));
    printf("%s\n", convertToTitle(52));
    printf("%s\n", convertToTitle(53));
    printf("%s\n", convertToTitle(54));

    return 0;
}
