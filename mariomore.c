#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char space = ' ';
    char pound = '#';
    int height;

    // Prompt user to input height in between 1 and 8.
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    int a = height;

    // Iterate over given height.
    for (int i = 0; i < height; i++)
    {
        // Iterate over each line
        for (int j = 1; j < a; j++)
        {
            printf("%c", space);
        }

        for (int k = height; k >= a; k--)
        {
            printf("%c", pound);
        }

        // Print spaces in between stair up and down
        printf("%c%c", space, space);

        // Repeating in reverse order.
        for (int l = height; l >= a; l--)
        {
            printf("%c", pound);
        }

        // Check if new line is needed.
        if (a > 0)
        {
            printf("\n");
        }
        a--;
    }
}
