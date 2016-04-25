/**
 * Description : Reverse Words in a string
 *               Given an input string, reverse the string word by word.
 * Author      : Evan Lau
 * Date        : 2016/04/25
 */

#include <stdio.h>
#include <string.h>

void reverse(char *s, int start, int end)
{
    char tmp;

    while (start < end)
    {
        tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        start++;
        end--;
    }
}

void reverseWords(char *s)
{
    int i = 0;
    int j = 0;

    while (s[i] == ' ' && s[i] != '\0')
    {
        i++;
    }

    while (s[i] != '\0')
    {
        if (s[i] == ' ')
        {
            while (s[i] == ' ' && s[i] != '\0')
                i++;
            if (s[i] == '\0')
            {
                break;
            }
            else
            {
                s[j++] = ' ';
            }
        }
        else
        {
            s[j++] = s[i++];
        }
    }
    s[j] = '\0';

    i = 0;
    j = strlen(s) - 1;

    reverse(s, i, j);
    j = 0;
    while (s[j] != '\0')
    {
        if (s[j] == ' ')
        {
            reverse(s, i, j - 1);
            i = j + 1;
            j++;
        }
        j++;
    }
    reverse(s, i, j - 1);
}

int main(void)
{
    char str[] = {' ', ' ', 't', 'h', 'e', ' ', ' ', 's', 'k', 'y', ' ',
                  'i', 's', ' ', ' ', 'b','l', 'u', 'e', ' ', ' ', '\0'};

    printf("%s\n", str);
    reverseWords(str);
    printf("%s\n", str);

    return 0;
}
