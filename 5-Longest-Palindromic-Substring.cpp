class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        string result = s.substr(0, 1);
    	int max = length > 1 ? 1 : 0;
        int equal[length][length];
        for (int i = 0; i < length; ++i) {
        	for (int j = 0; j < length; ++j) {
        		if (i==j) {
        			equal[i][j] = 1;
        		} else {
        			equal[i][j] = 0;
        		}
        	}
        }
        for (int delta = 1; delta < length; ++delta) {
        	for (int j = 0; j + delta < length; ++j) {
        		if (delta == 1) {
        			if (s[j]==s[j+delta]) {
        				equal[j][j+delta] = 2;
        			} else {
        				equal[j][j+delta] = 0;
        			}
        		} else {
        			if (s[j] == s[j+delta] && equal[j+1][j+delta-1] > 0) {
	        			equal[j][j+delta] = equal[j+1][j+delta -1] + 2;
	        		} else {
	        			equal[j][j+delta] = 0;
	        		}
        		}
        		if (max < equal[j][j+delta]) {
        		    max = equal[j][j+delta];
        		    result = s.substr(j, delta + 1);
        		}
        	}
        }
        return result;
    }
};