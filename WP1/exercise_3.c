#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
#define MAX 5
    int r = rand() % 101;
    int guess;
    int guessCounter;
    char response[10];
    int convertedInt;

    printf("Guess a random number: ");
    scanf("%d", &guess, guessCounter++);
    
            
        while (-1 && guessCounter <= MAX)
        {

            if (guess >= 1 && guess <= 100)
            {
                if (guess == r)
                {
                    printf("You have guessed %d times and your answer is correct\n", guessCounter);
                    printf("Do you want to finish or play a new round? type yes to play a new round and no to finish ");
                    scanf("%s", response);
                    if (strcmp(response, "yes") == 0)
                    {
                        main();
                    }
                    else if (strcmp(response, "no") == 0)
                    {
                        return 0;
                    }
                }
                else if (guess < r)
                {
                    printf("Your answer is too low. ");
                }
                else if (guess > r)
                {
                    printf("Your answer is too high. ");
                }
            }
            else
            {
                printf("Not an acceptable number.");
            }
        }
    

    return 0;
}