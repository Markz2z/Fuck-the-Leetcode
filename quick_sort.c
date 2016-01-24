#include "stdio.h"

int partition(int* seq, int start, int end) {
    if(end>start) {
        int pivot = seq[start];
        while(end>start){
            while(end>start && seq[end]>pivot) --end;
            seq[start] = seq[end];
            while(end>start && seq[start]<pivot) ++start;
            seq[end] = seq[start];
        }
        seq[start] = pivot;
    }
    return start;
}

void quick_sort(int* seq, int start, int end) {
    int location = 0;
    if(end>start) {
        location = partition(seq, start, end);
        quick_sort(seq, start, location-1);
        quick_sort(seq, location+1, end);
    }
}

int main() {
    int num[10] = {5,1,2,3,6,10,9,8,7,11};
    quick_sort(num,0,9);
    for(int i=0;i<10;i++) {
        printf("%d ", num[i]);
    }
    return 0;
}
