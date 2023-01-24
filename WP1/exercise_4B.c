void binary_to_hexdecimal(int i, int binary[]) {
    for (int j = i - 1; j >= 0; j--){
        printf("%ld\n", binary[j]);   
    }

    while(i % 4 != 0){
        binary[i];
        binary[i] = 0;
        i++;
    }
    for (int j = i-1; j >= 0; j--){
        printf("%ld", binary[j]);   
    }

    
}