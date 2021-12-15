#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    
    // open memory card | * declares a variable we want to be a pointer | 
    FILE *memory_card = fopen(argv[1], "r"); //  fopen 
    if (memory_card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    // fread(data, size, number, inptr) data: pointer to where to store data you're reading. size: size of each element. number: number of elements to read. inptr: FILE * to read from
    // there are 50 jpegs in the file
    typedef uint8_t BYTE;
    BYTE buffer[512];
    int jpeg_number = 0;
    char filename[8];
    FILE *img = NULL;
    
    while (fread(&buffer, 512, 1, memory_card)) // reads 512 memory card’s bytes at a time into a buffer
    {
        if (buffer[0] == 0xff & buffer[1] == 0xd8 & buffer[2] == 0xff & (buffer[3] & 0xf0) == 0xe0) // if start of new JPEG
        {   
            if (jpeg_number == 0)// first JPEG
            {
                sprintf(filename, "%03i.jpg", jpeg_number); // printf("%s\n", filename);
                img = fopen(filename, "w");
                fwrite(buffer, 512, 1, img);
                jpeg_number++;
            }
            else
            {
                fclose(img); // close JPEG file
                sprintf(filename, "%03i.jpg", jpeg_number); // printf("%s\n", filename);
                img = fopen(filename, "w");
                fwrite(buffer, 512, 1, img);
                jpeg_number++; // printf("%d\n", jpeg_number);
            }
        }
        else if (jpeg_number > 0) //already found JPEG
        {
            fwrite(buffer, 512, 1, img);
        }
    }

    // close memory card
    fclose(memory_card);
    return 0;
}