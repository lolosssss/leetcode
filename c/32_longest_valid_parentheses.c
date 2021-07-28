/**
 * Description : Longest Valid Parentheses
 *               Given a string containing just the characters '(' and ')', find
 *               the length of the longest valid (well-formed) parentheses
 *               substring. For "(()", the longest valid parentheses substring
 *               is "()", which has length = 2.
 * Author      : Evan Lau
 * Date        : 2016/03/20
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longestValidParentheses(char* s)
{
    int len = strlen(s);
    int max = 0;
    int *stack = (int *)malloc(sizeof(int) * len);

    if (len < 2)
        return 0;

    memset(stack, 0, sizeof(int) * len);

    for (int i = 1; i < len; i++)
    {
        if (s[i] == ')')
        {
            if (s[i - 1] == '(')
            {
                stack[i] = 2 + (i > 1 ? stack[i - 2] : 0);
            }
            else if (i - stack[i - 1] > 0 && s[i - stack[i - 1] - 1] == '(')
            {
                stack[i] = stack[i - 1] + stack[i - stack[i - 1] - 2] + 2;
            }

            if (stack[i] > max)
                max = stack[i];
        }
    }

    return max;
}

int main(void)
{
    char *s1 = "(()";
    char *s2 = ")()())";
    char *s3 = "()(()";

    printf("result of s1 : %d\n", longestValidParentheses(s1));
    printf("result of s2 : %d\n", longestValidParentheses(s2));
    printf("result of s3 : %d\n", longestValidParentheses(s3));

    return 0;
}
