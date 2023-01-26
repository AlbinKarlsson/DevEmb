#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include "bin2hec.c"
#include <string.h>

int storage[sizeof(long) * 8], i;
long number;
int k;

int decimalToBin(int n)
{
    int calc;

    if(number <= 9){
        calc = 4;
    } else if (number > 9 && number <= 99) {
        calc = 8;
    } else if(number > 99 && number <= 999) {
        calc = 12;
    }  else if(number > 999 && number <= 9999){
        calc = 16;
    }

    if(number > 4095){
        printf("Conversion was not successful. The number has to be lower than 4096 and has to be maximum 12 bit number");
        return 2;
    } else{
    for (i = 0; number > 0; i++)
    {
        storage[i] = number % 2;
        number = number / 2;
    }
    }

    printf("Number in binary: ");

    number = calc - (i % calc); // Get the amount of 0 needed to format the output in an 8-bit format
    for (k = 0; k < number; k++) { // For loop that runs binMod times
        printf("%d", 0); // Prints 0
    }

    int m = i;

    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", storage[i]);
    }

    getBinaryNumber(m, storage);
    

}

    int isNumber(char number[]) {
        int i;

        for(i = 0; number[i] != 0; i++) {
            if(!isdigit(number[i]))
            return 1;
        }
       return 0; 
    }

int main(int argc, char *argv[])
{
    if(strcmp(argv[1], "-h") == 0){
        printf("In order to use to program, type in a decimal number as argument.");
        return 0;
    } 

    // Store argument of switch number in shift as char array.
    char *shift = argv[1];

    // Converting the argument to an integer
    sscanf(shift, "%ld", &number);

    int test = isNumber(argv[1]);

    
    if ((number >= 0 && number <= LONG_MAX) && test == 0)
    {
        decimalToBin(number);
    }
    else
    {
        printf("Invalid input, the number should be between 0 and %ld.\n", LONG_MAX);
    }
    

    return 0;
}