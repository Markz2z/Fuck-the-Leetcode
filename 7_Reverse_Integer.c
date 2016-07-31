#include "stdio.h"
#include <string.h>

int getBit(int num, int* index) {
    int count = 0;
    while (num > 0) {
        index[count++] = num % 10;
        num /= 10;
    }
    return count;
}

int reverse(int x) {
    int bit[10];
    int is_positive = x > 0? 1:0; 
    memset(bit, 0 ,10*sizeof(int));
    x = is_positive? x : -x;
    int count = getBit(x, bit);
    int i, j;
    int res = 0;
    int max = 2147483648;
    if((count > 10) || (count == 10 && bit[0] > 2)) {
        return 0;
    }
    for(i = count - 1, j = 1;i >= 0;i--, j*=10) {
        int iter = bit[i] * j;
        res += iter;
        max -= iter;
        if(max < 0) {
            return 0;
        }
    }
    if(is_positive == 0) {
        res *= -1;
    }
    return res;
}

int main () {
    printf("%d\n", reverse(123456));
    return 1;
}