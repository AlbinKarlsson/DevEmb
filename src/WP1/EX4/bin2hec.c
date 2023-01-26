// (C) Felix Valkama, Erik Lindmaa, Albin Karlsson, group: 12 (2022)
// Work package 1
// Exercise 4 (bin2hec)
// Submission code: BB12BBBB 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>

void binaryToHex(char *binary, char *hex)
{
    int i, j;
    int length = strlen(binary);
    int k = 0;

    // Array for comparing hexvalue to its corresponding character
    char hexLookup[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    // Determine the hex value of a binary containing n bits
    for (i = 0; i < length; i += 4)
    {
        int hexValue = 0;

        // Determine the hex value of 4 bits 
        for (j = i; j < i + 4; j++)
        {
            // 1. First parenthesis:   Shift hex value, i.e. multiply by 2
            // 2. Second parenthesis:  Subtract ASCII value of the jth element by the ASCII value of 0 to get its int value
            // 3. Add the second and first parenthesis
            hexValue = (hexValue << 1) + (binary[j] - '0');
        }

        // Use the hex lookup table to convert the hex value to its corresponding character
        hex[k++] = hexLookup[hexValue];
    }

    // Null-terminate the string
    hex[k] = '\0';
}

// function that checks if entered string is actually a number and does not contain any characters
int isNumber(char number[])
{
    int i;
    // loops through each digit in number, as long as it is not 0
    for (i = 0; number[i] != 0; i++)
    {
        // checks if digits only or not
        if (!isdigit(number[i]))
            return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    // Check if the user provided the "-h" flag or if the user didn't provide any argument at all
    if (strcmp(argv[1], "-h") == 0)
    {
        // Print help message and return 0
        printf("To use the binary to hexadecimal conversion please provide a binary number as the second argument. E.g. 'bin2hec 1010101'");
        return 0;
    }

    // Check if input is a number. Provide error and exit if not.
    if (isNumber(argv[1]) != 0 || strlen(argv[1]) < 4)
    {
        printf("Please enter a valid binary\n");
        return 2;
    }

    // Instantiate array for hexadecimal string. Divide binary by 4 and add 1 for null character
    char hex[strlen(argv[1]) / 4];

    // Convert binary to hexadecimal
    binaryToHex(argv[1], hex);

    // Print the hexadecimal representation of the binary number
    printf("%s\n", hex);

    // Return 0
    return 0;
}