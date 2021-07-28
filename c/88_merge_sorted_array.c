/**
 * Description : Merge Sorted Array
 *               Given two sorted integer arrays nums1 and nums2, merge nums2
 *               into nums1 as one sorted array.
 * Author      : Evan Lau
 * Date        : 2016/04/06
 */

#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n)
{
    int i = m - 1;
    int j = 0;
    int l = m + n - 1;

    while (i + 1)
    {
        nums1[l--] = nums1[i--];
    }
    l++;
    i++;

    while (i < m + n)
    {
        if (l < m + n && j < n)
        {
            if (nums1[l] < nums2[j])
            {
                nums1[i++] = nums1[l++];
            }
            else
            {
                nums1[i++] = nums2[j++];
            }
        }
        else
        {
            if (l >= m + n)
            {
                nums1[i++] = nums2[j++];
            }
            else
            {
                nums1[i++] = nums1[l++];
            }
        }
    }
}

int main(void)
{
    int arr1[9] = {1, 3, 5, 7, 9};
    int arr2[4] = {2, 4, 6, 8};

    merge(arr1, 5, arr2, 4);
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    return 0;
}
