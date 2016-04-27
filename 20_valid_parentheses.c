/**
 * Description : Valid Parentheses
 *               Given a string containing just the characters '(', ')', '{',
 *               '}', '[' and ']', determine if the input string is valid.
 *               The brackets must close in the correct order, "()" and
 *               "()[]{}" are all valid but "(]" and "([)]" are not.
 * Author      : Evan Lau
 * Date        : 2016/03/02
 */

#include <stdio.h>
#include <stdbool.h>

bool isValid(char* s)
{
    char *p = s;
    char que[16];
    int top = 0;

    while (*p != '\0')
    {
        if (*p == '(' || *p == '[' || *p == '{')
        {
            que[top++] = *p;
        }

        if (*p == ')')
        {
            if (que[--top] != '(')
                return false;
        }

        if (*p == ']')
        {
            if (que[--top] != '[')
                return false;
        }

        if (*p == '}')
        {
            if (que[--top] != '{')
                return false;
        }

        p++;
    }

    if (top != 0)
        return false;
    else
        return true;
}

int main(void)
{
    if (isValid("(){}[]"))
        printf("true\n");
    else
        printf("false\n");

    if (isValid("(})"))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
