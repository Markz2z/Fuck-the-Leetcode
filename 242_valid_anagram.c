bool isAnagram(char* s, char* t) {
    int bit[256];
    memset(bit, 0 , 256*sizeof(int));
    int len1 = 0, len2 = 0;
    while(*s!='\0') {
    	bit[*s]++;
    	s++;
    	len1++;
    }
    while(*t!='\0') {
    	bit[*t]--;
    	if(bit[*t]<0)
    		return false;
    	len2++;
    	t++;
    }
    if(len1!=len2)
        return false;
    return true;
}