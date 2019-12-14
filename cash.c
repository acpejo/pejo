#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    int  F , c=0 ;
    float f ;
    bool t;
    // t is a bolean test
    // c is counter
    // f is the cash
    // F is intger cash
    do
    {
        f = get_float("change:");
        if (f < 0)
        {
            t = false ;
        }
        else
        {
            t = true;
        }
    }
    while (t==false);
    F = round(f*100);//f*100
    if ( F >= 25)
    {
        c += F / 25;
        F %= 25 ;
    }
    if (F >= 10)
    {
        c += F / 10;
        F %= 10 ;
    }
    if (F>=5)
    {
        c += F / 5 ;
        F %= 5;
    }
    if (F>=1)
    {
        c += F /1 ;
    }
    printf("%i\n" , c);
}
