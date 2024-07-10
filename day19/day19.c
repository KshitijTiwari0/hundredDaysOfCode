#include <stdio.h>

int maxAscendingSum(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            currentSum += nums[i];
        } else {
            currentSum = nums[i];
        }
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    return maxSum;
}

int main() {
    int nums1[] = {10, 20, 30, 5, 10, 50};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Max ascending subarray sum: %d\n", maxAscendingSum(nums1, numsSize1));

    int nums2[] = {10, 20, 30, 40, 50};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Max ascending subarray sum: %d\n", maxAscendingSum(nums2, numsSize2));

    int nums3[] = {12, 17, 15, 13, 10, 11, 12};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Max ascending subarray sum: %d\n", maxAscendingSum(nums3, numsSize3));

    return 0;
}
