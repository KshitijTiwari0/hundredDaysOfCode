#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If mid element is greater than the rightmost element, 
        // the minimum must be to the right of mid
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            // If mid element is less than or equal to the rightmost element,
            // the minimum must be to the left of mid (including mid itself)
            right = mid;
        }
    }

    // After the loop, left == right, pointing to the minimum element
    return nums[left];
}

int main() {
    int nums1[] = {3, 4, 5, 1, 2};
    int nums2[] = {4, 5, 6, 7, 0, 1, 2};
    int nums3[] = {11, 13, 15, 17};

    printf("Minimum element in nums1: %d\n", findMin(nums1, 5));  // Output: 1
    printf("Minimum element in nums2: %d\n", findMin(nums2, 7));  // Output: 0
    printf("Minimum element in nums3: %d\n", findMin(nums3, 4));  // Output: 11

    return 0;
}
