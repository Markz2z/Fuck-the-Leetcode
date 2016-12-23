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
    int calculate(TreeNode* root) {
    	queue<TreeNode*> queue_;
    	int sum = 0;
        if (root) {
            queue_.push(root);
            while(!queue_.empty()) {
            	TreeNode* cur = queue_.front();
            	queue_.pop();
            	++sum;
            	if (cur->left) queue_.push(cur->left);
   				if (cur->right) queue_.push(cur->right);
            }
        }
        return sum;
    }

    int kthSmallest(TreeNode* root, int k) {
    	queue<TreeNode*> queue_;
        if (root) {
        	queue_.push(root);
        	while(!queue_.empty()) {
        		TreeNode* cur = queue_.front();
        		queue_.pop();
        		int left_size = calculate(cur->left);
        		if (left_size + 1 == k) return cur->val;
        		else if (left_size + 1 > k) queue_.push(cur->left);
        		else {
        			k -= left_size + 1;
        			queue_.push(cur->right);
        		}
        	}
        }
        return -1;
    }
};