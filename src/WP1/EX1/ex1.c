// (C) Felix Valkama, Erik Lindmaa, Albin Karlsson, group: 12 (2022)
// Work package 1
// Exercise 1
// Submission code: BB12BBBB 

#include <stdio.h>
#include <string.h>

// Main function in the program, takes arguments
int main(int argc, char *argv[])
{
    // Initialize 'number' variable
    int number;

    // Do the following while the value of number is between 1-5, otherwise, exit
    do
    {
        printf("Enter a number between 1-5: ");

        // Read a decimal integer from user and assign it to the variable 'number'
        scanf("%d", &number);

        // Switch for the cases 1 through 5 with different prints for each value
        switch (number)
        {
        case 1:
            printf("Hello 1 \n");
            break;
        case 2:
            printf("Hello 2 \n");
            break;
        case 3:
            printf("Hello 3 \n");
            break;
        case 4:
            printf("Hello 4 \n");
            break;
        case 5:
            printf("Hello 5 \n");
            break;
        }
    } while (number <= 5 && number >= 1);

    printf("You entered a number outside the given range, exiting...");

    // Return 0 to indicate success
    return 0;
}
