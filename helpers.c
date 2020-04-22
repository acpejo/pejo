#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for (int h = 0 ; h < height; h++)
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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int avg, red, green, blue;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            red = round(0.393 * image[h][w].rgbtRed + 0.769 * image[h][w].rgbtGreen + 0.189 * image[h][w].rgbtBlue);
            green = round(0.349 * image[h][w].rgbtRed + 0.686 * image[h][w].rgbtGreen + 0.168 * image[h][w].rgbtBlue);
            blue = round(0.272 * image[h][w].rgbtRed + 0.534 * image[h][w].rgbtGreen + 0.131 * image[h][w].rgbtBlue);

            if (red > 255)
                image[h][w].rgbtRed = 255;
            else
                image[h][w].rgbtRed = red;

            if (green > 255)
                image[h][w].rgbtGreen = 255;
            else
                image[h][w].rgbtGreen = green;

            if (blue > 255)
                image[h][w].rgbtBlue = 255;
            else
                image[h][w].rgbtBlue = blue;
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
                        continue;
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
