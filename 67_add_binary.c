/**
 * Description : Add Binary
 *               Given two binary strings, return their sum.
 * Author      : Evan Lau
 * Date        : 2016/03/29
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* a, int len)
{
    int i = 0;
    char tmp;
    len--;

    while (i < len)
    {
        tmp = a[i];
        a[i] = a[len];
        a[len] = tmp;
        i++;
        len--;
    }
}

char* addBinary(char* a, char* b)
{
    int len1 = strlen(a);
    int len2 = strlen(b);
    int size = len1 > len2 ? (len1 + 2) : (len2 + 2);
    int i = 0;
    int carry = 0;

    char *ret = (char *)malloc(sizeof(char) * size);

    reverse(a, len1);
    reverse(b, len2);

    while (*a != '\0' && *b != '\0')
    {
        ret[i++] = (*a + *b - '0' - '0' + carry) % 2 + '0';
        carry = (*a + *b - '0' - '0' + carry) / 2;
        a++;
        b++;
    }


    if (*a == '\0')
    {
        while (*b != '\0')
        {
            ret[i++] = (*b - '0' + carry) % 2 + '0';
            carry = (*(b++) - '0' + carry) / 2;
        }
    }
    else
    {
        while (*a != '\0')
        {
            ret[i++] = (*a - '0' + carry) % 2 + '0';
            carry = (*(a++) - '0' + carry) / 2;
        }
    }
    if (carry)
    {
        ret[i++] = '1';
    }
    ret[i] = '\0';
    reverse(ret, i);

    return ret;
}

int main(void)
{
    char s1[] = "11";
    char s2[] = "1";
    char s3[] = "110010";
    char s4[] = "10111";

    printf("case 1 : %s\n", addBinary(s1, s2));
    printf("case 2 : %s\n", addBinary(s3, s4));

    return 0;
}
