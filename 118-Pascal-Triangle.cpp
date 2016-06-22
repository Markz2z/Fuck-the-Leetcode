class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=0;i<numRows;++i) {
        	vector<int> row_result;
        	for(int j=0;j<i+1;++j) {
 				if(j==0 || j==i) {
 					row_result.push_back(1);
 					continue;
 				}else {
 					row_result.push_back(result[i-1][j-1] + result[i-1][j]);
 				}
        	}
        	result.push_back(row_result);
        }
        return result;
    }
};