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
    int findBottomLeftValue(TreeNode* root) {
        int result;
        if (root==NULL) return result;
        queue<TreeNode*> cur, next;
        cur.push(root);
        result = root->val;
        while(!cur.empty()) {
            TreeNode* node = cur.front();
            if (node->left!=NULL) next.push(node->left);
            if (node->right!=NULL) next.push(node->right);
            cur.pop();
            if (cur.empty()) {
                if (!next.empty()) result = next.front()->val;
                swap(cur, next);
            }
        }
        return result;
    }
};