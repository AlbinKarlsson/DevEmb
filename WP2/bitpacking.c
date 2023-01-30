#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    printf("%d\n", argc);

    if((argc != 6)){
        printf("Not enough. It has to be 5 arguments");
        return 1;
    }

    int engine_on;
    int gear_pos;
    int key_pos;
    int break1;
    int break2;

    sscanf(argv[1], "%d", &engine_on);
    sscanf(argv[2], "%d", &gear_pos);
    sscanf(argv[3], "%d", &key_pos);
    sscanf(argv[4], "%d", &break1);
    sscanf(argv[5], "%d", &break2);


    
    printf("Name:           Value:\n");
    printf("-------------------------------\n");
    printf("Engine:         %d\n", engine_on);
    printf("gear position:  %d\n", gear_pos);
    printf("Key position:   %d\n", key_pos);
    printf("Break 1:        %d\n", break1);
    printf("Break 2:        %d\n", break2);
    printf("-------------------------------\n");

    return 0;
}