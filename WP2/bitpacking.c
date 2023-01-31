#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    printf("%d\n", argc);

    if((argc != 6)){
        printf("Not enough. It has to be 5 arguments");
        return 1;
    }

    // int engine_on;
    // int gear_pos;
    // int key_pos;
    // int break1;
    // int break2;
// 
    // sscanf(argv[1], "%d", &engine_on);
    // sscanf(argv[2], "%d", &gear_pos);
    // sscanf(argv[3], "%d", &key_pos);
    // sscanf(argv[4], "%d", &break1);
    // sscanf(argv[5], "%d", &break2);


    //This code takes in 5 arguments from the console and convert them into integers and stores them in the variables:  
    int engine_on = atoi(argv[1]);
    int gear_pos = atoi(argv[2]);
    int key_pos = atoi(argv[3]);
    int brake1 = atoi(argv[4]);
    int brake2 = atoi(argv[5]);
    printf("Engine: %X\n", engine_on);
    printf("Gear: %X\n", gear_pos);
    printf("key position: %X\n", key_pos);
    printf("Brake 1: %X\n", brake1);
    printf("Brake 2: %X\n", brake2);


    if((engine_on < 0 || engine_on > 1) || (gear_pos < 0 || gear_pos > 4) || (key_pos < 0 || key_pos > 2) || (brake1 < 0 || brake1 > 1) || (brake2 < 0 || brake2 > 1)){
        printf("Not correct input");
        return 1;
    }
    
    //The byte variable is initialized to 0 and the values of the 5 inputs 
    unsigned char byte = 0;
    byte |= engine_on << 1;
    byte |= gear_pos << 3;
    byte |= key_pos << 2;
    byte |= brake1 << 1;
    byte |= brake2 << 1;

    printf("%X\n", byte);

    printf("Name:           Value:\n");
    printf("-------------------------------\n");
    printf("Engine:         %d\n", engine_on);
    printf("gear position:  %d\n", gear_pos);
    printf("Key position:   %d\n", key_pos);
    printf("Break 1:        %d\n", brake1);
    printf("Break 2:        %d\n", brake2);
    printf("-------------------------------\n");

    return 0;
}