#include <stdlib.h>
#include <string.h>

int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    int bufferSize = numSize + 10;  // Allocate a buffer large enough to handle carry
    int* result = (int*)malloc(bufferSize * sizeof(int));
    int carry = 0;
    int i = numSize - 1;
    int j = bufferSize - 1;

    // Process from right to left (while there are digits in num or k is non-zero)
    while (i >= 0 || k > 0 || carry > 0) {
        int sum = carry;

        if (i >= 0) {
            sum += num[i--];  // Add the digit from num if available
        }
        if (k > 0) {
            sum += k % 10;    // Add the last digit of k
            k /= 10;
        }

        result[j--] = sum % 10;
        carry = sum / 10;
    }

    *returnSize = bufferSize - j - 1;

    // Shift the result to the beginning of the array
    memmove(result, result + j + 1, (*returnSize) * sizeof(int));

    return result;
}
