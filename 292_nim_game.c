/**
 * Description : Nim Game
 *               You are playing the following Nim Game with your friend: There
 *               is a heap of stones on the table, each time one of you take
 *               turns to remove 1 to 3 stones. The one who removes the last
 *               stone will be the winner. You will take the first turn to
 *               remove the stones.
 *               Both of you are very clever and have optimal strategies for the
 *               game. Write a function to determine whether you can win the
 *               game given the number of stones in the heap.
 *               For example, if there are 4 stones in the heap, then you will
 *               never win the game: no matter 1, 2, or 3 stones you remove, the
 *               last stone will always be removed by your frined.
 * Author      : Evan lau
 * Date        : 2016/03/27
 */

#include <stdio.h>
#include <stdbool.h>

bool canWinNim(int n)
{
    return (n % 4 == 0) ? false : true;
}

int main(void)
{
    for (int i = 1; i < 20; i++)
    {
        printf("%d stones: ", i);
        if (canWinNim(i) == true)
        {
            printf("win\n");
        }
        else
        {
            printf("lose\n");
        }
    }

    return 0;
}
