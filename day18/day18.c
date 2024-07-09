#include <stdio.h>
#include <limits.h> // For INT_MAX
#include <stdlib.h>




bool increasingTriplet(int* nums, int numsSize) {
    if (numsSize < 3) {
        return false; // Triplet not possible with less than 3 elements
    }

    int first = INT_MAX;  // Initialize to a very large value
    int second = INT_MAX; // Initialize to a very large value

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= first) {
            first = nums[i]; // Update the smallest value seen so far
        } else if (nums[i] <= second) {
            second = nums[i]; // Update the second smallest value seen so far
        } else {
            return true; // Found a triplet: first < second < nums[i]
        }
    }

    return false; // No increasing triplet found
}

// Example usage
int main() {
    int nums[] = {2, 1, 5, 0, 4, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    if (increasingTriplet(nums, numsSize)) {
        printf("Increasing triplet found!\n");
    } else {
        printf("No increasing triplet found.\n");
    }

    return 0;
}
