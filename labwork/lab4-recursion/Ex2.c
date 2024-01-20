#include <stdio.h>

int is_palindrome(int arr[], int start, int end) {
    if (start >= end)
        return 1;
    if (arr[start] == arr[end])
        return is_palindrome(arr, start + 1, end - 1);
    else
        return 0;
}

int main() {
    int array1[] = {1, 2, 9, 5, 2};
    printf("array1 = [1, 2, 9, 5, 2]\n");
    int n = sizeof(array1) / sizeof(array1[0]);
    
    if (is_palindrome(array1, 0, n - 1))
        printf("The array1 is a palindrome\n");
    else
        printf("The array1 is not a palindrome\n");

    int array2[] = {1, 3, 5, 3, 1};
    printf("\n\narray2 = [1, 3, 5, 3, 1]\n");
    int m = sizeof(array2) / sizeof(array2[0]);

    if (is_palindrome(array2, 0, m - 1))
        printf("The array2 is a palindrome\n");
    else
        printf("The array2 is not a palindrome\n");
    return 0;
}

// calculate the complexity 
/*
in is_palindrome function, the time complexity of this function is O(n), where n is the number of elements in the array.
in main function, i use the is_palindrome to check array1 and array2 => the complexity is: O(n + m) = O(5 + 5) = O(10)
*/