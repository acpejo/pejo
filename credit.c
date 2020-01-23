#include <cs50.h>
#include <stdio.h>

bool cal(long number);
int main(void)
{
    long number = get_long("Number: ");
    bool test = cal(number);
    if (test == true && number % 10000000000000 == number && (number - number % 1000000000000) / 1000000000000 == 4)
    {
        printf("%s\n", "VISA");
    }
    else if (test == true && number % 10000000000000000 == number && (number - number % 1000000000000000) / 1000000000000000 == 4)
    {
        printf("%s\n", "VISA");
    }
    else if (test == true && number % 1000000000000000 == number && ((number - number % 10000000000000) / 10000000000000 == 34
             || (number - number % 10000000000000) / 10000000000000 == 37))
    {
        printf("%s\n", "AMEX");
    }
    else if (test == true && number % 10000000000000000 == number && ((number - number % 100000000000000) / 100000000000000 == 51 
             || (number - number % 100000000000000) / 100000000000000 == 52
             || (number - number % 100000000000000) / 100000000000000 == 53 
             || (number - number % 100000000000000) / 100000000000000 == 54 
             || (number - number % 100000000000000) / 100000000000000 == 55))
    {
        printf("%s\n", "MASTERCARD");
    }
    else
    {
        printf("%s\n", "INVALID");
    }
}
bool cal(long number)
{
    int blona = 1, odd = 0, even = 0;
    for (long i = 10; i <= number * 10; i *= 10)
    {
        if (blona % 2 != 0)
        {
            if (i == 10)
            {
                odd += number % 10 ;
            }
            else
            {
                odd += (number % i - number % (i / 10)) / (i / 10);
            }
        }
        else
        {
            if (2 * (number % i - number % (i / 10)) / (i / 10) >= 10)
            {
                even += (2 * ((number % i - number % (i / 10)) / (i / 10))) % 10;
                even += (2 * (number % i - number % (i / 10)) / (i / 10) - (2 * ((number % i - number % (i / 10)) / (i / 10))) % 10) / 10;
            }
            else 
            {
                even += 2 * (number % i - number % (i / 10)) / (i / 10);
            }
        }
        blona ++;
    }
    if ((even + odd) % 10 == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
