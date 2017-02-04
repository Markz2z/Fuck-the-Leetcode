class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return findTargetSumWays(nums, S, nums.size() - 1);
    }

    int findTargetSumWays(vector<int>& nums, int S, int idx) {
        if (idx < 0) return S==0 ? ++result : result;
        int back = nums[idx--];
        findTargetSumWays(nums, S + back, idx);
        findTargetSumWays(nums, S - back, idx);
        return result;
    }
private:
    int result = 0;
};