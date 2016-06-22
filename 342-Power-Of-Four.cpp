class Solution {
public:
    bool isPowerOfFour(int num) {
        int res = num >> 2;
        if(num==1)
            return true;
        if(num > 0 && num==res*4) {
            return isPowerOfFour(res);
        }else {
            return false;
        }
    }
};