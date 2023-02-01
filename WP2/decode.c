#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main(int argc, char *argv[])
{
    unsigned char hex;
    int byte = sscanf(argv[1], "%hhx", &hex);

    int engine_on = (hex & 0x80) >> 7;
    int gear_pos = (hex & 0x70) >> 4;
    int key_pos = (hex & 0x0C) >> 2;
    int brake1 = (hex & 0x02) >> 1;
    int brake2 = (hex & 0x01);

    printf("Name:           Value:\n");
    printf("-------------------------------\n");
    printf("Engine:         %d\n", engine_on);
    printf("gear position:  %d\n", gear_pos);
    printf("Key position:   %d\n", key_pos);
    printf("Break 1:        %d\n", brake1);
    printf("Break 2:        %d\n", brake2);
    printf("-------------------------------\n");
}