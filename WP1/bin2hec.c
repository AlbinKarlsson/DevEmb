int passArray[20];
int k; 

void getBinaryNumber(int i, int array[])
{

    while (i % 4 != 0)
    {
        array[i] = 0;
        i++;
    }

    k = i;

    printf("\n");

    printf("Right order: ");
    for (int m = 0; m < k; m++)
    {
        passArray[m] = array[i-1];
        printf("%d", passArray[m]);
        i--;
    }
}
    


