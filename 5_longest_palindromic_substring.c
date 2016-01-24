int getLen(char *str){
    if(str) {
        int len = 0;
        while(*str!='\0') {
            len++;
            str++;
        }
        return len;
    }
    return 0;
}

char* longestPalindrome(char* s) {
    int len = getLen(s);
    int flag[len][len];
    int i, j;
    int piv1 = 0, piv2 = 0;
    int max = 0;
    if(len==1)
        return s;
    for(i=0;i<len;i++){
        for(j=0;j<len;j++){
            if(i>=j)
                flag[i][j] = 1;
            else
                flag[i][j] = 0;
        }
    }
    for(j=1;j<len;j++) {
        for(i=0;i<j;i++) {
            if(s[i]==s[j]) {
                flag[i][j] = flag[i+1][j-1];
                if(flag[i][j] && j-i+1>max) {
                    max = j-i+1;
                    piv1 = i;
                    piv2 = j;
                }
            }
        }
    }
    s[piv2+1] = 0;
    return s+piv1;
}