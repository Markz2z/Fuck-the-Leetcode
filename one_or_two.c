#include "stdio.h"

int calculate(int n) {
	int i = 0;
	int prev = 0;
	int prevprev = 0;
	int cur = 0;
	if(n<0)
		return 0;
	if(n==1)
		return 1;
	if(n==2)
		return 2;

	prevprev = 1;
	prev = 2;
	i = 3;
	while(i<n) {
		cur = max(prev+1, prevprev+2);
		prevprev = prev;
		prev = cur;
		++i;
	}
	return cur;
}

int main() {
	return 1;
}