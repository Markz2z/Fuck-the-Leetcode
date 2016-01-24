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
    for(i=0;i<len;i++){
        for(j=0;j<len;j++){
            if(i>=j)
                flag[i][j] = 1;
            else
                flag[i][j] = 0;
        }
    }
    for(j=1;j<len;j++)
        for(i=0;i<j;i++) {
            if(s[i]==s[j]) {
                flag[i][j] = flag[i+1][j-1];
                if(flag[i][j] && j-i+1>max) {
                    max = j-i+1;
                    piv1 = i;
                    piv2 = j;
                    printf("i:%d max:%d\n", piv1, max);
                }
            }
        }
    char * res = (char* )malloc(max);
    memcpy(res, s+piv1, max);
    return res;
}