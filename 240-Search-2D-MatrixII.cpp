class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = 0, y = matrix[0].size() - 1;
        while(x < matrix.size()) {
        	while(y > 0 && matrix[x][y] > target) {
        		--y;
        	}
        	if (matrix[x][y]==target) return true;
        	++x;
        }
        return false;
    }
};