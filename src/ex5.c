// Write a program that creates an array of integers, array[MAX], and then fill it with MAX number of random
// integers from 1 to 99.  Let then the program prints out the following:

// - The value of the address of the array (pointer) is:  xxxxxxxxxx
// - First integer in the array is (array[0]):  xxxxxxxxxx
// - The last integer in the array is:  xxxxxxxxxx
// - The size of an integer (number of bytes) is: xxxxxxxxx
// - The size of the whole array in bytes is: xxxxxxxxx

// The program shall then, by use of a pointer, print out each integer value and then print the value multiplied by
// two.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

int main()
{
    int array[MAX];
    int i;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Fill the array with random integers
    for (i = 0; i < MAX; i++)
    {
        array[i] = rand() % 99 + 1;
    }

    // Print the address of the array (pointer)
    printf("The value of the address of the array (pointer) is: %p\n", (void*)array);

    // Print the first integer in the array
    printf("First integer in the array is (array[0]): %d\n", array[0]);

    // Print the last integer in the array
    printf("The last integer in the array is: %d\n", array[MAX - 1]);

    // Print the size of an integer (number of bytes)
    printf("The size of an integer (number of bytes) is: %lu\n", sizeof(int));

    // Print the size of the whole array in bytes
    printf("The size of the whole array in bytes is: %lu\n\n", sizeof(array));

    // Print each integer value and its double
    for (i = 0; i < MAX; i++)
    {
        printf("The value of array[%d] is: %d\n", i, *(array + i));
        printf("The value of array[%d] * 2 is: %d\n\n", i, *(array + i) * 2);
    }

    return 0;
}