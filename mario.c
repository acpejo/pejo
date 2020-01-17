#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    while (true)
    {
        h = get_int("Height: ");
        if (h > 0 && h <= 8)
        {
            break; 
        }
    }
    for (int i = 1; i <= h ; i++)
    {
        for (int j = 0; j < h - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
