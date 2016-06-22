
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		int bit[10000];
		memset(bit, 0 ,sizeof(int)*10000);
		vector<int> result;
		memset(bit, 0, sizeof(int) * 10);
		for(vector<int>::iterator iter = nums1.begin();iter<nums1.end();++iter) {
			bit[*iter] += 1;
		}
		for(vector<int>::iterator iter = nums2.begin();iter<nums2.end();++iter) {
			if(bit[*iter]>0) {
				--bit[*iter];
				result.push_back(*iter);
			}
		}
		return result;
    }
};