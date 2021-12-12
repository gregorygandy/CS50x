#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("Who is the most beautiful woman on Earth? "); // Asks user question
    printf("%s is the most beautiful woman on Earth \n", answer);
}