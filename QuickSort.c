/*
algorithm
---------
QUICKSORT(A, low, high)
- If low < high
- Partition the array → find the pivot position p
- Recursively call QUICKSORT(A, low, p-1) (left side)
- Recursively call QUICKSORT(A, p+1, high) (right side)

PARTITION(A, low, high)
- Choose the pivot (commonly A[high]).
- Set i = low - 1.
- For j = low to high-1:
- If A[j] <= pivot:
- Increment i
- Swap A[i] and A[j]
- After loop, swap A[i+1] and A[high].
- Return i+1 (pivot index).

*/






#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // choose last element as pivot
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nOriginal array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array (Quick Sort): ");
    printArray(arr, n);

    return 0;
}