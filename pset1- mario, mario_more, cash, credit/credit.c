#include <stdio.h>

int main(void)
{    
    //long cc_number = 30569309025904;
    int digits[16];
    long cc_number;

    printf("Enter CC number: ");
    scanf("%li", &cc_number);

    //Get the length of cc number.
    int length_of_digits = 0;
    long num = cc_number;
    while(num != 0)
    {
        num /= 10;
        length_of_digits++;
    }

    // Add each digit of cc_number to array digits.
    for (int i = 0; cc_number; i++)
    {
        digits[i] = cc_number % 10;
        cc_number /= 10;
    }

    //Get first and second digit of cc number.
    int first_digit = digits[length_of_digits - 1];
    int second_digit = digits[length_of_digits - 2];

    // Calculate the sum of digits.
    int sum = 0;
    for (int i = 1; i < length_of_digits; i += 2)  
    {
        if (digits[i] < 5)
        {
            sum = sum + (digits[i]) * 2;
        }
        else
        {
            sum = sum + (digits[i] * 2) % 10 + 1;
        }

    }
    for (int i = 0; i < length_of_digits; i += 2)
    {
        sum += digits[i];
    }

    // Check conditions for type and valid cc_number.    
    if (sum % 10 == 0)
    {
        if (first_digit == 3 && (second_digit == 4 || second_digit == 7))
        {
            printf("AMEX\n");
        }
        else if (first_digit == 4)
        {
            printf("VISA\n");
        }
        else if (first_digit == 5 && (second_digit > 0 && second_digit < 6))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
        
    }
    else
    {
        printf("INVALID\n");
    }

    
}