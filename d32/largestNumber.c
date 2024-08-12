#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom comparator function for qsort
int compare(const void* a, const void* b) {
    char order1[22];  // 10 digits for the first number + 10 digits for the second number + 1 for '\0'
    char order2[22];  // 10 digits for the first number + 10 digits for the second number + 1 for '\0'

    // Convert integers to strings and concatenate them in both possible orders
    sprintf(order1, "%d%d", *(int*)a, *(int*)b);
    sprintf(order2, "%d%d", *(int*)b, *(int*)a);

    // Compare the two concatenated results
    return strcmp(order2, order1); // Descending order
}

char* largestNumber(int* nums, int numsSize) {
    // Sort the array using the custom comparator
    qsort(nums, numsSize, sizeof(int), compare);

    // Allocate memory for the result string
    char* result = (char*)malloc(numsSize * 11 * sizeof(char)); // 10 digits per number + null terminator
    result[0] = '\0';

    // Handle the case where the largest number is 0
    if (nums[0] == 0) {
        strcpy(result, "0");
        return result;
    }

    // Concatenate sorted numbers into the result string
    for (int i = 0; i < numsSize; i++) {
        char temp[12];
        sprintf(temp, "%d", nums[i]);
        strcat(result, temp);
    }

    return result;
}

int main() {
    // Test case
    int nums[] = {1000000000, 1000000000};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    char* result = largestNumber(nums, numsSize);
    printf("Largest Number: %s\n", result);

    free(result); // Free the allocated memory
    return 0;
}
