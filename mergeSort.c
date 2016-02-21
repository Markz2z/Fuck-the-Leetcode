#include "stdio.h"

void merge(int * unsort, int first, int mid, int last, int * sort) {

	int i = first, j = mid;
	int k = 0;
	while(i < mid && j < last) {
		sort[k++] = unsort[i] < unsort[j] ? unsort[i++] : unsort[j++];
	}
	while(i < mid)
		sort[k++] = unsort[i++];
	while(j < last)
		sort[k++] = unsort[j++];

	for(int v=0;v<k;v++)
		unsort[first+v] = sort[v];
}

void mergeSort(int* unsort, int first, int last, int* sort) {
	if(first + 1 < last) {
		int mid = (first + last) / 2;
		mergeSort(unsort, first, mid, sort);
		mergeSort(unsort, mid, last, sort);
		merge(unsort, first, mid, last, sort);
	}
}

int main() {
	int num1[10] = {1,3,10,2,4,7,6,5,9,8};
	int * num3 = (int *)malloc(sizeof(int) * 10);
	mergeSort(num1, 0, 10, num3);
	for(int i=0;i<10;i++) {
		printf("%d ", num3[i]);
	}
	printf("\n");
	return 1;
}