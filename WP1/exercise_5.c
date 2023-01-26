#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100      // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers

int count;

// ------ Function declarations   ----------

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab)
{

    srand(0);
    int i;
    srand(time(0));
    for (i = 0; i < MAX; i++)
    {
        int random = (rand() % 21);
        tab[i] = random;
        printf("%d,", tab[i]);
    }
}

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq)
{
    for (int i = 0; i <= MAXNUMBER; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (tab[j] == i)
            {
                count++;
            }
        }
        printf("\nFinal Result: %d has appeared %d times in the array.\n", i, count);
        freq[i] = count;
        count = 0;
    }
    printf("\n");
}

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq)
{
    int i;
    char count[] = "X";

    for (i = 0; i < MAXNUMBER + 1; i++)
        if (freq[i] != 0)
        {
            printf("%d ", i);
            for (int j = 0; j < freq[i]; j++)
            {
                printf("%s", count);
            }
              printf("\n");
        }
}

// ------ Function definitions   ----------

// ------ Main   --------------------------

// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main(void)
{

    int table[MAX], n;
    int frequency[MAXNUMBER];
    int *p = table;
    create_random(p);

    int *f = frequency;
    count_frequency(p, f);

    draw_histogram(f);
}