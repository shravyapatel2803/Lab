#include <stdio.h>

// Function to merge two subarrays
void merge(double arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    double leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Iterative Merge Sort function
void mergeSort(double arr[], int n) {
    int currSize;  // Size of subarrays to be merged
    int leftStart; // Starting index of left subarray

    // Merge subarrays in bottom-up manner
    for (currSize = 1; currSize <= n - 1; currSize = 2 * currSize) {
        for (leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) {
            int mid = leftStart + currSize - 1;
            int rightEnd = (leftStart + 2 * currSize - 1 < n - 1) ? leftStart + 2 * currSize - 1 : n - 1;

            merge(arr, leftStart, mid, rightEnd);
        }
    }
}

// Function to print the array
void printArray(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    double arr[] = {3, 7, 6, -10, 15, 23.5, 55, -13};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    mergeSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}