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
    void dumpVector(vector<int> & v1, vector<int> & v2) {
        while(v1.size()>0){
            int var = v1.back();
            v2.push_back(var);
            v1.pop_back();
        }
    }

	void traversalTree(queue<TreeNode *> traverse_list, vector<int>& v) {
		queue<TreeNode *> to_traverse_list;
		while(traverse_list.size()>1) {
			TreeNode* node = traverse_list.pop();
			if(node->left)
				to_traverse_list.push(node->left);
			if(node->right)
				to_traverse_list.push(node->right);
		}
		if(traverse_list.size()==1) {
			TreeNode *node = traverse_list.pop();
			v.push_back(node->val);
		}
		traversalTree(to_traverse_list, v);
	}

    vector<int> rightSideView(TreeNode* root) {
    	vector<int> result;
    	queue<TreeNode *> to_traverse_list;
    	to_traverse_list.push(result)
		traversalTree(to_traverse_list, result);
        return result2;
    }
};