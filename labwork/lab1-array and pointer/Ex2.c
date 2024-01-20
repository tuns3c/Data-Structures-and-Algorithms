#include <stdio.h>

void findMax(int *max, int a) {
    if (a > *max) {
        *max = a;
    }
}

int main() {
    int array[] = {11, 23, 38, 44, 15};
    int count_array = sizeof(array) / sizeof(array[0]);
    int max = array[0];

    for(int i = 0; i < count_array; i++) {
        findMax(&max, array[i]);
    }

    printf("The biggest value in array is: %d", max);

    return 0;
}
