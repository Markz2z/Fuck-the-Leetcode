class Solution {
  public:
    inline long create(int n) {
	    long result = n;
	    while (n > 0) {
	        result = result * 10 + n % 10;
	        n /= 10;
	    }
	    return result;
	}

    int largestPalindrome(int n) {
        if (n==1) return 9;
		int high = pow(10, n) - 1, low = (high + 1) / 10;
        for (int i = high; i >= low; --i) {
		    long palin_num = create(i);
			for (int j = high; palin_num / j <= high && j >= low; --j) {
				if (palin_num%j==0) return palin_num % 1337;
			}
		}
		return 0;
	}
};