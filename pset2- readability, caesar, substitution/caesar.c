#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Prototype of valid_argv function
bool valid_argv(int argc, string argv[]);

int main(int argc, string argv[])
{
    // Check if user enterd argument value is valid
    if (valid_argv(argc, argv))
    {
        // Convert enter key string to int
        int key = atoi(argv[1]);

        // Prompt user to input plaintext
        string plaintext = get_string("plaintext: ");
        string ciphertext = plaintext;

        // Figure out the ciphertext to plaintext using key
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            if (isupper(plaintext[i]))
            {
                ciphertext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
            }
            else if (islower(plaintext[i]))
            {
                ciphertext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
            }
            else
            {
                ciphertext[i] = plaintext[i];
            }

        }

        // Print ciphertext
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
    else
    {
        // Prompt user to enter key
        printf("Usage: ./caesar key\n");
        return 1;
    }
}


// Function to check if user entered valid argument value
bool valid_argv(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}
