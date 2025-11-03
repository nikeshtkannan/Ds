#include <stdio.h>

void insertion(int arr[],int size){
    for(int i=1;i<size;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

int main() {
    int arr[] = {8, 2, 5, 3, 9, 4, 7, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion(arr, n);

    printf("Insertion Sorted: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}