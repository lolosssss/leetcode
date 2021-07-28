/**
 * Description : Coin Change
 *               You are given coins of different denominations and a total
 *               amount of money amount. Write a funcion to compute the fewest
 *               number of coins that you need to make up that amount. If that
 *               amount of money cannot be made up by any combination of the
 *               coins, return -1.
 * Author      : Evan Lau
 * Date        : 2016/04/01
 */

#include <stdio.h>
#include <stdlib.h>

int coinChange(int* coins, int coinsSize, int amount)
{
    int dp[amount + 1];
    int i, j;

    for (i = 0; i <= amount; i++)
    {
        dp[i] = -1;
    }
    dp[0] = 0;
    for (i = 1; i <= amount; i++)
    {
        for (j = 0; j < coinsSize; j++)
        {
            if (i >= coins[j] && dp[i - coins[j]] >= 0)
            {
                if (dp[i] > 0)
                {
                    dp[i] = dp[i]<(dp[i-coins[j]]+1)?dp[i]:(dp[i-coins[j]]+1);
                }
                else
                {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }

    return dp[amount];
}

int main(void)
{
    int coins1[] = {1, 2, 5};
    int coins2[] = {2};
    int coins3[] = {2, 5, 10, 1};
    int coins4[] = {186, 419, 83, 408};

    printf("case 1 : %d\n", coinChange(coins1, 3, 11));
    printf("case 2 : %d\n", coinChange(coins2, 1, 3));
    printf("case 3 : %d\n", coinChange(coins3, 4, 27));
    printf("case 4 : %d\n", coinChange(coins4, 4, 6249));

    return 0;
}
