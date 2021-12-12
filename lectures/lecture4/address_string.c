#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //string s = "HI!";
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
}
// s, a string, is technically a pointer. Arrays, text. Pointer: address in computers memory. All strings end with a \0 == 00000000
// Strings do not technically exist as a data type in C. More low-level known as char star. 
// char star represents the address of a charector. 
// char *s = "HI!"; == string s = "HI!"; typedef char *string;
// Strings exist in C but there is not data type called string in C.
// segmentation fault 10000 away