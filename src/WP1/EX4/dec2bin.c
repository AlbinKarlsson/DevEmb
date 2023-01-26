/* EXERCISE 4: NUMBER CONVERSION
You should write two programs, which convert between numbers in different format. You should make sure that
these programs can be executed in a pipeline.

The programs should accept any number between 0 and the maximum value of type long in C for your compiler.

The program should use the smallest possible datatype for a given, number. For example, if the user inputs 12,
the program should use treat this as 8 bits and format the output accordingly. If the user inputs 1200, then the
program should format the output as 16 bits, etc.

The first program must convert a number in a decimal format to a binary format.
    dec2bin.exe 12 should result in 00001100

The second program should convert binary to hexadecimal value.
    bin2hec.exe 00001111 should result in 0F

You should use the program arguments so that it is possible to use these two programs like this:
    dec2bin.exe 12 | bin2hec.exe

The programs should be fail-safe, i.e.
- Should check if the string of the argument contains the correct digits
- Should check be able to provide help if the user provides the parameter ‘-h’
- Should output an error message if the conversion was not successful
- Should return 2 if the conversion is unsuccessful */
/*--------------------------------------------------------------------------------------------------------- */

/* CAN RUN BOTH THE PROGRAMS USING THE FOLLOWING IN LINUX */
/* ./dec2bin.exe 12 | xargs -I{} ./bin2hec.exe {} */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int calculateNeededBits(int decimal)
{
    // Find the number of bits needed to represent the decimal number
    int bits = floor(log2(decimal)) + 1;

    // Check if number can be represented by 8, 16 or 32 bits and assign the needed value to bits
    if (bits <= 8)
        bits = 8;
    // else if (bits <= 12)
    //     bits = 12;
    else if (bits <= 16)
        bits = 16;
    else if (bits <= 32)
        bits = 32;

    // Return the number of bits
    return bits;
}
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
        // Use modulus to get the last digit of the decimal number in binary and convert to character
        // binary[i] = (decimal % 2) + '0';
        binary[i] = decimal % 2;

        // Use integer division to ensure we are working with even numbers
        decimal /= 2;

        // Decrementing the index to move to the next element in the array
        i--;
    }

    for (int i = 0; i < bits; i++)
    {
        printf("%d", binary[i]);
    }

    // Print the binary representation of the decimal number

    // Add null character to end of string
    // binary[bits] = '\0';
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
