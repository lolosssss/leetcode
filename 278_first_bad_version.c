/**
 * Description : First Bad Version
 * Author      : Evan Lau
 * Date        : 2016/04/05
 */

#include <stdio.h>
#include <stdbool.h>

int bad_version;

bool isBadVersion(int version)
{
    return version >= bad_version;
}

int firstBadVersion(int n)
{
    int left = 1;
    int right = n;
    int mid;

    if (n <= 1)
        return n;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (isBadVersion(mid))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

int main(void)
{
    int n;

    printf("input n:");
    scanf("%d", &n);
    printf("input the number of the first bad version:");
    scanf("%d", &bad_version);

    printf("result: %d\n", firstBadVersion(n));

    return 0;
}
