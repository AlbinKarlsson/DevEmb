// (C) __Your names here, group: 123 __ (2022) 
// Work package 0 
// Exercise 1 
// Submission code: XXXXXX (provided by your TA-s) 
#include <stdio.h> 
#include <string.h>

int number;
int ask(void)

{
    printf("Please enter an integer between 1-5\n");
    scanf("%d",&number);
}
 
int main (void) { 

    ask();
     if (number == 1) {
      printf("Printing the first sentance\n");
      main();
    } else if (number == 2) {
      printf("Printing the second sentance\n");
      main();
    } else if (number == 3) {
      printf("Printing the third sentance\n");
      main();
    } else if (number == 4) {
      printf("Printing the fourth sentance\n");  
      main();
    } else if (number == 5) {
      printf("Printing the fifth sentance\n");
      main();   
    } else {
      return 0;
    }
}