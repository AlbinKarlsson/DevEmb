/* EXERCISE 2: ENCRYPTION
Create a very simple encryption program.
The program “shifts characters” in the ASCII-code table of a given input string.
In the example below, A has shifted 13 characters in the ASCII table to N, B to O, etc.
The word HELLO becomes URYYB after encryption.
The user enters a text and the program prints out the encrypted text.
Let the program read character by character, and encrypt it as above.
The program is repeated until EOF indicated the program ends.
EOF means End Of File and is a special character,
e.g. when the user enters Ctrl +Z for Windows and Ctrl + d for Linux system.
The number of characters to shift should be provided as a program argument, e.g. my_program.exe 13 */

/* Example of a test run:
HELLO (+enter)
URYYB
Banana (+enter)
Onanan
( +Ctrl-z)
(Program ends) */

#include <stdio.h>
#include <stdlib.h>

// Function that takes an array of characters and shifts them in the ascii table by the provided offset
char encrypt(char character, int offset)
{
    // Add the offset to the character in ascii format
    int result = character + offset;
    return result;
};

// Main function
int main(int argc, char *argv[])
{
    // Initialize variable character
    char character;

    // Get the users desired offset for the encryption
    int offset = atoi(argv[1]);

    // Repeat the following until the input equals end of file character
    while (character != EOF)
    {
        // Take a character from the user input
        character = getchar();

        // Call function to encrypt the input character
        char encrypted = encrypt(character, offset);

        // Print the the encrypted character
        printf("%c", encrypted);
    }

    return 0;
};
