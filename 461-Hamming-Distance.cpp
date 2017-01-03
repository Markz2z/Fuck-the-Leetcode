class Solution {
public:
    int hammingDistance(int x, int y) {
        x = x ^ y;
		int result = 0;
		while (x > 0) {
		    if (x%2==1) {
			    ++result;
			}
			x /= 2;
		}
		return result;
    }
};
