/**
 * Description : Wildcard Matching
 *               Implement wildcard pattern matching with support for '?' and
 *               '*'.
 *               '?' Matches any single character.
 *               '*' Matches any sequence of characters.
 * Author      : Evan Lau
 * Date        : 2016/05/17
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char *s, char *p)
{
    int len_s = strlen(s);
    int len_p = strlen(p);
    int i_s = 0;
    int i_p = 0;
    int back = 0;
    int prev_s, prev_p;

    while (i_s < len_s)
    {
        if (i_p < len_p && (p[i_p] == '?' || p[i_p] == s[i_s]))
        {
            i_s++;
            i_p++;
        }
        else if (p[i_p] == '*')
        {
            while (i_p < len_p && p[i_p] == '*')
                i_p++;

            if (i_p == len_p)
                return true;

            back = 1;
            prev_s = i_s;
            prev_p = i_p;
        }
        else if (back)
        {
            prev_s++;
            i_s = prev_s;
            i_p = prev_p;
        }
        else
            return false;
    }

    while (i_p < len_p && p[i_p] == '*')
        i_p++;

    return i_p == len_p;
}

int main(void)
{
    printf("%d\n", isMatch("aa", "a"));
    printf("%d\n", isMatch("aaa", "*"));
    printf("%d\n", isMatch("ab", "?*"));
    printf("%d\n", isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b"));

    return 0;
}
