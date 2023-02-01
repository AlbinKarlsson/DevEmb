#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    printf("%d\n", argc);

    if((argc != 6)){
        printf("Not enough. It has to be 5 arguments");
        return 1;
    }

    //This code takes in 5 arguments from the console and convert them into integers and stores them in the variables:  
    int engine_on = atoi(argv[1]);
    int gear_pos = atoi(argv[2]);
    int key_pos = atoi(argv[3]);
    int brake1 = atoi(argv[4]);
    int brake2 = atoi(argv[5]);

    if((engine_on < 0 || engine_on > 1) || (gear_pos < 0 || gear_pos > 4) || (key_pos < 0 || key_pos > 2) || (brake1 < 0 || brake1 > 1) || (brake2 < 0 || brake2 > 1)){
        printf("Not correct input");
        return 1;
    }
    
    //The byte variable is initialized to 0 and the values of the 5 inputs 
    unsigned char byte;
    byte |= engine_on << 7;
    byte |= gear_pos << 4;
    byte |= key_pos << 2;
    byte |= brake1 << 1;
    byte |= brake2;

    printf("%02X\n", byte);

    return 0;
}