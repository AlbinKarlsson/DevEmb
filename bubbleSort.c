// Run: gcc MergeSortList.c -o MergeSortList && ./MergeSortList
// This is actually bubble sort
#include <stdio.h>
#include <stdlib.h>

int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
int n = 0;
int temp;
int i = 0;

// Functions I will use in this exercise

int search_number(int number, int tab[], int size)
{
    for (i = 0; i < size; i++)
    {
        if (tab[i] == number)
        {
            printf("Works????");
            return i;
        }
    }
    return -1;
}

void sort(int number, int tab[])
{
    for (int x = 0; x < number - 1; x++)
    {
        for (int y = 0; y < number - x - 1; y++)
        {
            if (tab[y] > tab[y + 1])
            {
                temp = tab[y];
                tab[y] = tab[y + 1];
                tab[y + 1] = temp;
            }
        }
    }
    printf("Array after implementing bubble sort: \n");

    for (int j = 0; j < number; j++)
    {
        printf("%d  ", test[j]);
    }
}

int main()
{
    size_t size = sizeof(test) / sizeof(test[0]);
    printf("Scan for given number (n): ");
    scanf("%d", &n);
    int found = search_number(n, test, size);
    printf("Answer: %d\n", found);

    sort(size, test);
}
