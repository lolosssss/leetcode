/**
 * Description : Trapping Rain Water
 *               Given n non-negative integers representing an elevation map
 *               where the width of each bar is 1, compute how much water it is
 *               able to trap after raining.
 * Author      : Evan Lau
 * Date        : 2016/04/12
 */

#include <stdio.h>

int trap(int* height, int heightSize)
{
    if (heightSize < 2)
    {
        return 0;
    }

    int left = 0;
    int right = heightSize - 1;
    int currentHeight = 1;
    int areaAll = 0;
    int areaBar = 0;

    while (left < right)
    {
        while (left < right && height[left] < currentHeight)
        {
            areaBar += height[left++];
        }

        while (left < right && height[right] < currentHeight)
        {
            areaBar += height[right--];
        }

        if (left >= right)
        {
            break;
        }

        areaAll += (right - left + 1);
        currentHeight++;
    }

    if (left == right)
    {
        if (height[left] >= currentHeight)
        {
            areaAll += height[left] + 1 - currentHeight;
        }

        areaBar += height[left];
    }

    return areaAll - areaBar;
}

int main(void)
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int arr2[] = {2, 0, 2};
    int arr3[] = {4, 2, 3};
    int arr4[] = {0, 2, 0};

    printf("%d\n", trap(arr, 12));
    printf("%d\n", trap(arr2, 3));
    printf("%d\n", trap(arr3, 3));
    printf("%d\n", trap(arr4, 3));

    return 0;
}
