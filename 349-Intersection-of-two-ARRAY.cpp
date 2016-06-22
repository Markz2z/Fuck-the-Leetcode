
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int bit[10000];
        memset(bit, 0, sizeof(int) * 10000);
        for(vector<int>::iterator iter=nums1.begin();iter<nums1.end();++iter) {
        	if(bit[*iter]==0) {
        		bit[*iter] = 1;
        	}
        }
        for(vector<int>::iterator iter=nums2.begin();iter<nums2.end();++iter) {
        	if(bit[*iter]==1) {
        		bit[*iter] = 0;
        		result.push_back(*iter);
        	}
        }
        return result;
    }
};