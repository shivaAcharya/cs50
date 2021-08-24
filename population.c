#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int start, end, result, years;
    
    do 
    {
        start = get_int("Start size: ");
    } 
    while (start < 9);

    // Prompt for end size
    do 
    {
        end = get_int("End size: ");
    } 
    while (end < start);
    
    // Calculate number of years until we reach threshold
    result = start;
    for (years = 0; result < end; years++)
    {
        // Calculate number of llamas each year
        result = result + result / 3 - result / 4;
    }

    // Print number of years
    printf("Years: %i\n", years);
}