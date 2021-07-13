#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE; // we are creating a data type byte

int main(int argc, char *argv[])
{
    // checking for valid argc which has to be 2
    if (argc != 2)
    {
        printf("Invalid Key usage.\n");
        return 1;
    }
    // checking if the file is not empty
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Empty file.\n");
        return 1;
    }

    // we are gg read by blocks of 512 bytes
    BYTE bytes[512];
    int file_index = 0;
    FILE *new_file;
    char filename[8];

    //while we can read something on the files
    while (fread(bytes, 512, 1, file))
    {
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
        {
            if (new_file != NULL)
            {
                fclose(new_file);
            }
            sprintf(filename, "%03i.jpg", file_index++);
            new_file = fopen(filename, "w");
        }
        if (new_file != NULL)
        {
            fwrite(bytes, 512, 1, new_file);
        }

    }
    fclose(new_file);
    fclose(file);
}
