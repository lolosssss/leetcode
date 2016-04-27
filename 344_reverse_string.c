/**
 * Description : Reverse String
 *               Write a function that takes a string as input and returns the
 *               string reversed.
 * Author      : Evan Lau
 * Date        : 2016/04/23
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char* s)
{
    int len = strlen(s);
    int i = 0;
    char* ret = (char *)malloc(len + 1);

    while (len)
    {
        ret[i++] = s[--len];
    }
    ret[i] = '\0';

    return ret;
}

int main(void)
{
    printf("%s : %s\n", "hello", reverseString("hello"));

    return 0;
}
