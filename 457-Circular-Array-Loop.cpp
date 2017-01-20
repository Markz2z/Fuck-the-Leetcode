class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        bool result = false;
        int cur_idx = 0, len = nums.size(), flag = 0;
        if (len==0) return false;
        if (len==1) return true;
        while(true) {
            if (nums[cur_idx]==0) return false;
            int prev_idx = cur_idx;
            cur_idx = nums[cur_idx] + cur_idx;
            if (cur_idx >= len) {
                flag = 1;
                cur_idx %= len;
            }
            if (cur_idx < 0) cur_idx += len;
            if (cur_idx==0) return flag==1;
            nums[prev_idx] = 0;
        }
        return false;
    }
};