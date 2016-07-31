// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if(guess(n) == 0) return n;
        int flag = 0, left = 1, right = n;
        int predict = right / 2;
        while((flag = guess(predict)) != 0) {
        	if(flag == 1) {
                left = predict;
        	} else {
        		right = predict;
        	}
        	predict = left + (right - left) / 2;
        }
        return predict;
    }
};