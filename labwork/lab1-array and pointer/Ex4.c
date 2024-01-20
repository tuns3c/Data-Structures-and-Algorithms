#include <stdio.h>

int is_prime(int number) { 
    // check prime number
    if (number <= 1)
        return 0;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0)
            return 0;
    }
    return 1;
}

// check sphenic number
int is_sphenic(int number) {
    int count = 0;
    for (int i = 2; count < 3 && i * i <= number; ++i) {
        if (number % i == 0 && is_prime(i)) {
            while (number % i == 0) {
                number = number / i;
            }
            count++;
        }
    }
    if (number > 1 && is_prime(number))
        count++;
    return count == 3;
}

int main() {
    int number = 2023; // static data
    if (is_sphenic(number))
        printf("%d is sphenic number", number);
    else
        printf("\n%d is not sphenic number", number);
    return 0;
}

//----------------------------------------------------------------------------------
// pseudocode
/*
Function is_prime(number):
- If number <= 1, return 0 (false).
- For each integer i from 2 to the square root of number:
- If number is divisible by i, return 0 (false).
- If no divisors are found, return 1 (true).

Function is_sphenic(number):
- Initialize a counter variable count to 0.
- For each integer i from 2 to the square root of number:
  If number is divisible by i and i is a prime number:
  While number is divisible by i, update number to number/i.
  -> count increase.
- If number is greater than 1 and number is a prime number, -> count increase.
- If count equals 3, return true. Otherwise, return false.

Main:
- Set a static value for number (in this case, number = 2023).
- Call the function is_sphenic(number).
- If is_sphenic(number) returns true, print the number is a sphenic number. 
Otherwise, print the number is not a sphenic number.
*/



//----------------------------------------------------------------------------------
// complexity of this program:
/*
- The loop in is_prime function runs from 2 to the square root of number
    -> time complexity: O(sqrt(n)).

- The loop in is_sphenic function also runs from 2 to the square root of the number. 
Addition, for each iteration, we call the is_prime function 
    -> total time complexity is: O(sqrt(n) * sqrt(n)) = O(n).
*/