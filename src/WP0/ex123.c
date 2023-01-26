// (C) Felix Valkama, Erik Lindmaa, Albin Karlsson, group: 12 (2022)
// Work package 0
// Exercise 1, 2, 3
// Submission code: 12AAAAAA (provided by your TA-s)

#include <stdio.h>
#include <string.h>

// Main function in the program, takes arguments
int main(int argc, char *argv[])
{
    // Check if no arguments are provided
    if (argc == 1)
    {
        printf("-h          type -h to get information about how to use the program\n");
    }
    // Check if more than one argument is provided
    else if (argc > 2)
    {
        printf("-h          type -h to get information about how to use the program\n");
    }
    // Check if the first argument is -h
    else if (strcmp(argv[1], "-h") == 0)
    {
        printf("-h          provide filename and a name\n");
    }
    // Check if the number of arguments is exactly one
    else if (argc == 2)
    {
        printf("Hello World! - I'm: %s\n", argv[1]);
    }
    // Return 0 to indicate success
    return 0;
}