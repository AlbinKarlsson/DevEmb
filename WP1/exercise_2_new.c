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

        // create int array to store

        // enter string to encrypt
        printf("Enter a string: ");
        scanf("%s", &givenString);

        for(int i = 0; i<strlen(givenString); i++){
            printf("%d ", givenString[i]);
        }

        // printf("ASCCI values for each character: \n");
        // for(int i = 0; i<strlen(givenString); i++){
        //     printf("%c: %d \n", givenString[i], givenString[i]);
        // }
    }
    return 0;
}
