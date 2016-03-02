/**
 * Description : Letter Combinations of a Phone Number
 *               Given a digit string, return all possible letter combinations
 *               that the number could represent.
 *               A mapping of digit to letters is given below.
 *               |1     |2 abc |3 def |
 *               |4 ghi |5 jkl |6 mno |
 *               |7 pqrs|8 tuv |9 wxyz|
 *
 * Author      : Evan Lau
 * Date        : 2016/02/27
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char alpha[9][4] = {
    {},
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'}
};
int alphaSize[] = {0, 3, 3, 3, 3, 3, 4, 3, 4};

void letterComb(char** res, int* index, int* arr, int digitsSize, int depth, int size)
{
    int tmpSize = 0;

    if (depth == digitsSize)
    {
        res[*index][digitsSize] = '\0';
        (*index)++;
        return;
    }

    tmpSize = size / alphaSize[arr[depth] - 1];
    for (int i = 0; i < alphaSize[arr[depth] - 1]; i++)
    {
        for (int j = 0; j < tmpSize; j++)
        {
            res[(*index) + j][depth] = alpha[arr[depth] - 1][i];
        }
        letterComb(res, index, arr, digitsSize, depth + 1, tmpSize);
    }
}

/**
 * Return an array of size *returnSize.
 * Note : The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize)
{
    char **ret = NULL;
    int digitsSize = 0;
    int arr[16];
    int index = 0;

    // Convert array of char to array of int
    for (int i = 0; i < (int)strlen(digits); i++)
    {
        if ((digits[i] - '0' != 1) && (digits[i] - '0' != 0))
        {
            arr[digitsSize++] = digits[i] - '0';
        }
    }

    // Calculate the returnSize
    *returnSize = alphaSize[arr[0] - 1];
    for (int i = 1; i < digitsSize; i++)
    {
        *returnSize *= alphaSize[arr[i] - 1];
    }

    ret = (char **)malloc(sizeof(char *) * *returnSize);
    for (int i = 0; i < *returnSize; i++)
    {
        ret[i] = (char *)malloc(sizeof(char) * (digitsSize + 1));
    }

    letterComb(ret, &index, arr, digitsSize, 0, *returnSize);

    return ret;
}

int main()
{
    char arr[] = "273";
    int size;
    char **res;

    res = letterCombinations(arr, &size);

    printf("Size : %d\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", res[i]);
    }

    for (int i = 0; i < size; i++)
    {
        free(res[i]);
    }
    free(res);

    return 0;
}
