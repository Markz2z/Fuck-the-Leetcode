class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = MAX_INT;
        int positive = 0;
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
        	positive = 1;
        } else {
        	positive = -1;
        }
        dividend = dividend > 0 ? dividend : -dividend;
        divisor = divisor > 0 ? divisor : -divisor;
        while (dividend > divisor) {
        	dividend -= divisor;
        	--result;
        }
        return (MAX_INT - result) * positive;
    }
};