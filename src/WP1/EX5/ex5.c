/* EXERCISE 5: POINTERS

You should develop a program that calculates statistical values for an array of integers. Among other things, the
program should plot a histogram for the frequency of different numbers in the array.

You need to create an array of integers (table [MAX]) where MAX is the number of random numbers between 0
and MAXNUMBER. Then you should write a function that for each possible number between 0 – MAXNUMBER
calculates how many times the number exists in the array. The result is then stored in a new array (frequency
[]).

Finally, you should write a function that takes the array frequency [] as a parameter and draws a histogram as in
the example below.

Example:

    Given an array table[]={1,2,12,5,1,0,0,5,9,12,0,2,3,0} the program will printout:

    0 xxxx
    1 xx
    2 xx
    3 x
    5 xx
    9 x
    12 xx

    Note! Numbers with frequency 0 in the array frequency[] are not printed out.

Optional: instead of using #define MAX and #define MAXNUMBER, you can use the program arguments
instead.

Please start with the skeleton code below: */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100      // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers
// ------ Function declarations ----------
// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab);
// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq);
// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq);
// ------ Function definitions ----------
// ------ Main --------------------------
// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main(void)
{
    int table[MAX], n;
    int frequency[MAXNUMBER];
}