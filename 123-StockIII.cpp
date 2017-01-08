class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size<2) return 0;
        int transaction = 2;
        vector<vector<int> > global(size, vector<int>(transaction + 1, 0));
        vector<vector<int> > local(size, vector<int>(transaction + 1, 0));
        for (int i = 1; i < size; ++i) {
            int diff = prices[i] - prices[i-1];
            for (int j = 1; j <= transaction; ++j) {
                local[i][j] = max(global[i-1][j-1] + max(diff, 0), local[i-1][j] + diff);
                global[i][j] = max(global[i-1][j], local[i][j]);
            }
        }
        return global[size-1][2];
    }
};