/**
 * Description : Median of Two Sorted Arrays
 *               There are two sorted arrays nums1 and nums2 of size m and n 
 *               respectively. Find the median of the two sorted arrays. The 
 *               overall run time complexity should be O(log(m+n)).
 * Author      : Evan Lau
 * Date        : 2015.10.14
 */

#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    double ret;
    int count = 0;
    int isOdd = (nums1Size + nums2Size) % 2;
    int target = (nums1Size + nums2Size) / 2;

    
    
    return ret;
}


int main()
{
    int arr1[] = {1};
    int arr2[] = {1};

    printf("%f\n", findMedianSortedArrays(arr1, 1, arr2, 1));
    
    return 0;
}

