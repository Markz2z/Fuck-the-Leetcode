/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//author: Mingkun Zeng
//Date:03/28/2016
//result array represent the return val
//result[0] represents the maximum num that rob from current root
//result[1] represents the maximum num that rob from current root's left child plus the right child
//every time traverse to a new node, it will update the current maxmium and it's child layer's maximum
class Solution {
public:
    inline int max(int num1, int num2) {
        return num1 < num2 ? num2 : num1;
    }
    vector<int> traverse(TreeNode* root) {
        vector<int> left;
        vector<int> right;
        vector<int> result;
        if(root!=nullptr) {
            left = traverse(root->left);
            right = traverse(root->right);
            result.push_back(left[1] + right[1] + root->val);
            result.push_back(max(left[0], left[1]) + max(right[0], right[1]));
        }else {
            result.push_back(0);
            result.push_back(0);
        }
        return result;
    }

    int rob(TreeNode* root) {
        vector<int> result = traverse(root);
        return max(result[0], result[1]);
    }
};