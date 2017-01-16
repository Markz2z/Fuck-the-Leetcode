class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) return 0;
        int m;
        int maxArea = 0, left = 0, right = height.size() - 1;
        while (left < right) {
            m = min(height[left], height[right]);
            maxArea = max(maxArea, (right - left) * m);
            while (height[left]<=m && left < right) ++left;
            while (height[right]<=m && left < right) --right;
        }
        return maxArea;
    }
};