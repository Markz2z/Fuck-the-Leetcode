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
    void clear(queue<TreeNode *>& queue) {
        while(queue.size()>0)
            queue.pop();
    }

    void traversalTree(queue<TreeNode *> traverse_list, vector<int>& v) {
        queue<TreeNode *> to_traverse_list;
        while(traverse_list.size()>0) {
            TreeNode* node = traverse_list.front();
            if(node->left)
                to_traverse_list.push(node->left);
            if(node->right)
                to_traverse_list.push(node->right);
                
            if(traverse_list.size()==1) {
                TreeNode *node = traverse_list.front();
                traverse_list.pop();
                v.push_back(node->val);
                traverse_list = to_traverse_list;
                clear(to_traverse_list);
            }else
                traverse_list.pop();
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root) {
            queue<TreeNode *> to_traverse_list;
            to_traverse_list.push(root);
            traversalTree(to_traverse_list, result);
        }
        return result;
    }
};