#include <stdio.h>

int main(void)
{
    int input;
    unsigned int n;
    int count = 0;

    printf("ECE 528/L - Ryan Fuentes - HW1\n");
    printf("Enter a non-negative integer: ");

    // make sure the user typed a number
    if (scanf("%d", &input) != 1)
    {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    // no negatives, and nothing bigger than 5000
    if (input < 0 || input > 5000)
    {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    n = input;

    // n &= (n - 1) clears the lowest 1 bit each time,
    // so the number of loops = number of 1 bits
    while (n != 0)
    {
        n &= (n - 1);
        count++;
    }

    printf("Number of bits set in %d: %d\n", input, count);

    return 0;
}