/**
 * Description : Generate Parentheses
 *               Given n pairs of parentheses, write a function to generate all
 *               combinations of wellformed parentheses.
 *               For example, given n = 3, a solution set is:
 *               "((()))", "(()())", "(())()", "()(())", "()()()"
 * Author      : Evan Lau
 * Date        : 2016/03/03
 */

#include <stdio.h>
#include <stdlib.h>

void foo(char **res, int n, int* returnSize)
{
    char stack[64];
    int top = 0;


}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assum caller calls free().
 */
char** generateParentheses(int n, int* returnSize)
{
    char **res = NULL;

    res = (char **)malloc(sizeof(char *) * 128);
    for (int i = 0; i < 128; i++)
    {
        res[i] = (char *)malloc(sizeof(char) * n * 2);
    }

    *returnSize = 0;
    foo(res, n, returnSize);

    return res;
}

int main(void)
{
    char **res = NULL;
    int size = 0;

    res = generateParentheses(3, &size);

    for (int i = 0; i < size; i++)
    {
        printf("%s\n", res[i]);
    }

    for (int i = 0; i < size; i++)
    {
        free(res[i]);
    }
    free(res);
    res = NULL;

    return 0;
}
