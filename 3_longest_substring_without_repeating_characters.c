/**
 * Description : Longest substring without repeating characters
 *               Given a string, find the length of the longest substring 
 *               without repeating characters. For example, the longest
 *               substring without repeating letters for "abcabcbb" is
 *               "abc", which the length is 3. For "bbbbb" the longest 
 *               substring is "b", with the length of 1.
 * Author      : Evan Lau
 * Date        : 2015.09.14
 */

#include <stdio.h>

int lengthOfLongestSubstring(char *s)
{
    int alphabet[255] = {0};
    int head = 0;
    int tail = 0;
    int ret = 0;
    char *ptr = s;

    while (*ptr != '\0')
    {
        if (0 == alphabet[*ptr])
        {
            alphabet[*ptr] = 1;
            tail++;
            ptr++;
        }
        else
        {
            ret = (ret > (tail - head)) ? ret : (tail - head);
            alphabet[*(s + head)] = 0;
            head++;
        }
    }
    return (ret > (tail - head)) ? ret : (tail - head);
}

int main()
{
    char str[] = "pwwkew";

    printf("%d\n", lengthOfLongestSubstring(str));
    
    return 0;
}

