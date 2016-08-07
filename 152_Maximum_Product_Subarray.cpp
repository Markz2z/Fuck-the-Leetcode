class Solution {
public:
    int maxProduct(vector<int>& nums) {
   		int current = 1;
   		int max = 1;
   		int zeroCount = 0;
   		int negativeCount = 0;
   		for (int i = 0;i < nums.size(); ++i) {
   			if (nums[i] == 0) {
   				zeroCount++;
   			} else if (nums[i] < 0) {
   				negativeCount++;
   			}
   			max *= nums[i];
   		}
   		if (zeroCount==0 && negativeCount%2==0) {
   			return max;
   		} else if (zeroCount==nums.size()) {
   			return 0;
   		} else if (nums.size()==1) {
   			return nums[0];
   		}
   		max = 0;
   		int start = 0;
   		int end = 1;
   		for (int i = 1;i < nums.size();++i) {
   			if (end==i) {
   				if (nums[i] > 0) {
   					end = i + 1;
   					sum *= nums[i];
   				} else if (nums[i] < 0) {
   					if (nums[i] >= max) {
   						start = i;
   						end = i + 1;
   					} else {
   						
   					}
   				} else {

   				}
   			}
   		}
   		return max;
    }
};