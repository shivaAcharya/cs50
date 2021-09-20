#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    // Check the proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");

    // Error checking
    if (!file)
    {
        printf("%s cannot be opened.\n", argv[1]);
        return 1;
    }

    // Buffer array
    BYTE blocks[512];

    int fileCount = 0;
    char *filename = malloc(3);

    // Opening new jpeg file
    sprintf(filename, "%03i.jpg", fileCount);
    FILE *jpeg = fopen(filename, "w");

    // Looping while collected bytes are 512 long
    while (fread(blocks, sizeof(BYTE), 512, file) == 512)
    {
        // Check if its start of new JPEG
        if (blocks[0] == 0xff && blocks[1] == 0xd8 && blocks[2] == 0xff && (blocks[3] & 0xf0) == 0xe0)
        {
            // Check if its first JPEG
            if (fileCount == 0)
            {
                fwrite(blocks, sizeof(BYTE), 512, jpeg);
                fileCount++;
            }
            else
            {
                // Close previously open jpeg file
                fclose(jpeg);

                sprintf(filename, "%03i.jpg", fileCount);
                jpeg = fopen(filename, "w");

                fwrite(blocks, sizeof(BYTE), 512, jpeg);

                // Update file count
                fileCount++;

            }
        }

        else if (fileCount != 0)
        {
            fwrite(blocks, sizeof(BYTE), 512, jpeg);
        }
    }

    // End of file
    if (fread(blocks, sizeof(BYTE), 512, file) < 512)
    {
        int remBytes = fread(blocks, sizeof(BYTE), 512, file);
        fwrite(blocks, sizeof(BYTE), remBytes, jpeg);
        fclose(jpeg);
    }

    free(filename);
}
