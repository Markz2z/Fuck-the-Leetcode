class Solution {
public:
    char findTheDifference(string s, string t) {
        int len1 = s.size();
		int sum = 0;
		for (int i = 0; i < len1; ++i) {
		    sum += t[i] - s[i];
		}
		sum += t[len1];
		return (char)sum;
    }
};