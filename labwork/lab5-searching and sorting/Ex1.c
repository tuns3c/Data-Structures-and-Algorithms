#include <stdio.h>

void insert(int arr[], int n, int key) {
    int i, j, mid, low, high;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    for (i = n - 1; i >= high + 1; i--)
        arr[i + 1] = arr[i];

    arr[i + 1] = key;
}

void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, n = 10, key = 6;
    printf("array = "),print_array(arr, n);
    insert(arr, n, key);
    n = n + 1;
  
    printf("\nAfter insert, array is:\narray = ");
    print_array(arr, n);

    return 0;
}
