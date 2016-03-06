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

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assum caller calls free().
 */
/*char** generateParentheses(int n, int* returnSize)
{
    char **res = NULL;
    char stack[64];
    int top = 0;

    res = (char **)malloc(sizeof(char *) * 128);
    for (int i = 0; i < 128; i++)
    {
        res[i] = (char *)malloc(sizeof(char) * n * 2);
    }

    *returnSize = 0;



    return res;
}*/
char** generateParentheses(int n, int* returnSize)
{
    int ls = 0, rs = 0, i;
    char stack[2*n];
    int top = 0;
    char ** res = malloc(10000*sizeof(char*));
    (* returnSize) = 0;
    while (true) {
        if (top == 2 * n) {
            res[(* returnSize)] = malloc(top+1);
            for (i = 0 ; i < top ; i++) {
                res[(* returnSize)][i] = stack[i];
            }
            res[(* returnSize)][i] = '\0';
            (* returnSize)++;
            while (true) {
                if (top == 0) {
                    break;
                }
                while (stack[top-1] == ')') {
                    rs--;
                    top--;
                }
                // stack[top-1] == '('
                ls--;
                top--;
                if (ls <= rs) {
                    continue;
                } else {
                    stack[top++] = ')';
                    rs++;
                    break;
                }
            }
        }
        if ((* returnSize) != 0 && top == 0) {
            break;
        }
        if (ls < n) {
            stack[top++] = '(';
            ls++;
        } else {
            stack[top++] = ')';
            rs++;
        }
    }
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
