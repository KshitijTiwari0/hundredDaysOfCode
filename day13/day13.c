#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = malloc(2 * sizeof(int));  
    *returnSize = 0; 

    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) {
            result[0] = left+1;   
            result[1] = right+1;
            *returnSize = 2;   
            break;             
        } else if (sum < target) {
            left++;   
        } else {
            right--;  
        }
    }

    if (*returnSize == 0) { // No solution found
        free(result);       // Free memory to avoid leak
        return NULL;
    } else {
        return result;
    }
}
