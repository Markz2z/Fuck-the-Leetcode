class Solution {
public:
/*
解释：
首先，因为能买2次（第一次的卖可以和第二次的买在同一时间），但第二次的买不能在第一次的卖左边。
所以维护2个表，f1和f2，size都和prices一样大。
意义：
f1[i]表示 -- 截止到i下标为止，左边所做交易能够达到最大profit；
f2[i]表示 -- 截止到i下标为止，右边所做交易能够达到最大profit；
那么，对于f1 + f2，寻求最大即可。
*/
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int size = prices.size();
        if (size == 0)
            return 0;

        vector<int> f1(size);
        vector<int> f2(size);

        int minV = prices[0];
        for (int i = 1; i < size; i++){
            minV = std::min(minV, prices[i]);
            f1[i] = std::max(f1[i-1], prices[i] - minV);
        }

        int maxV = prices[size-1];
        f2[size-1] = 0;
        for (int i = size-2; i >= 0; i--){
            maxV = std::max(maxV, prices[i]);
            f2[i] = std::max(f2[i+1], maxV - prices[i]);
        }

        int sum = 0;
        for (int i = 0; i < size; i++)
            sum = std::max(sum, f1[i] + f2[i]);

        return sum;
    }
};