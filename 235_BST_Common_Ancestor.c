/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	if(root && p && q) {
		if(p->val==q->val)
			return p;
		if(p->val < root->val && q->val<root->val){
			return lowestCommonAncestor(root->left, p, q);
		}else if(p->val > root->val && q->val > root->val) {
			return lowestCommonAncestor(root->right, p, q);
		}
		return root;
	}
}