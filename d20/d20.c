
#include <stdlib.h>

#include <stdio.h>

typedef struct {
    int key;
    int value;
} KeyValuePair;

KeyValuePair* createKeyValuePair(int key, int value) {
    KeyValuePair* pair = malloc(sizeof(KeyValuePair));
    if (pair == NULL) exit(EXIT_FAILURE); // Always check for malloc failure
    pair->key = key;
    pair->value = value;
    return pair;
}

void freeKeyValuePair(KeyValuePair* pair) {
    free(pair);
}

void insertIntoMap(KeyValuePair*** map, int* size, int key, int value) {
    // Check if key already exists in the map to update the value
    for (int i = 0; i < *size; i++) {
        if ((*map)[i]->key == key) {
            (*map)[i]->value = value;
            return; // Exit if key found and value updated
        }
    }

    // Allocate space for the new KeyValuePair
    *map = realloc(*map, (*size + 1) * sizeof(KeyValuePair*));
    if (*map == NULL) exit(EXIT_FAILURE); // Always check for realloc failure
    (*map)[* size] = createKeyValuePair(key, value);
    (*size)++;
}

int findLucky(int* arr, int arrSize) {
    KeyValuePair** map = NULL;
    int size = 0;

    // Building the frequency map
    for (int i = 0; i < arrSize; i++) {
        int freq = 0;
        for (int j = 0; j < arrSize; j++) {
            if (arr[i] == arr[j]) {
                freq++;
            }
        }
        insertIntoMap(&map, &size, arr[i], freq);
    }

    int largestLucky = -1;
    // Finding the largest 'lucky' integer
    for (int i = 0; i < size; i++) {
        if (map[i]->key == map[i]->value && map[i]->key > largestLucky) {
            largestLucky = map[i]->key;
        }
    }

    // Free the allocated memory for the map
    for (int i = 0; i < size; i++) {
        freeKeyValuePair(map[i]);
    }
    free(map);

    return largestLucky;
}

int main() {
    int arr[] = {2, 2, 3, 4}; // Example input array
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int luckyNumber = findLucky(arr, arrSize);

    if (luckyNumber != -1) {
        printf("The largest lucky number is: %d\n", luckyNumber);
    } else {
        printf("There are no lucky numbers in the array.\n");
    }

    return 0;
}