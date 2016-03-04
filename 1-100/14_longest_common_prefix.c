/**
 * Description : Longest Common Prefix
 *               Write a function to find the longest common prefix string 
 *               amongst an array of strings.
 * Author      : Evan Lau
 * Date        : 2015/11/22
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
    if (0 == strsSize)
        return "";
    
    char* ret = (char *)malloc(strlen(strs[0]) + 1);
    int len = 0;
    int i;
    int j;

    strcpy(ret, strs[0]);

    for (i = 1; i < strsSize; i++)
    {
        if (strlen(ret) == 0 || strlen(strs[i]) == 0)
            return "";

        len = (strlen(ret) < strlen(strs[i])) ? strlen(ret) : strlen(strs[i]);

        for (j = 0; j < len; j++)
        {
            if (ret[j] != strs[i][j])
                break;
        }

        ret[j] = '\0';
    }

    return ret;
}


