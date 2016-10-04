class Solution {
public:
    int binary_search(vector<int>& nums, int target, int start, int end) {
        int idx = -1;
        if (end - start == 1) {
            return nums[start] == target ? start : -1;
        }
        while (end > start) {
            int halfIdx = start + (end - start) / 2;
            int half = nums[halfIdx];
            if (half > target) return binary_search(nums, target, start , halfIdx);
            else if (half == target) return halfIdx;
            else return binary_search(nums, target, halfIdx, end);
        }
        return -1;
    }

    int findPivot(vector<int>& nums, int start , int end) {
        int len = end - start + 1;
        int mid = start + (end - start) / 2;
        if (start == end) return start;
        if (end - start == 1) return nums[start] < nums[end] ? end : start;
        if (len > 1) {
            int halfNum = nums[mid], startNum = nums[start], endNum = nums[end];
            if (halfNum < startNum) {
                return findPivot(nums, start, mid);
            }
            if (halfNum > endNum) {
                return findPivot(nums, mid, end);
            }
        }
        return -1;
    }

    inline void swap(vector<int>& nums, int idx1, int idx2) {
        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
    }

    int partition(vector<int>& nums, int start, int end) {
        if (end <= start) return start;
        int pivot = nums[start], left = start;
        for (int i = start + 1; i <= end; ++i) {
            if (nums[i] < pivot) swap(nums, ++left, i);
        }
        swap(nums, start, left);
        return left;
    }
    
    void quick_sort(vector<int>&nums, int start, int end) {
        if (end <= start) return;
        int idx =partition(nums, start, end);
        quick_sort(nums, start, idx - 1);
        quick_sort(nums, idx + 1, end);
    }

    bool search(vector<int>& nums, int target) {
        quick_sort(nums, 0, nums.size() - 1);
        int idx = binary_search(nums, target, 0, nums.size());
        return idx > -1 ? true : false;
    }
};