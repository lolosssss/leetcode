/*
 * Description: Given a pattern and a string str, find if str follows the same
 * pattern.
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * Examples:
 * 1.pattern = "abba", str = "dog cat cat dog" should return true.
 * 2.pattern = "abba", str = "dog cat cat fish" should return false.
 *
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters separated by a single space.
 */

#include <stdio.h>
#include <stdbool.h>

unsigned char hash(char *src)
{
    unsigned char h;
    for (h = 0; *src && *src != ' '; src++)
    {
        h += 31 * h + *src;
    }

    return h;
}

bool wordPattern(char *pattern, char *str)
{
    char *patterns[26] = {0};
    char *p = NULL;
    char words[256] = {0};
    unsigned char tmp;

    while (*str)
    {
        if (!*pattern)
            return false;
        if (!patterns[*pattern-'a'])
        {
            tmp = hash(str);
            if (words[tmp])
                return false;
            words[tmp] = 1;
            patterns[*pattern-'a'] = str;
            while (*str && *str++ != ' ');
        }
        else
        {
            for (p = patterns[*pattern-'a']; *str && *str != ' '; p++, str++)
            {
                if (*p != *str)
                    return false;
            }
            if (*p != ' ')
                return false;
            if (*str)
                str++;
        }
        pattern++;
    }

    return !*pattern;
}

int main()
{
    char pattern[] = "aabb";
    char str1[] = "dog dog cat cat";
    char str2[] = "dog cat cat dog";

    printf("%d\n", wordPattern(pattern, str1));
    printf("%d\n", wordPattern(pattern, str2));

    return 0;
}





