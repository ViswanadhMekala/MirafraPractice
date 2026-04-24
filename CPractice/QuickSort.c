#include <stdio.h>

// Helper function to swap two elements using pointers
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partitioning: places the pivot in the correct sorted position
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);    // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int data[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(data) / sizeof(data[0]);
    
    quickSort(data, 0, n - 1);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", data[i]);
    return 0;
}

