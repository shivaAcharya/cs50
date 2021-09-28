#include <stdio.h>
#include <ctype.h>

const unsigned int N = 1001;


unsigned int hash(const char *s);

unsigned int hash(const char *s)
{

    unsigned int hashval;

    for (hashval = 0; *s != '\0'; s++)
    {
        int t = *s;
        if (isupper(*s))
        {
            t = tolower(t);
        }
        hashval = t + 31 * hashval;
    }
    return hashval % N;
}

char *s = "violence";

int main(void)
{
    printf("Hash code of hari is %i\n", hash(s));
    printf("%s\n", s);
}