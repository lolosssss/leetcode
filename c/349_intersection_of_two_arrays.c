/**
 * Description : Intersection of Two Arrays
 *               Given two arrays, write a function to compute their intersect-
 *               ion.
 * Author      : Evan Lau
 * Date        : 2016/05/19
 */

#include <stdio.h>
#include <stdlib.h>

int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size,
                  int *returnSize)
{
    int arr1[1000] = {0};
    int arr2[1000] = {0};
    int i;
    int min = nums1Size > nums2Size ? nums2Size : nums1Size;
    int *ret = NULL;

    ret = (int *)malloc(sizeof(int) * min);

    for (i = 0; i < nums1Size; i++)
    {
        arr1[nums1[i]] = 1;
    }
    for (i = 0; i < nums2Size; i++)
    {
        arr2[nums2[i]] = 1;
    }

    for (i = 0; i < 1000; i++)
    {
        if (arr1[i] != 0 && arr2[i] != 0)
        {
            ret[(*returnSize)++] = i;
        }
    }

    return ret;
}

int main(void)
{
    int arr1[] = {2, 1};
    int arr2[] = {1, 2};
    int *res = NULL;
    int size = 0;

    res = intersection(arr1, 2, arr2, 2, &size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
