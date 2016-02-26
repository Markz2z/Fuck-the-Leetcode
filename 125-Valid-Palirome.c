char isLetter(char s) {
	if(s) {
		if((s >= 'a' && s <= 'z') || (s>='0' && s<='9')) {
			return s;
		}else if(s >= 'A' && s <= 'Z') {
			return s + 'a' -'A';
		}
	}
	return NULL;
}

int getLen(char* s) {
	int len = 0;
	while(s && *s!='\0') {
		++len;
		++s;
	}
	return len;
}

bool isPalindrome(char* s) {
	int len = getLen(s);
	printf("len: %d\n", len);
	int i = 0, j = 0;
	char symb1, symb2;
	for(i=0, j=len-1;i<j;++i,--j) {
		while(i<j && !isLetter(s[i])) {
			++i;
		}
		symb1 = isLetter(s[i]);

		while(i<j && !isLetter(s[j])) {
			--j;
		}
		symb2 = isLetter(s[j]);

		if(symb1!=symb2){
			return false;
		}
	}
	return true;
}