/**
 * Description : Length of Last Word
 *               Given a string s consists of upper/lower-case alphabets and
 *               empty space characters ' ', return the length of last word in
 *               the string. If the last word does not exist, return 0.
 * Author      : Evan Lau
 * Date        : 2016/03/26
 */

#include <stdio.h>

int lengthOfLastWord(char* s)
{
    int cnt = 0;
    int len = 0;

    while (*s != '\0')
    {
        if (*s == ' ')
        {
            if (cnt != 0)
            {
                len = cnt;
            }
            cnt = 0;
        }
        else
        {
            cnt++;
        }
        s++;
    }

    if (cnt != 0)
    {
        len = cnt;
    }

    return len;
}

int main(void)
{
    char *s1 = "Hello world";
    char *s2 = "    ";
    char *s3 = "a   ";
    char *s4 = "a";

    printf("%s: %d\n", s1, lengthOfLastWord(s1));
    printf("%s: %d\n", s2, lengthOfLastWord(s2));
    printf("%s: %d\n", s3, lengthOfLastWord(s3));
    printf("%s: %d\n", s4, lengthOfLastWord(s4));

    return 0;
}
