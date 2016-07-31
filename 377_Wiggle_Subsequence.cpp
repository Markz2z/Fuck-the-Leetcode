class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int length = nums.size();
        if (length < 1) {
        	return 0;
        } else if (length == 1) {
        	return 1;
        } else {
        	int max = 1;
        	int lastNum = nums[0];
        	bool isPositive = nums[1] > nums[0] ? true : false;
	        for (int i = 1; i < length; ++i, isPositive = !isPositive) {
	        	if (isPositive) {
		        	if (nums[i] > lastNum) {
		        		++max;
		        	} else {
		        		isPositive = false;
		        	}
	        	} else {
	        		if (nums[i] < lastNum) {
	        			++max;
	        		} else {
		        		isPositive = true;
	        		}
	        	}
				lastNum = nums[i];
	        }
	        return max;
    	}
    }
};

    public int wiggleMaxLength(int[] nums) {
        Boolean flag = null;//true为递增
        if (nums.length <= 1)
            return nums.length;
        int count = 1;

        for (int i = 1; i < nums.length; i++) {
            if(nums[i]>nums[i-1]){//递增
                if(flag==null){//前面全相等
                    count++;
                    flag = true;
                }else{//前面位递减时
                    if(flag==false){
                        count++;
                        flag = true;
                    }
                }
            }else if(nums[i]<nums[i-1]){//与上同理
                if(flag==null){
                    count++;
                    flag = false;
                }else{
                    if(flag==true){
                        count++;
                        flag = false;
                    }
                }
            }
        }
        return count;
    }

int main {
	Solution so;
	std::vector<int> v;
	v.push_back(0);
	v.push_back(0);
	so.wiggleMaxLength();
	return 1;
}