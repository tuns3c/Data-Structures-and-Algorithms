#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 100

typedef struct {
    int sign;            // 1 for positive, -1 for negative 
    int digits[MAX_DIGITS];  
    int length;          
} unbounded_integer;

// create unbounded_integer func
void initialize(unbounded_integer* number) {
    number->sign = 1;
    for (int i = 0; i < MAX_DIGITS; i++) {
        number->digits[i] = 0;
    }
    number->length = 0;
}

// add new digits at any place in an integer
void add_digit(unbounded_integer* number, int digit) {
    if (number->length < MAX_DIGITS) {
        number->digits[number->length] = digit;
        number->length++;
    } else {
        printf("max place in this integer number\n");
    }
}

// remove a digit at a specfic position in an integer
void remove_digit(unbounded_integer* number, int position) {
    if (position >= 0 && position < number->length) {
        for (int i = position; i < number->length - 1; i++) {
            number->digits[i] = number->digits[i + 1];
        }
        number->digits[number->length - 1] = 0;
        number->length--;
    } else {
        printf("invalid position.\n");
    }
}

// calculate the sum of all digits from an unbounded integer
int sum_all_digits(unbounded_integer* number) {
    int sum = 0;
    for (int i = 0; i < number->length; i++) {
        sum += number->digits[i];
    }
    return sum;
}

// display the whole number on the screen
void display(unbounded_integer* number) {
    if (number->sign == -1) {
        printf("-");
    }
    for (int i = 0; i < number->length; i++) {
        printf("%d", number->digits[i]);
    }
    printf("\n");
}

int main() {
    unbounded_integer number;
    initialize(&number);

    add_digit(&number, 1);                   
    add_digit(&number, 1);
    add_digit(&number, 0);
    add_digit(&number, 7);
    add_digit(&number, 2);
    add_digit(&number, 0);
    add_digit(&number, 2);
    add_digit(&number, 3);

    printf("integer number: ");
    display(&number);

    remove_digit(&number, 2);

    printf("integer number after remove: ");
    display(&number);

    int sum = sum_all_digits(&number);
    printf("sum of all digits of an unbounded integer: %d\n", sum);

    return 0;
}