#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    //Ensure that the user enter the correct name at promt
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //Open file
    FILE *file = fopen(argv[1], "r");

    //Ensure that the file is 100 100
    if (file == NULL)
    {
        return 1;
    }

    BYTE *buffers = malloc(512 * sizeof(BYTE));
    int count = 0;

    char *filename = malloc(8 * sizeof(char));

    FILE *outptr = NULL;


    while (true)
    {
        size_t byteRead = fread(buffers, sizeof(BYTE), 512, file);

        if (byteRead == 0 && feof(file))
        {
            break;
        }

        bool containJpegHeader = buffers[0] == 0xff && buffers[1] == 0xd8 && buffers[2] == 0xff && (buffers[3] & 0xf0) == 0xe0;

        if (containJpegHeader && outptr != NULL)
        {
            fclose(outptr);
            count++;
        }

        if (containJpegHeader)
        {
            sprintf(filename,"%03i.jpg", count);
            outptr = fopen(filename, "w");

        }

        if (outptr != NULL)
        {
            fwrite(buffers, sizeof(BYTE), byteRead, outptr);
        }
    }

    fclose(outptr);
    fclose(file);

    free(buffers);
    free(filename);
}
