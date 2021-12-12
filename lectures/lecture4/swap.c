#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;
    
    printf("X is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("X is %i, y is %i\n", x, y);
}
void swap(int *a, int *b) //implement swap in a way that changes the values of x and y, rather than the copies of x and y. Pass addresses
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// heap overflow. Stack overflow.

