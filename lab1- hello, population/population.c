#include <stdio.h>
#include <math.h>

int main(void)
{
    // Prompt for start size
    int start, end, result, years;
    years = 0;
    start = 100;
    end = 1000000;
    result = start;
    // do {
    //     printf("Enter starting population of llamas (greater than 9): ");
    //     scanf("%i", start);
    // } while (start < 9);

    // Prompt for end size
    // do {
    //     printf("Enter the ending population of llamas (greater than starting population): ");
    //     scanf("%i", end);
    // } while (end < start);
    
    // Calculate number of years until we reach threshold
    
    for (years; result < end; years++)
    {
        result = result + result/3 - result/4;
    }
    printf("%i", years);
}