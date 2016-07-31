#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        combinationSumDFS(candidates, target, 0, out, res);
        return res;
    }
    static void combinationSumDFS(vector<int> &candidates, int target, int start, vector<int> &out, vector<vector<int> > &res) {
        if (target < 0) return;
        else if (target == 0) res.push_back(out);
        else {
            for (int i = start; i < candidates.size(); ++i) {
                out.push_back(candidates[i]);
                combinationSumDFS(candidates, target - candidates[i], i, out, res);
                out.pop_back();
            }
        }
    }
    static vector<vector<int> > generate(int numRows) {  
        vector<vector<int> > result;  
        for (int i=0; i<numRows; ++i) {  
            vector<int> temp(i+1,1);  
            cout<< &temp <<endl;  
            result.push_back(temp);  
        }  
        for (int i=0; i<numRows; ++i) {  
            cout<<&result[i]<<endl;  
        }  
        return result;  
    }  
};

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	vector<vector<int> > result = Solution::combinationSum(v, 4);
	for(auto i:result) {
		for(auto j:i) {
			cout << j << " ";
		}
		cout << endl;
	}
	vector<vector<int> > var;
	vector<int> var1;
	var1.push_back(1);
	var1.push_back(2);
	var.push_back(var1);
	var1.pop_back();
	var.push_back(var1);
	cout << endl;
	for(auto i : var) {
		for(auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

	cout << endl;
	var = Solution::generate(3);
}