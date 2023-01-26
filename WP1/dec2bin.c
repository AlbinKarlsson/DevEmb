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


    // check what range number is in. Calc is then later used to calculate how many numbers that should be added to the binary one.
    if(number <= 9){
        calc = 4;
    } else if (number > 9 && number <= 99) {
        calc = 8;
    } else if(number > 99 && number <= 999) {
        calc = 12;
    }  else if(number > 999 && number <= 9999){
        calc = 16;
    }

    // Added a check if number is bigger than 4095, and will print an error if user enters such a big number and return 2.
    if(number > 4095){
        printf("Conversion was not successful. The number has to be lower than 4096 and has to be maximum 12 bit number");
        return 2;
    } else{
    // As long as number is bigger than 0, perform calculation to binary.    
    for (i = 0; number > 0; i++)
    {
        // Get remainder each time and add it to the array called storage to get the binary number. Divide number by 2 each time.
        storage[i] = number % 2;
        number = number / 2;
    }
    }

    printf("Number in binary: ");

    // Calculate how many 0s to add to the number to get in the right binary format.
    number = calc - (i % calc); // Get the amount of 0 needed to format the output in an 8-bit format
    for (k = 0; k < number; k++) { // For loop that runs binMod times
        printf("%d", 0); // Prints 0
    }

    int m = i;

    // loop to reverse the binary string to the correct order.
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", storage[i]);
    }

    // function call in bin2hec to calculate the binary number
    getBinaryNumber(m, storage);
    

}
    // functiont that checks if entered string is actually a number and does not contain any characters
    int isNumber(char number[]) {
        int i;
        // loops through each digit in number, as long as it is not 0
        for(i = 0; number[i] != 0; i++) {
            // checks if digits only or not
            if(!isdigit(number[i]))
            return 1;
        }
       return 0; 
    }

int main(int argc, char *argv[])
{   
    // If user enters -hd, message on how to run the program will be shown.
    if(strcmp(argv[1], "-h") == 0){
        printf("In order to use to program, type in a decimal number as argument.");
        return 0;
    } 

    // Store argument of switch number in shift as char array.
    char *shift = argv[1];

    // Converting the argument to an integer
    sscanf(shift, "%ld", &number);

    int numberCheck = isNumber(argv[1]);

    
    if ((number >= 0 && number <= LONG_MAX) && numberCheck == 0)
    {
        decimalToBin(number);
    }
    else
    {
        printf("Invalid input, the number should be between 0 and %ld.\n", LONG_MAX);
    }
    

    return 0;
}