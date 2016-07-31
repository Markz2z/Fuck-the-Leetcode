class Solution {
public:
	int gen_bit(int num, int& bits[]) {
		int result = 0;
		int i = 0;
		while (num > 0) {
			bits[i++] = num%2;
			num = num >> 1;
			++result;
		}
		return result;
	}

	int generate(int bit[], int bit) {
		int result = 0, i = 0, j = 1;
		while(i < bit) {
			if (i) {
				j *= 2;
			}
			if (bit[i]) {
				result += j;
			}
			++i;
		}
		return result;
	}

	int gen_bit(int num[]) {
		int result = 31;
		while (result >= 0 && !num[result]) {
			--result;
		}
		return result + 1;
	}

	int add(int num1 ,int bits1[] int bit1, int num2, int bits2[], int bit2) {
		int result = 0;
		int idx = 0;
		while (idx < num2) {
			if(bits1[idx] && bits2[idx]) {
				bits1[idx] = 0;
				for(int j = idx + 1; j < 32; ++j) {
					bits1[j] 
				}
			}
		}
	}

    int getSum(int a, int b) {
    	int bits1[32];
        int bits2[32];
        int bit1 = gen_bit(a, bits1);
        int bit2 = gen_bit(b, bits2);
        return bit1 > bit2 ? add(a, bits1, bit1, b, bits2, bit2) : add(b, bits2, bit2, a, bits1, bit1);
    }
};