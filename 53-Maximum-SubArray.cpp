class Solution {
public:
    inline int getMax(int num1, int num2) {
        return num1 > num2 ? num1 : num2;
    }
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if (size==1) return nums[0];
        int prevMax = nums[0];
        int max = nums[0];
        for (int i = 1; i < size; ++i) {
            prevMax = getMax(prevMax + nums[i], nums[i]);
            max = getMax(max, prevMax);
        }
        return max;
    }
};
