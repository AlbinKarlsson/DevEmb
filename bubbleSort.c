// Run: gcc bubbleSort.c -o bubbleSort && ./bubbleSort
// This is actually bubble sort
#include <stdio.h>
#include <stdlib.h>

int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};          // Initialize an array with set elements
int n, temp;                                                // (n) A variable to store user input value  
                                                            // (temp) A variable to store a temporary value when sorting in the bubble sort function 

// Functions I will use in this exercise

int search_number(int number, int tab[], int size)          // A function to search for a number in an array, number is the user input, tab is the test array, 
{                                                           // and the size is a calculated value for how many elements in array 
    for (int i = 0; i < size; i++)                          // A for loop to loop through the whole array to find a match
    {
        if (tab[i] == number)                               // If the conditions are met we execute the following
        {
            return i;                                       // We return i (the position in the array we found the match)
        }
    }
    return -1;                                              // If the conditons are not met we will return the value -1 to the main function 
}

void sort(int number, int tab[])                            // A sort function, with passing values: an int which represents the size of the array (number), and a pointer to the tab array 
{
    for (int x = 0; x < number - 1; x++)                    // Iterate through the size of number (aka size of array), except for the last one 
    {
        for (int y = 0; y < number - x - 1; y++)            // This will iterate through the remaining unsorted elements 
        {
            if (tab[y] > tab[y + 1])                        // If the current element is bigger than the next element execute the following 
            {
                temp = tab[y];                              // Store the value in the temp variable 
                tab[y] = tab[y + 1];                        // Replace the element with the value of the index after it 
                tab[y + 1] = temp;                          // Then we store the temp value in the next index 
            }                                               // This will successfully swap the elements 
        }
    }
    printf("Array after implementing bubble sort: \n");

    for (int j = 0; j < number; j++)                        // A loop to print out the values of the array 
    {
        printf("%d  ", test[j]);                            // Print index value 
    }
}

int main()                                                  // Main function 
{
    size_t size = sizeof(test) / sizeof(test[0]);           // This will calculate the size of an array 
    printf("Scan for given number (n): ");                  // Promt the user to provide a value for n
    scanf("%d", &n);                                        // Store user input to the address of n 
    int found = search_number(n, test, size);               // Store the return value from the search_number to the variable found 
    printf("Answer: %d\n", found);                          // Print 'found'
    sort(size, test);                                       // Call the sort function and pass the following values: size (size of array), and test (the array provided)
}
