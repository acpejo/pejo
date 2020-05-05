#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //enure that the user input two strings
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //the main file of deleted memory
    FILE *inptr = fopen(argv[1], "r");

    //enusre that every thing is ok
    if (inptr == NULL)
    {
        return 2;
    }

    //The output files of the recoverd data
    FILE *outptr = NULL;

    //pointer to rewrite the data
    char *temp = malloc(8 * sizeof(char));

    //pointer to read the data
    BYTE *buffer = malloc(512 * sizeof(BYTE));

    short counter = 0;

    while (true)
    {
        //read a block of memory from a card image
        size_t fileRead = fread(buffer, sizeof(BYTE), 512, inptr);

        //flag to know wiether the pointer is jpg or not
        bool jpg = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

        //Ending form one image and start new one
        if (jpg && outptr != NULL)
        {
            fclose(outptr);
            counter++;
        }

        //All is done
        if (fileRead < 512)
        {
            break;
        }

        //write data to file
        if (jpg)
        {
            sprintf(temp, "%03i.jpg", counter);
            outptr = fopen(temp, "w");
        }

        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE), fileRead, outptr);
        }

    }

    fclose(inptr);
    fclose(outptr);
    free(buffer);
    free(temp);

}