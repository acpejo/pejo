#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h, i = 1, j = 0;
    for (;;)
    {
        h = get_int("Height: ");
        if (h >= 1 && h < 9)
        {
            break;
        }
    }
    while (i <= h)
    {
        while (j < h - i)
        {
            printf(" ");
            j++;
        }
        j = 0;
        while (j < i)
        {
            printf("#");
            j++;
        }
        j = 0;
        i++;
        printf("\n");
    }
}
