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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root) {
            unordered_map<TreeNode*, bool> visited_;
            stack<TreeNode*> stack_;
            stack_.push(root);
            int cur = 0;
            while (stack_.size() > 0) {
                TreeNode* node = stack_.top();
                if (!visited_[node]) {
                    visited_[node] = true;
                    cur += node->val;
                } else {
                    cur -= node->val;
                    stack_.pop();
                    continue;
                }
                if (!node->left && !node->right) {
                    if (cur == sum) {
                        std::cout << "val " << node->val << std::endl; 
                        std::cout << cur << std::endl;
                        return true;
                    }
                } else {
                    bool flag = false;
                    if (node->left && !visited_[node->left]) {
                        stack_.push(node->left);
                        flag = true;
                    }
                    if (node->right && !visited_[node->right]) {
                        stack_.push(node->right);
                        flag = true;
                    }
                    continue;
                }
            }
        }
        return false;
    }
};