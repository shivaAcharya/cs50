#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars = 0.41;

    // Convert float to int for calculation
    int cents = round(dollars * 100);

    int count = 0;

    // Increase the count by one for every change dispensed.
    while (cents >= 25)
    {
        cents -= 25;
        count++;
    }
    while (cents >= 10)
    {
        cents -= 10;
        count++;
    }
    while (cents >= 5)
    {
        cents -= 5;
        count++;
    }
    while (cents >= 1)
    {
        cents -= 1;
        count++;
    }

    // Print the number of least coins needed.
    printf("%i\n", count);
}
