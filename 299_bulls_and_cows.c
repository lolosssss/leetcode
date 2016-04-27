/**
 * Description : Bulls and Cows
 * Author      : Evan Lau
 * Date        : 2016/03/27
 */

#include <stdio.h>
#include <stdlib.h>

char* getHint(char* secret, char* guess)
{
    int markBulls[10] = {0};
    int markCows[10] = {0};
    int cntBulls = 0;
    int cntCows = 0;
    char *ret = (char *)malloc(sizeof(char) * 5);

    while (*secret != '\0')
    {
        if (*secret == *guess)
        {
            cntBulls++;
        }
        else
        {
            markBulls[*secret - '0']++;
            markCows[*guess - '0']++;
        }

        secret++;
        guess++;
    }

    for (int i = 0; i < 10; i++)
    {
        if (markBulls[i] != 0 && markCows[i] != 0)
        {
            cntCows += (markBulls[i] < markCows[i] ? markBulls[i] : markCows[i]);
        }
    }

    sprintf(ret, "%dA%dB", cntBulls, cntCows);

    return ret;
}

int main(void)
{
    char *s1 = "1807";
    char *g1 = "7810";
    char *s2 = "1123";
    char *g2 = "0111";

    printf("case 1: %s\n", getHint(s1, g1));
    printf("case 2: %s\n", getHint(s2, g2));

    return 0;
}
