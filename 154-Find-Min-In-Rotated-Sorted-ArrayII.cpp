class Solution {
public:
	int find(vector<int>& nums, int low, int high) {
		if (high - low > 1) {
			int mid = low + (high - low) / 2;
            if (nums[low] >= nums[mid]) {
				return find(nums, low, mid);
			} else if (nums[high] < nums[mid]) {
				return find(nums, mid, high);
			}
			return nums[low];
		}
		else if (high - low == 1) return nums[high] < nums[low] ? nums[high] : nums[low];
		else if (high == low) return nums[low];
		return -1;
	}

    int findMin(vector<int>& nums) {
       	return find(nums, 0, nums.size() - 1);
    }
};