#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            avg = round((image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3.0);
            image[h][w].rgbtRed = avg;
            image[h][w].rgbtGreen = avg;
            image[h][w].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0, n = width / 2; w < n; w++)
        {
            temp = image[h][w].rgbtRed;
            image[h][w].rgbtRed = image[h][width - w - 1].rgbtRed;
            image[h][width - w - 1].rgbtRed = temp;

            temp = image[h][w].rgbtGreen;
            image[h][w].rgbtGreen = image[h][width - w - 1].rgbtGreen;
            image[h][width - w - 1].rgbtGreen = temp;

            temp = image[h][w].rgbtBlue;
            image[h][w].rgbtBlue = image[h][width - w - 1].rgbtBlue;
            image[h][width - w - 1].rgbtBlue = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int red[height][width], green[height][width], blue[height][width];

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            red[h][w] = image[h][w].rgbtRed;
            green[h][w] = image[h][w].rgbtGreen;
            blue[h][w] = image[h][w].rgbtBlue;
        }
    }
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int avgR = 0, avgG = 0, avgB = 0;
            float counter = 0;
            for (int h1 = h - 1; h1 <= h + 1; h1++)
            {
                for (int w1 = w - 1; w1 <= w + 1; w1++)
                {
                    if (h1 < 0 || h1 >= height || w1 < 0 || w1 >= width)
                    {
                        continue;
                    }
                    avgR += red[h1][w1];
                    avgG += green[h1][w1];
                    avgB += blue[h1][w1];
                    counter++;
                }
            }
            image[h][w].rgbtRed = round(avgR / counter);
            image[h][w].rgbtGreen = round(avgG / counter);
            image[h][w].rgbtBlue = round(avgB / counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int red[height][width], green[height][width], blue[height][width];

    //delcare x & y matrix
    int mx[3][3], my[3][3];

    //assing new value to x
    mx[0][0] = -1;
    mx[0][1] = 0;
    mx[0][2] = 1;

    mx[1][0] = -2;
    mx[1][1] = 0;
    mx[1][2] = 2;

    mx[2][0] = -1;
    mx[2][1] = 0;
    mx[2][2] = 1;

    //assing new value to y
    my[0][0] = -1;
    my[0][1] = -2;
    my[0][2] = -1;

    my[1][0] = 0;
    my[1][1] = 0;
    my[1][2] = 0;

    my[2][0] = 1;
    my[2][1] = 2;
    my[2][2] = 1;

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            red[h][w] = image[h][w].rgbtRed;
            green[h][w] = image[h][w].rgbtGreen;
            blue[h][w] = image[h][w].rgbtBlue;
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int redX = 0, redY = 0, greenX = 0, greenY = 0, blueX = 0, blueY = 0;
            for (int h1 = h - 1, i = 0; h1 <= h + 1; h1++, i++)
            {
                for (int w1 = w - 1, j = 0; w1 <= w + 1; w1++, j++)
                {
                    if (w1 < 0 || w1 >= width || h1 < 0 || h1 >= height)
                    {
                        continue;
                    }

                    //else
                    redX += red[h1][w1] * mx[i][j];
                    redY += red[h1][w1] * my[i][j];

                    greenX += green[h1][w1] * mx[i][j];
                    greenY += green[h1][w1] * my[i][j];

                    blueX += blue[h1][w1] * mx[i][j];
                    blueY += blue[h1][w1] * my[i][j];
                }
            }
            if (sqrt(pow(redX, 2) + pow(redY, 2)) > 255)
            {
                image[h][w].rgbtRed = 255;
            }
            else
            {
                image[h][w].rgbtRed = round(sqrt(pow(redX, 2) + pow(redY, 2)));
            }


            if (sqrt(pow(greenX, 2) + pow(greenY, 2)) > 255)
            {
                image[h][w].rgbtGreen = 255;
            }
            else
            {
                image[h][w].rgbtGreen = round(sqrt(pow(greenX, 2) + pow(greenY, 2)));
            }


            if (sqrt(pow(blueX, 2) + pow(blueY, 2)) > 255)
            {
                image[h][w].rgbtBlue = 255;
            }
            else
            {
                image[h][w].rgbtBlue = round(sqrt(pow(blueX, 2) + pow(blueY, 2)));
            }

        }
    }
    return;
}
