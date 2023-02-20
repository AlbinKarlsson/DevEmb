// (C) Felix Valkama, Erik Lindmaa, Albin Karlsson, group: 12 (2022)
// Work package 2
// Exercise 4
// Submission code: C12CCCCC 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[])                                    // Main function
{                                                                   // Opening bracket for the main function
    printf("%d\n", argc);

    if ((argc != 6))                                                // Check if the number of arguments is invalid
    {
        printf("Not enough. It has to be 5 arguments");
        return 1;                                                   // Return 1 to indicate failure
    }

                                                                    
    int engine_on = atoi(argv[1]);                                  // Assign the input parameter values to the variables
    int gear_pos = atoi(argv[2]);
    int key_pos = atoi(argv[3]);
    int brake1 = atoi(argv[4]);
    int brake2 = atoi(argv[5]);
                                                                    // Sanity check the values
    if ((engine_on < 0 || engine_on > 1) || (gear_pos < 0 || gear_pos > 4) || (key_pos < 0 || key_pos > 2) || (brake1 < 0 || brake1 > 1) || (brake2 < 0 || brake2 > 1))
    {
        printf("Not correct input");
        return 1;                                                   // Return 1 to indicate failure
    }

    unsigned char byte;                                             // Declare byte variable
    byte |= engine_on << 7;                                         // Shift the value of 'engine_on' to the last position in a binary and store it in the byte
    byte |= gear_pos << 4;                                          // Shift the value of 'gear_pos' to position 4, 5 and 6 in a binary and store it in the byte
    byte |= key_pos << 2;                                           // Shift the value of 'key_pos' to position 2 and 3 in a binary and store it in the byte
    byte |= brake1 << 1;                                            // Shift the value of 'brake1' to position 1 in a binary and store it in the byte
    byte |= brake2;                                                 // Since this value is either 1 or 0 it will already be in the right positions, store it in byte

    printf("%02X\n", byte);

    return 0;                                                       // Return 0 to indicate success
}