public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        int prev = -10000;
        for (int i = 0; i < nums.length - 2; i++) {
            if (nums[i] == prev) continue;
            int start = i + 1;
            int end = nums.length - 1;
            int prevStart = -10000, prevEnd = 10000;
            while (start < end) {
                if (nums[start] == prevStart) {
                    start++;
                    continue;
                } else if (nums[end] == prevEnd) {
                    end--;
                    continue;
                }
                if (nums[i] + nums[start] + nums[end] == 0) {
                    List<Integer> list = new ArrayList<Integer>();
                    list.add(nums[i]);
                    list.add(nums[start]);
                    list.add(nums[end]);
                    result.add(list);
                    prevStart = nums[start];
                    prevEnd = nums[end];
                    start++;
                    end--;
                } else if (nums[i] + nums[start] + nums[end] < 0) {
                    start++;
                } else {
                    end--;    
                }
            }
            prev = nums[i];
        }
        return result;
    }
}
