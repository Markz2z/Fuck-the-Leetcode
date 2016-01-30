class Solution {
public:
	bool containsDuplicate(std::vector<int>& nums) {
		map<int, int> int_map;
		for(int i=0;i<nums.size();i++){
			if(int_map.count(nums[i])) {
				return true;
			}
			int_map.insert(std::pair<int, int>(nums[i], i));
		}
		return false;
	}
};