/**
 * Description : Isomorphic Strings
 *               Given two strings s and t, determine if they are isomorphic.
 * Author      : Evan Lau
 * Date        : 2016/04/05
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isIsomorphic(char* s, char* t)
{
    if (s == NULL)
    {
        return true;
    }

    int s_cnt[255] = {0};
    int t_cnt[255] = {0};
    int i = 0;

    while (*(s + i) != '\0')
    {
        s_cnt[*(s + i)] += (i + 1);
        t_cnt[*(t + i)] += (i + 1);
        if (s_cnt[*(s + i)] != t_cnt[*(t + i)])
        {
            return false;
        }
        i++;
    }

    return true;
}

int main(void)
{
    printf("%d\n", isIsomorphic("egg", "add"));
    printf("%d\n", isIsomorphic("foo", "bar"));
    printf("%d\n", isIsomorphic("paper", "title"));
    printf("%d\n", isIsomorphic("aba", "baa"));
    printf("%d\n", isIsomorphic("13", "42"));

    return 0;
}
