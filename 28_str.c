int strStr(char* haystack, char* needle) {
    int idx = 0;
    char * ptr1 = haystack;
    char * ptr2 = needle;
    char * temp = NULL;
    int    num_temp = 0;
    while(*ptr1!='\0') {
        idx++;
        if(*ptr2==*ptr1) {
            temp = ptr1;
            while(*ptr2==*ptr1 && *ptr2!='\0') {
                ptr2++;
                ptr1++;
            }
            if(*ptr2=='\0') 
                return idx;
            else {
                ptr1 = temp;
                ptr2 = needle;
            }
        }
        ptr1++;
    }
    if(idx==0) {
        return -1;
    }
}
