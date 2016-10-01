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
	inline int getBit(int num) {
		int res = 0;
		if (num == 0) return 1;
		while(num > 0) {
			num /= 10;
			++res;
		}
		return res;
	}

	inline int genPower(int idx) {
	    if (idx <= 0) return 0;
		int res = 1;
		while(idx-- > 0) res *= 10;
		return res;
	}

	int calRecursive(TreeNode* root, int sum) {
		if (root) {
		    sum = sum * 10 + root->val;
		    if (!root->left && !root->right) {
		    	return sum;
		    }
		    return calRecursive(root->left, sum) + calRecursive(root->right, sum);
		}
		return 0;
	}

    int sumNumbers(TreeNode* root) {
        if (root) return calRecursive(root, 0);
        return 0;
    }
};