/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getMaxDepth(struct TreeNode* root, int depth) {
	if(root) {
		depth++;
		int left = depth, right = depth;
		if(root->left) {
			left = getMaxDepth(root->left, depth);
		}
		if(root->right) {
			right = getMaxDepth(root->right, depth);
		}
		return left >= right ? left : right;
	}
	return depth;
}

int maxDepth(struct TreeNode* root) {
    if(root) {
    	int left = getMaxDepth(root->left, 1);
    	int right = getMaxDepth(root->right, 1);
    	return left > right? left : right;
    }
    return 0;
}