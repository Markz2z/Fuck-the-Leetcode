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
                cout << "halfNum:" << halfNum << " startNum:" << startNum << endl;
                cout << "start:" << start << " mid:" << mid << endl;
                return findPivot(nums, start, mid);
            }
            if (halfNum > endNum) {
                cout << "halfNum:" << halfNum << " endNum:" << endNum << endl;
                cout << "mid:" << mid << " end:" << end << endl;
                return findPivot(nums, mid, end);
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int idx = findPivot(nums, 0 , nums.size() - 1);
        cout << idx << endl;
        int left = binary_search(nums, target, 0, idx + 1);
        int right = binary_search(nums, target, idx, nums.size());
        return left > right ? left : right;
    }
};