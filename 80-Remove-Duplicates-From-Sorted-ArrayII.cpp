class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int count = 0, idx = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i]==nums[i-1]) {
                ++count;
                if (count >= 2) continue;
            } else {
                count = 0;
            }
            nums[idx++] = nums[i];
        }
        return idx;
    }
};