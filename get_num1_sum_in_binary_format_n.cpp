#include <iostream>
#include "string.h"
using namespace std;

int factorial(int num) {
	int result = 1;
	int i = 0;
	while(i<num) {
		result *= ++i;
	}
	return result;
}


//the sum of 1 between 1~11111(n个1)111
int get_power_between(int num) {
  int sum1 = 1;
  int sum2 = 1;
  int res = 0;
  for(int i=num,j=0;i>=1;--i,++j){
    sum1 *= (num-j);
    res += (sum1/factorial(j+1)) * (j+1);
  }
  return res;
}

int power_2(int num) {
	int res = 1;
	while(num--) {
		res *= 2;
	}
	return res;
}

int get_len(int num, int bit[]) {
  int len = 0;
  while(num) {
  	if(num%2) {
  		bit[len] = 1;
  		cout << "1";
  	}else {
  		cout << "0";
  	}
    num /= 2;
    ++len;
  }
  cout << endl;
  return len;
}

int func(int num) {
	int bit[10];
	memset(bit, 0, sizeof(int)*10);
	get_len(num, bit);
	int result = 0;
	int count_1 = 0;
	for(int i=9;i>=0;--i) {
		if(bit[i]) {
			result += get_power_between(i) + 1 + power_2(i) * count_1;
			++count_1;
		}
	}
	return result;
}

// To execute C++, please define "int main()"
int main() {
  //001 010 011 100 101  110  111 1000
  int res = func(9);
  cout << res << endl;
  return 0;
}