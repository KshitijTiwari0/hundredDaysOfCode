#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = -1;
    result[1] = -1;

    *returnSize = 2;

    if (numsSize == 0) {
        return result; // Handle empty array case
    }

    // Binary search for the first occurrence
    int low = 0, high = numsSize - 1;
    while (low <= high) {  // Continue until the search space is exhausted
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            result[0] = mid;
            high = mid - 1; // Search for potential earlier occurrences
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Binary search for the last occurrence (reset low)
    low = 0; 
    high = numsSize - 1;
    while (low <= high) {  // Continue until the search space is exhausted
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            result[1] = mid;
            low = mid + 1;  // Search for potential later occurrences
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}
