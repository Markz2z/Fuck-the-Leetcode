class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size<=1) return 0;
        int min = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            min = prices[i] > min ? min : prices[i];
            maxProfit = (prices[i] - min) > maxProfit ? (prices[i] - min) : maxProfit;
        }
        return maxProfit;
    }
};