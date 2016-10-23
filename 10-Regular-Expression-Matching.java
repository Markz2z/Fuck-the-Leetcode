public class Solution {
    // Dynamic Programming Solution
    public boolean isMatch(String /* string to check */ s, String /* patterns */ p) {
        boolean[] match = new boolean[s.length()+1];
        for(int i = 0; i < match.length; ++i) {
            match[i] = false;
        }
        match[s.length()] = true;
        for(int i = p.length() - 1; i >= 0; --i) {
            if(p.charAt(i)=='*') {
                for(int j = s.length() - 1; j >= 0; --j) {
                    match[j] = match[j] || match[j+1] && (p.charAt(i - 1)=='.'||p.charAt(i-1)==s.charAt(j));
                }
                --i;
            } else {
                for(int j=0; j<s.length(); ++j){
                    match[j] = match[j+1]&&(p.charAt(i)=='.'||p.charAt(i)==s.charAt(j));
                }
                match[s.length()] = false;
            }
        }
        return match[0];
    }
}