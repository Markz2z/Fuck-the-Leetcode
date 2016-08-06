class Solution {
public:
    inline int getMax(int num1, int num2) {
        return num1 > num2 ? num1 : num2;
    }
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if (size==1) return nums[0];
        int* currentMaxArray = new int[size];
        int max = nums[0];
        currentMaxArray[0] = nums[0];
        for (int i = 1; i < size; ++i) {
            currentMaxArray[i] = getMax(nums[i], currentMaxArray[i-1] + nums[i]);
            max = getMax(max, currentMaxArray[i]);
        }
        delete[] currentMaxArray;
        return max;
    }
}
