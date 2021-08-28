#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Prototypes of functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt user for input text
    string text = get_string("Text: ");

    // Get letters and words from text and calculate L and S
    float L = (count_letters(text) * 100.0) / count_words(text);
    float S = (count_sentences(text) * 100.0) / count_words(text);

    // Calculate Coleman-Liau Index
    int index = (int) round(0.0588 * L - 0.296 * S - 15.8);

    // Print grade level.
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

// Function to count total letter(s) in text
int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Check if character is a valid alphabet
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Function to count total word(s) in text
int count_words(string text)
{
    int count = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Check for space in between words
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Function to count total sentence(s) in text
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Check for '.', '!', or '?' to determine the end of sentence
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}