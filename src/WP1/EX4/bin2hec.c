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

void binaryToHex(char *binary, char *hex)
{
    int i, j;
    int length = strlen(binary);
    int k = 0;

    // Array for comparing hexvalue to its corresponding character
    char hexLookup[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    /* Shifting basically 2x the decimal number in binary form
    e.g.
    0001 = 1
    0001 << 1 = 0010
    0010 = 2
    0010 << 1 = 0100
    0100 = 4
    0100 << 1 = 1000
    1000 = 8

    To explain the inner loop we can use an example:
    Convert 0011 to hexadecimal

     Iteration     Comparisons
         1       0000 << 1 = 0000
                 0000 + 0000 = 0000
         2       0000 << 1 = 0000
                 0000 + 0000 = 0000
         3       0000 << 1 = 0000
                 0000 + 0001 = 0001
         4       0001 << 1 = 0010
                 0010 + 0001 = 0011 */

    // Iterate through the binary string by 4 bits at a time
    for (i = 0; i < length; i += 4)
    {
        int hexValue = 0;

        // Iterate through 4 bits
        for (j = i; j < i + 4; j++)
        {
            // Shift the current hex value to the left by 1 (basically *2), add the current binary digit (1 or 0)
            hexValue = (hexValue << 1) + (binary[j] - '0');
        }

        // Use the hex lookup table to convert the hex value to its corresponding character
        hex[k++] = hexLookup[hexValue];
    }

    // Null-terminate the string
    hex[k] = '\0';
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
    if (strspn(argv[1], "01") != strlen(argv[1]) || strlen(argv[1]) < 4)
    {
        printf("Please enter a valid binary\n");
        return 2;
    }

    // Instantiate array for hexadecimal string. Divide binary by 4 since each hex digit is 4 binary digits
    char hex[strlen(argv[1]) / 4];

    // Convert binary to hexadecimal
    binaryToHex(argv[1], hex);

    // Print the hexadecimal representation of the binary number
    printf("%s\n", hex);

    // Return 0
    return 0;
}