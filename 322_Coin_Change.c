void init(int *vec, int len, int num){
    int i;
    for(i=0;i<len;i++) {
        vec[i] = num;
    }
}

int scanAndFindMin(int* vec, int len) {
    int min = 0;
    int i;
    for(i=0;i<len;i++){
        if(vec[i]>0 && min==0){
            min = vec[i];
        }else if(vec[i]>0 && vec[i]<min) {
            min = vec[i];
        }
    }
    if(min==0){
        return -1;
    }else {
        return min;
    }
}

int coinChange(int* coins, int coinsSize, int amount) {
    int i,j;
    amount++;
    int res[amount];
    int temp[coinsSize];
    init(res,amount,0);
    res[0] = 0;
    for(i=1;i<amount;i++) {
        init(temp, coinsSize, 0);
        for(j=0;j<coinsSize;j++){
            if(i>=coins[j]) { 
                if(res[i-coins[j]]>=0) {
                    temp[j] = res[i-coins[j]] + 1;
                }
            }
        }
        //quickSort(temp,0,coinsSize-1);
        //res[i] = findMin(temp, coinsSize);
        res[i] = scanAndFindMin(temp, coinsSize);
    }
    return res[amount-1];
}
