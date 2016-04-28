/**
 * Description : Candy
 *               There are N children standing in a line. Each child is assigned
 *               a rating value. You are giving candies to these children subje-
 *               cted to the following requirements:
 *               . Each child must have at least one candy.
 *               . Children with a higher rating get more candies than their ne-
 *                 ightbors.
 *               What is the minimum candies you must give?
 * Author      : Evan Lau
 * Date        : 2016/04/27
 */

#include <stdio.h>

int candy(int* ratings, int ratingsSize)
{
    int candy[ratingsSize];
    int sum = 0;
    int i;

    if (ratingsSize < 2)
    {
        return ratingsSize;
    }

    for (i = 0; i < ratingsSize; i++)
    {
        candy[i] = 1;
    }

    for (i = 1; i < ratingsSize; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            if (candy[i] <= candy[i - 1])
            {
                candy[i] = candy[i - 1] + 1;
            }
        }
    }

    for (i = ratingsSize - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            if (candy[i] <= candy[i + 1])
            {
                candy[i] = candy[i + 1] + 1;
            }
        }
    }

    for (i = 0; i < ratingsSize; i++)
    {
        sum += candy[i];
    }

    return sum;
}

int main(void)
{
    int arr1[] = {1, 2, 2};
    int arr2[] = {3, 2, 1, 1, 2, 3};

    printf("%d\n", candy(arr1, 3));
    printf("%d\n", candy(arr2, 6));

    return 0;
}
