// (C) __Your names here, group: 123 __ (2022) 
// Work package 0 
// Exercise 1 
// Submission code: XXXXXX (provided by your TA-s) 
#include <stdio.h> 
#include <string.h>

int number;

// Ask function asks the user for input, and stores the number.
int ask(void)
{
    printf("Please enter an integer between 1-5\n");
    scanf("%d",&number);
}
 
int main (void) { 
  // Calls function every time main runs.
    ask();
    /* if input number is 1, it checks that the value is 1 and prints the first sentance. 
     it then calls main to repeat the function. */
     if (number == 1) {
      printf("Printing the first sentance\n");
      main();
    /* if input number is 2, it checks that the value is 2 and prints the second sentance. 
     it then calls main to repeat the function. */
    } else if (number == 2) {
      printf("Printing the second sentance\n");
      main();
    /* if input number is 3, it checks that the value is 3 and prints the third sentance. 
     it then calls main to repeat the function. */
    } else if (number == 3) {
      printf("Printing the third sentance\n");
      main();
    /* if input number is 4, it checks that the value is 4 and prints the fourth sentance. 
     it then calls main to repeat the function. */
    } else if (number == 4) {
      printf("Printing the fourth sentance\n");  
      main();
    /* if input number is 5, it checks that the value is 5 and prints the fifth sentance. 
     it then calls main to repeat the function. */
    } else if (number == 5) {
      printf("Printing the fifth sentance\n");
      main();   
    } else {
      /* return 0 if number is not in the range from 1-5 */
      return 0;
    }
}