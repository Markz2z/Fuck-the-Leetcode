int lengthOfLastWord(char* s) {
	int len = 0;
	bool is_change = false;
	if(s) {
    	while(*s!='\0') {
    		if(*s!=' ') {
    		    if(is_change) {
    		        len = 1;
    		        is_change = false;
    		    }
    		    else
    			    ++len;
    		}
    		else
    		    is_change = true;
    	    ++s;
    	}
	}
	return len;
}