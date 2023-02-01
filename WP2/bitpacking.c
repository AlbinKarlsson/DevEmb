#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


int main(int argc, char *argv[])
{
    printf("%d\n", argc);

    if ((argc != 6))
    {
        printf("Not enough. It has to be 5 arguments");
        return 1;
    }

    // This code takes in 5 arguments from the console and convert them into integers and stores them in the variables:
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
    int j = 0;



    // 0 000 | 00 0 0
    /*
1 = 0001
2 = 0010
3 = 0011
4 = 0100
5 = 0101
6 = 0111
7 = 1000
8 = 1001
9 = 1010
10 = 1011
11 = 1100
12 = 1101
13 = 1111
*/
    // for(int i = 0; i < 8; i++){
    //     printf("Bits:\n ");
    //     printf("Bits: %d\n", bin[i]);
    // }

    if ((engine_on < 0 || engine_on > 1) || (gear_pos < 0 || gear_pos > 4) || (key_pos < 0 || key_pos > 2) || (brake1 < 0 || brake1 > 1) || (brake2 < 0 || brake2 > 1))
    {
        printf("Not correct input");
        return 1;
    }

    // The byte variable is initialized to 0 and the values of the 5 inputs
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