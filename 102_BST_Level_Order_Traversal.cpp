class Solution {
public:
	void dump(queue<TreeNode *>& q1, queue<TreeNode *>& q2) {
		while(q1.size()>0) {
			q2.push(q1.front());
			q1.pop();
		}
	}

    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> vec_;
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
        return vec_;
    }
};