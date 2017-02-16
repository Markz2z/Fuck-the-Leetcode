/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define MIN -2147483648
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (root==NULL) return result;
        queue<TreeNode*> cur, next;
        int max = MIN;
        cur.push(root);
        while(!cur.empty()) {
            TreeNode* node = cur.front();
            max = max < node->val ? node->val : max;
            if (node->left!=NULL) next.push(node->left);
            if (node->right!=NULL) next.push(node->right);
            cur.pop();
            if (cur.empty()) {
                result.push_back(max);
                max = MIN;
                swap(cur, next);
            }
        }
        return result;
    }
};