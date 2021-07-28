/**
 * Description : Remove Element
 *               Given an array and a value, remove all instances of that value
 *               in place and return the new length.
 *               The order of elements can be changed. It doesn't matter what
 *               you leave beyond the new length.
 * Author      : Evan Lau
 * Date        : 2016/03/09
 */

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val)
{
    int index = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[index++] = nums[i];
        }
    }

    return index;
}

int main(void)
{
    int arr1[10] = {1, 1, 3, 1, 2, 1, 5, 6, 7, 8};
    int arr2[10] = {1, 1, 3, 1, 2, 1, 5, 6, 7, 8};
    int arr3[10] = {1, 1, 3, 1, 2, 1, 5, 6, 7, 8};
    int len1 = removeElement(arr1, 10, 3);
    int len2 = removeElement(arr2, 10, 1);
    int len3 = removeElement(arr3, 10, 0);

    printf("len1 = %d\n", len1);
    for (int i = 0; i < len1; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("len2 = %d\n", len2);
    for (int i = 0; i < len2; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    printf("len3 = %d\n", len3);
    for (int i = 0; i < len3; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    return 0;
}
