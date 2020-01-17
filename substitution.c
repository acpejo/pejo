#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (int argc , string argv[])
{
    char A[26];
    if(argc !=2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if(strlen(argv[1])!=26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for(int i=0; i<26; i++)
    {
        if(! isupper(argv[1][i]) && ! islower(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    for(int i=0; i<26; i++)
    {
        for(int j=0;j<26;j++)
        {
            if (i==j)
                continue;
            if(argv[1][i]==toupper(argv[1][j]) || argv[1][i]==tolower(argv[1][j]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }
    string plain=get_string("plaintext:  ");
    printf("ciphertext: ");
    char cipher[strlen(plain)];
    for(int i=0;i<strlen(plain);i++)
    {
        if(! isupper(plain[i]) && ! islower(plain[i]))
        {
            cipher[i]=plain[i];
            continue;
        }
        else if(isupper(plain[i]))
        {
            cipher[i]=toupper(argv[1][plain[i]-65]);
        }
        else //plain is lower
            cipher[i]=tolower(argv[1][plain[i]-97]);
    }
    printf("%s\n",cipher);
}
