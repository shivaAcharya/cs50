#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int image[3][3][3] = {{{10, 20, 30}, {40, 50, 60}, {70, 80, 90}}, {{110, 130, 140}, {120, 140, 150}, {130, 150, 160}}, {{200, 210, 220}, {220, 230, 240}, {240, 250, 255}}};

int main(void)
{
    int avgRed, avgGreen, avgBlue;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
        // Handle middle pixels
            if ((i > 0) && (i < 3 - 1) && (j > 0) && (j < 3 - 1))
            {
                avgRed = round((image[i-1][j][0] + image[i][j][0] + image[i+1][j][0] +
                                image[i-1][j-1][0] + image[i][j-1][0] + image[i+1][j-1][0] +
                                image[i-1][j+1][0] + image[i][j+1][0] + image[i+1][j+1][0]) / 9.0);

                avgGreen = round((image[i-1][j][1] + image[i][j][1] + image[i+1][j][1] +
                                image[i-1][j-1][1] + image[i][j-1][1] + image[i+1][j-1][1] +
                                image[i-1][j+1][1] + image[i][j+1][1] + image[i+1][j+1][1]) / 9.0);

                avgBlue = round((image[i-1][j][2] + image[i][j][2] + image[i+1][j][2] +
                                image[i-1][j-1][2] + image[i][j-1][2] + image[i+1][j-1][2] +
                                image[i-1][j+1][2] + image[i][j+1][2] + image[i+1][j+1][2]) / 9.0);
            }
            else if (i == 0 && j != 0 && j != 3 - 1)
            {
                avgRed = round((image[i][j][0] + image[i+1][j][0] +
                                    image[i][j-1][0] + image[i+1][j-1][0] +
                                    image[i][j+1][0] + image[i+1][j+1][0]) / 6.0);

                avgGreen = round((image[i][j][1] + image[i+1][j][1] +
                                    image[i][j-1][1] + image[i+1][j-1][1] +
                                    image[i][j+1][1] + image[i+1][j+1][1]) / 6.0);

                avgBlue = round((image[i][j][2] + image[i+1][j][2] +
                                    image[i][j-1][2] + image[i+1][j-1][2] +
                                    image[i][j+1][2] + image[i+1][j+1][2]) / 6.0);
            }

            // Handle last row except corner pixels
            else if (i == 3 - 1 && j != 0 && j != (3 - 1))
            {
                avgRed = round((image[i-1][j][0] + image[i][j][0] +
                                    image[i-1][j-1][0] + image[i][j-1][0] +
                                    image[i-1][j+1][0] + image[i][j+1][0]) / 6.0);

                avgGreen = round((image[i-1][j][1] + image[i][j][1] +
                                    image[i-1][j-1][1] + image[i][j-1][1] +
                                    image[i-1][j+1][1] + image[i][j+1][1]) / 6.0);

                avgBlue = round((image[i-1][j][2] + image[i][j][2] +
                                    image[i-1][j-1][2] + image[i][j-1][2] +
                                    image[i-1][j+1][2] + image[i][j+1][2]) / 6.0);
            }

            // Handle top-left corner case
            else if (i == 0 && j == 0)
            {
                avgRed = round((image[i][j][0] + image[i+1][j][0] +
                                    image[i][j+1][0] + image[i+1][j+1][0]) / 4.0);

                avgGreen = round((image[i][j][1] + image[i+1][j][1] +
                                    image[i][j+1][1] + image[i+1][j+1][1]) / 4.0);

                avgBlue = round((image[i][j][2] + image[i+1][j][2] +
                                    image[i][j+1][2] + image[i+1][j+1][2]) / 4.0);
            }

            // Handle top-right corner case
            else if (i == 0 && j == 3 - 1)
            {
                avgRed = round((image[i][j][0] + image[i+1][j][0] +
                                    image[i][j-1][0] + image[i+1][j-1][0]) / 4.0);

                avgGreen = round((image[i][j][1] + image[i+1][j][1] +
                                    image[i][j-1][1] + image[i+1][j-1][1]) / 4.0);

                avgBlue = round((image[i][j][2] + image[i+1][j][2] +
                                    image[i][j-1][2] + image[i+1][j-1][2]) / 4.0);
            }

            // Handle bottom-left corner case
            else if (i == 3 - 1 && j == 0)
            {
                avgRed = round((image[i][j][0] + image[i-1][j][0] +
                                    image[i][j+1][0] + image[i-1][j+1][0]) / 4.0);

                avgGreen = round((image[i][j][1] + image[i-1][j][1] +
                                    image[i][j+1][1] + image[i-1][j+1][1]) / 4.0);

                avgBlue = round((image[i][j][2] + image[i-1][j][2] +
                                    image[i][j+1][2] + image[i-1][j+1][2]) / 4.0);
            }

            // Handle bottom-right corner case
            else if ((i == 3 - 1) && (j == 3 - 1))
            {
                avgRed = round((image[i][j][0] + image[i-1][j][0] +
                                    image[i][j-1][0] + image[i-1][j-1][0]) / 4.0);

                avgGreen = round((image[i][j][1] + image[i-1][j][1] +
                                    image[i][j-1][1] + image[i-1][j-1][1]) / 4.0);

                avgBlue = round((image[i][j][2] + image[i-1][j][2] +
                                    image[i][j-1][2] + image[i-1][j-1][2]) / 4.0);
            }

            //Handle first column except corner pixels
            else if (j == 0 && i != 0 && i != 3 - 1)
            {
                avgRed = round((image[i-1][j][0] + image[i][j][0] + image[i+1][j][0] +
                                    image[i-1][j+1][0] + image[i][j+1][0] + image[i+1][j+1][0]) / 6.0);

                avgGreen = round((image[i-1][j][1] + image[i][j][1] + image[i+1][j][1] +
                                    image[i-1][j+1][1] + image[i][j+1][1] + image[i+1][j+1][1]) / 6.0);

                avgBlue = round((image[i-1][j][2] + image[i][j][2] + image[i+1][j][2] +
                                    image[i-1][j+1][2] + image[i][j+1][2] + image[i+1][j+1][2]) / 6.0);
            }

            //Handle last column except corner pixels
            else if (j == 3 - 1 && i != 0 && i != 3 - 1)
            {
                avgRed = round((image[i-1][j][0] + image[i][j][0] + image[i+1][j][0] +
                                    image[i-1][j-1][0] + image[i][j-1][0] + image[i+1][j-1][0]) / 6.0);

                avgGreen = round((image[i-1][j][1] + image[i][j][1] + image[i+1][j][1] +
                                    image[i-1][j-1][1] + image[i][j-1][1] + image[i+1][j-1][1]) / 6.0);

                avgBlue = round((image[i-1][j][2] + image[i][j][2] + image[i+1][j][2] +
                                    image[i-1][j-1][2] + image[i][j-1][2] + image[i+1][j-1][2]) / 6.0);
            }

                printf("%i %i %i\n", avgRed, avgGreen, avgBlue);
        }
    }
}

