#include <stdio.h>

int findPeakElement(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1]) {
            // The peak is in the left half
            right = mid;
        } else {
            // The peak is in the right half
            left = mid + 1;
        }
    }

    // left and right should converge to the peak element
    return left;
}

int main() {
    int nums1[] = {1, 2, 3, 1};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int peak1 = findPeakElement(nums1, size1);
    printf("Peak element index for nums1: %d\n", peak1);

    int nums2[] = {1, 2, 1, 3, 5, 6, 4};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int peak2 = findPeakElement(nums2, size2);
    printf("Peak element index for nums2: %d\n", peak2);

    return 0;
}
