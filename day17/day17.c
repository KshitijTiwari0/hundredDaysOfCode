#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;

    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int w = right - left;
        int current_area = h * w;
        if (current_area > max_area) {
            max_area = current_area;
        }

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(height[0]);
    int result = maxArea(height, heightSize);
    printf("Max Area: %d\n", result); // Output: Max Area: 49
    return 0;
}
