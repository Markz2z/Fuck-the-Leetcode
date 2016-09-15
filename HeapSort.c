/*
* Get Top k num in an unsorted list
* Date:3/17/2016
* Author:puer
*/

#include "stdio.h"

void swap(int array[], int idx1, int idx2) {
    int temp = array[idx1];
    array[idx1] = array[idx2];
    array[idx2] = temp;
}

//guarantee the array[start] is the biggest between array[start-end]
void HeapAdjust(int array[], int start, int end) {
    int origin = array[start];

    for(int i=start*2+1;i<=end;i*=2) {
        if(i<end && array[i] < array[i+1])
            ++i;
        if(origin>array[i])
            break;
        array[start] = array[i];
        start = i;
    }
    array[start] = origin;
}

void HeapSort(int array[], int len) {

    for(int i=len/2;i>=0;--i) {
        HeapAdjust(array, i, len-1);
    }

    for(int i=len-1;i>0;--i) {
        swap(array, 0, i);
        HeapAdjust(array, 0, i-1);
    }
}

void HeapAdjust2(int array[], int start, int end) {
    int origin = array[start];
    for(int i=2*start+1;i<=end;i*=2) {
        if(i+1<=end && array[i+1] < array[i])
            ++i;
        if(origin < array[i])
            break;
        array[start] = array[i];
        start = i;
    }
    array[start] = origin;
}

int* HeapSort2(int k, int array[], int len) {
    int list[k];
    for(int i=len/2;i>=0;--i) {
        HeapAdjust2(array, i, len-1);
    }

    for(int i=len-1, j=0;i>0 && j<k;--i, ++j) {
        list[j] = array[0];
        swap(array, 0, i);
        HeapAdjust2(array, 0, i-1);
    }
    return list;
}

int main() {
    int num[10] = {9,2,3,5,1,4,8,7,6,10};
    int k = 5;
    int* list = HeapSort2(k, num, 10);
    for(int i=0;i<k;i++)
        printf("%d\n", list[i]);
    return 1;
}