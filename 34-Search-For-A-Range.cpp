class Solution {
public:
    void find_index_in_vector(vector<int>& nums, int start, int end, int target, vector<int>& result) {
	    int len = end -start;
		if (len == 1) {
		    if (nums[start] == target) {
			    result.push_back(start);
			}
		} else if (len >= 2) {
		    int mid = (start + end) / 2;
		    find_index_in_vector(nums, start, mid, target, result);
		    find_index_in_vector(nums, mid, end, target, result);
		}
	}

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> index_vec, result;
		find_index_in_vector(nums, 0, nums.size(), target, index_vec);
        if (index_vec.size() > 1) {
		    std::sort(index_vec.begin(), index_vec.end());
		    result.push_back(index_vec[0]);
			result.push_back(index_vec[index_vec.size() - 1]);
		} else if (index_vec.size() == 1) {
		    result.push_back(index_vec[0]);
		    result.push_back(index_vec[0]);
		} else {
		    result.push_back(-1);
		    result.push_back(-1);
		}
		return result;
	}
};
