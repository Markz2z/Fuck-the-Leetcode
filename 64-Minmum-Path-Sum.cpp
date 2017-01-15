class Solution {
public:
    inline int min(int num1, int num2) {
        return num1 < num2 ? num1 : num2;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int len1 = grid.size(), len2, i, j;
        if (len1 == 0 || (len2 = grid[0].size())==0) return 0;
        vector<vector<int> > cnt(len1, vector<int>(len2, 0));
        cnt[0][0] = grid[0][0];
        for (i = 1; i < len2; ++i) cnt[0][i] = grid[0][i] + cnt[0][i-1];
        for (i = 1; i < len1; ++i) cnt[i][0] = grid[i][0] + cnt[i-1][0];
        for (i = 1; i < len1; ++i) {
            for (j = 1; j < len2; ++j) {
                cnt[i][j] = min(cnt[i-1][j], cnt[i][j-1]) + grid[i][j];
            }
        }
        return cnt[len1-1][len2-1];
    }
};