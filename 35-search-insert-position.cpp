class Solution {
public:
    int find_index(vector<int>& nums, const int& target, const int& start, const int& end) {
	   if ((end - start) == 1) {
	       if (nums[start] == target) return start;
	   } else {
	       int mid_idx = (end - start) / 2 + start;
		   if (target > nums[mid_idx - 1] && target < nums[mid_idx]) return mid_idx;
	       int ret = find_index(nums, target, start, mid_idx);
		   if (ret != -1) return ret;
	       ret = find_index(nums, target, mid_idx, end);
		   if (ret != -1) return ret;
	   }
	   return -1;
	}

    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 1) {
		    return target > nums[0] ? 1 : 0;
		} else {
		    if (target < nums[0]) return 0;
			if (target > nums[nums.size() - 1]) return nums.size();
			return find_index(nums, target, 0, nums.size());
		}
	}
};