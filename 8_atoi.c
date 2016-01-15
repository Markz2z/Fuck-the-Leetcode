int myAtoi(char* str) {
    int result = 0;
    int count = 0;
    int num[10];
    int i;
    int max = 2147483647;
    int is_postive = 1;
    for(int i=0;i<10;i++) {
        num[i] = 0;
    }
    if(str) {
        char* ptr = str;
        while(*ptr==' ') {
            ptr++;
        }
        if(*ptr=='-') {
            ptr++;
            is_postive = 0;
        }else if(*ptr=='+'){
            ptr++;
        }
        for(count=0;*ptr!='\0';ptr++) {
            if(*ptr<='9' && *ptr>='0') {
                if(count==10 && is_postive) {
                    return 2147483647;
                }else if(count==10 && !is_postive) {
                    return -2147483648;
                }
                num[count] = *ptr - '0';
                count++;
            }else {
                break;
            }
        }
        for(i=1;count>0;i*=10) {
            count--;
            result += num[count] * i;
            max -= num[count] * i;
            if(max<0&&is_postive) {
                return 2147483647;
            }else if(max<0 && !is_postive){
                return -2147483648;
            }
        }
        if(!is_postive){
            result *= -1;
        }
    }
    return result;
}