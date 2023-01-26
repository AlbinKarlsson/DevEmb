// (C) Felix Valkama, Erik Lindmaa, Albin Karlsson, group: 12 (2022)
// Work package 1
// Exercise 2
// Submission code: BB12BBBB 

/* This program takes one argument which is the number of times to shift a word
Once the program starts, input a word in the terminal and press enter. 
The terminal outputs the word you inputted with its characters shifted by the amount provided as argument
Press Ctrl + Z to close the program

E.g. 
HELLO (+enter) 
URYYB 
Banana (+enter) 
Onanan 
( +Ctrl-z) 
(Program ends) */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function that takes an array of characters and shifts them in the ascii table by the provided offset
char encrypt(char character, int offset)
{
    int result;
    // If character is uppercase:
    if (isupper(character))
    {
        // 1. Subtract ASCII 'A' from character to get its pos in alphabet
        // 2. Add the offset
        // 3. Mod 26 to ensure the value can't be higher than the number of character in the alphabet
        // 4. Add 'A' to convert the result back to ASCII format
        result = (character - 'A' + offset) % 26 + 'A';
    }
    // If character is lowercase:
    else if (islower(character))
    {
        // Perform the same actions as above using lower case letters
        result = (character - 'a' + offset) % 26 + 'a';
    }
    // If character is empty:
    else
    {
        // Return the same character as was inputted
        result = character;
    }
    return (char)result;
}

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
