/**
 * Description : Reverse Vowels of a String
 *               Write a function that takes a string as input and reverse only
 *               the vowels of a string.
 * Author      : Evan Lau
 * Date        : 2016/04/23
 */

#include <stdio.h>
#include <string.h>

char* reverseVowels(char* s)
{
    int left = 0;
    int right = strlen(s);
    char tmp;

    while (left < right)
    {
        while (left < right && s[left] != 'a' && s[left] != 'e' &&
               s[left] != 'i' && s[left] != 'o' && s[left] != 'u' &&
               s[left] != 'A' && s[left] != 'E' && s[left] != 'U' &&
               s[left] != 'I' && s[left] != 'O')
            left++;
        while (left < right && s[right] != 'a' && s[right] != 'e' &&
               s[right] != 'i' && s[right] != 'o' && s[right] != 'u' &&
               s[right] != 'A' && s[right] != 'E' && s[right] != 'O' &&
               s[right] != 'I' && s[right] != 'U')
            right--;

        tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }

    return s;
}

int main(void)
{
    char str[] = {'l', 'e', 'e', 't', 'c', 'o', 'd', 'e', '\0'};
    printf("%s : %s\n", str, reverseVowels(str));

    return 0;
}
