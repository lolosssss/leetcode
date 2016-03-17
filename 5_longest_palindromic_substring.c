/**
 * Description : Longest Palindromic Substring
 *               Given a string S, find the longest palindromic Substring in S.
 *               You may assume that the maximum length of S is 1000, and there
 *               exists one unique longest palindromic substring.
 * Author      : Evan Lau
 * Date        : 2015.10.14
 */

#include <stdio.h>


char* longestPalindrome(char* s)
{
    int max = 0;
    int len = 0;
    int i, j;
    char *ptr = s;
    char *tail = NULL;

    while (*ptr++ != '\0')
        len++;

    for (i = 0; i < len; i++)
    {
        for (j = 0; (i - j >= 0) && (i + j < len); j++)
        {
            if (s[i-j] != s[i+j])
                break;
        }
        if (2 * j + 1 > max)
        {
            max = 2 * j + 1;
            ptr = s + i - j + 1;
            tail = s + i + j;
        }

        for (j = 0; (i - j >= 0) && (i + j + 1 < len); j++)
        {
            if (s[i-j] != s[i+ j + 1])
                break;
        }
        if (2 * j + 2 > max)
        {
            max = 2 * j + 2;
            ptr = s + i - j + 1;
            tail = s + i + j + 1;
        }
    }

    *tail = '\0';

    return ptr;
}

int main()
{
    char src[] = "abcdeedcjif";
    char *result = NULL;
    result = longestPalindrome(src);
    printf("%s\n", result);

    return 0;
}

