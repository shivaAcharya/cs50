#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int image[3][3][3] = {{{0, 10, 25}, {0, 10, 30}, {40, 60, 80}}, {{20, 30, 90}, {30, 40, 100}, {80, 70, 90}}, {{20, 20, 40}, {30, 10, 30}, {50, 40, 10}}};

int main(void)
{
    int sobelRed, sobelGreen, sobelBlue;

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Initialize temp struct
    //RGBTRIPLE(*temp)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Get 3x3 matrix with surrounding pixels
            int GxRed = 0, GxGreen = 0, GxBlue = 0;
            int GyRed = 0, GyGreen = 0, GyBlue = 0;

            if ((i > 0) && (i < 3 - 1) && (j > 0) && (j < 3 - 1))
            {
            // Hadamard product
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    // Get Gx value given the 3x3 matrix
                    // Get Gy value given the 3x3 matrix
                    GxRed += image[k][l][0] * Gx[k][l];
                    GxGreen += image[k][l][1] * Gx[k][l];
                    GxBlue += image[k][l][2] * Gx[k][l];

                    GyRed += image[k][l][0] * Gy[k][l];
                    GyGreen += image[k][l][1] * Gy[k][l];
                    GyBlue += image[k][l][2] * Gy[k][l];
                }
            }

            // Get sobel value given Gx and Gy
            sobelRed = round(sqrt(GxRed * GxRed + GyRed * GyRed));
            sobelGreen = round(sqrt(GxGreen * GxGreen + GyGreen * GyGreen));
            sobelBlue = round(sqrt(GxBlue * GxBlue + GyBlue * GyBlue));

            // Cap the sobel values at 255
            if (sobelRed > 255)
            {
                sobelRed = 255;
            }
            if (sobelGreen > 255)
            {
                sobelGreen = 255;
            }
            if (sobelBlue > 255)
            {
                sobelBlue = 255;
            }

            // Store sobel values in temp struct and repeat the process

            //temp[i][j][0] = sobelRed;
            //temp[i][j][1] = sobelGreen;
            //temp[i][j][2] = sobelGreen;
        }
        }

    }
            printf("%i %i %i\n", sobelRed, sobelGreen, sobelBlue);
}

