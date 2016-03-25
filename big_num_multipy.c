#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int get_len(char* str) {
	int len = 0;
	while(*str!='\0') {
		++len;
		++str;
	}
	return len;
}

void reverse(char str[]) {
	int len = get_len(str);
	int j = len - 1;
	while(j >= len/2) {
		char temp = str[j];
		str[j] = str[len - 1 - j];
		str[len-1-j] = temp;
		--j;
	}
}

void append(char result[], int idx, int operand) {
	if(result) {
		if(result[idx]==0)
			result[idx] = '0';
		result[idx] += operand;
		int i = idx;
		while(result[i]>'9') {
			if(result[i+1]!=0)
				result[i+1] += 1;
			else {
				result[i+1] = '1';
			}
			result[i] -= 10;
			++i;
		}
	}
}

int calculate(char num1[], int len1, char num2[], int len2, char* result) {
	int i = 0 , j = 0;
	int res = 0;
	for(i=len1-1;i>=0;--i) {
		for(j=len2-1;j>=0;--j) {
			res = (num1[i]-'0') * (num2[j]-'0');

			if(result[len1+len2-2-i-j]==0) {
				result[len1+len2-2-i-j] = '0' + res%10;
			}else {
				append(result, len1+len2-2-i-j, res%10);
			}

			if(res/10 > 0) {
				if(result[len1+len2-1-i-j]==0) {
					result[len1+len2-1-i-j] = '0' + res/10;
				}else {
					append(result, len1+len2-1-i-j, res/10);
				}
			}
		}
	}
}

char* multiply(char num1[], char num2[]) {
	int len1 = get_len(num1);
	int len2 = get_len(num2);
	char result[len1 + len2 + 2];
	memset(result, 0 , sizeof(char) * (len1 + len2 + 2));
	if(len1<len2) {
		calculate(num2, len2, num1, len1, result);
	}
	else {
		calculate(num1, len1, num2, len2, result);
	}
	reverse(result);
	return result;
}


int main() {
	char str[] = "98765432111111111";
	char str2[] = "2345678999999999";
	//printf("%c\n", get_len(str2));
	printf("%s\n", multiply(str, str2));
	return 1;
}