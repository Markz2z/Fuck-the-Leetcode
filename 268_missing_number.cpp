class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int>::iterator it;
        int bit[65536];
        memset(bit, 0, sizeof(int)*65536);
		for(it=nums.begin();it!=nums.end();it++) {
    		bit[*it] = 1;
		}
		for(int i=0;i<65536;i++) {
			if(!bit[i])
				return i;
		}
    }
};