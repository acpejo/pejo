#include <stdio.h>
#include <cs50.h>

int main(void)
{   
    int x,test;
    do 
    {
        x = get_int("Height: ");
        test = (x<=0 || x>8) ? 0 : 1 ;
    }
    while (test ==0);
    for (int i=1 ; i<(x+1) ; i++)
    {   
        for (int j=0 ; j<(x-i) ; j++)
        {
            printf(" ");
        }
        for (int j=0 ; j<i ; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j=0; j<i ; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
