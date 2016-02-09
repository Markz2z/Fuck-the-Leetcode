int getLen(struct TreeNode* node, int len) {
	if(node) {
		int len1 = getLen(node->left, len+1);
		int len2 = getLen(node->right, len+1);
		return len1>len2? len1 : len2;
	}
	return len;
}

bool isBalanced(struct TreeNode* root) {
	int len1 = 0;
	int len2 = 0;
	if(root) {
	    len1 = getLen(root->left, 1);
	    len2 = getLen(root->right, 1);
	    if((len2>len1+1) || (len1>len2+1)) {
	    	return false;
	    }
	    if(isBalanced(root->left) && isBalanced(root->right)) {
	    	return true;
	    }else {
	    	return false;
	    }
	}
	return true;
}