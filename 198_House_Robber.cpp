class Solution {
public:
    int rob(vector<int>& nums) {
        int maxprepre = 0;
        int maxpre = 0;
        int max = 0;
        for(vector<int>::iterator iter = nums.begin();iter != nums.end();++iter) {
        	max = maxprepre + *iter > maxpre? maxprepre + *iter:maxpre;
        	maxprepre = maxpre;
        	maxpre = max;
        }
        return max;
    }
};