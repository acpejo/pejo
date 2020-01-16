#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(int argc, string argv[])
{
    if(argc !=2)
    {
        printf("Usage: ./vigenere keyword\n");
    }
    else
    {
        int vector=strlen(argv[1]);
        for(int i=0;i<vector;i++)
        {
            if (! isupper(argv[1][i]) && ! islower(argv[1][i]) )
            {
                printf("Usage: ./vigenere keyword\n");
                return 0;
            }
        }
        string plaintext = get_string("plaintext:  ");
        int plainLen=strlen(plaintext),argPlain[plainLen];
        //plaintext == the first and the real massage
        //plainLen == length of first and real one
        //argPlain == the alpha of change of the code
        //    argv[1][i]-=65;
         //   else if(plaintext)
           //     argv[1][i]-=97;
            //else
        for(int i=0;i<plainLen;i++)
        {
            argPlain[i]=argv[1][i%vector];
            if(islower(argPlain[i]))
                argPlain[i]-=97;
            else
                argPlain[i]-=65;
            //vector is the lenght of the argv[1]
            if(islower(plaintext[i]))
            {
                plaintext[i]+=argPlain[i]%26;
                if(plaintext[i]>122)
                    plaintext[i]-=26;
            }
            else if(isupper(plaintext[i]))
            {
                plaintext[i]+=argPlain[i]%26;
                if(plaintext[i]>90)
                    plaintext[i]-=26;
            }
            
        }
        printf("ciphertext: %s\n",plaintext);
        
    }
}
