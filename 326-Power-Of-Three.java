public class Solution {
    public boolean isPowerOfThree(int n) {
        double num = Math.log(n)/Math.log(3);
        return Math.abs(num - Math.rint(num))< 0.0000000001;  
    }
}