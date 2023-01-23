#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    while (1)
    {

        // Store argument of switch number in shift as char array.
        char *shift = argv[1];

        // Converting the argument to an integer
        int convertedArg;
        sscanf(shift, "%d", &convertedArg);

        // Store given string
        char givenString[20];

        // enter string to encrypt
        printf("Enter a string: ");
        scanf("%s", &givenString);

        // String consisting of alphabet
        char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        int i;
        int j;
        char result[20];

        // loop through the length of the string the user has entered
        for (i = 0; i < strlen(givenString); ++i)
        {
            // loop through the length of the alphabet string, -1 to not use \0
            for (j = 0; j < strlen(alpha) - 1; ++j)
            {
                // if a character at a certain index mathes a letter in the alphabet
                if (givenString[i] == alpha[j])
                {
                    // check if the index of the character found + the added argument is bigger than or equal to the length of the alphabet
                    if (j + convertedArg >= strlen(alpha))
                    {
                      // If bigger or equal, remove the length of the alphabet to start over in the alphabet and find the right character at position j
                        j = j - strlen(alpha);
                    }
                    // result is the encrypted word by adding each character by findig the characters position with j and the given argument.
                    result[i] = alpha[j + convertedArg];
                }
            }
        }
        printf("Encrypted word: %s\n", result);
    }
    return 0;
}
