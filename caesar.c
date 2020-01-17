#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int j;
    //j will be disscusd later
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int lenarg = strlen(argv[1]); 
        for (j = 0; j < lenarg; j++)
        { 
            if ((int)argv[1][j] >= 48 && (int)argv[1][j] <= 57)
            {     
                //j loop to make sure that the input string after "caesar" is number.....48-57==0-9
                continue;
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        int x = atoi(argv[1]);
        string s = get_string("plaintext:  ");
        printf("ciphertext: ");
        int lenplain = strlen(s);
        for (j = 0; j < lenplain; j++)
        {
            if ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))
            {
                if (islower(s[j]))
                {
                    s[j] = (s[j] + x - 97) % 26 + 97;     
                }
                else
                {
                    s[j] = (s[j] + x - 65) % 26 + 65;
                }
            }
            else
            {
                continue;
            }
        }
        printf("%s\n", s);
        return 0;
    }
}    
