#include "stdio.h"

void merge(int* num1, int len, int* num2) {
    int i = 0, j = len/2, k = 0;
    while(i < len/2 && j < len) {
        num2[k++] = num1[i] < num1[j] ? num1[i++] : num1[j++];
    }
    while(i < len/2) {
        num2[k++] = num1[i++];
    }
    while(j < len) {
        num2[k++] = num1[j++];
    }
    for (i = 0; i < k; ++i) {
        num1[i] = num2[i];
    }
}

void merge_sort(int* num1, int len, int* num2) {
    if (len > 1) {
        merge_sort(num1, len/2, num2);
        merge_sort(num1 + len/2, len - len/2, num2);
        merge(num1, len, num2);
    }
}

int main() {
    int num[11] = {11, 1, 9, 8, 7, 6, 5, 2, 3, 4, 10};
    int num2[11];
    merge_sort(num, 11, num2);
    for(int i = 0; i < 11; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 1;
}