#include <string.h>
#include <stdio.h>

void copyStringLibrary(char s[]);                   // Function declaration for function using library
void copyString(char s[]);                          // Function declaration for manual copy

int main()
{

    char inputString[25];                           // Declare char varible for the input string
    scanf("%s", inputString);                       // Saving the inputted string

    if (strlen(inputString) > 21)
    { // If length is bigger than 21 return 0
        printf("String too long. Try again \n");
        return 0;
    }

    copyStringLibrary(inputString);                 // Call function using the libarary strcpy function
    copyString(inputString);                        // Call function with the manual implementation for copying a string

    return 0;
}

void copyString(char s[])
{
    char secondCopy[21];                            // Declare variable for making the second copy
    int i;                                          // Declare int variable i to be used to loop through string

    for (i = 0; s[i] != '\0'; i++)                  // Loop through string until character is \0
    {
        secondCopy[i] = s[i];                       // Copy over string at each position to secondCopy
    }

    printf("String copied with copyString method: %s\n", secondCopy);
}

void copyStringLibrary(char s[])
{
    char copy[21];                                  // Declare char variable for the copy
    strcpy(copy, s);                                // Use strcpy to copy string to copy

    printf("String copied with strcpy: %s\n", copy);
}
