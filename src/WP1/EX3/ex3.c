// (C) Felix Valkama, Erik Lindmaa, Albin Karlsson, group: 12 (2022)
// Work package 1
// Exercise 3
// Submission code: BB12BBBB

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_COUNT 10
#define LO 1
#define HI 100

int randomNumberGenerator()
{
    // Generate a random number within the given range
    int number = (rand() % (HI - LO + 1)) + 1;
    return number;
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

void guesserGame()
{
    printf("\nGuess a number between 1-100\n\n");

    int count = 0;

    // Use current time as seed for random number generation
    srand(time(0));

    // Generate a random number between 1 and 100
    int number = randomNumberGenerator();

    while (count < MAX_COUNT)
    {
        // Increase the counter every time the while loop runs
        count++;
        printf("You have %d guess(es) left", (MAX_COUNT - count + 1));

        // Keep track of guesses
        char input[4];

        printf("\nGuess the number: ");

        // Get the guess from the user
        scanf("%s", &input);
        int guess = atoi(input);

        // If input insn't a number, print error
        if (isNumber(input) != 0)
        {
            printf("Your guess needs to a number\n");
            // Don't count invalid guesses
            count--;
        }

        // Print error message if users' guess is outside the range
        else if (guess > 100 || guess < 1)
        {
            printf("Your guess needs to be from 1 to 100\n");
            // Don't count invalid guesses
            count--;
        }

        // If the guess matches the generated number print success message
        else if (guess == number)
        {
            printf("You have guessed %d time(s) and your guess is correct\n", count);
            // Return to main function (end game)
            return;
        }

        // If the guess is lower, print a hint
        else if (guess < number)
        {
            printf("Your guess is too low\n");
        }

        // If the guess is higher, print a hint
        else if (guess > number)
        {
            printf("Your guess is too high\n");
        }
    }

    // Return to main function if the user runs out of tries
    return;
}

int main(int argc, char *argv[])
{
    char choice = 'y';

    // Launch the game if the input is 'y'
    while (choice == 'y')
    {
        // Start the game
        guesserGame();

        // Prompt user to play again once the game finishes
        printf("\nDo you want to play again? (y/n)");

        // Check the users input
        scanf(" %c", &choice);
    }
    return 0;
}