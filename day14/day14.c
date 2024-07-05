/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    // Allocate memory for the result array
    int* result = (int*)malloc(numsSize * sizeof(int));

    *returnSize = numsSize;

    // Initialize the first element of result to 1 

    result[0] = 1;

    // Fill in the result array with the products of all elements to the left

    for(int i = 1; i < numsSize;i++)
    {
        result[i] = result[i-1] * nums[i-1];
    }

    // Now calculate the product of elements to the right
    // Initialize a variable to keep track of the running product of elements to the right

    int rightProduct = 1;

    // Update the result array with the product of elements to the right

    for(int i = numsSize - 1; i>=0;i--)
    {
        result[i] = result[i] * rightProduct;
        rightProduct *= nums[i];
    }

    return result;

}