#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_size;
    do
    {
        start_size = get_int("Start Size: ");
    }
    while (start_size < 9);
    
    int ending_size;
    do
    {
        ending_size = get_int("End size: ");
    }
    while (ending_size < start_size);
    
    int years = 0;
    while (ending_size > start_size)
    {
        start_size = start_size + (start_size / 3) - (start_size / 4);
        years = years + 1;
    }
    printf("Years: %i\n", years);
}