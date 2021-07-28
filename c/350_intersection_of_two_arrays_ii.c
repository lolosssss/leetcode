/**
 * Description : Intersection of Two Arrays II
 *               Given two arrays, write a function to compute their intersec-
 *               tion.
 * Author      : Evan Lau
 * Date        : 2016/05/21
 */

#include <stdio.h>
#include <stdlib.h>

int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size,
               int *returnSize)
{
    int arr1[1000] = {0};
    int arr2[1000] = {0};
    int min = nums1Size > nums2Size ? nums2Size : nums1Size;
    int i;
    int *ret = (int *)malloc(sizeof(int) * min);

    for (i = 0; i < nums1Size; i++)
    {
        arr1[nums1[i]]++;
    }
    for (i = 0; i < nums2Size; i++)
    {
        arr2[nums2[i]]++;
    }

    for (i = 0; i < 1000; i++)
    {
        while (arr1[i] != 0 && arr2[i] != 0)
        {
            ret[(*returnSize)++] = i;
            arr1[i]--;
            arr2[i]--;
        }
    }

    return ret;
}

int main(void)
{
    int arr1[] = {1, 2, 2, 1};
    int arr2[] = {2, 2};
    int *res = NULL;
    int size = 0;

    res = intersect(arr1, 4, arr2, 2, &size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
