int titleToNumber(char* s) {
    if(s) {
    	int num = 0;
    	int index = 0;
    	while(*s!='\0') {
    		num *= 26;
    		num += *s-'A' + 1;
    		s++;
    		index++;
    	}
    	return num;
    }
    return -1;
}