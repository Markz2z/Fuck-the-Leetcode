#include "stdio.h"

int get_len(char* s) {
	int len = 0;
	while(*s!='\0') {
		++s;
		++len;
	}
	return len;
}

int isMatch(char* s, char* p) {
	char *s_cur = s;
	char *p_cur = p;
	int  len_s = get_len(s);
	int  len_p = get_len(p);
	char *s_prev = NULL;
	char *p_prev = NULL;
	char resolve[10];
	int  resolve_idx = 0;
	while(*p_cur!='\0' && *s_cur!='\0') {
		printf("p_cur: %c s_cur: %c\n", *p_cur, *s_cur);
		//printf("p_prev: %c s_prev: %c\n", *p_prev, *s_prev);
		if(*p_cur=='.') {
			
		}else if(*p_cur=='*') {
			if(*p_prev=='.') {
                while(*s_cur==*s_prev) {
                    ++s_cur;
                }
                //--s_cur;
                resolve[resolve_idx++] = *s_prev;
                p_prev = p_cur;
                ++p_cur;
                continue;
			}else {
				while(*s_cur==*p_prev) {
					s_prev = s_cur;
					++s_cur;
				}
				++p_cur;
				if(*s_cur=='\0' && *p_cur!='\0') {
					return isMatch(s_prev, p_cur);
				}
				else {
					return isMatch(s_cur, p_cur);
				}
			}
		}else if(*p_cur!=*s_cur) {
			for(int i=0;i<resolve_idx;++i) {
				if(resolve[i]==*p_cur) {
					resolve[i] = 0;
					++s_cur;
					++p_cur;
					continue;
				}
			}
			if(*(++p_cur)=='*') {
				resolve[resolve_idx++] = p_cur[-1];
				++p_cur;
				continue;
				//return isMatch(s_cur, p_cur);
			}else
				return 0;
		}
		if(*s_cur=='\0' && *(p_cur+1)=='\0'){
			++p_cur;
			break;
		}
		if(resolve_idx>0) {
			resolve_idx = 0;
			memset(resolve, 0, sizeof(char)*10);
		}
		s_prev = s_cur;
		p_prev = p_cur;
		if(p_cur!='\0')
			++p_cur;
		if(s_cur!='\0')
			++s_cur;
	}
	printf("p: %s s: %s\n", p_cur, s_cur);
	if(*s_cur=='\0' && *p_cur!='\0') {
		while(*p_cur=='*' || *(p_cur+1)=='*' || *p_cur=='.') {
			if(*(p_cur+1)=='*') {
				p_cur += 2;
			}else {
				p_cur += 1;
			}
		}
	}
	if(*s_cur!='\0' || *p_cur!='\0')
		return 0;
	return 1;
}

int main() {
	char *s = "bbbbab";
	char *p = ".*a*ab";
	if(isMatch(s, p))
		printf("true\n");
	else
		printf("false\n");
	return 1;
}