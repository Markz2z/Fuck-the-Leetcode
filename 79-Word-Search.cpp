class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
		if (board.empty() || board[0].empty())  return false;
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
		for (int i = 0; i < board.size(); ++i) {
		    for (int j = 0; j < board[0].size(); ++j) {
			    if (dfs(board, i, j, word, visited, 0)) return true;
			}
		}
        return false;
	}

    bool dfs(vector<vector<char> >& board, int row_idx, int col_idx, string& word, vector<vector<bool> >& visited, int idx) {
	    if (idx == word.length()) return true;
		if (row_idx < 0 || col_idx < 0 || row_idx >= board.size() || col_idx >= board[0].size() || visited[row_idx][col_idx] || board[row_idx][col_idx]!= word[idx]) return false;
        visited[row_idx][col_idx] = true;
		if (dfs(board, row_idx-1, col_idx, word, visited, idx+1)) return true;
		if (dfs(board, row_idx+1, col_idx, word, visited, idx+1)) return true;
		if (dfs(board, row_idx, col_idx-1, word, visited, idx+1)) return true;
		if (dfs(board, row_idx, col_idx+1, word, visited, idx+1)) return true;
	    visited[row_idx][col_idx] = false;
		return false;
	}
};