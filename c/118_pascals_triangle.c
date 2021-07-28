/**
 * Description : Pascal's Triangle
 *               Given numRows, generate the first numRows of Pascal's Triangle.
 * Author      : Evan Lau
 * Date        : 2016/04/28
 */

#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int** columnSizes)
{
    if (numRows == 0)
    {
        return NULL;
    }
    
    int **ret = (int **)malloc(sizeof(int *) * numRows);
    int i, j;

    *columnSizes = (int *)malloc(sizeof(int) * numRows);

    for (i = 0; i < numRows; i++)
    {
        ret[i] = malloc(sizeof(int) * (i + 1));
        (*columnSizes)[i] = i + 1;
    }

    ret[0][0] = 1;

    if (numRows == 1)
    {
        return ret;
    }
    
    ret[1][0] = 1;
    ret[1][1] = 1;
    for (i = 2; i < numRows; i++)
    {
        j = 0;
        ret[i][j] = 1;
        ret[i][i] = 1;
        for (j = 1; j < i; j++)
        {
            ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
        }
    }
    
    return ret;
}

int main(void)
{
    int i, j;
    int *columnSizes;
    int **res = generate(5, &columnSizes);

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < columnSizes[i]; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
