class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        char temp;
        while(i<j) {
            while(s[i]!='a' && s[i]!='e' && s[i]!='i'&& s[i]!='o'&& s[i]!='u'&& s[i]!='A' && s[i]!='E' && s[i]!='I'&& s[i]!='O'&& s[i]!='U' && i<j) {
                ++i;
            }
            while(s[j]!='a' && s[j]!='e' && s[j]!='i'&& s[j]!='o'&& s[j]!='u'&& s[j]!='A' && s[j]!='E' && s[j]!='I'&& s[j]!='O'&& s[j]!='U' && i<j) {
                --j;
            }
            if(i<j) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                ++i;
                --j;
            }
        }
        return s;
    }
};