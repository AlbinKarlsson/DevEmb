void main(int argc, char *argv[])
{

#include <stdio.h>
#include <string.h>

    // Store argument of switch number in shift as char array.
    char *shift = argv[1];

    // Converting the argument to an integer
    int convertedArg;
    sscanf(shift, "%d", &convertedArg);
    printf("Converting: %d\n", convertedArg);

    // Store given string
    char givenString[20];

    // enter string to encrypt
    printf("Enter a string:\n");
    scanf("%s", &givenString);

    // String consisting of alphabet
    char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int i;
    int j;
    char result[20];


    for (i = 0; i < strlen(givenString); ++i)
    {   
        for (j = 0; j < strlen(alpha); ++j) {
            if(givenString[i] == alpha[j]){
                // printf("works\n");
                result[i] = alpha[j+convertedArg];
            }
            if(j == strlen(alpha)-1){
                    j = 0;
                    printf("works\n");
            }
        }
    }
    printf("%s\n", result);
}