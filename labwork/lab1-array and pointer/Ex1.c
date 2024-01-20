// Pseudocode
/*
Function swap(number)
1. Initialize count as the base 10 logarithm of number
2. Initialize first_digit as number divided by 10 to the power of count
3. Initialize last_digit as the remainder of number when divided by 10
4. Subtract first_digit * 10 to the power of count from number
5. Add last_digit * 10 to the power of count to number
6. Subtract last_digit from number
7. Add first_digit to number
8. Return number

Function main()
1. Initialize number 
2. Print the value of number
3. Print the value of number after swapping

*/



#include <stdio.h>
#include <math.h>

int swap(int number) {
    int count = (int)log10(number);

    int first_digit = number / pow(10, count);
    int last_digit = number % 10;

    number = number - first_digit * pow(10, count);
    number = number + last_digit * pow(10, count);

    number = number - last_digit;
    number = number + first_digit;

    return number;
}

int main() {
    int number = 20112023;
    printf("number: %d", number);
    printf("\nnumber after swapping: %d", swap(number));
    return 0;
}

