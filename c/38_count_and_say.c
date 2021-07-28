/**
 * Description : Count and Say
 *               The count-and-say sequence is the sequence of integers begining
 *               as follows: 1, 11, 21, 1211, 111221, ...
 *               1 is read off as "one 1" or 11.
 *               11 is read off as "two 1" or 21.
 *               21 is read off as "one 2, then one 1" or 1211.
 *               Given an integer n, generate the nth sequence.
 * Author      : Evan Lau
 * Date        : 2016/03/22
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay(int n)
{
    char *ret = (char *)malloc(sizeof(char) * 8192);
    char buffer[8192];
    char last;
    int cnt = 0;
    int i = 0;
    int j = 0;

    buffer[0] = '1';
    buffer[1] = '\0';

    if (n == 1)
    {
        ret[0] = '1';
        ret[1] = '\0';

        return ret;
    }
    n--;

    while (n--)
    {
        cnt = 0;
        j = 0;
        i = 0;
        last = buffer[0];
        while (buffer[i] != '\0')
        {
            if (buffer[i] == last)
            {
                cnt++;
            }
            else
            {
                ret[j++] = cnt + '0';
                ret[j++] = last;
                last = buffer[i];
                cnt = 1;
            }
            i++;
        }
        ret[j++] = cnt + '0';
        ret[j++] = last;
        ret[j] = '\0';
        strcpy(buffer, ret);
    }

    return ret;
}

int main(void)
{
    char *res = NULL;
    for (int i = 1; i < 30; i++)
    {
        res = countAndSay(i);
        printf("%d : %s\n", i, res);
        free(res);
    }

    return 0;
}
