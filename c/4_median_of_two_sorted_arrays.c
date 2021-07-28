/**
 * Description : Median of Two Sorted Arrays
 *               There are two sorted arrays nums1 and nums2 of size m and n
 *               respectively. Find the median of the two sorted arrays. The
 *               overall run time complexity should be O(log(m+n)).
 * Author      : Evan Lau
 * Date        : 2015/10/14
 *               Update: 2016/03/18
 */

#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int arr[nums1Size + nums2Size];
    int index1 = 0;
    int index2 = 0;
    double ret;

    for (int i = 0; i < nums1Size + nums2Size; i++)
    {
        if (nums1[index1] < nums2[index2])
        {
            if (index1 < nums1Size)
            {
                arr[i] = nums1[index1++];
            }
            else
            {
                arr[i] = nums2[index2++];
            }
        }
        else
        {
            if (index2 < nums2Size)
            {
                arr[i] = nums2[index2++];
            }
            else
            {
                arr[i] = nums1[index1++];
            }
        }
    }

    ret = ((nums1Size + nums2Size) % 2) ? (double)arr[(nums1Size + nums2Size - 1) / 2] : ((arr[(nums1Size + nums2Size - 1) / 2] + arr[(nums1Size + nums2Size) / 2]) / 2.0);
    return ret;
}

int main()
{
    int arr1[] = {1, 4, 7, 9, 10};
    int arr2[] = {2, 3, 5, 6, 8};

    printf("%f\n", findMedianSortedArrays(arr1, 5, arr2, 2));

    return 0;
}

