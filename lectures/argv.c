#include <stdio.h>
#include <cs50.h>
int main(int argc, string argv[])
{
    if (argc == 3)
    {
        printf("hello, %s %s\n", argv[1], argv[2]);
    }
    else
    {
        printf("hello, world\n");
    }
}