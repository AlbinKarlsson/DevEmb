#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
 
#define MAX 100 // Defines the maximum number of the values in the table 
#define MAXNUMBER 20 // Defines the maximum value of random numbers 
 
// ------ Function declarations   ----------  
 
// This function generates a set of random numbers 
// and fills the table *tab with these numbers 
void create_random(int *tab ){
// This is a time seed, the purpose is to get a new set of random number each time you compile the program
    srand(time(0));                         
    for(int i = 0; i < MAX; i++){               // Loop through the size of MAX(100)
            int random = (rand() % MAXNUMBER);  // Assign a random number between 0 - MAXNUMBER to an int variable
            tab[i] = random;                    // Assign the int random to the element[i] in the tab array
    }
}
 
// This function takes the *tab of random numbers 
// and creates a table with the frequency counts for these numbers 
void count_frequency(int *tab, int *freq ){
    int counter = 0;                            // Initializing a variable called counter with 0. To keep track of number of times a match occur
    for(int i = 0; i < MAXNUMBER; i++){         // Loop through the freq array (0-19) 
        counter = 0;                            // Reset the counter to 0 each new freq index
        for(int j = 0; j < MAX; j++){           // Loop through each tab index 
            if(tab[j] == i){                    // If there is a match between the value of tab[j] and the i then condition has met
                counter = counter + 1;          // Add 1 to the counter 
            } 
        }
        freq[i] = counter;                      // After the whole tab array has been looped through we assign the value of counter to the index of [i]
    }
}     
 
// This function takes the frequency count table 
// and draws a histogram of the values in that frequency table 
void draw_histogram(int *freq ){
    int counter = 0;                            // Initializing a variable called counter, with value 0
    for(int i = 0; i < MAXNUMBER; i++){         // Loop through freq array using MAXNUMBER
        while(freq[i] != 0){                    // If the value is not = to 0, then we add to the counter
            freq[i] = freq[i] -1;
            counter++;
        }
        
        if(counter != 0){
            printf("%d ", i);
            for (int i = 0; i < counter; i++){
            printf("X");
            }
            printf("\n");
        }
        counter = 0;
    }
}  
 
// ------ Function definitions   ---------- 
 
 
// ------ Main   -------------------------- 
 
// The main entry point for the program 
//  
// If you choose to go for the optional part 
// Please modify it accordingly 
int main (void){ 
 
    int table[MAX], n ;             // Initializing an array with MAX amount of elements 
    int frequency[MAXNUMBER];       // Initializing an array with MAXNUMBER of elements  
    int *p = table;                 // Initializing a pointer to where the table array address is
    create_random(p);               // Call the create_ranom function and pass the pointer p to it
    int counter1 = 0;                
    for (int i = 0; i < MAX; i++){
        counter1++;
    }

    for (int i = 0; i < MAXNUMBER; i++){    // This will iterate through MAXNUMBER times over the array frequency
        frequency[i] = 0;                   // To assign a value of 0 to each index, to later count how many
    }                                       // times a number appears in the table array
    int *f = frequency;                     // Initializing a pointer to where the frequency array address is
    count_frequency(p, f);                  // Call the count_frequency function and pass p and f (pointers)
    draw_histogram(f);                      // Call the draw_histogram function and pass f (pointer)
    } 