/**
 * Description : Palindrome Number
 *               Determine whether an integer is a palindrome. Do this without
 *               extra space.
 * Author      : Evan lau
 * Date        : 2015.10.23
 */

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    int y = 0;
    int z = x;
    
    if (x < 0)
        return false;

    while (z != 0)
    {
        y = y * 10 + z % 10;
        z = z / 10;
    }

    if (y == x)
        return true;
    else
        return false;
}

int main()
{
    int n = -1321;

    if (isPalindrome(n))
        printf("Yes\n");
    else
        printf("No\n");
    
    return 0;
}


