#include<stdio.h>

typedef struct Complex {
    double real;
    double imaginary;
} Complex;

// add operator
Complex add(Complex n1,Complex n2)
{
      Complex temp;
      temp.real = n1.real + n2.real;
      temp.imaginary = n1.imaginary + n2.imaginary;
      return(temp);
}

// multiply operator
Complex multiply(Complex n1, Complex n2)
{
    Complex temp;
    temp.real = n1.real*n2.real - n1.imaginary*n2.imaginary;                          // (ac - bd) + (ad + bc)i        formula
    temp.imaginary = n1.real*n2.imaginary + n1.imaginary*n2.real;
    return(temp);
}

int main()
{
    Complex n1, n2, result;

    // static data for 2 complex numbers
    n1.real = 1.0;
    n1.imaginary = 5.0;

    n2.real = 9.0;
    n2.imaginary = 6.0;

    result = add(n1, n2);
    printf("add operator = %.1lf + %.1lfi", result.real, result.imaginary);

    result = multiply(n1, n2);
    printf("\nmultiply operator = %.1lf + %.1lfi", result.real, result.imaginary);

    return 0;
}
