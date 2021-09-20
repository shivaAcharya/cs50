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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            // Cap at 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Update image struc with average value
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

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
