int maxProduct(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    int firstMax = 0, secondMax = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > firstMax) {
            secondMax = firstMax;
            firstMax = nums[i];
        } else if (nums[i] > secondMax) {
            secondMax = nums[i];
        }
    }

    return (firstMax - 1) * (secondMax - 1);
}
