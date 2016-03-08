/**
 * Description : Container with Most Water
 *               Given n non-negative integers a1, a2, a3,..., an, where each 
 *               represents a point at coordinate (i, ai), n vertical lines are
 *               drawn such that the two endpoints of line i is at (i, ai) and 
 *               (i, 0). Find two lines, which together with x-axis forms a 
 *               container, such that the container contains the most water.
 * Author      : Evan Lau
 * Date        : 2015.10.30
 */

#include <stdio.h>

#define min(a,b) (((a)<(b))?(a):(b))

int maxArea(int* height, int heightSize)
{
    int area;
    int max = 0;
    int left = 0;
    int right = heightSize - 1;

    while (left < right)
    {
        area = min(height[left], height[right]) * (right - left);
        if (area > max)
            max = area;

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return max;
}

int main()
{
    int height[5] = {1, 1, 2, 3, 4};

    printf("%d\n", maxArea(height, 5));
    
    return 0;
}


