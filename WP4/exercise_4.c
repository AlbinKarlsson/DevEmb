#include <stdio.h>

int search_number(int number, int tab[], int size);
void sort (int number, int tab []);

void main()
{
    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
    int result = search_number(5, test, 10);
    printf("Index of searched number: %d\n", result);

    sort(10, test);
}

int search_number(int number, int tab[], int size)
{
 
    for (int i = 0; i < size; i++)
    {
        printf("%d", tab[i]);
        if (tab[i] == number)
        {
            return i;
        }
    }

    return -1;
}

void sort (int number, int tab []){

    for(int i = 0; i < number - 1; i++){
        for(int j = 0; j < number - i - 1; j++){
            if(tab[j] > tab[j+1]){
                int temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
    printf("Numbers sorted with bubble sort: ");
    for(int k = 0; k < number; k++){
        printf("%d ", tab[k]);
    }
    printf("\n");

}