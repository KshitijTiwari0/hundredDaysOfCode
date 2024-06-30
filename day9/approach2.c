#include <stdio.h>

// Function to find the median of two sorted arrays
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    int midIndex1 = (totalSize - 1) / 2;
    int midIndex2 = totalSize / 2;
    int i = 0, j = 0, k = 0;
    int current, prev;
    
    while (k <= midIndex2) {
        prev = current;
        if (i < nums1Size && (j >= nums2Size || nums1[i] < nums2[j])) {
            current = nums1[i++];
        } else {
            current = nums2[j++];
        }
        k++;
    }
    
    if (totalSize % 2 == 0) {
        return (prev + current) / 2.0;
    } else {
        return current;
    }
}

// Example usage
int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    
    double median = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("The median is: %.2f\n", median);
    
    return 0;
}
