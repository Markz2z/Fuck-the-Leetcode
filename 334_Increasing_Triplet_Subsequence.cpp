class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        int cur[3];
        int min = 0;
        int idx = 0;
        if(len<3) {
        	return false;
        }

        if(len==3) {
        	if(nums[0] < nums[1] && nums[1] < nums[2])
        		return true;
        	else
        		return false;
        }

        cur[idx++] = nums[0];
        min = nums[0];

        for(vector<int>::iterator iter=nums.begin()+1;iter!=nums.end();++iter) {
        	if(*iter > cur[idx-1]) {
        		cur[idx++] = *iter;
        	}else if(idx==2 && *iter > cur[0]) {
        		cur[1] = *iter;
        	}else if(*iter > min) {
        		cur[0] = min;
        		cur[1] = *iter;
        	}else {
        		min = *iter;
        	}
        	if(idx==3) {
        		return true;
        	}
        }
        return false;
    }
};