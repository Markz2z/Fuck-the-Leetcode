class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    	int len = nums.size(), max = 0;
    	if (len < 2) return nums;
    	vector<int> longest_subset, count(len, 1), par(len);
    	sort(nums.begin(), nums.end(), greater<int>());
    	for (int i = 0; i < len; ++i) par[i] = i;
    	for (int i = 1; i < len; ++i) {
    		for (int j = 0; j < i; ++j)  {
    			if (nums[j] % nums[i]==0) {
    				if (count[j] + 1 > count[i]) {
    					count[i] = count[j] + 1;
    					par[i] = j;
    				}
    				if (count[i] > max) {
    					max = count[i];
    				 	k = i;
    				}
    			}
    		}
    	}
    	while(par[k] != k) {
    		longest_subset.push_back(nums[k]);
    		k = par[k];
    	}
    	longest_subset.push_back(nums[k]);
    	return longest_subset;
    }
};