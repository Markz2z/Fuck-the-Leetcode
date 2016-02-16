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

    void dumpVector(vector<vector<int>> & v1, vector<vector<int>> & v2) {
        while(v1.size()>0){
            vector<int> var = v1.back();
            v2.push_back(var);
            v1.pop_back();
        }
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vec_;
        vector<vector<int>> vec_2;
    	queue<TreeNode *> queue_;
    	queue<TreeNode *> next_level_;
    	if(root) {
	    	next_level_.push(root);
	        while(next_level_.size()>0){
	        	dump(next_level_, queue_);
	        	vector<int> v;
	        	while(queue_.size()>0) {
	        		TreeNode * node = queue_.front();
	        		queue_.pop();
        			v.push_back(node->val);
        			if(node->left)
        				next_level_.push(node->left);
        			if(node->right)
        				next_level_.push(node->right);
	        	}
	        	vec_.push_back(v);
	        }
		}
		dumpVector(vec_, vec_2);
        return vec_2;
    }
};