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
    int prev, prev_cnt = 0, max_cnt = 0;
    void inorder(vector<int>& result, TreeNode* root) {
        if (root!=NULL) {
            inorder(result, root->left);
            if (prev==root->val) {
                ++prev_cnt;
            } else {
                prev_cnt = 1;
                prev = root->val;
            }
            if (prev_cnt > max_cnt) {
                result.clear();
                result.push_back(root->val);
                max_cnt = prev_cnt;
            } else if (prev_cnt==max_cnt) {
                result.push_back(root->val);
            }
            inorder(result, root->right);
        }
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        inorder(result, root);
        return result;
    }
};