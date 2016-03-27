class Solution {
public:
    int rob_without_tail(vector<int>& nums) {
        int maxprepre = 0;
        int maxpre = 0;
        int max = 0;
        for(vector<int>::iterator iter = nums.begin();iter != nums.end() - 1;++iter) {
        	max = maxprepre + *iter > maxpre? maxprepre + *iter:maxpre;
        	maxprepre = maxpre;
        	maxpre = max;
        }
        return max;
    }
    int rob_without_head(vector<int>& nums) {
        int maxprepre = 0;
        int maxpre = 0;
        int max = 0;
        for(vector<int>::iterator iter = nums.begin() + 1;iter != nums.end();++iter) {
        	max = maxprepre + *iter > maxpre? maxprepre + *iter:maxpre;
        	maxprepre = maxpre;
        	maxpre = max;
        }
        return max;
    }
    int rob_without_head_tail(vector<int>& nums) {
        int maxprepre = 0;
        int maxpre = 0;
        int max = 0;
        for(vector<int>::iterator iter = nums.begin() + 1;iter != nums.end()-1;++iter) {
        	max = maxprepre + *iter > maxpre? maxprepre + *iter:maxpre;
        	maxprepre = maxpre;
        	maxpre = max;
        }
        return max;
    }
    int rob(vector<int>& nums) {
        if(nums.size()>0) {
            if(nums.size()==1) {
                return nums[0];
            }
            if(nums.size()==2) {
                return nums[1] < nums[0] ? nums[0] : nums[1];
            }
            if(nums.size()==3) {
                int max = nums[0] < nums[1] ? nums[1] : nums[0];
                return nums[2] < max ? max: nums[2];
            }
            int num1 = rob_without_tail(nums);
            int num2 = rob_without_head(nums);
            int num3 = rob_without_head_tail(nums);
            int max = num1 < num2 ? num2 : num1;
            return num3 < max ? max : num3;
        }
    }
};