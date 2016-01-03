void init(int* vec,int len) {
    int i;
    for(i=0;i<len;i++) {
        vec[i] = 0;
    }
}

int calculateLength(char* s) {
    int len = 0;
    char *temp = s;
    while(*temp++!='\0') {
        len++;
    }
    return len;
}

void holderAssign(int* dest, int* src, int len){
    for(int i=0;i<len;i++){
        *(dest+i)=*(src+i);
    }
}

int lengthOfLongestSubstring(char* s) {
    //hashtable for characters to show if it is part of the max sequence
    int placeholder[256];
    //tail holder for characters
    int tailHolder[256];
    //tail holder index for every character
    int index[256];
    //flag
    int isTail = 0;
    init(placeholder, 256);
    init(tailHolder, 256);
    init(index, 256);
    //length of s
    int length = calculateLength(s);
    int maxLetter[length];
    init(maxLetter, length);
    int i,j,k;
    int tail_max = 0;
    int pre_tail_max = 0;
    if(length>0) {
        placeholder[s[0]] = 1;
        maxLetter[0] = 1;
        isTail = 1;
        tailHolder[s[0]] = 1;
        tail_max = 1;
        index[s[0]] = tail_max;
    }else {
        return 0;
    }
    for(i=1;i<length;i++) {
        if(isTail==1) {
            if(placeholder[s[i]]==0) {
                maxLetter[i] = maxLetter[i-1] + 1;
                placeholder[s[i]] = 1;
                tailHolder[s[i]] = 1;
                tail_max++;
                index[s[i]] = tail_max;
            }else {
                maxLetter[i] = maxLetter[i-1];
                pre_tail_max = tail_max;
                tail_max = tail_max - index[s[i]] + 1;
                index[s[i]] = tail_max;
                for(j=i-tail_max-1;j>i-1-pre_tail_max;j--){
                    tailHolder[s[j]] = 0;
                    index [s[j]] = 0;
                }
                for(j=i-tail_max+1,k=1;j<=i;j++,k++){
                    index[s[j]] = k;
                }
                tailHolder[s[i]] = 1;
                isTail = 0;
            }
        }else {
            if(tailHolder[s[i]]==0){
                tail_max++;
                index[s[i]] = tail_max;
                tailHolder[s[i]] = 1;
            }else {
                pre_tail_max = tail_max;
                tail_max = tail_max - index[s[i]] + 1;
                for(j=i-tail_max-1;j>i-1-pre_tail_max;j--){
                    tailHolder[s[j]] = 0;
                    index[s[j]] = 0;
                }
                for(j=i-tail_max+1,k=1;j<=i;j++,k++){
                    index[s[j]] = k;
                }
                index[s[i]] = tail_max;
                tailHolder[s[i]] = 1;
            }

            if(tail_max >= maxLetter[i-1]) {
                maxLetter[i] = tail_max;
                holderAssign(placeholder, tailHolder, 256);
                isTail = 1;
            }else {
                maxLetter[i] = maxLetter[i-1];
                isTail = 0;
            }
        }
    }
    return maxLetter[length-1];
}