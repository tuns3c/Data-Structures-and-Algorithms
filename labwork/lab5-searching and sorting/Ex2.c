#include <stdio.h>

int binary_search(int arr[], int item, int low, int high) {
    if (high <= low)
        return (item > arr[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == arr[mid])
        return mid + 1;

    if (item > arr[mid])
        return binary_search(arr, item, mid + 1, high);
    return binary_search(arr, item, low, mid - 1);
}

void insertion_sort(int arr[], int n) {
    int i, loc, j, selected;

    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = arr[i];

        loc = binary_search(arr, selected, 0, j);

        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}

void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {11, 23, 34, 12, 2, 82, 45, 56, 100, 88, 99};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: \n");
    print_array(arr, n);

    insertion_sort(arr, n);

    printf("\nAfter sorting: \n");
    print_array(arr, n);

    return 0;
}


/*
Time Complexity:

- Best case: When the array is already sorted, as each element only needs to be compared once, the algorithm runs with a time complexity of O(N)
- Average case: When the array is unsorted or sorted in descending order, the algorithm runs with a time complexity of O(N^2). 
This is because each element needs to be compared with all other elements.
- Worst Case: like the average case.
*/