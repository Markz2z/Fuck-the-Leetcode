int countPrimes(int n) {
    if(n<=1)
        return 0;
    int* bit = (int *)malloc(sizeof(int) * (n+1));
    bit[2] = 0;
    for(int i=3;i<n;i++){
        if(!(i&0x01))
            bit[i] = 1;
        else
            bit[i] = 0;
    }
    for(int i=3;i<=sqrt(n);i=i+2) {
        for(int j=2;i*j<n;j++)
            bit[i*j] = 1;
    }
    int count = 0;
    for(int i=2;i<n;i++) {
        if(!bit[i])
            count++;
    }
    free(bit);
    return count;
}