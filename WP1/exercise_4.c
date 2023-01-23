#include <stdio.h>
#include <limits.h>

long given_decimal;
char *endPointer;
char *argv;
long num;
void givenDecimalToBinary(int n) {
    int binaryNum[sizeof(long) * 8];    // Adjusting the size of the array to a predetermined size of Long 
    int i = 0;                          // Initilizing the size of the binary length
    while (n > 0) {                     // A while loop to check as long as given number is larger than 0, then continue 
        binaryNum[i] = n % 2;           // Mod n to find if it is a 0 or a 1 from the remainder
        n = n / 2;                      // Divide n continously 
        i++;                            // Add one to the index of the binary array 
    }
    printf("Binary representation of %ld is: ", num);
    for (int j = i - 1; j >= 0; j--)    // This for loop will iterate through the binary array and print out the numbers 
        printf("%d", binaryNum[j]);
}

int main(int argc, char *argv[]) {
    num = strtol(argv[1], endPointer, 10);
    if (num >= 0 && num <= LONG_MAX) {
        givenDecimalToBinary(num);
    } else {
        printf("Invalid input, the number should be between 0 and %ld.\n", LONG_MAX);
    }
    return 0;
}


/*
Step 1: Mod the given given_decimal number by 2 and you get a 0 or a 1 
Exmaple:
10 % 2 = 0 
20 % 2 = 0 

Store the divded n and do mod on that, for example: 
10 % 2 = 0 
5 % 2 = 1 
2 % 2 = 0
1 % 2 = 1

So the binary code is 1010 as you start from right to left.

*/