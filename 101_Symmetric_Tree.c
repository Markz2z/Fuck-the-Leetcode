bool isSym(struct TreeNode* left, struct TreeNode* right) {
	if(!left && !right)
		return true;
	if(!left && right)
		return false;
	if(!right && left)
		return false;
	if(left->val==right->val) {
		return isSym(left->left, right->right) && isSym(left->right, right->left);
	}else {
		return false;
	}
}


bool isSymmetric(struct TreeNode* root) {
	if(root) {
		return isSym(root->left, root->right);
	}
	return true;
}