public class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        int i = len-1;
        digits[i]++;
        while(i>0) {
	    	if(digits[i]==10) {
	    		digits[i] = 0;
	    		digits[i-1]++;
	    		i--;
	    	}else {
	    		return digits;
	    	}
    	}
    	if(digits[0]==10) {
    		digits = new int[len+1];
    		digits[0] = 1;
    		for(int j=1;j<len+1;j++){
    			digits[j] = 0;
    		}
    	}
    	return digits;
    }
}