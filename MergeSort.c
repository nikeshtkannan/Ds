/* algorithm
📘 Merge Sort Algorithm
Algorithm: MERGE_SORT(A, left, right)
- If left < right
- Find the middle index:
mid = (left + right) / 2
- Recursively call MERGE_SORT(A, left, mid)
- Recursively call MERGE_SORT(A, mid+1, right)
- Call MERGE(A, left, mid, right) to merge the two sorted halves




Algorithm: MERGE(A, left, mid, right)
- Create two temporary arrays:
- L[] = A[left … mid]
- R[] = A[mid+1 … right]
- Initialize three indices:
- i = 0 (for L[])
- j = 0 (for R[])
- k = left (for A[])
- While both arrays have elements:
- If L[i] <= R[j], set A[k] = L[i], increment i
- Else set A[k] = R[j], increment j
- Increment k
- Copy any remaining elements of L[] into A[]
- Copy any remaining elements of R[] into A[]



*/




#include <stdio.h>

// Function to merge two halves
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;   // size of left subarray
    int n2 = right - mid;      // size of right subarray

    int L[n1], R[n2];          // temporary arrays

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements of L[]
    while (i < n1)
        arr[k++] = L[i++];

    // Copy remaining elements of R[]
    while (j < n2)
        arr[k++] = R[j++];
}

// Recursive merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, n - 1);

    printf("Sorted array (Merge Sort): ");
    printArray(arr, n);

    return 0;
}