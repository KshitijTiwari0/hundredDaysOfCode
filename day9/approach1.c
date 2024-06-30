#include <stdio.h>
#include <stdlib.h>

// Function to merge two arrays
void mergeArrays(int* nums1, int nums1Size, int* nums2, int nums2Size, int* mergedArray) {
    int i = 0, j = 0, k = 0;
    
    // Merge the two arrays into mergedArray
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            mergedArray[k++] = nums1[i++];
        } else {
            mergedArray[k++] = nums2[j++];
        }
    }
    
    // Copy remaining elements of nums1, if any
    while (i < nums1Size) {
        mergedArray[k++] = nums1[i++];
    }
    
    // Copy remaining elements of nums2, if any
    while (j < nums2Size) {
        mergedArray[k++] = nums2[j++];
    }
}

// Function to find the median of two sorted arrays
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    int* mergedArray = (int*)malloc(totalSize * sizeof(int));
    
    // Merge nums1 and nums2 into mergedArray
    mergeArrays(nums1, nums1Size, nums2, nums2Size, mergedArray);
    
    double median;
    if (totalSize % 2 == 0) {
        // If totalSize is even, median is the average of the two middle elements
        int midIndex1 = (totalSize / 2) - 1;
        int midIndex2 = totalSize / 2;
        median = (mergedArray[midIndex1] + mergedArray[midIndex2]) / 2.0;
    } else {
        // If totalSize is odd, median is the middle element
        int midIndex = totalSize / 2;
        median = mergedArray[midIndex];
    }
    
    free(mergedArray);
    return median;
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
