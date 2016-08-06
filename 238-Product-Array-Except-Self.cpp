class Solution {

public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        if(size<=0) return nums;
        int countZero = 0;
        int sum = 1;
        for (int i = 0; i < size; ++i) {
            if (nums[i]==0) ++countZero;
            if (i >= 1) sum *= nums[i];
        }
        if (countZero >= 2) {
            for (int i = 0; i < size; ++i) {
                nums[i] = 0;
            }
        } else if (countZero == 1) {
            int zeroProduct = 1;
            int zeroIdx = 0;
            for (int i = 0; i < size; ++i) {
                if (nums[i]!=0) {
                    zeroProduct *= nums[i];
                } else {
                    zeroIdx = i;
                }
            }
            for (int i = 0; i < size; ++i) {
                nums[i] = 0;
            }
            nums[zeroIdx] = zeroProduct;
        } else {
            for (int i = 1; i < size; ++i) {
                nums[i] = sum / nums[i] * nums[0];
            }
            nums[0] = sum;
        }
        return nums;
    }
};
