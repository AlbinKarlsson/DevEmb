// (C) Felix Valkama, Erik Lindmaa, Albin Karlsson, group: 12 (2022)
// Work package 2
// Exercise 4
// Submission code: C12CCCCC 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int main(int argc, char *argv[])
{
    unsigned char hex;                                              // Declare 'hex' variable
    int byte = sscanf(argv[1], "%hhx", &hex);                       // Convert input to a hex and store it in 'hex' variable

    if (argc != 2)                                                  // If the number of arguments is invalid
    {
        printf("Too many arguments!");
        return 1;                                                   // Return 1 to indicate failure
    }

    if (byte != 1 || strlen(argv[1]) != 2 || atoi(argv[1]) < 0)     // If the input is not a hex, the length of argument 1 is not equal to 2, or if the input is less than 0
    {
        printf("Invalid input: %s\n", argv[1]);
        return 1;                                                   // Return 1 to indicate failure
    } 

    int engine_on = (hex & 0x80) >> 7;                              // Isolate the last bit and shift it to the far right. Assign the bit to 'engine_on' variable
    int gear_pos = (hex & 0x70) >> 4;                               // Isolate bit 6, 5 and 4 and shift them to the far right. Assign these bits to the variable 'gear_pos'
    int key_pos = (hex & 0x0C) >> 2;                                // Isolate bit isolate bit 2 and 3 and shift them to the far right. Assign the value to 'key_pos'
    int brake1 = (hex & 0x02) >> 1;                                 // Isolate bit 1 and shift it to the far right. Assign the value to 'brake1'
    int brake2 = (hex & 0x01);                                      // Isolate the last bit and assign the value to 'brake2'
                                                 
    printf("Name:           Value:\n");          
    printf("-------------------------------\n"); 
    printf("Engine:         %d\n", engine_on);   
    printf("gear position:  %d\n", gear_pos);    
    printf("Key position:   %d\n", key_pos);     
    printf("Break 1:        %d\n", brake1);      
    printf("Break 2:        %d\n", brake2);      
    printf("-------------------------------\n"); 
                                                 
    return 0;                                                       // Return 0 to indicate success
}