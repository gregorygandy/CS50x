#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// step 5, calculate and return coleman-liau, whole number
// if output is less than "Before Grade 1"
// "Grade 16+"

int letters(string text);
int words(string text);
int sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    float letter_cn = letters(text);
    float words_cn = words(text);
    float sentences_cn = sentences(text);
    float L = (100 / words_cn) * letter_cn;
    float S = (100 / words_cn) * sentences_cn;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int letters(string text)
{
    int letter_cn = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        text[i] = (char) text[i];
        if (isalpha(text[i]) != 0)
        {
            letter_cn = letter_cn + 1;
        }
    }
    return letter_cn;
}

int words(string text)
{
    int word_cn = 1; // need to count first word of text which is not preceded by " "
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            word_cn = word_cn + 1;
        }
    }
    return word_cn;
}

int sentences(string text)
{
    int sentence_cn = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_cn = sentence_cn + 1;
        }
    }
    return sentence_cn;
}