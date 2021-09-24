#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            // Update image struct
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }

    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Initialize temp struct
            RGBTRIPLE temp = image[i][j];

            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int avgRed, avgGreen, avgBlue;

    // Initialize temp struct
    RGBTRIPLE(*temp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Handle middle pixels
            if ((i > 0) && (i < height - 1) && (j > 0) && (j < width - 1))
            {
                avgRed = round((image[i - 1][j].rgbtRed + image[i][j].rgbtRed + image[i + 1][j].rgbtRed +
                                image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed +
                                image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / 9.0);

                avgGreen = round((image[i - 1][j].rgbtGreen + image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen +
                                  image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen +
                                  image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 9.0);

                avgBlue = round((image[i - 1][j].rgbtBlue + image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue +
                                 image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
                                 image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 9.0);
            }

            // Handle first row except corner pixels
            else if (i == 0 && j != 0 && j != width - 1)
            {
                avgRed = round((image[i][j].rgbtRed + image[i + 1][j].rgbtRed +
                                image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed +
                                image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.0);

                avgGreen = round((image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen +
                                  image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen +
                                  image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.0);

                avgBlue = round((image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue +
                                 image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
                                 image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.0);
            }

            // Handle last row except corner pixels
            else if (i == height - 1 && j != 0 && j != width - 1)
            {
                avgRed = round((image[i - 1][j].rgbtRed + image[i][j].rgbtRed +
                                image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed +
                                image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed) / 6.0);

                avgGreen = round((image[i - 1][j].rgbtGreen + image[i][j].rgbtGreen +
                                  image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen +
                                  image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen) / 6.0);

                avgBlue = round((image[i - 1][j].rgbtBlue + image[i][j].rgbtBlue +
                                 image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue +
                                 image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue) / 6.0);
            }

            // Handle top-left corner case
            else if (i == 0 && j == 0)
            {
                avgRed = round((image[i][j].rgbtRed + image[i + 1][j].rgbtRed +
                                image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / 4.0);

                avgGreen = round((image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen +
                                  image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 4.0);

                avgBlue = round((image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue +
                                 image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 4.0);
            }

            // Handle top-right corner pixel
            else if (i == 0 && j == width - 1)
            {
                avgRed = round((image[i][j].rgbtRed + image[i + 1][j].rgbtRed +
                                image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed) / 4.0);

                avgGreen = round((image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen +
                                  image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 4.0);

                avgBlue = round((image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue +
                                 image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 4.0);
            }

            // Handle bottom-left corner case
            else if (i == height - 1 && j == 0)
            {
                avgRed = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed +
                                image[i][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed) / 4.0);

                avgGreen = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen +
                                  image[i][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 4.0);

                avgBlue = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue +
                                 image[i][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 4.0);
            }

            // Handle bottom-right corner case
            else if ((i == height - 1) && (j == width - 1))
            {
                avgRed = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed +
                                image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed) / 4.0);

                avgGreen = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen +
                                  image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen) / 4.0);

                avgBlue = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue +
                                 image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue) / 4.0);
            }

            //Handle first column except corner pixels
            else if (j == 0 && i != 0 && i != height - 1)
            {
                avgRed = round((image[i - 1][j].rgbtRed + image[i][j].rgbtRed + image[i + 1][j].rgbtRed +
                                image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.0);

                avgGreen = round((image[i - 1][j].rgbtGreen + image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen +
                                  image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.0);

                avgBlue = round((image[i - 1][j].rgbtBlue + image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue +
                                 image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.0);
            }

            //Handle last column except corner pixels
            else if (j == width - 1 && i != 0 && i != height - 1)
            {
                avgRed = round((image[i - 1][j].rgbtRed + image[i][j].rgbtRed + image[i + 1][j].rgbtRed +
                                image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed) / 6.0);

                avgGreen = round((image[i - 1][j].rgbtGreen + image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen +
                                  image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 6.0);

                avgBlue = round((image[i - 1][j].rgbtBlue + image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue +
                                 image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 6.0);
            }

            // Store new values on temp struct
            temp[i][j].rgbtRed = avgRed;
            temp[i][j].rgbtGreen = avgGreen;
            temp[i][j].rgbtBlue = avgBlue;

        }
    }
    // Copy temp to image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    free(temp);
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int sobelRed, sobelGreen, sobelBlue;

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Initialize temp struct
    RGBTRIPLE(*temp)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get 3x3 matrix with surrounding pixels
            int GxRed = 0, GxGreen = 0, GxBlue = 0;
            int GyRed = 0, GyGreen = 0, GyBlue = 0;


            int m = -1, n = 2, o = -1, p = 2;
            // 1. Handle first row except corner pixels
            if (i == 0 && j != 0 && j != width - 1)
            {
                m = 0;
            }

            // 2. Handle last row except corner pixels
            else if (i == height - 1 && j != 0 && j != width - 1)
            {
                n = 1;
            }

            // 3. Handle top-left corner case
            else if (i == 0 && j == 0)
            {
                m = 0;
                o = 0;
            }

            // 4. Handle top-right corner pixel
            else if (i == 0 && j == width - 1)
            {
                m = 0;
                p = 1;
            }

            // 5. Handle bottom-left corner case
            else if (i == height - 1 && j == 0)
            {
                n = 1;
                o = 0;
            }

            // 6. Handle bottom-right corner case
            else if ((i == height - 1) && (j == width - 1))
            {
                n = 1;
                p = 1;
            }

            // 7. Handle first column except corner pixels
            else if (j == 0 && i != 0 && i != height - 1)
            {
                o = 0;
            }

            // 9. Handle last column except corner pixels
            else if (j == width - 1 && i != 0 && i != height - 1)
            {
                p = 1;
            }

            // 10. Handle middle pixels
            // Hadamard product
            for (int k = m; k < n; k++)
            {
                for (int l = o; l < p; l++)
                {
                    // Get Gx value given the 3x3 matrix
                    GxRed += image[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                    GxGreen += image[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                    GxBlue += image[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];

                    // Get Gy value given the 3x3 matrix
                    GyRed += image[i + k][j + l].rgbtRed * Gy[k + 1][l + 1];
                    GyGreen += image[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                    GyBlue += image[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
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
            temp[i][j].rgbtRed = sobelRed;
            temp[i][j].rgbtGreen = sobelGreen;
            temp[i][j].rgbtBlue = sobelBlue;
        }

    }
    // Copy temp to image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    free(temp);
}
