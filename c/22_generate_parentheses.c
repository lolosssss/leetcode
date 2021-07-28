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
#include <stdbool.h>

void foo(int l, int r, char **res, char *stack,int n, int top)
{

}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assum caller calls free().
 */
char** generateParentheses(int n, int* returnSize)
{
    char **res = NULL;
    char stack[2 * n];
    int top = 0;

    res = (char **)malloc(sizeof(char *) * 128);
    for (int i = 0; i < 128; i++)
    {
        res[i] = (char *)malloc(sizeof(char) * (n * 2 + 1));
    }

    *returnSize = 0;

    foo(n, n, res, stack, n, top);

    return res;
}

int main(void)
{
    char **res = NULL;
    int size = 0;

    res = generateParentheses(5, &size);

    printf("size = %d\n", size);

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
