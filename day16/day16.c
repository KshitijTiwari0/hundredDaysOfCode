#include<stdio.h>
#include<stdlib.h>

int dominantIndex(int* nums, int numsSize) {
    int maxIndex = 0;

    // Find the index of the largest number
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[maxIndex]) {
            maxIndex = i;
        }
    }

    // Check if the largest number is at least twice as much as every other number
    for (int i = 0; i < numsSize; i++) {
        if (i != maxIndex && nums[maxIndex] < 2 * nums[i]) {
            return -1;
        }
    }

    return maxIndex;
}
int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = dominantIndex(nums, numsSize);
    printf("The dominant index is: %d\n", result);

    return 0;
}