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

    // printf("Right order: ");
    for (int m = 0; m < k; m++)
    {
        passArray[m] = array[i-1];
        // printf("%d", passArray[m]);
        i--;
    }


    long hexadecimalval = 0, p = 1, remainder;

    int t;
    long long y = 0;
    for(t = 0; t < k; t++){
        y = 10 * y + passArray[t];
    }

    while (y != 0){
        remainder = y % 10;
        hexadecimalval = hexadecimalval + remainder * p;
        p = p * 2;
        y = y / 10;
    }
    printf("\nEquivalent hexadecimal value: %lX", hexadecimalval);

}
    


