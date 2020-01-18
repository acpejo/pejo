#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float mon;
    do
    {
        mon = get_float("Change: ");
    }
    while (mon < 0);
    int k = 0, money = round(mon * 100);
    if (money >= 25)
    {
        k += money / 25;
        money %= 25;
    }
    if (money >= 10)
    {
        k += money / 10;
        money %= 10;
    }
    if (money >= 5)
    {
        k += money / 5;
        money %= 5;
    }
    if (money >= 1)
    {
        k += money ;
    }
    printf("%i\n", k);
}
