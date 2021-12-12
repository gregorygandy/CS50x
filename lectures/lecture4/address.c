#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n; //pointer variable. Pointer: variable that contains the address of some other value. Int *name of variable to create
    printf("%p \n", p); // & (with %p) refers to the memory address of a variable with %p and *& (with %i) looks inside the memory address
}
