/**
 * Description : Add Digits
 *               Given a non-negative integer num, repeatedly add all its digits
 *               until the result has only one digit.
 * Author      : Evan Lau
 * Date        : 2016/04/05
 */

#include <stdio.h>

int addDigits(int num)
{
    return num - (num - 1) / 9 * 9;
}

int main(void)
{
    printf("%d\n", addDigits(38));

    return 0;
}
