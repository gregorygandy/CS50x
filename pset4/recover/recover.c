#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Open a new JPEG fil
// Write 512 bytes until a new JPEG is found
// Stop at end of file

int main(int argc, char *argv[])
{
    
    if (argc != 2)
    {
        return 1;
    }
    
    // open memory card file
    FILE *memory_card = fopen(argv[1], "r");
    if (memory_card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    uint8_t BYTE;
    char filename[512];
    
    while (fread(&BYTE, 512, 1, memory_card)) // repeat until end of card
    {
        
        if (BYTE[0] == 0xff & BYTE[1] == 0xd8 & BYTE[2] == 0xff & ((BYTE[3] & 0xf0) == 0xe0)) // if start of new JPEG
        {
            if (jpeg_number == 0) // if first JPEG
            {
                sprintf(filename, "%03i.jpg", jpeg_number); // make sure file name has enough memory (charectors) to represent names
                FILE *img = fopen(filename, "w"); // write data from memory card
                fwrite(&BYTE, 512, 1, img);
                jpeg_number = 1;
            }
            else // if already found JPEG, open up new file to continue writing
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", jpeg_number); // make sure file name has enough memory (charectors) to represent names
                FILE *img = fopen(filename, "w"); // write data from memory card
                fwrite(&BYTE, 512, 1, img);
                jpeg_number += 1;
            }
        }
        else // not start of new JPEG
        {
            if (jpeg_number != 0) // condition if fread has got to the end of the file or not.
            {
                fwrite(&BYTE, 512, 1, img);
            }
            else // if there are no more JPEGs left to find
            { 
                fclose(memory_card);
            }
        }
    }
}