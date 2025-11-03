#include <stdio.h>

#define MAX 20

int a[MAX], b[MAX];   // Global arrays

// Function to merge two sorted subarrays: a[l..mid] and a[mid+1..r]
void merge(int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;

    // Compare elements from both halves
    while (i <= mid && j <= h) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements from right half
    while (j <= h) {
        b[k] = a[j];
        j++;
        k++;
    }

    // Copy merged elements back into original array
    for (k = l; k <= h; k++) {
        a[k] = b[k];
    }
}

// Recursive Merge Sort
void mergesort(int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        mergesort(l, mid);       // Sort left half
        mergesort(mid + 1, h);   // Sort right half
        merge(l, mid, h);        // Merge the two halves
    }
}

int main() {
    int n = 8;   // Fixed size
    int i;

    // Predefined array
    int temp[8] = {38, 27, 43, 3, 9, 82, 10, 5};

    // Copy into global array 'a'
    for (i = 0; i < n; i++) {
        a[i] = temp[i];
    }

    printf("Original array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    mergesort(0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}