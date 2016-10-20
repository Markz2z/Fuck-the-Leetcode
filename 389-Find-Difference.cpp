class Solution {
public:
    char findTheDifference(string s, string t) {
        int len1 = s.size(), len2 = t.size(), i, count[len2];
        string result;
        memset(count, 0 , sizeof(int) * t);
        count[0] = t[0] == s[0] ? 1 : 0;
        for (i = 1; i < len2; ++i) {
        	if (s[count[i-1]]==t[i]) {
        		count[i] = count[i-1] + 1;
        		if (count[i]==len1) break;
        	}
        }
        result = t.substr(0, i-len1) + t.substr(i, len2-i);
        return result;
    }
};