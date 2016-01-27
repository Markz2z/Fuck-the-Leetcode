int addDigits(int num) {
    int result = 0;
    while(num) {
    	result += num % 10;
    	num /= 10;
    }
    if(result<10)
    	return result;
    else
    	return addDigits(result);
}