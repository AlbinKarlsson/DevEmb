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
