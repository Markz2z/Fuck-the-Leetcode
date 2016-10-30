public class Solution {
    private int[] orig = null;
    private int[] current = null;
    private Random random = new Random();

    public Solution(int[] nums) {
        this.orig = nums;
        this.current = nums.clone();
    }

    public int[] reset() {
        return orig;
    }

    public int[] shuffle() {
        for (int i = 0; i < current.length; ++i) {
            int pick = random.nextInt(current.length);
            int swap = current.length - 1 - i;
            int temp = current[swap];
            current[swap] = current[pick];
            current[pick] = temp;
        }
        return current;
    }
}