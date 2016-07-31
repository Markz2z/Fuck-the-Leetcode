#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int len = s.length();
        int ptr = 0;
        char temp;
        while(ptr < len / 2) {
            temp = s[ptr];
            s[ptr] = s[len-1-ptr];
            s[len-1-ptr] = temp;
            cout << "Round" << ptr + 1 << " exchange " << s[ptr] << " and " << temp << endl;
            ++ptr;
        }
        return s;
    }
};

int main () {
    Solution s;
    cout << s.reverseString("123456") << endl;
}