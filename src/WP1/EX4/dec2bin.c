#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Calculate how many bits are needed to represent a decimal number as binary
int calculateNeededBits(int decimal)
{
    // Find the number of bits needed to represent the decimal number
    int bits = floor(log2(decimal)) + 1;

    // Check if number can be represented by 8, 16 or 32 bits and assign the needed value to bits
    if (bits <= 8)
        bits = 8;
    else if (bits <= 16)
        bits = 16;
    else if (bits <= 32)
        bits = 32;

    // Return the number of bits
    return bits;
}

// Convert a decimal number to binary
void decimalToBinary(int decimal, int bits)
{
    // Instantiate array for string
    int binary[bits];

    // Initialize all elements in the array to '0'
    int i;
    for (i = 0; i < bits; i++)
    {
        binary[i] = 0;
    }

    // Set the index to the last element in the array
    i = bits - 1;

    // Convert decimal to binary
    while (decimal > 0)
    {
        // Use modulus to get the last digit of the decimal number in binary
        binary[i] = decimal % 2;

        // Use integer division to ensure we are working with even numbers
        decimal /= 2;

        // Decrementing the index to move to the next element in the array
        i--;
    }

    // One by one print the bits
    for (int i = 0; i < bits; i++)
    {
        printf("%d", binary[i]);
    }
}

int main(int argc, char *argv[])
{
    // Check if the user provided the "-h" flag or if the user didn't provide any argument at all
    if (strcmp(argv[1], "-h") == 0)
    {
        // Print help message and return 0
        printf("To use the decimal to binary conversion please provide a decimal number as the second argument. E.g. 'dec2bin 12'");
        return 0;
    }

    // Pointer for end of the string after conversion
    char *endptr;

    // Convert the argument from a string to a long int
    long long decimal = strtoll(argv[1], &endptr, 10);

    // If pointer isn't null, it must be an invalid character. Print error.
    // If decimal is between 0 and the maximum value of type long, print error.
    if (*endptr != '\0' || decimal > LONG_MAX || decimal < 0)
    {
        // Print error message and return 2
        printf("Error: invalid input\n");
        return 2;
    }

    // Find the number of bits needed to convert the decimal
    int bits = calculateNeededBits(decimal);

    // Convert the decimal to binary
    decimalToBinary(decimal, bits);

    // Return 0 to indicate success
    return 0;
}
