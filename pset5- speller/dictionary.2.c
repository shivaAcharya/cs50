// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 20001;

// Hash table
node *table[N];

// Words size in dictionary
int size_out = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    // 1. Hash word to obtain a hash value
    unsigned int hash_value = hash(word);

    // 2. Access linked list at that index in the hash table
    // 3. Traverse linked list, looking for the word(strcasecmp)
    node *cursor = table[hash_value];
    while (cursor != NULL)
    {
        if (strcasecmp((cursor -> word), word) == 0)
        {
            return true;
        }
        cursor = cursor -> next;
    }

    return false;
}

// Hashes word to a number
// Credit: https://stackoverflow.com/questions/4384359/quick-way-to-implement-dictionary-in-c
unsigned int hash(const char *word)
{
    // TODO

    // Lookup online for good hash function
    unsigned int hashval;

    for (hashval = 0; *word != '\0'; word++)
    {
        int s = *word;

        // Convert to lowercase if uppercase
        if (isupper(s))
        {
            s = tolower(s);
        }
        hashval = s + 31 * hashval;
    }
    return hashval % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // 1. Open dictionary file
    // Use fopen
    // Remember to check if return value is NULL

    FILE *f = fopen(dictionary, "r");
    if (!f)
    {
        return false;
    }

    // 2. Read strings from file
    char lexicon[LENGTH + 1];
    while (fscanf(f, "%s", lexicon) != EOF)
    {

        // 3. Create a new node for each word
        node *n = calloc(1, sizeof(node));
        if (n != NULL)
        {
            strcpy(n -> word, lexicon);

            // 4. Hash word to obtain a hash value
            unsigned int hash_code = hash(lexicon);

            // 5. Insert node into hash table
            if (!table[hash_code])
            {
                // Add first node in hash_code index of hash table
                table[hash_code] = n;
            }
            else
            {
                n -> next = table[hash_code];
                table[hash_code] = n;
            }
        }
        size_out++;
    }
    fclose(f);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // Update size_out as a new node/word is added in data structure
    return size_out;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // 1. Define tmp and cursor variables to point 1st node
    // 4. Repeat unti cursor = NULL; repeat this process to all linked lists in the hash table
    node *cursor = table[0];
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            // 2. Update cursor to point to 2nd node, cursor = cursor -> next
            cursor = cursor -> next;

            // Free node
            free(tmp);
            size_out--;
        }
    }
    return (size_out == 0) ? true : false;
}
