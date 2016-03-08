/**
 * Description : Regular Expression Matching
 *               Implement regular expression matching withsupport for '.' and '*'.
 *               '.' Matches any single character.
 *               '*' Matches zero or more of the preceding element.
 *               The matching should cover the entire input string (not partial).
 *               The function prototype should be:
 *               bool isMatch(const char *s, const char *p);
 * Author      : Evan Lau
 * Date        : 2015.10.23
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char *s, char *p)
{
    if (*p == '\0')
        return *s == '\0';

    // next char is not '*'
    if (*(p + 1) != '*')
    {
        return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s + 1, p + 1);
    }

    // next char is '*'
    while ((*p == *s) || (*p == '.' && *s != '\0'))
    {
        if (isMatch(s, p + 2))
            return true;
        s++;
    }
    
    return isMatch(s, p + 2);
}

int main()
{
    char str[] = "aaa";
    char ptr[] = "a*a";

    if (isMatch(str, ptr))
        printf("Yes\n");
    else
        printf("No\n");
    
    return 0;
}


