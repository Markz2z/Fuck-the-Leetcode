class Solution {
public:
    int getSum(int a, int b) {
        int sum = a ^ b;
        int incre = (a & b) << 1;
        while (incre != 0) {
            int tmp = sum;
            sum = tmp ^ incre;
            incre = (tmp & incre) << 1;
        }
        return sum;
    }
};