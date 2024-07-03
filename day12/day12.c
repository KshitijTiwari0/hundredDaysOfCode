int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* result = malloc(numsSize * sizeof(int));
    int left = 0, right = numsSize - 1;
    *returnSize = numsSize;

    for (int i = numsSize - 1; i >= 0; i--) {
        if (abs(nums[left]) >= abs(nums[right])) {
            result[i] = nums[left] * nums[left];
            left++;
        } else {
            result[i] = nums[right] * nums[right];
            right--;
        }
    }
    return result;
}
