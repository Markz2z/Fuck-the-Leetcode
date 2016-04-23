class Solution {
public:
    string reverseString(string s) {
        int len = s.length();
        int ptr = 0;
        char temp;
        while(ptr < len/2) {
            temp = s[ptr];
            s[ptr] = s[len-1-ptr];
            s[len-1-ptr] = temp;
            ++ptr;
        }
        return s;
    }
};