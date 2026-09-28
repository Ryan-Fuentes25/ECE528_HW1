#include <stdio.h>

int main(void)
{
    int n;
    int a = 0;   // F(0)
    int b = 1;   // F(1)
    int next;
    int i;

    printf("ECE 528/L - Ryan Fuentes - HW1\n");
    printf("Enter N (2 or greater): ");

    // make sure the user typed an integer that is at least 2
    if (scanf("%d", &n) != 1 || n < 2)
    {
        printf("Invalid input. Please enter an integer N >= 2.\n");
        return 1;
    }

    // keep N small so the numbers fit in an int
    if (n > 40)
    {
        printf("N is too large. Please enter N <= 40.\n");
        return 1;
    }

    printf("Fibonacci sequence up to %d terms:\n", n);
    printf("%d %d", a, b);

    // each new term is the sum of the last two
    for (i = 2; i <= n; i++)
    {
        next = a + b;
        printf(" %d", next);
        a = b;
        b = next;
    }
    printf("\n");

    printf("F(%d) = %d\n", n, b);

    return 0;
}