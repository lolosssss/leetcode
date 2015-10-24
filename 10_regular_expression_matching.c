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

bool isMatch(char *s, char *p)
{
    char *str = s;
    char *ptr = p;

    while (*ptr != '\0')
    {
        if (*ptr == '.')
        {
            if (*(ptr + 1) == '*')
            {
                if (*(ptr + 2) == '\0')
                    return true;
                
                str++;
                if (*str == '\0' && *(ptr + 2) == '\0')
                    return true;
                else
                    return false;
            }
            else
            {
                str++;
                ptr++;
                if (*str == '\0' && *ptr == '\0')
                    return true;
            }
        }
        else
        {
            if (*(ptr + 1) == '*')
            {
                if (*str != *ptr)
                {
                    ptr += 2;
                }
                else
                {
                    str++;
                    if (*str == '\0')
                    {
                        ptr += 2;
                        if (*ptr == '\0' || (*ptr == *(str - 1) && *(ptr + 1) == '\0'))
                            return true;
                    }
                }
            }
            else
            {
                if (*str == *ptr)
                {
                    str++;
                    ptr++;
                    if (*str == '\0' && *ptr == '\0')
                        return true;
                }
                else
                {
                    ptr++;
                }
            }
        }
    }

    return false;
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


