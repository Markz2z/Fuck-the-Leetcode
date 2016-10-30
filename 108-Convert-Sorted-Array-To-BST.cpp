/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        TreeNode* root = nullptr;
        if (end > start) {
            int mid = (end + start) / 2;
            root = new TreeNode(nums[mid]);
            root->left = sortedArrayToBST(nums, start, mid);
            root->right = sortedArrayToBST(nums, mid + 1, end);
        }
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
};