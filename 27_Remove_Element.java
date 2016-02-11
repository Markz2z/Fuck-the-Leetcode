public class Solution {
    public int removeElement(int[] nums, int val) {
        int len = nums.length;
        int i = 0, j = 0;
        for(i=0;i<len;i++) {
        	if(nums[i]!=val) {
        		nums[j++] = nums[i];
        	}
        }
        return j;
    }
}