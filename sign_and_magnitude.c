#include <stdio.h>
#include <stdlib.h>   // for abs()

int main(void)
{
    int num;

    printf("ECE 528/L - Ryan Fuentes - HW1\n");
    printf("Enter an integer: ");

    // scanf returns 1 if it read one integer successfully
    if (scanf("%d", &num) != 1)
    {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    // figure out the sign
    if (num > 0)
    {
        printf("%d is positive.\n", num);
    }
    else if (num < 0)
    {
        printf("%d is negative.\n", num);
    }
    else
    {
        printf("%d is zero.\n", num);
    }

    // abs() gives the absolute value
    printf("Absolute value: %d\n", abs(num));

    return 0;
}