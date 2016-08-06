class Solution {
public:
    inline int getMax(int num1, int num2) {
        return num1 > num2 ? num1 : num2;
    }

    inline int getMin(int num1, int num2) {
        return num1 > num2 ? num2 : num1;
    }

    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if (size <= 0) return 0;
        int max = nums[0];
        int prevMax = nums[0];
        int prevMin = nums[0];
        for (int i = 1; i < size; ++i) {
            int tmp1 = getMax(nums[i] * prevMax, nums[i] * prevMin);
            int tmp2 = getMin(nums[i] * prevMax, nums[i] * prevMin);
            prevMin = getMin(nums[i], tmp2);
            prevMax = getMax(nums[i], tmp1);
            max = getMax(max, prevMax);
        }
        return max;
    }
};
