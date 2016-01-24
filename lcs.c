//Date:   2016.1.24
//author: Mingkun Zeng

int getMax(int num1, int num2) {
	if(num1>num2)
		return num1;
	return num2;
}

int getLen(char *str){
	if(str){
		int max = 0;
		while(*str!='\0'){
			max++;
			str++;
		}
		return max;
	}
	return 0;
}

int lcs(char* str1, char* str2) {
	int max = 0, i = 0, j = 0;
	int len1 = getLen(str1)+1, len2 = getLen(str2)+1;
	int counter[len1][len2];
	for(i=0;i<len1;i++)
		counter[i][0] = 0;
	for(j=0;j<len2;j++)
		counter[0][j] = 0;
	for(i=1;i<len1;i++) {
		for(j=1;j<len2;j++) {
			if(str1[i]==str2[j]){
				counter[i][j] = counter[i-1][j-1]+1;
			}
			else{
				counter[i][j] = getMax(counter[i-1][j], counter[i][j-1]);
			}
		}
	}
	return counter[len1-1][len2-1];
}