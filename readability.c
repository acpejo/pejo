#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string s = get_string("Text: ");
    int l = 0, S = 0, w = 1;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            w++;
        }
        else if (s[i] == '!' || s[i] == '?' || s[i] == '.')
        {
            S++;
        }
        else if (isupper(s[i]) || islower(s[i]))
        {
            l++;
        }
    }
    l = l * 100 / w;
    S = S * 100 / w;
    float index = 0.0588 * l - 0.296 * S - 15.8;
    int p = round(index);
    if ((int)(index * 100) % 100 >= 50 && (int)(index * 100) % 100 < 60)
    {
        p --; 
    }
    if (p < 1)
    {
        printf("%s\n", "Before Grade 1");
    }
    else if (p >= 16)
    {
        printf("%s\n", "Grade 16+");
    }
    else
    {
        printf("%s%i\n", "Grade ", p);
    }
}
