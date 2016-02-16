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
	void dump(queue<TreeNode *>& q1, queue<TreeNode *>& q2) {
		while(q1.size()>0) {
			q2.push(q1.front());
			q1.pop();
		}
	}

    int minDepth(TreeNode* root) {
    	queue<TreeNode*> queue_;
    	queue<TreeNode*> next_level_;
    	int depth = 0;
    	if(root) {
    		next_level_.push(root);
    		while(next_level_.size()>0) {
    			dump(next_level_, queue_);
    			depth++;
    			while(queue_.size()>0) {
    				TreeNode * node = queue_.front();
    				queue_.pop();
    				if(!node->left && !node->right)
    					return depth;
    				if(node->left)
    					next_level_.push(node->left);
    				if(node->right)
    					next_level_.push(node->right);
    			}
    		}
    	}
    	return depth;
    }
};