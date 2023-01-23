#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess;                      // This is the input guess variable from the user
    int random_number;              // This is the random number variable that will be assigned later  
    int number_of_guesses = 1;      // The program will also keep track of how many guesses
    srand(time(0));                 // THis will produce a new time seed to make the random number be a new number each time 
    random_number = rand() % 100 + 1;   // This is the funcion to produce the random number 

    printf("Guess a number between 1 and 100: \n");
    scanf("%d", &guess);            // The input from the user 

    while (guess != random_number) {    // As long as the users guess is not the same number as the random assigned number it will loop until it matches 
        if (guess < random_number) {    // If the guess is lower than the random number is will let the user know it is too low 
            printf("Too low! Guess again: \n");
        } else {
            printf("Too high! Guess again: \n");    // Else the guess is too high 
        }
        scanf("%d", &guess);                        // Checking a new answer 
        number_of_guesses++;                        // Adding another guess to the counter
    }

    printf("You guessed the correct number: %d\n", random_number);
    printf("Your number of guesses: %d\n", number_of_guesses);

    return 0;
}