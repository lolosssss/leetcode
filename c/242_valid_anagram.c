/**
 * Description : Valid Anagram
 *               Given two strings s and t, write a function to determine if t
 *               is an anagram of s.
 * Author      : Evan Lau
 * Date        : 2016/04/05
 */

#include <stdio.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t)
{
    int cnt[26] = {0};

    while (*s != '\0')
    {
        cnt[*s - 'a']++;
        s++;
    }
    while (*t != '\0')
    {
        cnt[*t - 'a']--;
        t++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    char s1[] = "anagram";
    char t1[] = "nagaram";
    char s2[] = "rat";
    char t2[] = "car";

    printf("%d\n", isAnagram(s1, t1));
    printf("%d\n", isAnagram(s2, t2));

    return 0;
}
