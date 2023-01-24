#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include "bin2hec.c"

int storage[sizeof(long) * 8], i;
long number;
char *dummy;

void decimalToBin(int n)
{

    for (i = 0; number > 0; i++)
    {
        storage[i] = number % 2;
        number = number / 2;
    }

    int k;


    printf("Number in binary: ");
    
    number = 8 - (i % 8); // Get the amount of 0 needed to format the output in an 8-bit format
    for (k = 0; k < number; k++) { // For loop that runs binMod times
        printf("%d", 0); // Prints 0
    }

    int m = i;

    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", storage[i]);
    }

    getBinaryNumber(m, storage);

}

int main(int argc, char *argv[])
{

    // Store argument of switch number in shift as char array.
    char *shift = argv[1];

    // Converting the argument to an integer
    sscanf(shift, "%ld", &number);

    if (number >= 0 && number <= LONG_MAX)
    {
        decimalToBin(number);
    }
    else
    {
        printf("Invalid input, the number should be between 0 and %ld.\n", LONG_MAX);
    }
    

    return 0;
}