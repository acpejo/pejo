#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int t , F , c=0 ;
    float f ;
    // t is a bolean test
    // c is counter
    // f is the cash
    // F is intger cash
    do
    {
        f = get_float("change:");
        if (f <= 0)
        {
            t = 0 ;
        }
        else
        {
            t = 1;
        }
    }
    while (t==0);
    F = f * 100 ;
    if ( F >= 25)
    {
        c += F / 25;
        F = F % 25 ;
    }
    if (F >= 10)
    {
        c += F /10;
        F = F %10 ;
    }
    if (F>=5)
    {
        c += F / 5 ;
        F = F % 5;
    }
    if (F>=1)
    {
        c += F /1 ;
        F = F %1;
    }
    printf("%i\n" , c);
}
