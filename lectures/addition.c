#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long x = get_long("x: "); // asks user for an integer
    
    long y = get_long("y: ");
    
    printf("%li\n", x + y);
}