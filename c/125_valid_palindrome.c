/**
 * Description : Valid Palindrome
 *               Given a string, determine if it is a palindrome, considering
 *               only alphanumeric characters and ignoring cases.
 * Author      : Evan Lau
 * Date        : 2016/04/03
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static inline int is_character(char c)
{
    return ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'));
}

static inline int is_match(char a, char b)
{
    if (a >= 'A' && a <= 'Z')
        a = a - 'A' + 'a';
    if (b >= 'A' && b <= 'Z')
        b = b - 'A' + 'a';

    return a == b;
}

bool isPalindrome(char* s)
{
    int i = 0;
    int j = strlen(s) - 1;

    if (s == NULL)
    {
        return true;
    }

    while (i < j)
    {
        if (!is_character(s[i]))
        {
            i++;
            continue;
        }
        if (!is_character(s[j]))
        {
            j--;
            continue;
        }
        if (!is_match(s[i], s[j]))
            return false;
        i++;
        j--;
    }
    if (i < j)
    {
        return false;
    }
    return true;
}

int main(void)
{
    char str1[] = "A man, a plan, a canal: Panama";
    char str2[] = "race a car";
    char str3[] = "aa";
    char str4[] = "ab";
    char str5[] = "a.";
    char str6[] = "";

    printf("%d\n", isPalindrome(str1));
    printf("%d\n", isPalindrome(str2));
    printf("%d\n", isPalindrome(str3));
    printf("%d\n", isPalindrome(str4));
    printf("%d\n", isPalindrome(str5));
    printf("%d\n", isPalindrome(str6));

    return 0;
}
