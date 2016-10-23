class Solution {
public:
    int trap(vector<int>& height) {
    	if (height.size() < 3) return 0;
        int left[height.size()];
        int right[height.size()];
        int result = 0;
        left[0] = height[0];
        for (int i = 1; i < height.size(); ++i) {
        	left[i] = left[i-1] > height[i] ? left[i-1] : height[i];
        }
        right[height.size()-1] = height[height.size()-1];
        for (int i = height.size() - 2; i > 0; --i) {
        	right[i] = right[i+1] > height[i] ? right[i+1] : height[i];
        }
        for (int i = 1; i < height.size() - 1; i++) {
        	int min = left[i] < right[i] ? left[i] : right[i];
        	result += min > height[i] ? (min - height[i]) : 0;
        }
        return result;
    }
};