class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if(!n)
            return 0;
        int bit[32];
        memset(bit, 0, sizeof(int)*32);
        int i = -1, j = 1, res = 0;
        for(i=0;i<32 && n>0;i++) {
        	if(n%2==1) {
        		bit[i] = 1;
        	}else
        	    bit[i] = 0;
        	n /= 2;
        }
        i = 31;
        while(i>=0) {
        	if(bit[i]==1)
        		res += j;
        	j *= 2;
        	i--;
        }
        return res;
    }
};