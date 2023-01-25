#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
#define MAX 100 // Defines the maximum number of the values in the table 
#define MAXNUMBER 20 // Defines the maximum value of random numbers 
 

 
// ------ Function declarations   ----------  
 
// This function generates a set of random numbers 
// and fills the table *tab with these numbers 
void create_random(int *tab ){

srand(0);
int i;
srand(time(0));
for (i = 0; i < MAX; i++) {
    int random = (rand() % 21);
    tab[i] = random;
    // printf("%d,", tab[i]);
}
}
 
// This function takes the *tab of random numbers 
// and creates a table with the frequency counts for these numbers 
void count_frequency(int *tab, int *freq ){
    int i; 
    int count;
    for(i = 0; i < MAX; i++)  
    {  
        if(tab[i] == freq[i])  
        {  
          printf("%d has appeared at position %d in the array.\n", freq[i], i + 1);  
          count++;  
        }  
    }  
  
    printf("\nFinal Result: %d has appeared %d times in the array.\n", freq[i], count);  
    printf("\n");  
} 
 
// This function takes the frequency count table 
// and draws a histogram of the values in that frequency table 
void draw_histogram(int *freq );  
 
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

    int *f = frequency;

    // for(int i = 0; i< MAX; i++){
       // frequency[i] = 0;
    //}

    count_frequency(p, f);

} 