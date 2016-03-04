/**
 * Description : String to Integer (atoi)
 *               Implement atoi to vonvert a string to an integer.
 * Author      : Evan Lau
 * Date        : 2015.10.23
 */


#include <stdio.h>

int myAtoi(char* str)
{
    int ret = 0;
    char *ptr = str;
    char negative = 0;

    while (*ptr == ' ')
        ptr++;
    
    if (*ptr == '-')
    {
        negative = 1;
        ptr++;
        if (*ptr > '9' || *ptr < '0')
            return 0;
    }
    if (*ptr == '+')
    {
        ptr++;
        if (*ptr > '9' || *ptr < '0')
            return 0;
    }

    while (*ptr == '0')
        ptr++;

    while (*ptr != '\0')
    {
        if (*ptr > '9' || *ptr < '0')
            break;
        
        ret = ret * 10 + *ptr - '0';
        if (ret > 214748364 && (*(ptr + 1) <= '9' && *(ptr + 1) >= '0'))
        {
            if (negative)
                return -2147483648;
            else
                return 2147483647;
        }

        if (ret == 214748364 && (*(ptr + 1) == '8' | *(ptr + 1) == '9'))
        {
            if (negative)
                return -2147483648;
            else
                return 2147483647;
        }
        ptr++;
    }

    if (negative)
        ret = -ret;
    
    return ret;
}

int main(int argc, char *argv[])
{
    char str[] = "-12345";
    printf("%d\n", myAtoi(str));
    
    return 0;
}


