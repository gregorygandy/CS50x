#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Open a new JPEG file
// Write 512 bytes until a new JPEG is found
// Stop at end of file

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    
    if (argc != 2)
    {
        return 1;
    }
    
    // open input, memory card, file
    FILE *memory_card = fopen(argv[1], "r");
    if (memory_card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    
    BYTE buffer;
    while (fread(&buffer, 512, 1, memory_card))
        {
            printf("1");
        }
    
    // Close memory card
    fclose(memory_card);
    return 0;
}