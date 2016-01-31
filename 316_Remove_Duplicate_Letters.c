#include "stdio.h"
#include "stdlib.h"

void init(int* vec, int len){
    int i;
    for(i=0;i<len;i++){
        vec[i] = 0;
    }
}

void join(char* a, char b, int index){
    *(a+index) = b;
}

char* removeDuplicateLetters(char* s) {
    int placehold[26];
    char* str = s;
    init(placehold, 26);
    while(*str!='\0') {
        placehold[(*str)-'a'] = 1;
        str++;
    }
    int i,j;
    int index = 0;
    char* result=(char*)malloc(sizeof(char)*26);
    memset(result,0,sizeof(char)*26);
    for(i=0;i<26;i++){
        if(placehold[i]!=0){
            join(result,'a'+i,index++);
        }
    }
    return result;
}

int main(){
    char* str = "cbacdcbc";
    printf("%s\n", removeDuplicateLetters(str));
}
