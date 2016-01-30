/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if(p==q && !p)
		return true;
    if((p && q) && (p->val==q->val)) {
    	bool result1 = isSameTree(p->left, q->left);
    	bool result2 = isSameTree(p->right, q->right);
    	if(result1&&result2)
    		return true;
    }
    return false;
}