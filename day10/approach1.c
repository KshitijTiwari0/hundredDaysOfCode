#include <stdio.h>

void swap(int* nums, int first, int last) {
    int temp = nums[first];
    nums[first] = nums[last];
    nums[last] = temp;
}

int missingNumber(int* nums, int numsSize) {
    int p = 0;
    while (p < numsSize) {
        int correct = nums[p];
        if (nums[p] < numsSize && nums[p] != nums[correct]) {
            swap(nums, p, correct);
        } else {
            p++;
        }
    }

    for (p = 0; p < numsSize; p++) {
        if (nums[p] != p) {
            return p;
        }
    }
    return numsSize;
}

int main() {
    int nums[] = {3, 0, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int missing = missingNumber(nums, numsSize);
    printf("Missing number is: %d\n", missing);
    return 0;
}
