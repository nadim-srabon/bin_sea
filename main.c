#include <stdio.h>

int binary_search(int arr[], int low, int high, int tar) {
    if (high < low) {
        return -1; // Target not found
    }

    int mid = (low + high) / 2;

    if (arr[mid] == tar) {
        return mid; // Target found
    } else if (arr[mid] > tar) {
        return binary_search(arr, low, mid - 1, tar); // Search in left half
    } else {
        return binary_search(arr, mid + 1, high, tar); // Search in right half
    }
}

int searchInsert(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}


void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {2, 4, 6, 3, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int low = 0;
    int high = n - 1;
    int tar = 3;

    int result = searchInsert(arr,n,tar);

   //int result = binary_search(arr, low, high, tar);

    if (result != -1) {
        printf("Target %d found at index %d\n", tar, result);
    } else {
        printf("Target %d not found in any index\n", tar);
    }

    return 0;
}
