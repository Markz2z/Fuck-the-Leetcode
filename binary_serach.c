#include "stdio.h"

int binary_search(int array[], int num, int len) {
	if(len>1) {
		int mid = len/2;
		if(array[mid]==num)
			return 1;
		else if(array[mid]<num)
			return binary_search(array+mid, num, len-mid);
		else
			return binary_search(array, num, mid);
	}else{
		if(array[0]==num)
			return 1;
	}
	return 0;
}

int is_bst_postorder(int array[], int len) {
	if(len==1)
		return 1;
	int result = 0;
	int root_val = array[len-1];
	printf("%d\n", root_val);
	int i = 0, brk = 0;
	while(i < len-1 && array[i] < root_val) {++i;}
	brk = i;
	printf("brk:%d\n", brk);
	while(i < len-1 && array[i] > root_val) {++i;}
	printf("i:%d\n", i);
	if(i==len-1)
		return is_bst_postorder(array, i) && is_bst_postorder(array+i, len-i);
	else
		return 0;
}

int main() {
	int a[7] = {2,7,5,11,13,12,10};
	printf("%d\n", is_bst_postorder(a, 7));
	return 1;
}