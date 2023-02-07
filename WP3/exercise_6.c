#include <string.h>
#include <stdio.h>

void copyStringLibrary(char s[]);
void copyString(char s[]);
#define BUFFERSIZE 21

int main () { 

    char inputString[21];
   
    printf("Enter a string: ");
    scanf("%s", inputString);
    printf("\n");
    
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

    printf("String copied with copyString method: %s\n", secondCopy);
 
}

void copyStringLibrary(char s[]){
    char copy[21];
    strcpy(copy, s);

    printf("String copied with strcpy: %s\n", copy);

}
