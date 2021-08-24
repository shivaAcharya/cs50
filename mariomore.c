#include <stdio.h>
#include <string.h>

int main(void)
{
    int a = 4;
    // printf("Please input an interger value: ");
    // scanf("%i", &a);
    char space [] = " ";
    char hash[] = "#";

    int k = a;
    for (int i = 0; i < a; i++)
    {    
        for(int i = 1; i < k; i++)
        {
            printf("%s", space);   
        }
        for (int i = a; i >= k; i--)
        {
            printf("%s", hash);
        }
        printf("%s", space);
                for (int i = a; i >= k; i--)
        {
            printf("%s", hash);  
        }
        k--;
        if (k > 0)
        {
            printf("\n");
        }
        
    }

}