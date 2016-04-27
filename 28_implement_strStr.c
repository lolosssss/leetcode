/**
 * Description : Implement strStr()
 *               Returns the index of the first occurrence of needle in haystack
 *               or -1 if needle is not part of haystack.
 * Author      : Evan Lau
 * Date        : 2016/03/09
 */

#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle)
{
    int i = 0;
    int len = strlen(needle);

    if (!*haystack && !*needle)
    {
        return 0;
    }

    while (*(haystack + i))
    {
        if (!strncmp(haystack + i, needle, len))
        {
            return i;
        }
    }

    return -1;
}

int main(void)
{
    char *haystack = "";
    char *needle = "a";
    int index = strStr(haystack, needle);

    if (index != -1)
    {
        printf("index of needle in haystack is : %d\n", index);
    }
    else
    {
        printf("Not find!\n");
    }

    return 0;
}
