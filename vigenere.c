#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc,string argv[])
{
    if(argc!=2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    for(int i=0;i<strlen(argv[1]);i++)
    {
        if(! isupper(argv[1][i]) && ! islower(argv[1][i]) )
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    }
    string plain=get_string("plaintext:  ");
    printf("ciphertext: ");
    int k=0; //k is a counter of plaintext
    char argv2[strlen(plain)];
    for(int i=0;i<strlen(plain);i++)
    {
        argv2[i]=argv[1][i%strlen(argv[1])];
        if(isupper(argv2[i]))
            argv2[i]-=65;
        else 
            argv2[i]-=97;
        if(! isupper(plain[k]) && ! islower(plain[k]) )
        {
            printf("%c",plain[k]);
            i--;
            k++;
            if(k>strlen(plain))
            {
                printf("\n");
                return 0;
            }
            continue;
        }
        if(isupper(plain[k]))
        {
            plain[k]-=65;
            plain[k]+=argv2[i];
            plain[k]%=26;
            plain[k]+=65;
        }
        else
        {
            plain[k]-=97;
            plain[k]+=argv2[i];
            plain[k]%=26;
            plain[k]+=97;
        }
        printf("%c",plain[k]);
        k++;
        if(k>strlen(plain))
        {
            printf("\n");
            return 0;
        }
    }
    printf("\n");
}
