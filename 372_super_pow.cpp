class Solution {
public:
	int superPow(int a, int k) {
		if(k==0) return 1;
		int ans = 1;
		for (int i = 1; i <= k; ++i) {
			ans = (ans * a) % 1337;
		}
		return ans;
	}

    int superPow(int a, vector<int>& b) {
    	if(b.empty()) return 1;
    	a %= 1337;
    	int lastBit = b.back();
    	b.pop_back();
    	return (superPow(superPow(a, b), 10) * superPow(a, lastBit)) % 1337;
    }
};