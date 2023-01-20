// (C) __Your names here, group: 123 __ (2022) 
// Work package 0 
// Exercise 1 
// Submission code: XXXXXX (provided by your TA-s) 
#include <stdio.h> 
#include <string.h>

 // Main function in the program, no program arguments supported 
void main (int argc, char *argv[]) { 
 // Print a string to the console 

    // If only filename is provided, print an error and how to use the program.
   if (argc == 1) {
      printf("Error...\n");
    // If more than two arguments are provided, print error  
   } else if (argc > 2) {
      printf("Error...\n");
    // Check if provided argument is -h and then print how to use the program
   } else if (strcmp(argv[1], "-h") == 0){
      printf("Use the program by adding an argument after the filename hellworld");
    // If two arguments are provided, and the second one is not -h, print message.  
   } else if( argc == 2 ) {
      printf("Hello World! - I'm %s\n", argv[1]);
   } 
}