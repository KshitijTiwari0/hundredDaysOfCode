#include <stdio.h>
#include <stdlib.h>

#define RUN 32
//Function to perform insertion sort on a subarray
void insertionSort(int arr[],int left, int right)
{
    for(int i = left+1;i <=right; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j >=left && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}


// Function to merger two sorted subarrays

void merge(int arr[],int left, int mid, int right)
{
    int len1 = mid - left + 1, len2 = right - mid;

    int *leftArr = (int*)malloc(len1 * sizeof(int));

    int *rightArr = (int*)malloc(len2 * sizeof(int));

    int i = 0,j = 0,k = left;

    while (i < len1 && j < len2) {
        if(leftArr[i] <= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < len1) {
        arr[k++] = leftArr[i++];
    }

    while (j < len2) {
        arr[k++] = rightArr[j++];
    }

    free(leftArr);
    free(rightArr);
}

void timSort(int arr[], int n) {
    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i += RUN) {
        insertionSort(arr, i, ((i + RUN - 1) < (n - 1)) ? (i + RUN - 1) : (n - 1));
    }

    // Merge sorted subarrays
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = ((left + 2 * size - 1) < (n - 1)) ? (left + 2 * size - 1) : (n - 1);

            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}

void sortColors(int* nums, int numsSize) {
    timSort(nums, numsSize);
}

// Helper function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test sortColors
int main() {
    int nums1[] = {2, 0, 2, 1, 1, 0};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    sortColors(nums1, numsSize1);
    printArray(nums1, numsSize1);

    int nums2[] = {2, 0, 1};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    sortColors(nums2, numsSize2);
    printArray(nums2, numsSize2);

    return 0;
}