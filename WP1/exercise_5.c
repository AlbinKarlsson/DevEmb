#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
 
#define MAX 100 // Defines the maximum number of the values in the table 
#define MAXNUMBER 20 // Defines the maximum value of random numbers 
 
// ------ Function declarations   ----------  
 
// This function generates a set of random numbers 
// and fills the table *tab with these numbers 
void create_random(int *tab ){
    srand(time(0));
    for(int i = 0; i < MAX; i++){
            int random = (rand() % 20);
            tab[i] = random;
            // printf("%d,", tab[i]);
    }


}
 
// This function takes the *tab of random numbers 
// and creates a table with the frequency counts for these numbers 
void count_frequency(int *tab, int *freq ){
    int counter = 0;
    for(int i = 0; i < MAXNUMBER; i++){
        counter = 0;
        for(int j = 0; j < MAX; j++){
            if(tab[j] == i){
                counter = counter + 1;
            } 
        }
        freq[i] = counter;
    }
}     
 
// This function takes the frequency count table 
// and draws a histogram of the values in that frequency table 
void draw_histogram(int *freq ){
    int counter = 0;
    for(int i = 0; i < MAXNUMBER; i++){
        while(freq[i] != 0){
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
 
    int table[MAX], n ; 
    int frequency[MAXNUMBER]; 
    int *p = table;
    create_random(p);
    int counter1 = 0;
    for (int i = 0; i < MAX; i++){
        printf("%d,", table[i]);
        counter1++;
    }

    for (int i = 0; i < MAXNUMBER; i++){
        frequency[i] = 0;
    }
    int *f = frequency;
    count_frequency(p, f);
    printf("size of array: %d\n", counter1);
    /*
    for(int i = 0; i < MAXNUMBER; i++){
        printf("Freq: %d : With number: %d \n", frequency[i], i);
    }
    */
    draw_histogram(f);
    } 