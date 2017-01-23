class Solution {
public:
    int findTarget(vector<int>& nums, int S, int num, int idx) {
        if (idx==-1) return S==0 ? num + 1 : num;
        num = findTarget(nums, S + nums[idx], findTarget(nums, S - nums[idx], num, idx - 1), idx - 1);
        return num;
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        return findTarget(nums, S, 0, nums.size() - 1);
    }
};