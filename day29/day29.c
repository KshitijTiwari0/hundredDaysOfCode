#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    int max_current = nums[0];
    int max_global = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > max_current + nums[i]) {
            max_current = nums[i];
        } else {
            max_current += nums[i];
        }
        
        if (max_current > max_global) {
            max_global = max_current;
        }
    }
    
    return max_global;
}

int main() {
    int nums1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int nums2[] = {1};
    int nums3[] = {5, 4, -1, 7, 8};

    printf("Example 1: %d\n", maxSubArray(nums1, sizeof(nums1)/sizeof(nums1[0]))); // Output: 6
    printf("Example 2: %d\n", maxSubArray(nums2, sizeof(nums2)/sizeof(nums2[0]))); // Output: 1
    printf("Example 3: %d\n", maxSubArray(nums3, sizeof(nums3)/sizeof(nums3[0]))); // Output: 23

    return 0;
}
