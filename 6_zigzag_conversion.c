/**
 * Description : ZigZag Conversion
 *               The string "PAYPALISHIRING" is written in a zigzag pattern on 
 *               a given number of rows like this:( you may want to display this 
 *               pattern in fixed font for better legibility)
 *               P   A   H   N
 *               A P L S I I G 
 *               Y   I   R
 *
 *               A     G     M
 *               B   F H   L N
 *               C E   I K   O
 *               D     J     P 
 *
 *               And then read line by line: "PAHNAPLSIIGYIR"
 *               Write the code that will take a string and make this vonversion 
 *               given a number of rows:
 *               string convert(string text, int nRows);
 *               convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 * Author      : Evan Lau
 * Data        : 2015.10.15
 */

#include <stdio.h>
#include <stdlib.h>

char* convert(char* s, int numRows)
{
    int len = 0;
    int i = 0;
    int index = 0;
    int tmp = 0;
    int n = numRows * 2 - 2;
    int step = n;
    char *ptr = s;
    char *ret = NULL;

    if (numRows == 1)
        return s;
    
    while (*ptr++ != '\0')
        len++;

    if (len < numRows)
        return s;

    ret = (char *)malloc((len + 1) * sizeof(char));

    for (i = 0; i < numRows; i++)
    {
        tmp = i;
        step = n - 2 * i;
        while (tmp < len)
        {
            *(ret + index) = s[tmp];
            tmp += step;
            if (step)
                index++;
            step = n - step;
        }
    }

    *(ret + index) = '\0';

    return ret;
}

int main(int argc, char *argv[])
{
    char src[] = "hsscheopebsyzagbpcwcbmvuwmrgpixwarajvpycssartgskkqomcjiaxzgnhfljxmsudswvlxogfgsqygebsm";
    char *res = NULL;
    char sr[] = "123";

    printf("%s\n", sr);
    res = convert(sr, 68);
    
    printf("%s\n", res);
    free(res);
    res = NULL;
    
    return 0;
}

