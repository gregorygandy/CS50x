#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool validate(string text);
string shift(string text, int key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        bool validation = validate(argv[1]);
        if (validation == 1)
        {
            int key = atoi(argv[1]);
            string plaintext = get_string("plaintext: ");
            string ciphertext = shift(plaintext, key);
            printf("ciphertext: %s\n", ciphertext);
        }
        else
        {
            return 1;
            printf("Usage: ./caesar key\n");
        }
    }
    else
    {
        return 1;
        printf("Usage: ./caesar key\n");
    }
}

bool validate(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        text[i] = (char) text[i];
        if (isdigit(text[i]) == 0)
        {
            return (int) 0;
        }
    }
    return (int) 1;
}

string shift(string text, int key)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]) == 0)
        {
            text[i] = text[i];
        }
        else if (isupper(text[i]) != 0) // uppercase
        {
            if (text[i] + key < 91)
            {
                text[i] = (char)((int) text[i] + key);
            }
            else
            {
                int remain = (((int) text[i] + key) - 91) % 26; // returns 
                text[i] = (char)(remain + 65);
            }
        }
        else
        {
            if (text[i] + key < 123)
            {
                text[i] = (char)((int) text[i] + key);
            }
            else
            {
                int remain = (((int) text[i] + key) - 123) % 26; // returns 
                text[i] = (char)(remain + 97);
            }
        }
    }
    return (string) text;
}