class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> queue;
        int limit = matrix.size() > k ? k : matrix.size();
        for (int i = 0; i < limit; ++i) {
            for (int j = 0; j < limit; ++j) {
                queue.push(matrix[i][j]);
                if (queue.size()>k) queue.pop();
            }
        }
        return queue.top();
    }
};