public class Solution {
    public String shortestPalindrome(String s) {
		int pivot = 0;
		int len = s.length();
		int left = 0, right = 0;
		int current_max = 0;
		int max = 0;
		if(isSymmetry(s)){
			return s;
		}
		for(pivot=0;pivot<len;pivot++){
			for(left=pivot-1,right=pivot+1;left>=0 && right<len && s.charAt(left)==s.charAt(right);left--,right++){
				current_max++;
			}
			if(current_max>max){
				max = current_max;
			}
			current_max = 0;
		}
		String reverse_string = s.substring(max);
		s = inverseString(reverse_string) + s;
		return s;
    }
    
    public boolean isSymmetry(String s){
    	int len = s.length();
    	int mid = 0;
    	int i,j;
    	if(len%2==0){
    		for(i=len/2, j=len/2-1;i<s.length() && j>=0 && s.charAt(i)==s.charAt(j);i++,j--){
    		}
    		if(j==0 && s.charAt(i)==s.charAt(j)){
    			return true;
    		}
    	}
    	else{
    		for(i=len/2+1, j=len/2-1;i<s.length() && j>=0 && s.charAt(i)==s.charAt(j);i++,j--){
    		}
    		if(j==0 && s.charAt(i)==s.charAt(j)){
    			return true;
    		}
    	}
    	return false;
    }

    public String inverseString(String s){
    	String res = "";
    	for(int i=s.length()-1;i>=0;i--){
    		res += s.charAt(i);
    	}
    	return res;
    }
}
