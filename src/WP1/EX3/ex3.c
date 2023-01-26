/* EXERCISE 3: GUESS THE NUMBER GAME
You should develop a very simple game in which the computer creates a random integer number, between
1..100, and the user then tries to guess the number. The program should work as specified below:

- The computer creates a random number
- The user guesses the number
- The computer responds by printing one of the following:
    - You have guessed AA times and your guess is correct (if the user guesses correctly)
    - Your guess is too low or too high, depending on the mistake of the user
- If wrong the user is asked for a new guess, this will continue until the guess is right or the number
  of guesses exceeds the value MAX_NUMBER.
- After end of one round the user is asked for a new round or to finish.

The program should only except guessed numbers in the range of 1 ...100.

An option, but not a demand, is to secure that the program does not fail (crashes) if a user by accident inputs a
number outside of the range or a character/string. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNumberGenerator(int lo, int hi)
{
    // Generate a random number within the given range
    int number = (rand() % (hi - lo + 1)) + 1;
    // printf("\nNumber is: %d", number);
    return number;
}

void guesserGame()
{
    int lo = 1;
    int hi = 100;
    int count = 0;

    // Initialize the MAX_COUNT variable
    const int MAX_COUNT = 10;

    // TODO: New solution for generating seed as this will make it possible to predict what the number is as it increases
    //       as time increases until it reaches 100 and then restarts from 1
    // Use current time as seed for random number generation
    srand(time(0));

    // Generate a random number between 1 and 100
    int number = randomNumberGenerator(lo, hi);

    while (count < MAX_COUNT)
    {
        // Increase the counter every time the while loop runs
        count++;

        // Keep track of guesses
        int guess;

        printf("\nGuess the number: ");

        // Get the guess from the user
        scanf("%d", &guess);

        // Check if input is a number. Provide error and exit if not.
        if (strspn(guess, "0123456789") != strlen(guess))
        {
            printf("Please enter a valid number");
            // Don't count invalid guesses
            count--;
        }

        // Print error message if users' guess is outside the range
        if (guess > 100 || guess < 1)
        {
            printf("Your guess needs to be from 1 to 100");
            // Don't count invalid guesses
            count--;
        }

        // If the guess matches the generated number print success message
        else if (guess == number)
        {
            printf("You have guessed %d time(s) and your guess is correct", count);
            // Return to main function (end game)
            return;
        }

        // If the guess is lower, print a hint
        else if (guess < number)
        {
            printf("Your guess is too low");
        }

        // If the guess is higher, print a hint
        else if (guess > number)
        {
            printf("Your guess is too high");
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