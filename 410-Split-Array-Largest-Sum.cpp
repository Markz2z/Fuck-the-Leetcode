class Solution {
public:
    bool valid(int mid, vector<int>& nums, int m) {
        int count = 1, cur_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cur_sum += nums[i];
            if (cur_sum > mid) {
                ++count;
                if (count > m) {
                    return false;
                }
                cur_sum = nums[i];
            }
        }
        return true;
    }

    int binary_search(vector<int>& nums, int m, long high, long low) {
        while (high > low) {
            long mid = (low + high) / 2;
            if (valid(mid, nums, m)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }


    int splitArray(vector<int>& nums, int m) {
        if (nums.size() == 1) return nums[0];
        long sum = 0, max = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            max = max > nums[i] ? max : nums[i];
            sum += nums[i];
        }
        return binary_search(nums, m, sum, max);
    }
};