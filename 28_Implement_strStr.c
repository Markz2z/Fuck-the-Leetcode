int strStr(char* haystack, char* needle) {
    int  idx   = 0;
    char *ptr1 = haystack;
    char *ptr2 = needle;
    char *temp = NULL;
    int  num_temp = 0;
    int  bit[256];

    if((*haystack!='\0' && *needle=='\0')||(*haystack=='\0' && *needle=='\0'))
        return 0;

    while(*ptr1!='\0') {
        if(*ptr2==*ptr1) {
            memset(bit, 0, 256*sizeof(int));
            bit[*ptr1] = 1;
            temp = ptr1;
            while(*ptr2==*ptr1 && *ptr2!='\0' && *ptr1!='\0') {
                bit[*ptr1] = 1;
                ptr2++;
                ptr1++;
            }
            if(*ptr2=='\0') {
                return idx;
            }
            if(*ptr1=='\0') {
                return -1;
            }
            else {
                if(bit[*ptr1]==0) {
                    ptr2 = needle;
                    idx += ptr1 - temp;
                }else {
                    ptr1 = temp;
                    ptr2 = needle;
                }
            }
        }
        idx++;
        ptr1++;
    }
    return -1;
}