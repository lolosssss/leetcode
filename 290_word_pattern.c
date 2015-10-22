/*
 * Description: Given a pattern and a string str, find if str follows the same 
 * pattern.
 * Here follow means a full match, such that there is a bijection between a 
 * letter in pattern and a non-empty word in str.
 * Examples:
 * 1.pattern = "abba", str = "dog cat cat dog" should return true.
 * 2.pattern = "abba", str = "dog cat cat fish" should return false.
 *
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains 
 * lowercase letters separated by a single space.
 */

#include <stdio.h>
#include <stdbool.h>

bool wordPattern(char *pattern, char *str)
{
    
}

int main()
{
    char pattern[] = "aabb";
    char str1[] = "dog dog cat cat";
    char str2[] = "dog cat cat dog";
    
    if (wordPattern(pattern, str1) == true)
        printf("TRUE\n");
    else
        printf("FALSE\n");
    
    return 0;
}





