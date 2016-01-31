using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result = s[0];
        int len = s.length();
        int temp = numRows+1;
        while(temp<len) {
            result += s[temp];
            temp += numRows+1;
        }
        
    }
}


