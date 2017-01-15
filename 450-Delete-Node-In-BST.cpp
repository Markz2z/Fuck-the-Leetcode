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
	TreeNode* merge(TreeNode* n1, TreeNode* n2) {
	    TreeNode* root = n1;
		if (n1==NULL) return n2;
		if (n2==NULL) return n1;
		while (n1->right!=NULL) n1 = n1->right;
		n1->right = n2;
		return root;
	}

    TreeNode* delete_node_reconstruct(TreeNode* parent, int key) {
        if (parent==NULL) return NULL;
        if (parent->val==key) {
      		if (parent->left!=NULL) {
      			parent->left->right = merge(parent->left->right, parent->right);
      		    return parent->left;
      		} else {
      			return parent->right;
      		}
        } else if (parent->left!=NULL && parent->left->val==key) {
        	TreeNode* delete_node = parent->left;
        	if (delete_node->left!=NULL) {
        		parent->left = delete_node->left;
        		parent->left->right = merge(parent->left->right, delete_node->right);
        	} else {
        		parent->left = delete_node->right;
        	}
        } else if (parent->right!=NULL && parent->right->val==key) {
        	TreeNode* delete_node = parent->right;
        	if (delete_node->left!=NULL) {
        		parent->right = delete_node->left;
				parent->right->right = merge(parent->right->right, delete_node->right);
        	} else {
        		parent->right = delete_node->right;
        	}
        }
        return parent;
    }

    TreeNode* search_node_parent(TreeNode* root, int key) {
        if (root==NULL) return NULL;
		if ((root->left!=NULL && root->left->val==key) || (root->right!=NULL && root->right->val==key)) {
			return root;
		}
		if (root->val > key) {
			return search_node_parent(root->left, key);
		} else {
			return search_node_parent(root->right, key);
		}
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = NULL;
        if (root==NULL) return NULL;
        if (root!=NULL && root->val == key) {
        	parent = root;
        	return delete_node_reconstruct(root, key);
        } else {
        	parent = search_node_parent(root, key);
        	delete_node_reconstruct(parent, key);
        	return root;
        }
    }
};