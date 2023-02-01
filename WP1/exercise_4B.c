int arr[20];
int k;
void binary_to_hexdecimal(int i, int binary[]) {
    while(i % 4 != 0){      // i is the amount of elements, and if the number of elements is mod 4 then it is a full set of 4 (ex. 0110)
        binary[i] = 0;      // 
        i++;
    }
    k = i;
    for (int j = 0; j <= k+1;j++) {
        arr[j] = binary[i-1];
        i--;
    }
    printf("Binary Representation with full bits: ");
    for (int j = 0; j < k; j++){
        printf("%d", arr[j]);
    }
    long hexadecimalval = 0, p = 1, remainder;

    int t;
    long long y = 0;
    printf("num of k %lli", k);
    for(t = 0; t < k; t++){
        y = 10 * y + arr[t];
    }


    while (y != 0){
        remainder = y % 10;
        hexadecimalval = hexadecimalval + remainder * p;
        p = p * 2;
        y = y / 10;
    }
    printf("\nEquivalent hexadecimal value: %lX", hexadecimalval);

}
