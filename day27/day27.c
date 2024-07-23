#include <stdio.h>

int singleNonDuplicate(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // Ensure mid is even for comparison
        if (mid % 2 == 1) {
            mid--;
        }
        
        // Compare the element at mid with the next element
        if (nums[mid] == nums[mid + 1]) {
            // If they are the same, move the left pointer to mid + 2
            // This means the single element is on the right half
            left = mid + 2;
        } else {
            // If they are not the same, move the right pointer to mid
            // This means the single element is on the left half or is the mid element
            right = mid;
        }
    }
    
    // When left equals right, we have found the single element
    return nums[left];
}

// Example usage:
int main() {
    int nums1[] = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("The single element in nums1 is: %d\n", singleNonDuplicate(nums1, size1));
    
    int nums2[] = {3, 3, 7, 7, 10, 11, 11};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("The single element in nums2 is: %d\n", singleNonDuplicate(nums2, size2));
    
    return 0;
}
