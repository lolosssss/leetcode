/**
 * Description : Valid Number
 *               Validate if a given string is numeric.
 *               Some example:
 *               "0" => true
 *               " 0.1" => true
 *               "abc" => false
 *               "1 a" => false
 *               "2e10" => true
 * Author      : Evan lau
 * Date        : 2016/03/31
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isNumber(char* s)
{
    int len = strlen(s);
    int i = 0;
    bool isNum = false;

    while (i < len && s[i] == ' ')
        i++;

    if (i < len && (s[i] == '+' || s[i] == '-'))
        i++;

    while (i < len && s[i] >= '0' && s[i] <= '9')
    {
        i++;
        isNum = true;
    }

    if (i < len && s[i] == '.')
    {
        i++;
        while (i < len && s[i] >= '0' && s[i] <= '9')
        {
            i++;
            isNum = true;
        }
    }

    if (i < len && isNum && s[i] == 'e')
    {
        i++;

        if (s[i] == '+' || s[i] == '-')
            i++;

        isNum = false;
        while (i < len && s[i] >= '0' && s[i] <= '9')
        {
            i++;
            isNum = true;
        }
    }

    while (i < len && s[i] == ' ')
        i++;

    return isNum && i == len;
}

int main(void)
{
    char s1[] = "0";
    char s2[] = " 0.1";
    char s3[] = "abc";
    char s4[] = "1 a";
    char s5[] = "2e10";

    if (isNumber(s1) == true)
    {
        printf("%s => true\n", s1);
    }
    else
    {
        printf("%s => false\n", s1);
    }

    if (isNumber(s2) == true)
    {
        printf("%s => true\n", s2);
    }
    else
    {
        printf("%s => false\n", s2);
    }

    if (isNumber(s3) == true)
    {
        printf("%s => true\n", s3);
    }
    else
    {
        printf("%s => false\n", s3);
    }

    if (isNumber(s4) == true)
    {
        printf("%s => true\n", s4);
    }
    else
    {
        printf("%s => false\n", s4);
    }

    if (isNumber(s5) == true)
    {
        printf("%s => true\n", s5);
    }
    else
    {
        printf("%s => false\n", s5);
    }

    return 0;
}
