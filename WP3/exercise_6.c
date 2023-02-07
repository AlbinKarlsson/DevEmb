#include <string.h>
#include <stdio.h>

void copyStringLibrary(char s[]);
void copyString(char s[]);
#define BUFFERSIZE 100

int main () { 

    char inputString[21];
   
    printf("Enter a string of maximum 20 characters or read from file: ");
    scanf("%s", inputString);
    printf("\n");

    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE , stdin);
    
    copyStringLibrary(inputString);
    copyString(inputString);

    return 0;

return 0;
}


void copyString(char s[])
{
    char secondCopy[21];
    int i;
 
    for (i = 0; s[i] != '\0'; i++) {
        secondCopy[i] = s[i];
    }

    printf("String method: %s\n", secondCopy);
 
}

void copyStringLibrary(char s[]){
     char copy[21];
    strcpy(copy, s);

    printf("Your string: %s\n", copy);

}
