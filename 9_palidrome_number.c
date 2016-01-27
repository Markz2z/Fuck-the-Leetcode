int getIndex(int x) {
	int index = 0;
	while(x) {
		++index;
		x /= 10;
	}
	return index;
}

int reverse(int num) {
	int result = 0, i = 0, j = 0;
	int index = getIndex(num);
	while(index) {
		i = num % 10;
		num /= 10;
		j = index-1;
		while(j) {
			i *= 10;
			--j;
		}
		--index;
		result += i;
	}
	return result;
}

bool isPalindrome(int x) {
    if(x<0) return false;
	int num = reverse(x);
	if(num==x)
		return true;
	return false;    
}