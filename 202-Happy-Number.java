public class Solution {
	HashSet<Integer> set = new HashSet<Integer>();
    public boolean isHappy(int n) {
        if(n==1)
			return true;
		if(set.contains(n))
			return false;
		else {
			set.add(n);
			int result = 0;
			while(n>0) {
	    		result += (n%10)*(n%10);
	    		n /= 10;
	    	}
	    	return isHappy(result);
		}
    }
}