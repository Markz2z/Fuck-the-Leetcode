#include "stdio.h"

void merge(int* nums1, int len, int* nums2) {
    int i = 0, j = len/2, k = 0;
    while (i < len/2 && j < len)
        nums2[k++] = nums1[i] < nums1[j] ? nums1[i++] : nums1[j++];

    while (i < len/2)
        nums2[k++] = nums1[i++];

    while (j < len)
        nums2[k++] = nums1[j++];

    for (int v = 0; v < k; v++) {
        nums1[v] = nums2[v];
    }
}

void split(int *array1, int len, int* array2) {
    if (len > 1) {
        split(array1, len/2, array2);
        split(array1 + len/2, len - len/2, array2);
        merge(array1, len, array2);
    }
}

int main() {
    int num[11] = {11, 1, 9, 8, 7, 6, 5, 2, 3, 4, 10};
    int num2[11];
    split(num, 11, num2);
    for(int i = 0; i < 11; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 1;
}