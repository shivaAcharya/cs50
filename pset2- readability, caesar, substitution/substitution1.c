#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Prototype of valid_argv function
bool valid_argv(int argc, string argv[]);

int key_index(string key, char c);

int main(int argc, string argv[])
{
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
    }

    // Check if user enterd argument value is valid
    else if (valid_argv(argc, argv))
    {
        // Convert entered key string to lower and uppercase
        char key_upper[26], key_lower[26];
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            key_upper[i] = toupper(argv[1][i]);
            key_lower[i] = tolower(argv[1][i]);
        }
        //printf("key_lower %c\n", key_lower);
        //printf("key_upper %c\n", key_upper);

        // Prompt user to input plaintext
        string plaintext = get_string("plaintext: ");
        string ciphertext = plaintext;

        // Figure out the ciphertext to plaintext using key
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            if (isupper(plaintext[i]))
            {
                ciphertext[i] = key_index(key_upper, plaintext[i]) + 'A';
            }
            else if (islower(plaintext[i]))
            {
                ciphertext[i] = key_index(key_upper, plaintext[i]) + 'a';
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
        printf("Usage: ./substitution key\n");
        return 1;
    }
}


// Function to check if user entered valid argument value
bool valid_argv(int argc, string argv[])
{
    if (argc == 2 && strlen(argv[1]) == 26)
    {
        for (int i = 0; i < 26; i++)
        {
            if (isalpha(argv[1][i]) == 0)
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

int key_index(string key, char c)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (key[i] == c)
        {
            return i;
        }
    }
    return -1;
}
