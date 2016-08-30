class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int maxProfit = 0;
        for (int i = 1; i < size; ++i) {
        	if (prices[i] > prices[i-1]) {
        		maxProfit += prices[i] - prices[i-1];
        	}
        }
        return maxProfit;
    }
};